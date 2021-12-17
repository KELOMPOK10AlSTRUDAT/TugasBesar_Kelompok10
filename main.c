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
[16.34, 17/12/2021] Okto Situmorang: int lihatRute() {
	rute *r;
	rute r1;
    FILE *fp;
    int n,i,j, counter=1;
    

	
	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("rute.txt","r");
	system("cls");
	printf("#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t%d\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}


int lihatJadwal() {
	jadwal *j;
	jadwal j1;
    FILE *fp;
    int n,i;
    

	
	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("jadwal.txt","r");
	system("cls");
	printf("#LIHAT DATA JADWAL#");
	printf("\nData Lengkap Jadwal Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("Kode Jadwal\tTanggal\tWaktu Keberangkatan\t\tKeberangkatan\tTujuan\t\tKAI\t\tStatus\n");
	while(fread(&j1,sizeof(jadwal),1,fp)) { 
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tKAI %s\t\tSisa %d Kursi\n",j1.kode,j1.tanggal, j1.waktuKbrt, j1.kbrt, j1.tjn, j1.kai, j1.sisa);
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}
[16.34, 17/12/2021] Okto Situmorang: int hapusKota() {
	int i, j, found=0;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("kota.txt","r");
	system("cls");
	lihatKota();
    
    printf("\nDelete Kota : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("kota.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&k1,sizeof(kota),1,fp1)){
            fwrite(&k1,sizeof(kota),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
    
    kelolaKota();
} 


int hapusRute() {
	int i, j, found=0;
    rute r1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("rute.txt","r");
	system("cls");
	lihatRute();
    
    printf("\nDelete Rute : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("rute.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&r1,sizeof(rute),1,fp)){
        if(strcmp(r1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&r1,sizeof(rute),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("rute.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&r1,sizeof(rute),1,fp1)){
            fwrite(&r1,sizeof(rute),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
    
    kelolaRute();
}


int hapusJadwal() {
	int i, found=0;
    jadwal j1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("jadwal.txt","r");
    
	system("cls");
	lihatJadwal();
    
    printf("\nDelete Jadwal : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("jadwal.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&j1,sizeof(jadwal),1,fp)){
        if(strcmp(j1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&j1,sizeof(jadwal),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("jadwal.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&j1,sizeof(jadwal),1,fp1)){
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
        
    kelolaJadwal();
}

int kelolaKota() {
	int i, j, counter=1;
    kota k1;
    kota *k;
    FILE *fp;
	
	fp = fopen("kota.txt","r");

	system("cls");
	printf("::::::::::::::::::");
	printf("#LIHAT DATA KOTA#");
	printf("::::::::::::::::::");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Kota");
	printf("\n2. Lihat Data Kota");
	printf("\n3. Edit Data Kota");
	printf("\n4. Delete Data Kota");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahKota();
			break;
		case 2:
			system("cls");
			lihatKota();
			kelolaKota();
			break;
		case 3:
			system("cls");
			editKota();
			break;
		case 4:
			system("cls");
			hapusKota();
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}


int kelolaRute() {
	int i, j, counter=1;
    rute r1;
    rute *r;
    FILE *fp;
	
	fp = fopen("rute.txt","r");

	system("cls");
	printf("::::::::::::::::::");
	printf("#LIHAT DATA RUTE#");
	printf("::::::::::::::::::");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
    
    printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
[16.35, 17/12/2021] Okto Situmorang: printf("\n\n-------------------------------------------------------------------");
	printf(":::::::::::::::::::::::");
	printf("\n\n1. Tambah Data Rute");
	printf(":::::::::::::::::::::::");
	printf("\n2. Lihat Data Rute");
	printf("\n3. Edit Data Rute");
	printf("\n4. Delete Data Rute");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahRute();
			break;
		case 2:
			system("cls");
			lihatRute();
			kelolaRute();
			break;
		case 3:
			system("cls");
			editRute();
			break;
		case 4:
			hapusRute();
			system("cls");
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}

int kelolaJadwal() {
	int i, counter=1;
    jadwal j1;
    jadwal *j;
    FILE *fp;
	
	fp = fopen("jadwal.txt","r");

	system("cls");
	lihatJadwal();
	
	printf("\n\n1. Tambah Data Jadwal");
	printf("\n2. Lihat Data Jadwal");
	printf("\n3. Edit Data Jadwal");
	printf("\n4. Delete Data Jadwal");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahJadwal();
			break;
		case 2:
			system("cls");
			lihatJadwal();
			kelolaJadwal();
			break;
		case 3:
			system("cls");
			editJadwal();
			break;
		case 4:
			hapusJadwal();
			system("cls");
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}


int kelolaPengguna() {
    int i, j, found=0;
    pengguna s1;
    FILE *fp, *fp1;
    char ktp[100];
    printf(":::::::::::::::::::::::");
    printf("#KELOLA AKUN BY ADMIN#");
    printf(":::::::::::::::::::::::");
    fflush(stdin);
    printf("Masukkan Nomor KTP : ");
    scanf("%[^\n]s",ktp);

    fp = fopen("pengguna.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.ktp,ktp)==0){
            found = 1;
            printf("::::::::::::::");
            printf("Data Pengguna");
            printf("::::::::::::::");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
   			printf(":::::::::::::::::::::::");
   			printf("\n\nUbah Data Pengguna");
   			printf(":::::::::::::::::::::::");
            fflush(stdin);
        	printf("\nNomor KTP : ");
	        fflush(stdin);
	        scanf("%[^\n]s",s1.ktp);
	        fflush(stdin);
	        printf("Nama Lengkap : ");
	        scanf("%[^\n]s",s1.nama);
	        fflush(stdin);
	        printf("Nomor Handphone : ");
	        scanf("%[^\n]s",s1.hp);
	        fflush(stdin);
	        printf("Email : ");
	        scanf("%[^\n]s",s1.email);
	        fflush(stdin);
	        printf("Password : ");
	        scanf("%[^\n]s",s1.password);
	        fflush(stdin);
	        printf("Re-Password : ");
	        scanf("%[^\n]s",s1.repassword);
        } else {
        	printf("\nTidak Ada Nomor KTP dalam sistem, silahkan coba lagi\n");
        	kelolaPengguna();
		}
        fwrite(&s1,sizeof(pengguna),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("pengguna.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&s1,sizeof(pengguna),1,fp1)){
            fwrite(&s1,sizeof(pengguna),1,fp);
            printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);

			}  
        }
        fclose(fp);
        fclose(fp1);
    }


int kelolaProfile() {
	int i, j, found=0;
    pengguna s1;
    FILE *fp, *fp1;
    char ktp[100];
    printf("::::::::::::::::::::::::::");
    printf("#KELOLA AKUN BY PENUMPANG#");
    printf("::::::::::::::::::::::::::");
    fflush(stdin);
    printf("\n\nMasukkan Nomor KTP : ");
    scanf("%[^\n]s",ktp);

    fp = fopen("pengguna.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.ktp,ktp)==0){
        	
            found = 1;
            printf("--Data Pengguna--");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
   			
   			printf("\n\n--Ubah Data Pengguna--");
            fflush(stdin);
        	printf("\nNomor KTP : ");
	        fflush(stdin);
	        scanf("%[^\n]s",s1.ktp);
	        fflush(stdin);
	        printf("Nama Lengkap : ");
	        scanf("%[^\n]s",s1.nama);
	        fflush(stdin);
	        printf("Nomor Handphone : ");
	        scanf("%[^\n]s",s1.hp);
	        fflush(stdin);
	        printf("Email : ");
	        scanf("%[^\n]s",s1.email);
	        fflush(stdin);
	        printf("Password : ");
	        scanf("%[^\n]s",s1.password);
	        fflush(stdin);
	        printf("Re-Password : ");
	        scanf("%[^\n]s",s1.repassword);
        } else {
        	printf("\nTidak Ada Nomor KTP dalam sistem, silahkan coba lagi\n");
        	kelolaPengguna();
		}
        fwrite(&s1,sizeof(pengguna),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    int hapusKota() {
	int i, j, found=0;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("kota.txt","r");
	system("cls");
	lihatKota();
    
    printf("\nDelete Kota : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("kota.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&k1,sizeof(kota),1,fp1)){
            fwrite(&k1,sizeof(kota),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
    
    kelolaKota();
} 


int hapusRute() {
	int i, j, found=0;
    rute r1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("rute.txt","r");
	system("cls");
	lihatRute();
    
    printf("\nDelete Rute : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("rute.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&r1,sizeof(rute),1,fp)){
        if(strcmp(r1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&r1,sizeof(rute),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("rute.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&r1,sizeof(rute),1,fp1)){
            fwrite(&r1,sizeof(rute),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
    
    kelolaRute();
}


int hapusJadwal() {
	int i, found=0;
    jadwal j1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("jadwal.txt","r");
    
	system("cls");
	lihatJadwal();
    
    printf("\nDelete Jadwal : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("jadwal.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&j1,sizeof(jadwal),1,fp)){
        if(strcmp(j1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&j1,sizeof(jadwal),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("jadwal.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&j1,sizeof(jadwal),1,fp1)){
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
        
    kelolaJadwal();
}

int kelolaKota() {
	int i, j, counter=1;
    kota k1;
    kota *k;
    FILE *fp;
	
	fp = fopen("kota.txt","r");

	system("cls");
	printf("::::::::::::::::::");
	printf("#LIHAT DATA KOTA#");
	printf("::::::::::::::::::");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Kota");
	printf("\n2. Lihat Data Kota");
	printf("\n3. Edit Data Kota");
	printf("\n4. Delete Data Kota");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahKota();
			break;
		case 2:
			system("cls");
			lihatKota();
			kelolaKota();
			break;
		case 3:
			system("cls");
			editKota();
			break;
		case 4:
			system("cls");
			hapusKota();
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}


int kelolaRute() {
	int i, j, counter=1;
    rute r1;
    rute *r;
    FILE *fp;
	
	fp = fopen("rute.txt","r");

	system("cls");
	printf("::::::::::::::::::");
	printf("#LIHAT DATA RUTE#");
	printf("::::::::::::::::::");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
    
    printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
