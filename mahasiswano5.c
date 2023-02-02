// include library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// define pewarnaan
#define F "\x1b[1;91m" // False / warna merah 
#define G "\x1b[1;32m" // Green / warna hijau 
#define W "\x1b[1;37m" // white / putih
#define B "\x1b[1;33m" // Yellow
#define Y "\x1b[1;34m" // Blue
#define R "\x1b[0m" // Reset
#define S "\x1b[2m" // Faint 

// targeting OS , hal ini disebabkan karena OS saya adalah MAC OS 
// untuk mencegah error karena perbedaan OS maka saya melakukan targeting OS 
#ifdef _WIN32
    #define CLS system("cls")
#else
    #define CLS system("clear")
#endif

// untuk menangkap data pada file 
struct mahasiswa{
    char nama [255] , JK;
    int usia , waktu ; 
}mhs[12] ;


void menu(); void search(); void baca();
int sortnama(); int sortusia();int berhenti(); int set(int x);


void baca(){
    FILE *fp ; 
    fp = fopen("psikotest043.dat","r");
    int i = 0-1 , x, y;
   
    while(i++<12-1){
        x = i + 1;
        struct  mahasiswa x ;
        fread(&mhs[i],sizeof(struct mahasiswa),1,fp);
        // hapus komen multi line dibawah ini untuk mengetahui keseluruhan data yang disimpan.
        /*
        printf("\n");
        puts("------------------------------------");
        printf("Nama          :%s \n",mhs[i].nama);
        printf("Jenis Kelamin :%c \n",mhs[i].JK);
        printf("Usia          :%d \n",mhs[i].usia);
        printf("Durasi        :%d \n",mhs[i].waktu);
        puts("------------------------------------");
        printf("\n");
        sleep(1);
        if(i==9){
            set(3);
        }
        */
        
    }
    fclose(fp);
    menu();
}
int set(int x){ // buat sleep & clear screen 
    sleep(x);
    CLS ; 
    return -1 ;
}
int main(){
    #ifdef _WIN32
        printf(Y"Program akan dijalankan sebagai OS WINDOWS\n");
        set(1);
    #else
        printf(Y"Program akan dijalankan dengan sistem UNIX\n");
        set(1);
        CLS;
    #endif

    baca();
    

}



void menu(){  
    int pilihan ; 
   
    set(0);
    printf(W"+----------------------------------+\n");
    printf("|               Menu               |\n");
    puts("+----------------------------------+");
    printf("|1. Search Nama                    |\n");
    printf("|2. Sorting by Name                |\n"); 
    printf("|3. Sorting by Age                 |\n");
    printf("|4. Exit                           |\n");
    printf(W"+----------------------------------+\n\n");
   
    printf(S"Masukkan menu yang ingin dipilih: "R);

    scanf("%d",&pilihan);
    printf("\n");
    set(0);
    if(pilihan==1){
      
        search();
    } else if(pilihan==2){
       
        sortnama();
    } else if(pilihan == 3) {
      
       sortusia();
    }else if(pilihan==4){
        
        berhenti();
    }else if ( pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan !=4) {
        printf(F"Perintah tidak valid!\nSilahkan masukan ulang\n"R); sleep(2); CLS ;menu();
    }
}
void search(){

    int i=0 -1 , nilai=0; 
    int  x , len , j , spasi=0 ;
    char dicari[255];
    
    getchar();
    printf("Masukkan nama yang ingin dicari: ");
    scanf("%[^\n]",dicari); getchar();
    len = strlen(dicari); 
    
    for(j=1 ; j < len ; j++){
        if(dicari[j]>= 65 && dicari[j]<= 90){
            dicari[j] += 32 ;
        } else if(dicari[j]==32){
          
            spasi = j ;
            if(dicari[j+1]>= 65 && dicari[j+1]<= 90){
                dicari[j+1] += 32 ;
             
            } else if (dicari[j+1] >=97 && dicari[j+1]<= 122){
                dicari[j+1] -= 32 ;
               
            }
            j++;
        }
    }
    if(dicari[0] >=97 && dicari[0]<= 122){
        dicari[0] -= 32 ;
    }else if(spasi !=0){
        if(dicari[spasi+1]>=97 && dicari[spasi+1]<=122){
            dicari[spasi+1] -= 32 ;
        }
    }
    

    printf("%s\n",dicari);
    while(i++<12-1){
        x = i + 1;
        
        struct  mahasiswa x ;
        if(strcmp(dicari,mhs[i].nama)==0){
            nilai = 1;
            printf(W"------------------------------------\n");
            printf(G"Nama          :%s \n",mhs[i].nama);
            printf(G"Jenis Kelamin :%c \n",mhs[i].JK);
            printf(G"Usia          :%d \n",mhs[i].usia);
            printf(G"Durasi        :%d \n",mhs[i].waktu);
            printf(W"------------------------------------\n");
            sleep(1);
         
            break ;
        }
       
    }


    if(nilai==0){
        printf(F"Nama tidak ada.\n");
        sleep(1);
    
    }
    set(0);
    menu();
    
   
}
int berhenti(){
    set(0);
    printf(B"Program akan diberhentikan setelah pesan ini.\n");
    set(1);
    return 0 ;
}

