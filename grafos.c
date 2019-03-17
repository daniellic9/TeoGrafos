#include <stdio.h>
#include <stdlib.h>

//estrutura do grafo
typedef struct grafo{
  int V;
  int E;
  int **adj;
}Grafo;

//alocação da matriz adjunta
int **alocaMatrizAdj(int r, int c, int val){
  int i,j;
  int **m=(int **)malloc(r*sizeof(int*));
  for(i=0; i<r; i++)
    m[i]=(int *)malloc(c*sizeof(int));
  for(i=0; i<r; i++)
    for (j=0; j<c j++)
      m[i][j]=val;
  return m;
}

//função que cria o Grafo
Grafo *criaGrafo(int V){
  Grafo *G= (Grafo *)malloc(sizeof(Grafo));
  G-> V=V;
  G->E=0;
  G->adj=alocaMatrizAdj(V,V,0);
  return G;
}

//função que faz inserção de arestas na matriz
void insereAresta(Grafo *G, int v, int w){
  if(v!=w && G->adj[v][w]==0){
    G->adj[v][w]=1;
    G->adj[w][v]=1;
    G->E++;
  }
}

//função que remove arestas da matriz
void removeAresta(Grafo *G, int v, int w){
  if(G->adj[v][w]==1){
    G->E--;
    G->adj[v][w]=0;
    G->adj[w][v]=0;
  }
}

//função que imprime a matriz que representa o Grafo
void imprimeGrafo(Grafo *G){
  int v, w;
  for(v=0; v<G->V; v++){
    printf("%2d:", v);
    for(w=0; w<G->V; w++)
      if(G->adj[v][w]==1)
        printf(" %2d", w);
    printf("\n");
  }
}

int main(){
  Grafo *novoGrafo=criaGrafo(4);
  insereAresta(novoGrafo,0,1);
  insereAresta(novoGrafo,1,2);
  insereAresta(novoGrafo,0,2);
  insereAresta(novoGrafo,2,3);
  insereAresta(novoGrafo,1,3);
  imprimeGrafo(novoGrafo);
  removeAresta(novoGrafo,1,3);
  imprimeGrafo(novoGrafo);
  return 0;
}
