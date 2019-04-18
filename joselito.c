#include <stdio.h>

int main( ){
  int i,argc;

  printf("Quantos nomes vc quer guardar?" );
  scanf("%d",&argc);
  char nome[argc][100];
  for(i=0;i<argc;i++){
    printf("Qual seu nome?" );
    scanf("%s",nome[i]);
  }
  for(i=0;i<argc;i++){
    printf("ola ");
    printf("%s\n",nome[i] );
  }
  return 0;
}
