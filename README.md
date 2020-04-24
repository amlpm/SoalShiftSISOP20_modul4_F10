# SoalShiftSISOP20_Modul4_F10

## Kelompok F10 
- **Geizka Wahyu 05111840000062**
- **Amelia Puji  05111840000147**

### 1. Enkripsi versi 1 : 

- **a.** Jika sebuah direktori dibuat dengan awalan “encv1_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.
- **b.** Jika sebuah direktori di-rename dengan awalan “encv1_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.
- **c.** Apabila sebuah direktori terenkripsi di-rename menjadi tidak terenkripsi, maka isi adirektori tersebut akan terdekrip.
- **d.** Setiap pembuatan direktori terenkripsi baru (mkdir ataupun rename) akan tercatat ke sebuah database/log berupa file.
- **e.** Semua file yang berada dalam direktori ter enkripsi menggunakan caesar cipher dengan key. ```9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO```
- **f.** Metode enkripsi pada suatu direktori juga berlaku kedalam direktori lainnya yang ada didalamnya.
Jawab : 

Funsi Enkripsi versi 1 :
```Javascript
void encription1WithLength(char* enc, int length) {
	if(strcmp(enc, ".") == 0 || strcmp(enc, "..") == 0)return;
	for(int i = length; i >= 0; i--){
		if(enc[i]=='/')break;
		if(enc[i]=='.'){
			length = i;
			break;
		}
	}
	int start = 0;
	for(int i = 0; i < length; i++){
		if(enc[i] == '/'){
			start = i+1;
			break;
		}
	}
    for ( int i = start; i < length; i++) {
		if(enc[i]=='/')continue;
        for (int j = 0; j < 87; j++) {
            if(enc[i] == key[j]) {
                enc[i] = key[(j+10) % 87];
                break;
            }
        }
    }
}

void encription1(char* enc) {
	encription1WithLength(enc, strlen(enc));
}
```

-  ```char key[100] = "9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO"``` Untuk menyimpan character key yang dipakai. Character ini memiliki panjang 87 karakter, dan key yang di pakai adalah 10, sehingga artinya kalau di enkrip akan di geser ke kanan sebanyak 10 karakter.
- Variable enc merupakan string yang akan dienkripsi. Apabila enc ke-i sama dengan key ke-j, maka variable enc ke-i akan dibah menjaid key ke (j+17) % 87.
- ```if(enc[i]=='/')continue``` Untuk emngabaikan apabila bertemu tanda / sesuai note pada soal
- ```void encription1WithLength(char* enc, int length)``` untuk mengenkripsi nama file / direktori. Misalkan apabila mkdir rahasia/encv1_coba, maka yg di enkripsi hanya string encv1_coba saja, rahasia/ tidak akan di enkripsi. Begitu juga dengan ekstensi dari file. Untuk memenuhi persyartan diatas menggunakan 
```Javascript
if(enc[i]=='/')break;
	if(enc[i]=='.'){
		length = i;
		break;
	}
    int start = 0;
	for(int i = 0; i < length; i++){
		if(enc[i] == '/'){
			start = i+1;
			break;
		}
``` 
Sehingga enkripsi dimulai dari karakter ke start hingga ke length


Fungsi Dekripsi versi 1 :
```Javascript
void decription1WithLength(char * enc, int length){
	if(strcmp(enc, ".") == 0 || strcmp(enc, "..") == 0)return;
	if(strstr(enc, "/") == NULL)return;
	for(int i = length; i >= 0; i--){
		if(enc[i]=='/')break;
		if(enc[i]=='.'){
			length = i;
			break;
		}
	}
	int start = length;
	for(int i = 0; i < length; i++){
		if(enc[i] == '/'){
			start = i+1;
			break;
		}
	}
    for ( int i = start; i < length; i++) {
		if(enc[i]=='/')continue;
        for (int j = 0; j < 87; j++) {
            if(enc[i] == key[j]) {
                enc[i] = key[(j+77) % 87];
                break;
            }
        }
    }
}
void decription1(char* enc){
	decription1WithLength(enc, strlen(enc));
}
```
(kurang lebih sama seperti enkripsi, hanya beda di pergeseran karakter)
-  ```char key[100] = "9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO"``` Untuk menyimpan character key yang dipakai. Character ini memiliki panjang 87 karakter, dan key yang di pakai adalah 10, sehingga artinya kalau di enkrip akan di geser ke kanan sebanyak 10 karakter. Jika didekripsi akan bergeser ke kanan sebanyak banyak karakter pada key (87) dikurangi key yang dipakai (10), maka 87-10=77.
- Variable enc merupakan string yang akan didekripsi. Apabila enc ke-i sama dengan key ke-j, maka variable enc ke-i akan dibah menjaid key ke (j+77) % 87.
- ```if(enc[i]=='/')continue``` Untuk emngabaikan apabila bertemu tanda / sesuai note pada soal
- ```void decription1WithLength(char* enc, int length)``` untuk mengenkripsi nama file / direktori. Misalkan apabila mkdir rahasia/encv1_coba, maka yg di enkripsi hanya string encv1_coba saja, rahasia/ tidak akan di enkripsi. Begitu juga dengan ekstensi dari file. Untuk memenuhi persyartan diatas menggunakan 
```Javascript
if(enc[i]=='/')break;
	if(enc[i]=='.'){
		length = i;
		break;
	}
    int start = 0;
	for(int i = 0; i < length; i++){
		if(enc[i] == '/'){
			start = i+1;
			break;
		}
``` 
Sehingga dekripsi dimulai dari karakter ke start hingga ke length

