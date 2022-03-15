#include <stdio.h>

int ordenar_eficiente(int v1[], int v2[], int vo[], int n){
    int temp, i , j;
    
     temp = vo[0];
    for ( i = 0; i < (2*n); i++ )
        for ( j = i; j < (2*n); j++ )
            if ( vo[j] < vo[i]  )
            {
                temp = vo[j];
                vo[j] = vo[i];
                vo[i] = temp;
            }

   
    for(i=0;i<(2*n);i++){
        printf("%3d",vo[i]);
    }
        
return i;
}

int main(){
    int n, i, j;
    int v1[100],v2[100], vo[100];
    j=0;
    
    printf("  ");
    scanf("%d",&n);
    
    
    for(i=0;i<n;i++){
    printf("  ");
    scanf("%d",&v1[i]);
}

    for(i=0;i<n;i++){
    printf("  ");
    scanf("%d",&v2[i]);
}
   for(i=0;i<n;i++){
       vo[i]=v1[i];
   }
   
   for(i=n;i<(2*n);i++){
       vo[i]=v2[j];
       j++;
   }


ordenar_eficiente(v1,v2,vo,n);

return 0;
}