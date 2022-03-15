#include <stdio.h>
#define NMAX 100

void imprime ( int m , int n , char C[200][200]){
  int i , j;
  for(i=0;i<=m;i++){
      for(j=0;j<=n;j++){
          printf("%3c",C[i][j]);
      }
  }
      
}  
      
      int main(){
          char C[200][200];
          int m , n ;
          int i, j;
          
          printf("   ");
          scanf("%d",&m);
          printf("   ");
          scanf("%d",&n);
          
           for(i=0;i<=m;i++){
                   for(j=0;j<=n;j++){
                       printf("   ");
                       scanf(" %c",&C[i][j]);
                   }
                   
           }
          
          imprime(m,n,C);
          return 0;
    
      }
  