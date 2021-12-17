#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct pengguna{
    char ktp[16];
    char nama[100];
    char hp[16];
    char email[100];
    char password[100];
    char repassword[100];
} pengguna;

typedef struct kota {
	char kode[100];
	char nama[100];
} kota;

typedef struct rute {
	char kbrt[100];
	char tjn[100];
	char kode[100];
	int bisnis;
	int premium;
}rute;

typedef struct jadwal {
	char kode[100];
	char tanggal[100];
	char waktuKbrt[100];
	char kbrt[100];
	char tjn[100];
	char kai[100];
	int sisa;
}jadwal;


int editKota() {
	int i=0;
	int j, found=0, counter=1;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    
    fp = fopen("kota.txt","r");
	printf(":::::::::::::::::");
    printf("#EDIT DATA KOTA#");
    printf(":::::::::::::::::");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	fclose(fp);

    fflush(stdin);
    printf("\n\nEdit Kota : \nEDIT_");
    scanf("%[^\n]s",kode);
    
    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
       		found = 1;
        	fflush(stdin);
            printf("\nKode Kota : ");
		    scanf("%[^\n]s",k1.kode);
		    fflush(stdin);
		    printf("Nama Kota : ");
		     printf("Nama Kota : ");
		    scanf("%[^\n]s",k1.nama);
        } 
        fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    
    if (found==1) {
    	fp = fopen("kota.txt","w");
    	fp1 = fopen("temp.txt","r");
    	while(fread(&k1,sizeof(kota),1,fp1)) {
            fwrite(&k1,sizeof(kota),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	} else {
		printf("\n\nnot found");
	}
	
	kelolaRute();
}

int editRute() {
	rute *r;
	int i=0;
	int j, found=0, counter=1;
    rute r1;
    kota k1;
    FILE *fp, *fp1, *fp2;
    
    char kode[100], kode1[100], kode2[100], kode3[100];
    
	system("cls");
    lihatRute();


    fflush(stdin);
    
	fp = fopen("kota.txt","r");
    fp1 = fopen("rute.txt","r");
    fp2 = fopen("temp.txt","w");
    
    
    printf("\n\nEdit Rute : \nEDIT_");
    scanf("%[^\n]s",kode);
    
	while(fread(&r1,sizeof(rute),1,fp1)){
    	if(strcmp(r1.kode,kode)==0){
				found = 1;
		    	fflush(stdin);
	            printf("\nKeberangkatan : ");
			    scanf("%[^\n]s",r1.kbrt);
			    fflush(stdin);
			    printf("Tujuan : ");
			    scanf("%[^\n]s",r1.tjn);
			    fflush(stdin);
			    printf("Bisnis : ");
			    scanf("%d",&r1.bisnis);
			    fflush(stdin);
			    printf("Premium : ");
			    scanf("%d",&r1.premium);
				fflush(stdin);	    	

			while(fread(&k1,sizeof(kota),1,fp)) {
	            if((strcmp(r1.kbrt,k1.nama)==0) && (strcmp(r1.tjn,k1.nama)==0)) {
	            	if(strcmp(r1.kbrt,k1.nama)==0) {
						strcpy(kode1,k1.kode);	
						strcpy(kode3,strcat(kode1,"-"));
					} else if (strcmp(r1.tjn,k1.nama)==0){
						strcpy(kode2,k1.kode);
					}	
					strcpy(r1.kode,(strcat(kode3,kode2)));
				} 
				
	        }
	    	
        } 
        
    	fwrite(&r1,sizeof(rute),1,fp2);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    if (found==1) {
	    
    	fp = fopen("rute.txt","w");
    	fp1 = fopen("temp.txt","r");
    	
		while(fread(&r1,sizeof(rute),1,fp1)) {
            fwrite(&r1,sizeof(rute),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	    
	} else {
		printf("\n\nnot found");
	}
	
	kelolaRute();
}


int editJadwal() {
	jadwal *j;
	int i=0;
	int found=0, counter=1;
    jadwal j1;
    rute r1;
    FILE *fp, *fp1, *fp2;
    
    char kode[100], kode1[100], kode2[100], kode3[100];
    
	system("cls");
    lihatJadwal();


    fflush(stdin);
    
	fp = fopen("rute.txt","r");
    fp1 = fopen("jadwal.txt","r");
    fp2 = fopen("temp.txt","w");
    
    
    printf("\n\nEdit Jadwal : \nEDIT_");
    scanf("%[^\n]s",kode);
    
	while(fread(&j1,sizeof(jadwal),1,fp1)){
    	if(strcmp(j1.kode,kode)==0){
				found = 1;
		    	printf("\n\nKode Jadwal : ");
	    	fflush(stdin);
	        scanf("%s",j1.kode);
	        printf("\nTanggal : ");
	    	fflush(stdin);
	        scanf("%s",j1.tanggal);
	        printf("\nWaktu Keberangkatan : ");
	    	fflush(stdin);
	        scanf("%s",j1.waktuKbrt);
	        printf("\nKeberangkatan : ");
	    	fflush(stdin);
	        scanf("%s",j1.kbrt);
	        printf("\nTujuan : ");
	    	fflush(stdin);
	        scanf("%s",j1.tjn);
	        printf("\nKAI : ");
	    	fflush(stdin);
	        scanf("%s",j1.kai);
	        printf("\nJumlah sisa kursi : ");
	    	fflush(stdin);
	        scanf("%d",&j1.sisa);   	

			while(fread(&r1,sizeof(rute),1,fp1)) {
	            if(strcmp(j1.kbrt,r1.kbrt)!=0) {
	            	printf("\n\nKeberangkatan %s tidak ada pada daftar !",j1.kbrt);
				} 
				
				if (strcmp(j1.tjn,r1.tjn)!=0) {
					printf("\n\nTujuan %s tidak ada pada daftar !",j1.tjn);
				}
			
	        }
	        
	        
	    	
        } 
        
    	fwrite(&j1,sizeof(jadwal),1,fp2);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    if (found==1) {
	    
    	fp = fopen("jadwal.txt","w");
    	fp1 = fopen("temp.txt","r");
    	
		while(fread(&j1,sizeof(jadwal),1,fp1)) {
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	    
	} else {
		printf("\n\nnot found");
	}
	
	kelolaJadwal();
}
int tambahKota() {
	kota *k;
    FILE *fp;
    int n,i,j;

    k = (kota*)malloc(100*sizeof(kota));
    fp = fopen("kota.txt","a+");
    
	printf("#TAMBAH DATA KOTA#\n\n");
    for(i=0;i<1;i++){
    	printf("Tambah Kota : ");
    	fflush(stdin);
        scanf("%s %s",k[i].kode,k[i].nama);
        
        fwrite(k+i,sizeof(kota),1,fp);
    }
    
    fclose(fp);
    
    kelolaKota();
}


int tambahRute() {
	rute *r;
	kota k1;
    FILE *fp,*fp1;
    int n,i,j;

    r = (rute*)malloc(100*sizeof(rute));
    fp = fopen("rute.txt","a+");
    fp1 = fopen("kota.txt","r");
    
	printf("#TAMBAH DATA RUTE#\n\n");
	char kode1[100], kode2[100], kode3[100];
    for(i=0;i<1;i++){
    	printf("Tambah Data Rute : ");
    	fflush(stdin);
        scanf("%s %s %d %d",r[i].kbrt,r[i].tjn,&r[i].bisnis,&r[i].premium);
        while(fread(&k1,sizeof(kota),1,fp1)) {
            if(strcmp(r[i].kbrt,k1.nama)==0) {
            	strcpy(kode1,k1.kode);
			} 
			
			if (strcmp(r[i].tjn,k1.nama)==0) {
				strcpy(kode2,k1.kode);
			}
			
			strcpy(kode3,strcat(kode1,"-"));
			strcpy(r[i].kode,(strcat(kode3,kode2)));
        }
        
        fwrite(r+i,sizeof(rute),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelolaRute();
}


int tambahJadwal() {
	jadwal *j;
	jadwal j1;
	rute r1;
    FILE *fp,*fp1;
    int n,i;

    j = (jadwal*)malloc(100*sizeof(jadwal));
    fp = fopen("jadwal.txt","a+");
    fp1 = fopen("rute.txt","r");
    
	printf("#TAMBAH DATA JADWAL#\n\n");
	
    for(i=0;i<1;i++){
    	printf("Tambah Data Jadwal : ");
    	printf("\n\nKode Jadwal : ");
    	fflush(stdin);
        scanf("%s",j[i].kode);
        printf("\nTanggal : ");
    	fflush(stdin);
        scanf("%s",j[i].tanggal);
        printf("\nWaktu Keberangkatan : ");
    	fflush(stdin);
        scanf("%s",j[i].waktuKbrt);
        printf("\nKeberangkatan : ");
    	fflush(stdin);
        scanf("%s",j[i].kbrt);
        printf("\nTujuan : ");
    	fflush(stdin);
        scanf("%s",j[i].tjn);
        printf("\nKAI : ");
    	fflush(stdin);
        scanf("%s",j[i].kai);
        printf("\nJumlah sisa kursi : ");
    	fflush(stdin);
        scanf("%d",&j[i].sisa);
        
        
        
        while(fread(&r1,sizeof(rute),1,fp1)) {
            if(strcmp(j[i].kbrt,r1.kbrt)!=0) {
            	printf("\n\nKeberangkatan %s tidak ada pada daftar !",j[i].kbrt);
			} 
			
			if (strcmp(j[i].tjn,r1.tjn)!=0) {
				printf("\n\nTujuan %s tidak ada pada daftar !",j[i].tjn);
			}
		
        }
        
        fwrite(j+i,sizeof(jadwal),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelolaJadwal();
}

int lihatKota() {
	kota *k;
	kota k1;
    FILE *fp;
    int n,i,j, counter=1;
    
    fp = fopen("kota.txt","r");
	system("cls");
	printf("#LIHAT DATA KOTA#");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
    
}