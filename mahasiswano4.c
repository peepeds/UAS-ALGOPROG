#include <stdio.h>

struct mahasiswa{
    char nama [255] , JK;
    int usia , waktu ; 

}mhs[11] ;

void nulis() ; void baca();int menu();
int main(){
    menu();
}

void nulis(){
    FILE *fp ;
   
    int i = 0;
    int x;
    int y;
    const long int NIM = 2602063043; //  NIM saya adalah 2602063043 
    long int dummy = NIM ; 
    char namaFile[260];

    if(dummy > 1000){
        dummy%= 1000 ;
    }
    printf("%003ld\n",dummy);
    
    sprintf(namaFile, "psikotest%003ld.dat", dummy);
    fp = fopen(namaFile,"a+");
    while(i<11){
        x = i + 1;
        y = x;
        struct  mahasiswa x ;
        if(i>0){
            printf("Tekan ENTER untuk melanjutkan program.\n");
        }
        //getchar();
        printf("Masukkan Nama : ");
        scanf("%[^\n]",mhs[i].nama);
       
        getchar();
     
        do{
            printf("Masukkan Jenis Kelamin (L/P) : ");
            scanf("%c",&mhs[i].JK);
          
            if(mhs[i].JK=='p'){
                mhs[i].JK= 'P' ;
            } else if(mhs[i].JK=='l'){
                mhs[i].JK= 'L' ;
            }
            getchar();
        }while(mhs[i].JK !='P'&& mhs[i].JK!='L');
   
        
       
        do{
            printf("Masukkan usia : ");
            scanf("%d",&mhs[i].usia);
            getchar();
        }while(!(mhs[i].usia >= 25 && mhs[i].usia <= 35));
      

        do{
            printf("Masukkan durasi pengerjaan: ");
            scanf("%d",&mhs[i].waktu);
        
            if(mhs[i].waktu < 5){
                mhs[i].waktu *= 60 ;
            }
            getchar();
        }while(!(mhs[i].waktu >= 120 && mhs[i].waktu <= 240));
       
        
        
        

        fwrite(&mhs[i],sizeof(struct mahasiswa),1,fp);
  

        printf("\n");

        puts("------------------------------------");
        printf("Nama          : %s \n",mhs[i].nama);
        printf("Jenis Kelamin : %c \n",mhs[i].JK);
        printf("Usia          : %d \n",mhs[i].usia);
        printf("Durasi        : %d \n",mhs[i].waktu);
        puts("------------------------------------");
        printf("\n");
        
       i++;
    } 
    fclose(fp);
    menu();
}

void baca(){
 
    FILE *fp ; 
    fp = fopen("psikotest043.dat","r");
    int i = 0 , x, y;
   

    while(i<11){
        x = i + 1;
        struct  mahasiswa x ;
        fread(&mhs[i],sizeof(struct mahasiswa),1,fp);
       
        
        printf("\n");
        puts("------------------------------------");
        printf("Nama          :%s \n",mhs[i].nama);
        printf("Jenis Kelamin :%c \n",mhs[i].JK);
        printf("Usia          :%d \n",mhs[i].usia);
        printf("Durasi        :%d \n",mhs[i].waktu);
        puts("------------------------------------");
        printf("\n");
        
        i++;
    }
    fclose(fp);
    menu();
}
int menu(){  

    int pilihan ; 
   
  
    printf("+----------------------------------+\n");
    printf("|               Menu               |\n");
    puts("+----------------------------------+");
    printf("|1. Write files                    |\n");
    printf("|2. Read files                     |\n");
    printf("|3. Exit                           |\n");
    printf("+----------------------------------+\n\n");
   

    printf("Masukkan menu yang ingin dipilih: ");

    scanf("%d",&pilihan);
    printf("\n");

    if(pilihan==1){
      
        nulis();
    } else if(pilihan==2){
       
        baca();
    } else if(pilihan == 3) {
      
       return 0 ;
    }else if ( pilihan != 1 && pilihan != 2 && pilihan != 3) {
        printf("Perintah tidak valid\n"); menu();
    }
    return -1 ;
}