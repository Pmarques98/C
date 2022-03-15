#include <stdio.h>

int somadorpar (int n, int soma){
    
    while(soma!=n*(n+1)){
    soma = soma + 2;
    }
    
    if(soma!=n*(n+1)){
    somadorpar(n,soma);
}
    return soma;
    
}

int main(){
    int n, soma, somador;
    soma=0;
    somador=0;
    
    printf("  ");
    scanf("%d",&n);
    
    if(n==0){
        printf("%d : %d = %d",n,somador,somador);
    }
    
    if(n!=0){
        printf("%d : %d = %d",n,somadorpar(n,soma),somadorpar(n,soma));
    }
    
    return 0;
}