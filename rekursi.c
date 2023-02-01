#include <stdio.h>

int rekursi(int a){
    if (a==0) 
        return 1;
    if (a==1)
        return 1 ;
    return a * rekursi(a-1);
}
int main(){
    int x ; 
    printf("Ingin Mencari nilai faktorial berapa ? \n>> ");
    scanf("%d",&x);
    printf("Nilai faktorial dari %d adalah: %d\n",x,rekursi(x));
}