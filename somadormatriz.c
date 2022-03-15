#include <stdio.h>

void soma(int m , int n, float v[100][100]){
    int i , j;
    float soma;
    soma=0;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%5.1f",v[i][j]);
            soma = soma + v[i][j];
            if(j==n-1){
                printf("=");
                printf("%5.1f",soma);
            }
        }
        soma=0;
    }
}

int main(){
    float v[100][100];
    int m , n;
    int i, j;
    printf("  ");
    scanf("%d",&m);
    printf("  ");
    scanf("%d",&n);
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("  ");
            scanf("%f",&v[i][j]);
        }
    }
    
    soma(m,n,v);
    
    return 0;
}