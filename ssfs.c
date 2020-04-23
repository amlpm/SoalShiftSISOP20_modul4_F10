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

static  const  char *dirName = "/home/amelia/Documents";
char key[100] = "9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO";

//enkrip pake caesar cipher
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

//dekrip pake caesar cipher
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

static  int  xmp_getattr(const char *path, struct stat *stbuf){
    int res;
    char fpath[1000];
    char nama1[100];

    sprintf(nama1, "%s", path);
    encription1(nama1);

    sprintf(fpath,"%s%s", dirName, nama1);
    res = lstat(fpath, stbuf);

    if (res == -1) return -errno;
    return 0;
}

//klo buat direktori
static int xmp_mkdir(const char *path, mode_t mode)
{
	int result;
	char d_name1[100];
    char fpath[100];
    char compare1[100];
    char res1[100];

	sprintf(d_name1, "%s", path);
    sprintf(fpath, "%s%s", dirName, d_name1);
    result = mkdir(fpath, 0750); 
	if (result == -1) return -errno;

    return 0;
}

//kalau direktori / file di rename
static int xmp_rename(const char *dari, const char *ke)
{
	int res;
    char baru_dari[1000];
    char baru_ke1[1000];
	char nama1[1000];
    char satu[] = "encv1_";
    char compare1[100];
    char res1[100];

	sprintf(nama1, "encv1_%s", ke);
    sprintf(baru_dari, "%s%s", dirName, dari);

    //kalo dr folder normal di rename dgn awalan encv1_
    strcpy(res1, strncpy(compare1, nama1, 6));
    if(strcmp(res1, satu) == 0){
        encription1(nama1);
        sprintf(baru_ke1, "%s%s", dirName, nama1);
        res = rename(baru_dari, baru_ke1);
        if (res == -1) return -errno;
    }
    return 0;
}

//untuk enkrip dalem direktorinya 
static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    DIR *directory;
	struct dirent *de;

    (void) offset;
	(void) fi;

    char fpath[1000];
    char nama1[1000];

	sprintf(nama1, "%s", path);
    encription1(nama1);

	sprintf(fpath, "%s%s", dirName, nama1);
	directory = opendir(fpath);
	if (directory == NULL) return -errno;

	while ((de = readdir(directory)) != NULL) {
        char enkrip[1000];
		strcpy(enkrip, de->d_name);
		char fileName[1000];

		sprintf(fileName, "%s%s", fpath, enkrip);
		encription1(enkrip);
    }
    return 0;
}

static  struct fuse_operations xmp_oper = {
    .getattr = xmp_getattr,
    .readdir = xmp_readdir,
    .mkdir = xmp_mkdir,
    .rename = xmp_rename,
};

int main (int argc, char* argv[]){
    umask(0);
    return fuse_main(argc, argv, &xmp_oper, NULL);
}