### 2. Enkripsi versi 2 : 
- **a.** Jika sebuah direktori dibuat dengan awalan “encv2_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v2.
- **b.** Jika sebuah direktori di-rename dengan awalan “encv2_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v2.
- **c.** Apabila sebuah direktori terenkripsi di-rename menjadi tidak terenkripsi, maka isi direktori tersebut akan terdekrip.
- **d.** Setiap pembuatan direktori terenkripsi baru (mkdir ataupun rename) akan tercatat ke sebuah database/log berupa file.
- **e.** Pada enkripsi v2, file-file pada direktori asli akan menjadi bagian-bagian kecil sebesar 1024 bytes dan menjadi normal ketika diakses melalui filesystem rancangan jasir. Sebagai contoh, file File_Contoh.txt berukuran 5 kB pada direktori asli akan menjadi 5 file kecil yakni: File_Contoh.txt.000, File_Contoh.txt.001, File_Contoh.txt.002, File_Contoh.txt.003, dan File_Contoh.txt.004.
- **f.** Metode enkripsi pada suatu direktori juga berlaku kedalam direktori lain yang ada didalam direktori tersebut (rekursif).
Jawab : 

Enkripsi Versi 2 :
```Javascript
void encription2(char * path){
	FILE * file = fopen(path, "rb");
	int count = 0;
	char topath[1000];
	sprintf(topath, "%s.%03d", path, count);
	void * buffer = malloc(1024);
	while(1){
		size_t readSize = fread(buffer, 1, 1024, file);
		if(readSize == 0)break;
		FILE * op = fopen(topath, "w");
		fwrite(buffer, 1, readSize, op);
		fclose(op);
		count++;
		sprintf(topath, "%s.%03d", path, count);
	}
	free(buffer);
	fclose(file);
	remove(path);
}
```
- Untuk menyalin isi file yang akan di enkripsi, menggunakan FILE * file dengan command fopen dan fclose. 
- Membuka / membuat file dengan ```fopen(path, "rb");```. "rb" digunakan untuk membuka file sebagai binary file, bukan text file
- Mengformat nama file seperti persyaratan no 2 menggunakan ```sprintf(topath, "%s.%03d", path, count)``` dimana topath nantinya akan berisi file yang sama persis dengan path, namun dengan format nama yang berbeda. "%s.%03d" untuk menambahkan nama file sesuai ukuran dari file dengan karakter 0 berjumlah 3 setelah titik. Misalkan ssfs.c.000, ssfs.c.001, dst.
- Mengcopy isi file ke sub-file topath menggunakan write ```fopen(topath, "w")```
- Untuk mengcopy file ke buffer / disimpan di memory buffer menggunakan ```size_t fread```
- Setelah isi file di copy, tutup filenya, tambahkan countnya (sebagai penanda berapa topath / sub-file yang sudah dibuat), dan Mengformat nama file lagi menggunakan ```sprintf(topath, "%s.%03d", path, count)``` dengan count yang sudah bertambah.
- Tidak lupa setelah sudah terbentuk n sub-file sesuai ukuran file asli, free buffer, tutup file, dan hapus file aslinya

