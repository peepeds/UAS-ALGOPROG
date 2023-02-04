#include<stdio.h>

int main(){
    long long unsigned int i,  n , tot , dummy;
    printf("Ingin Mencari nilai faktorial berapa ? \n>> ");
    scanf("%lld",&n);
    
    dummy = n;
    if(n == 0){
        n = 1 ;
    }
    tot = n;
    while(n--!=1){
        tot*= n ;
    }
    printf("Nilai faktorial dari %lld adalah: %lld\n",dummy,tot);
  
}
