#include <stdio.h>

int binary(int arr[] , int x , int kecil , int besar);
int main(){
    int arr[9] = {4 , 8 , 10 , 15 , 17 , 20 } ; 
    int x = 17, N = 6  , hasil ;

    hasil =binary(arr,x,0,N-1);
    if (hasil == -1){
        printf("hasil tidak ditemui.\n");
    } else {
        printf("hasil ditemui di index : %d\n",hasil );
    }

}
int binary(int arr[] , int x , int kecil , int besar){
    while( kecil <= besar){
        int tengah = kecil  + (besar - kecil ) / 2;

        if (arr[tengah] == x){
            return tengah ;
        } else if ( arr[tengah] > x){
            besar = tengah - 1 ;
        } else if ( arr[tengah] < x){
            kecil = tengah + 1  ; 
        }
    }
    return -1 ;
}