Dekripsi versi 2 :
```Javascript
void decription2(char * path){
	FILE * check = fopen(path, "r");
	if(check != NULL)return;
	FILE * file = fopen(path, "w");
	int count = 0;
	char topath[1000];
	sprintf(topath, "%s.%03d", path, count);
	void * buffer = malloc(1024);
	while(1){
		FILE * op = fopen(topath, "rb");
		if(op == NULL)break;
		size_t readSize = fread(buffer, 1, 1024, op);
		fwrite(buffer, 1, readSize, file);
		fclose(op);
		remove(topath);
		count++;
		sprintf(topath, "%s.%03d", path, count);
	}
	free(buffer);
	fclose(file);
}
```
- Untuk menyalin isi file yang akan di dekripsi, menggunakan FILE * file dengan command fopen dan fclose. 
- Membuka / membuat file dengan ```fopen(path, "r");```. "r" digunakan untuk membuka file sebagai text file dan menyalin isinya dengan command ```fopen(path, "w")```. "w" digunakan untuk menulis isi file asli (sub-file akan menjadi 1 file asli sesuai file sebelum di enkripsi).
- Membuka semua sub-file yang telah di enkripsi (di format) dengan ```FILE * op = fopen(topath, "rb");```. Apabila isinya kosong, berarti file tersebut tidak ada /not exist.
- Untuk mengcopy file ke buffer / disimpan di memory buffer menggunakan ```size_t fread```
- Untuk mendekripsi kembali, kita harus menghapus sub-file hasil enkripsi dengan ```remove(topath);```, menambah countnya, mengformat nama file lagi menggunakan ```sprintf(topath, "%s.%03d", path, count)``` dengan count yang sudah bertambah dan menghapusnya lagi sesuai jumlah sub-file.
- Tidak lupa setelah sudah terbentuk n sub-file sesuai ukuran file asli, free buffer dan tutup file

#### (untuk nomor 1 dan nomor 2). 
#### Selanjutnya fungsi enkripsi dan dekripsi tersebut akan dipanggil dalam xmp_readdir dan xmp_getattr dan yang lainnya sesuai permintaan soal. Pemanggilan fungsi dekripsi pada xmp_readdir akan menampilkan nama file di folder tujuan yang telah didekripsi. Sedangkan pada xmp_getattr pemanggilan fungsi enkripsi agar file dapat menemukan lokasi aslinya dengan nama sebelumnya (awal). 
#### Untuk fungsi lainnya menyesuaikan, misalkan xmp_rename untuk mengganti nama file yang akan di enkripsi / dekripsi, xmp_unlink untuk menghapus suatu file, xmp_read dan xmp_wite untuk membuka / membuat file dan mengcopy isi file dst. Contoh xmp_readdir dan xmp_getattr :

xmp_readdir :
```Javascript
static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi){

	printf("DEBUGGING %s\n", path);
	char * enc1Ptr = strstr(path, encv1);
	if(enc1Ptr != NULL)
		decription1(enc1Ptr);
	char * enc2Ptr = strstr(path, encv2);

	printf("\n\nDEBUG readdir\n\n");

	char fpath[1000];
	if(strcmp(path,"/") == 0){
		path=dirpath;
		sprintf(fpath,"%s",path);
	} else sprintf(fpath, "%s%s", dirpath, path);

	int res = 0;
	DIR *dp;
	struct dirent *de;
	(void) offset;
	(void) fi;
	dp = opendir(fpath);
	if (dp == NULL) return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		if(enc2Ptr != NULL){
			if(de->d_type == DT_REG ){
				if(strcmp(de->d_name+(strlen(de->d_name)-4), ".000") == 0){
					de->d_name[strlen(de->d_name)-4] = '\0';
					res = (filler(buf, de->d_name, &st, 0));
				}
			}else{
				res = (filler(buf, de->d_name, &st, 0));
			}
		}else{
			if(enc1Ptr != NULL)
				encription1(de->d_name);
			res = (filler(buf, de->d_name, &st, 0));
		}
		if(res!=0) break;
	}
	closedir(dp);

	return 0;
}
```
- Pada xmp_readdir, akan menampilkan hasil dekripsi1 dari ```char * enc1Ptr = strstr(path, encv1)```
- ```spintf(fpath, "%s", path)``` dan ```sprintf(fpath, "%s%s", dirpath, path);``` untuk menggabungkan path dari file yang akan di enkripsi apabila enc1Ptr tidak kosong yang enc2Ptr ini berada di dalam fpath.
- Tidak lupa untuk menutup directory apabila telah selesai menenkripsi / mendekripsi suatu file / direktori dengan ```close(dp)```


