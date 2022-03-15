/*
  AO PREENCHER ESSE CABECALHO COM O MEU NOME E O MEU NUMERO USP, DECLARO
  QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESSE PROGRAMA.
  TODAS AS PARTES ORIGINAIS DESSE EXERCICIO PROGRAMA (EP) FORAM
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUCOES
  DESSE EP E QUE PORTANTO NAO CONSTITUEM DESONESTIDADE ACADEMICA OU PLAGIO.
  DECLARO TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESSE PROGRAMA E
  QUE EU NAO DISTRIBUI OU FACILITEI A SUA DISTRIBUICAO.
  ESTOU CIENTE QUE OS CASOS DE PLAGIO E DESONESTIDADE ACADEMICA SERAO
  TRATADOS SEGUNDO OS CRITERIOS DIVULGADOS NA PAGINA DA DISCIPLINA.
  ENTENDO QUE EPS SEM ASSINATURA NAO SERAO CORRIGIDOS E,
  AINDA ASSIM, PODERAO SER PUNIDOS POR DESONESTIDADE ACADEMICA.

  Nome :Patrick Marques de Barros Costa
  NUSP :11257550
  Turma:13
  Prof.:Leonidas

  Referencias: Com excecao das rotinas fornecidas no enunciado
  e em sala de aula, caso voce tenha utilizado alguma refencia,
  liste-as abaixo para que o seu programa nao seja considerado
  plagio ou irregular.

  Exemplo:
  - O algoritmo Quicksort foi baseado em
  http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
#define MAX 50


void listaCoeficientes (float p[], int np) {
  int i;
  printf("[ ");
  for (i=0; i<np; i++)
    printf("%f, ", p[i]);
  printf(" ]\n");
  }
  
  char sig (int nTermAnte, float coef) {
  if (nTermAnte > 0 && coef >= 0)
    return '+';
  else
    return 0; 
  }
  
  void inverterString (char *str, int tam) {
  int i = 0, j = tam - 1, temp;
  if (str[0]=='-') 
    i = 1;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
    }
  }

int intToStr (int x, char str[], int d) {
  int i = 0;
  if (x<0) { str[i++] = '-'; x = -x; }
  if (x==0) str[i++] = '0';
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
    }
  
  while (i < d)
    str[i++] = '0';
  str[i] = '\0';
  inverterString(str, i);
  return i;
  }

void ftoa (float floatn, char *res, int precisao) {
  int ipart = (int)floatn; 
  float fpart = floatn - (float)ipart; 
  int i, negativo = 0, tam;
  i = intToStr(ipart, res, 0); 
  if (precisao != 0) { 
    res[i] = '.';
   
    fpart = fpart * pow(10, precisao);
    if (fpart<0) { 
      fpart = -fpart; 
      negativo = 1;
      }
    intToStr((int)fpart, res + i + 1, precisao);
    }
  if (negativo == 1 && res[0]!='-') { 
    tam = strlen(res);
    for (i=tam; i>0; i--) res[i] = res[i-1];
    res[0] = '-';
    res[tam] = '\0';
    }
  } 

char *polinomioToStringF (float p[], int np) {
  char *expressao = malloc(sizeof(char)*100), str[] = "                         ", sinal;
  int m, tam = 0; 
  float val;
  np -= 1; 
  expressao[0] = '\0';
  tam = 0;
  for (m=0; m<np-1; m++) { 
    if (np-m<0 || np-m>np) { printf("polinomioToStringF: Erro: np-m=%d (m=%d)\n", np-m,m); return expressao; } else
    val = p[np-m];
    sinal = sig(m,val);
    if (sinal!=0) { expressao[tam++] = sinal; expressao[tam] = '\0'; }
    ftoa(val, str, 4);
    tam += strlen(str);
    strcat(expressao, str); 
    expressao[tam++] = 'x';
    expressao[tam++] = '^';
    expressao[tam] = '\0';
    intToStr(np-m, str, 0);
    strcat(expressao, str);
    tam += strlen(str);
    }
  if (np>0 && p[1] != 0) {
    sinal = sig(np-1,p[1]);
    if (sinal!=0) { tam = strlen(expressao); expressao[tam++] = sinal; expressao[tam] = '\0'; }
    ftoa(p[1], str, 4);
    tam += strlen(str);
    strcat(expressao, str);
    expressao[tam++] = 'x';
    expressao[tam] = '\0';
    }
  if (p[0] != 0) {
    sinal = sig(np,p[0]);
    if (sinal!=0) { expressao[tam++] = sinal; expressao[tam] = '\0'; }
    ftoa(p[0], str, 4);
    tam += strlen(str);
    strcat(expressao, str);
    }
  return expressao;
  }

void racionalReduzido (float r, int *num, int *den) {
    int cont;
    int nu, de;
    cont=2;
    nu = *num;
    de = *den;
    while(cont<=nu && cont<=de){
        if(nu%cont==0 && de%cont==0){
            nu=nu/cont;
            de=de/cont;
            cont--;
        }
        cont++;
    }
    
    
    if(r<0){
        nu = -nu;
    }
    if(de>1){
    printf("%d/%d",nu,de);
    }
    else
    printf("%d",nu);
}

void encontraInteiro (float parteFlut, int *pot, int *flutInt) {
  int potA = 1;
  if (parteFlut<0) parteFlut = -parteFlut;
  while (parteFlut-(int)parteFlut > 0) {
    potA *= 10;
    parteFlut *= 10;
    }
  *flutInt = (int)parteFlut;
  *pot = potA;
  }


int polinomioComRaiz (float p[], float x, int np){
    int i, j, y;
    float soma, resultado;
    resultado=1;
    y=0;
    soma=0;

    
    while(y<=np){
    for(j=1;j<=y;j++){
        resultado = resultado * x;
    }
    soma = soma + p[y]*resultado;
    resultado=1;
    y++;
    }
    
    if(soma==0){
        return 1;
    }
    else
    return 0;
    
}


 

float avaliaPolinomio (float p[MAX], float x, int np){
    int i, j, y;
    float soma, resultado;
    resultado=1;
    y=0;
    soma=0;

    
    while(y<=np){
    for(j=1;j<=y;j++){
        resultado = resultado * x;
    }
    soma = soma + p[y]*resultado;
    resultado=1;
    y++;
    }
    
    
    return soma;
}

int listaCanonicaDeRaizes (float p[], float raizes[], int np) {
    int  contr, i, j, y, resultado, soma, contp, m;
    float x;
    x=contr=m=contp=0;
    y=0;
    resultado=1;
    soma=0;
     while(y<=np){
    for(j=1;j<=y;j++){
        resultado = resultado * x;
    }
    soma = soma + p[y]*resultado;
    resultado=1;
    y++;
    }
     if(soma==0){
         raizes[m]=x;
         contr++;
         m++;
    }
    contp++;
    y=soma=0;
    resultado=1;
    x--;
   
   while(contp<50){
    while(y<=np){
    for(j=1;j<=y;j++){
        resultado = resultado * x;
    }
    soma = soma + p[y]*resultado;
    resultado=1;
    y++;
    }
    if(soma==0){
         raizes[m]=x;
         contr++;
         m++;
    }
    y=0;
    soma=0;
    resultado=1;
    contp++;
    x=-x;
    while(y<=np){
     for(j=1;j<=y;j++){
        resultado = resultado * x;
    }
    soma = soma + p[y]*resultado;
    resultado=1;
    y++;
    }
     if(soma==0){
         raizes[m]=x;
         contr++;
         m++;
     }
     x++;
     x=-x;
     contp++;
     y=soma=0;
     resultado=1;
   }
   if(contr!=0){
       printf("A(s) %d raiz(es):",contr);
   }
   for(j=0;j<contr;j++){
       printf("\np(%f) = 0.000000",raizes[j]);
   }
   
   if(contr==0){
       printf("\nSem raizes");
   }
return soma;
}

float polinomioQuocienteRacional (float p[], float q[], int b, int a, int np) {
    int j , r, x, i;
    j=np;
    i=0;
 
    

    return np;
    }
int polinomioQuociente (float p[], float q[], float raiz, int np, int nq) {
   int j, i;
   float x , soma;
   x=raiz;
   j=np;
   i=nq;

   
   while(j>0){
        if(j==np){
            q[nq]=p[np];
            soma=q[nq];
        }
        if(j!=np){
            soma = soma * x;
            soma = soma + p[j];
            q[i] = soma;
        }
        j--;
        i--;
   }
   return soma;
       
   }
   
   void reduzRacional (int *b, int *a) {
      
         int cont;
    int nu, de;
    cont=2;
    nu = *b;
    de = *a;
    while(cont<=nu && cont<=de){
        if(nu%cont==0 && de%cont==0){
            nu=nu/cont;
            de=de/cont;
            cont--;
        }
        cont++;
    }
   }
    
    
       
   

int main(){
    int n, np, i, j, pot, f, cont, a , b, nq;
    int coe;
    float p[MAX], x, r;
    float p1[MAX], raizes[MAX], q[MAX];
    
    
    pot=f=1;
    cont=0;
    
    printf("Digite opcao:  ");
    scanf("%d",&n);
    
    if(n!=2){
    printf("\nDigite o grau:");
    scanf("%d",&np);
      coe = np + 1;
      i=np;
    printf("\nDigite os %d coeficientes:",coe);
       for(j=0;j<=np;j++){
      printf("  ");
       scanf("%f",&p[j]);
       }
    }
    
    if(n==0){
  
      printf("  ");
      scanf("%f",&x);
       
      printf("Digite os 6 valores: p(%f) = %f", x ,avaliaPolinomio(p,x,np));
      
     while(cont<5){
      printf("  ");
      scanf("%f",&x);
      printf("\np(%f) = %f",x,avaliaPolinomio(p,x,np));
      cont++;
     }
      
      
    }
    
    if(n==1){
      for(j=0;j<=np;j++){
          p1[j]= p[j] + 1;
      }
      printf("\np+1=%s\n", polinomioToStringF(p1, np+1));
       printf("p=%s\n", polinomioToStringF(p, np+1));
    }
    if(n==2){
        
        printf("Digite os 5 valores: ");
        scanf("%f",&x);
        encontraInteiro(x, &pot,&f);
        racionalReduzido(x,&f,&pot);
        while(cont<4){
            printf("  ");
            scanf("%f",&x);
            printf("\n");
            encontraInteiro(x, &pot,&f);
            racionalReduzido(x,&f,&pot);
            cont++;
        }
       
    }
    
    if(n==3){
        printf("Digite os 8 valores:");
       while(cont<8){
        printf("  ");
        scanf("%f",&x);
        printf("p(%f) : %d",x,polinomioComRaiz(p,x,np));
        cont++;
       }
        
    }
    if(n==4){
        printf("Digite uma raiz r para fatorar por (x-r) : ");
        scanf("%f",&r);
        nq = np - 1;
        printf("%f:",r);
        polinomioQuociente(p,q,r,np,nq);
        printf("%s\n", polinomioToStringF(q, nq+1));
        
    }
    if(n==5){
         listaCanonicaDeRaizes(p,raizes,np);
        
    }
    if(n==6){
       printf("\nDigite a e b:  ");
       scanf("%d %d",&a,&b);
        polinomioQuocienteRacional(p,q,b,a,np);
    }
    
    return 0;
}
