#include <stdio.h>

int main (){
    int n ,j;
    float soma,cont;
    cont=j=1;
    soma=0;
    printf("  ");
    scanf("%d",&n);
    
    while(j<=n){
        soma = soma + (1/cont);
        cont++;
        j++;
    }
    printf("%f\n",soma);
    
    return 0;
}