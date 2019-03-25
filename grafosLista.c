//Declaracao vertice
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
  int no;
  struct vertice *prox;
}Vertice;

//Declaracao estrutura Grafo
typedef struct grafo{
  int V;
  int E;
  Vertice *adj;
}Grafo;

//Criacao de grafo
Grafo *criaGrafo(int V){
  Grafo *G=(Grafo *)malloc(sizeof(Grafo));
  G->V=V;
  G->E=0;
  G->adj=(Vertice *)calloc(V,sizeof(Vertice));
  return G;
}

//Criacao de novo Vertice
Vertice *novoVertice(int x){
  Vertice *novo=(Vertice *)malloc(sizeof(Vertice));
  if(novo==NULL){printf("ERRO.\n"); exit(1);}
  novo->no=x;
  novo->prox=NULL;
  return novo;
}

//Insercao de aresta
void insereAresta(Grafo *G, int v, int w){
  if(v!=w){
    Vertice *p=G->adj[v].prox;
    while(p!=NULL){
      if(p->no==w)break;
      p=p->prox;
    }
    if(p==NULL){
      Vertice *novo=novoVertice(w);
      novo->prox=G->adj[v].prox;
      G->adj[v].prox=novo;
      G->E++;
    }
    p=G->adj[w].prox;
    while(p!=NULL){
      if(p->no==v)break;
      p=p->prox;
    }
    if(p==NULL){
      Vertice *novo=novoVertice(v);
      novo->prox=G->adj[w].prox;
      G->adj[w].prox=novo;
      G->E++;
    }
  }
}

//Imprimir grafo - Dani
void imprimeGrafo(Grafo *G){
  int v;
  for(v=0; v<G->V; v++){
    printf("%.2d:", v);
    Vertice *p=G->adj[v].prox;
    while(p!=NULL){
      printf("%d",p->no);
      p=p->prox;
    }
    printf("\n");
  }
}

//Calcula grau vertice - Dani
int grauVertice(Grafo *G, int v){
  int cont=0;
  Vertice *p=G->adj[v].prox;
  while(p!=NULL){
    cont++;
    p=p->prox;
  }
  return cont;
}

//Sequencia de graus de dois grafos é identica?


 int main() {
   Grafo *G=criaGrafo(5);
   insereAresta(G,0,1);
   insereAresta(G,1,2);
   insereAresta(G,1,3);
   insereAresta(G,0,3);
   insereAresta(G,3,2);
   insereAresta(G,1,4);
   insereAresta(G,2,4);
   imprimeGrafo(G);
   printf("%d\n",grauVertice(G,1) );

  return 0;
}
