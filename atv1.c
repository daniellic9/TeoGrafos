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

//Union-Find
Vertice ch[1000];
int sz[1000];

void UFinit( int V) {
   for (Vertice v = 0; v < V; ++v) {
      ch[v] = v;
      sz[v] = 1;
   }
}

//devolve o chefe de v (ou seja, o chefe da componente conexa que contém v na floresta geradora mst[0..k-1]).
Vertice UFfind( Vertice v) {
   Vertice v0 = v;
   while (v0 != ch[v0])
      v0 = ch[v0];
   return v0;
}

//recebe dois chefes distintos v0 e w0 e faz a união das correspondentes componentes.
void UFunion( Vertice v0, Vertice w0) {
   if (sz[v0] < sz[w0]) {
      ch[v0] = w0;
      sz[w0] += sz[v0];
   }
   else {
      ch[w0] = v0;
      sz[v0] += sz[w0];
   }
}

//Algoritmo de kruskal
#define UGraph Grafo

void UGRAPHmstKruskal1( UGraph G, int mst[])
{
   int *e=(int *)malloc(G->E*sizeof(int)); 

   UGRAPHedges( G, e);
   int E = G->A/2;
   sort( e, 0, E-1);

   UFinit( G->V);
   int k = 0;
   for (int i = 0; k < G->V-1; ++i) {
      Vertice v0, w0;
      v0 = UFfind( e[i].v); w0 = UFfind( e[i].w);
      if (v0 != w0) {
         UFunion( v0, w0);
         mst[k++] = e[i];
      }
   }
}

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
