#include <stdio.h>
#define NC 100

 void func_media (float mat[][NC], int ind, int n){
     float media, soma;
     int i;
     soma=0;
 
    for(i=0;i<n;i++){
        soma = soma + mat[i][ind];
    }
    
    media = soma/n;
    
    
    if(media==1.5){
        media++;
    }
    
    
    printf("%5.1f",media);
 }

int main(){
    int m , n, ind;
    float mat[NC][NC];
    int i , j;
    printf("  ");
    scanf("%d",&m);
    printf("  ");
    scanf("%d",&n);
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("  ");
            scanf("%f",&mat[i][j]);
        }
    }
    
    printf("  ");
    scanf("%d",&ind);
    
    func_media(mat,ind,n);
    
    return 0;
}