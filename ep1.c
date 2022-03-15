#include <stdio.h>

int main(){
    int soma, n1, n2, n3, n4, n, modo;
    int contador,j;
    printf("  ");
    scanf("%d", &modo);
    contador=0;
    j=1;
    soma=87;
    if (modo==1){
        printf("  ");
        scanf("%d %d %d %d %d", &n1 , &n2 , &n3 , &n4 , &n);
        if(n == n1*n1 + n2*n2 + n3*n3 + n4*n4){
            printf("modo:\n n1:\n n2:\n n3:\n n4:\n n:\n");
            printf("Verdadeiro\n");
        }
            else{
            printf("modo:\n n1:\n n2:\n n3:\n n4:\n n:\n");
            printf("Falso\n");
            }
    }
    if (modo==2){
        printf("  ");
        scanf("%d",&n);
        n1=2;
        n2=3;
        n3=5;
        n4=7;
         while(soma < n){
        n1 = n2;
        n2 = n3;
        n3 = n4;


        contador = 0;
       while(contador != 2){
            n4++;
            j = 1;
            contador = 0;
            while(j <= n4){
                if(n4 % j == 0)
                    contador = contador + 1;
                j++;
            }

       }
        soma = (n1*n1) + (n2*n2) + (n3*n3) + (n4*n4);

    }

    if (soma == n){
        printf("modo:\n n:\n \n%d %d %d %d", n1,n2,n3,n4);
    }
    else {
        printf( "modo:\n n:\n \nFalso");
    }

    }
return 0;
}