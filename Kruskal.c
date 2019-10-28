//Código de Kruskal utilizando quicksort e matriz de adjacencias
//Autor: Danielli dos Reis Costa
//Obs.: Pode ser usado para exercício 2404 do urionlinejudge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura do grafo
typedef struct grafo{
  int V;
  int E;
  int **adj;
}Grafo;

//estutura de arestas
typedef struct aresta{
  int v;
  int w;
  int peso;
}Aresta;

//alocação da matriz adjacencias
int **alocaMatrizAdj(int r, int c, int val){
  int i,j;
  int **m=(int **)malloc(r*sizeof(int*));
  for(i=0; i<r; i++)
    m[i]=(int *)malloc(c*sizeof(int));
  for(i=0; i<r; i++)
    for (j=0; j<c; j++)
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
void insereAresta(Grafo *G, int v, int w,int peso){
  if(v!=w && G->adj[v][w]==0){
    G->adj[v][w]=peso;
    G->adj[w][v]=peso;
    G->E++;
  }
}

//função que remove arestas da matriz
/*void removeAresta(Grafo *G, int v, int w){
  if(G->adj[v][w]!=0){
    G->E--;
    G->adj[v][w]=0;
    G->adj[w][v]=0;
  }
}*/

//função que imprime a matriz que representa o Grafo
/*void imprimeGrafo(Grafo *G){
  int v, w;
  for(v=0; v<G->V; v++){
    printf("%2d:", v);
    for(w=0; w<G->V; w++)
      if(G->adj[v][w]!=0){
        printf(" %2d", w);
        printf(" peso: %d", G->adj[v][w]);
      }
    printf("\n");
  }
}*/

//modulo
int modulo(int n){
  if(n<0)return n*-1;
  else return n;
}

//find
int find_set(int i, int *p){
  while(p[i]>=0){
    i=p[i];
  }
  return i;
}

//union
int *union_set(int i, int j, int *p){
  int k, w;
	k = find_set( i,p );
	w = find_set(  j,p );
	if ( modulo(p[k]) > modulo(p[w]) )
	{
		p[w] = k;
	} else
	{
		if ( modulo(p[w]) == modulo(p[k]) ) p[w]--;
		p[k] = w;
	}

	return p;
}
int separa (Aresta *v, int p, int r) {
   int c = v[r].peso; // pivô
   int t, j = p;
   int k;
   for ( k = p; /*A*/ k < r; ++k)
      if (v[k].peso <= c) {
         t = v[j].peso, v[j].peso = v[k].peso, v[k].peso = t;
         t = v[j].v, v[j].v = v[k].v, v[k].v = t;
         t = v[j].w, v[j].w = v[k].w, v[k].w = t;
         ++j;
      }
   t = v[j].peso, v[j].peso = v[r].peso, v[r].peso = t;
   t = v[j].v, v[j].v = v[k].v, v[k].v = t;
   t = v[j].w, v[j].w = v[k].w, v[k].w = t;
   return j;
}

void quickSort (Aresta *v, int p, int r)
{
   while (p < r) {
      int j = separa (v, p, r);
      if (j - p < r - j) {
         quickSort (v, p, j-1);
         p = j + 1;
      } else {
         quickSort (v, j+1, r);
         r = j - 1;
      }
   }
}

//conjuntos
int *cria_conjunto( int n )
{
	n++;
	int *novo = (int*)calloc( n, sizeof(int));
	memset(novo,-1, sizeof(int)*n );
	return novo;
}

//kruskal
void kruskal(Grafo *G){
  Grafo *arvoreG=criaGrafo(G->V);
  int i=0,k=0,v,w, tam=G->E+1;
  Aresta a[tam]; //vetor de arestas a ser ordenado
/*for (i = 0; i < tam; i++) {
  a[tam].peso=0;
  a[tam].v=0;
  a[tam].w=0;
}*/
  int *p = cria_conjunto( G -> V ); //cria conjunto de cada vertices
  for(v=0; v<G->V; v++){
    for(w=0; w<G->V; w++){
      if(G->adj[v][w]!=0 && v<w){
        a[k].peso=G->adj[v][w];
        a[k].v=v;
        a[k].w=w;
        k++;
      }
    }
  }
quickSort(a,0,G->E-1);
int soma=0,cont=0;
while (cont < G->E) {

    if(find_set(a[cont].v,p)!=find_set(a[cont].w,p)){//se find_set de cada vértice dessa aresta for diferente
      soma+=a[cont].peso;
      //insereAresta(arvoreG,(a[cont].v),(a[cont].w),a[cont].peso);//coloca aresta na árvore
      p=union_set(a[cont].v,a[cont].w,p);//union_set dos vétices dessa aresta

    }
    cont++;
  }
        printf("%d\n",soma );
        free(p);
        free(G);
}

int main(){
  int vertices,arestas,i,j,k;
  scanf("%d %d",&vertices,&arestas );
  Grafo *novoGrafo=criaGrafo(vertices);
while(arestas>0){
  scanf("%d %d %d",&i,&j,&k );
  insereAresta(novoGrafo,i-1,j-1,k);
  arestas--;
}
kruskal(novoGrafo);
  return 0;
}
