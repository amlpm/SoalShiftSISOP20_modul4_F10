#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/wait.h>
#include <pthread.h>

char dirName[100] = "/home/amelia/Documents";
char key[100] = "9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO";

void encription1(char* enc) {
    if(strcmp(enc, ".") == 0 || strcmp(enc, "..")) return;
    int length = strlen(enc);
    for ( int i = 0; i < length; i++) {
        for (int j = 0; j < 87; j++) {
            if(enc[i] == key[j]) {
                enc[i] = key[(j+10) % 87];
                break;
            }
        }
    }
}

void encription2(char* enc){

}

void decription1(char* dec) {
    if(strcmp(dec, ".") == 0 || strcmp(dec, "..")) return;
    int length = strlen(dec);
    for ( int i = 0; i < length; i++) {
        for (int j = 0; j < 87; j++) {
            if(dec[i] == key[j]) {
                dec[i] = key[(j+77) % 87];
                break;
            }
        }
    }
}

void decription2(char* dec) {

}

static int xmp_mkdir(const char *path, mode_t mode)
{
	int result;
	char d_name1[100], d_name2[100];
    char fpath[100];
    char satu[] = "encv1_";
    char dua[] = "encv2_";
    char compare1[100], compare2[100];
    char res1[100], res2[100];

    //kalau direktori dibuat dengan awalan encv1_
	sprintf(d_name1, sizeof(d_name1), "encv1_%s", path);
    strcpy(res1, strncpy(compare1, d_name1, 5));
    if(strcmp(res1, satu) == 0){
        encription1(d_name1);
        sprintf(fpath, "%s%s", dirName, d_name1);
        result = mkdir(fpath, 0750); 
	    if (result == -1) return -errno;
    }

    //kalau direktori dibuat dengan awalan encv2_
	sprintf(d_name2, sizeof(d_name2), "encv2_%s", path);
    strcpy(res2, strncpy(compare2, d_name2, 5));
	if(strcmp(res2, dua) == 0){
        encription2(d_name2);
	    sprintf(fpath, "%s%s", dirName, d_name2);
        result = mkdir(fpath, 0750); 
	    if (result == -1) return -errno;
    }
}

static  struct fuse_operations xmp_oper = {
//     .getattr = xmp_getattr,
//     .readdir = xmp_readdir,
    .mkdir = xmp_mkdir,
//     .rmdir = xmp_rmdir,
//     .rename = xmp_rename,
};

int main (int argc, char* argv[]){
    umask(0);
    return fuse_main(argc, argv, &xmp_oper, NULL);
}