int sortnama(){
    int i , j  ;

    struct mahasiswa tmp ; 

    char stmp [255] ;
    
    for(i=0 ; i < 12-1; i++){
        for(j= i+1 ;j< 12 ; j++){
            if(strcmp(mhs[i].nama,mhs[j].nama)>0){
                tmp = mhs[i] ; 
                mhs[i] = mhs[j];
                mhs[j] = tmp ;
            } else if(strcmp(mhs[i].nama,mhs[j].nama)==0){
                if(mhs[i].usia>mhs[j].usia){
                    tmp = mhs[i] ; 
                    mhs[i] = mhs[j];
                    mhs[j] = tmp ;
                }
            }
        }
    }
   
    i = 0 ;
    int pilihan ; 
    printf(G"Berhasil di sorting\n"R);
    set(1);
    i=0-1;
    while(i++<12-1){

        printf(Y"\n");
        puts("------------------------------------");
        printf("Nama          :%s \n",mhs[i].nama);
        //printf("Jenis Kelamin :%c \n",mhs[i].JK);
        printf("Usia          :%d \n",mhs[i].usia);
        //printf("Durasi        :%d \n",mhs[i].waktu);
        puts("------------------------------------");
        printf(R"\n");
        
    }
    set(4);
    menu();
    return 0;
}

int sortusia(){
    int i , j  ;

    struct mahasiswa tmp ; 

    char stmp [255] ;
    
    for(i=0 ; i < 12-1; i++){
        for(j= i+1 ;j< 12 ; j++){
            if(mhs[i].usia>mhs[j].usia){
                tmp = mhs[i] ; 
                mhs[i] = mhs[j];
                mhs[j] = tmp ;
            } else if(mhs[i].usia == mhs[j].usia){
                if(strcmp(mhs[i].nama,mhs[j].nama)>0){
                    tmp = mhs[i] ; 
                    mhs[i] = mhs[j];
                    mhs[j] = tmp ;
                }
            }
        }
    }
   
    i = 0-1 ;

    int pilihan ; 
    printf(G"Berhasil di sorting\n"R);
    set(1);
    
    while(i++<12-1){

        printf(S"\n");
        puts("------------------------------------");
        printf("Nama          :%s \n",mhs[i].nama);
        //printf("Jenis Kelamin :%c \n",mhs[i].JK);
        printf("Usia          :%d \n",mhs[i].usia);
        //printf("Durasi        :%d \n",mhs[i].waktu);
        puts("------------------------------------");
        printf(R"\n");

    }
    set(4);
    menu();
    return 0 ;
}