xmp_getattr
```Javascript
static  int  xmp_getattr(const char *path, struct stat *stbuf){
	char * enc1Ptr = strstr(path, encv1);
	if(lastCommand == MKNOD_STATUS || lastCommand == MKDIR_STATUS){

	}else{
		if(enc1Ptr != NULL)
			decription1(enc1Ptr);
	}
	printf("DEBUG getattr %d %s\n", lastCommand, path);
	char * enc2Ptr = strstr(path, encv2);
	int res;
	char fpath[1000];
	sprintf(fpath,"%s%s", dirpath, path);
	// printf("%s\n", fpath);
	res = lstat(fpath, stbuf);
	if (res == -1){
		if(enc2Ptr == NULL){
			return -errno;
		}else{
			sprintf(fpath,"%s%s.000", dirpath, path);
			lstat(fpath, stbuf);
			int count = 0;
			struct stat st;
			int sizeCount = 0;
			while(1){
				if(stat(fpath, &st) < 0){
					break;
				}
				count++;
				sprintf(fpath, "%s%s.%03d", dirpath, path, count);
				sizeCount += st.st_size;
			}
			stbuf->st_size = sizeCount;
		}
	}
	return 0;
}
```
- ```strstr(path, encv1);``` untuk mengambil / mereturn path yang stringnya hanya dimulai dari encv1, yaitu "encv1_", sehingga dari string encv1_ steerusnya dapat di dekripsi. 
- ```lstat(fpath, stbuf)``` untuk mereturn informasi dari suatu file, dalam hal ini berarti fpath

### 3. Sinkronisasi direktori otomatis:
Jawab : 


### 4. Log System 

- **a.** Sebuah berkas nantinya akan terbentuk bernama "fs.log" di direktori *home* pengguna (/home/[user]/fs.log) yang berguna menyimpan daftar perintah system call yang telah dijalankan.
Jawab : 
- **b.** Agar nantinya pencatatan lebih rapi dan terstruktur, log akan dibagi menjadi beberapa level yaitu INFO dan WARNING.
- **c.** Untuk log level WARNING, merupakan pencatatan log untuk syscall rmdir dan unlink.
- **d.**Sisanya, akan dicatat dengan level INFO.
- **e.**Format untuk logging yaitu: [LEVEL]::[yy][mm][dd]-[HH]:[MM]:[SS]::[CMD]::[DESC ...]
Jawab :

Untuk log level WARNING (pencatatan log untuk yscall rmdir dan unlink)
 ```
 void writeWarning(char * str){
	FILE * logFile = fopen("/home/geizka/fs.log", "a");
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime (&rawtime);
	fprintf(logFile, "WARNING::%d%d%d-%d:%d:%d::%s\n", timeinfo->tm_year+1900, timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, str);
	fclose(logFile);
}
```
- Parameter ```char * str)``` untuk menuliskan format CMD / DESC
- Untuk membuka logFile menggunakan ```fopen("/home/geizka/fs.log", "a")``` yang nantinya akan berisi perintah system call yang dijalankan. Mode "a" menandakan bahwa file fs.log hanya untuk ditulis.
- Format untuk logging berisi time (tahun, bulan, hari, jam, menit, detik) diketahui menggunakan ```t_time rawtime``` . time_t merepresentasikan calendar time. ```localtime(&rawtime)``` berguna untuk mengambil argument tipe data time_t.
- ```fprintf()``` untuk menuliskan / print format logging WARNING ke logFile. 
- Setelah selesai, maka tutup logFile.

Untuk log level INFO
```
void writeInfo(char * str){
	FILE * logFile = fopen("/home/geizka/fs.log", "a");
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime (&rawtime);
	fprintf(logFile, "INFO::%d%d%d-%d:%d:%d::%s\n", timeinfo->tm_year+1900, timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, str);
	fclose(logFile);
}
```
(kurang lebih sama seperti level WARNING)
- Parameter ```char * str)``` untuk menuliskan format CMD / DESC
- Untuk membuka logFile menggunakan ```fopen("/home/geizka/fs.log", "a")``` yang nantinya akan berisi perintah system call yang dijalankan. Mode "a" menandakan bahwa file fs.log hanya untuk ditulis.
- Format untuk logging berisi time (tahun, bulan, hari, jam, menit, detik) diketahui menggunakan ```t_time rawtime``` . time_t merepresentasikan calendar time. ```localtime(&rawtime)``` berguna untuk mengambil argument tipe data time_t.
- ```fprintf()``` untuk menuliskan / print format logging INFO ke logFile. 
- Setelah selesai, maka tutup logFile.