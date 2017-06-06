#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
#define INFINITY 655535
typedef int WeightType;
typedef int Vertex;
typedef int DataType;

typedef struct MGNode *PtrToMGNode;
struct MGNode
{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
};
typedef PtrToMGNode MGraph;

typedef struct ENode *PtrToMENode;
struct ENode
{
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToMENode Edge;

MGraph CreatMGraph(int VertexNum);
void MGraphInsertEdge(MGraph Graph, Edge E);
MGraph BuildMGraph();
void FindAnimal(MGraph Graph);
WeightType FindMaxDist(WeightType D[][MaxVertexNum],
	Vertex i, int N);
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum]);

int main()
{
	MGraph G = BuildMGraph();
	FindAnimal(G);
	return 0;
}

MGraph CreatMGraph(int VertexNum) {
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct MGNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; Graph->Nv > V; V++)
		for (W = 0; Graph->Nv > W; W++)
			Graph->G[V][W] = INFINITY;
	return Graph;
}

void MGraphInsertEdge(MGraph Graph, Edge E) {
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildMGraph() {
	MGraph Graph;
	Edge E;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreatMGraph(Nv);
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; Graph->Ne > i; i++) {
			scanf("%d %d %d",
				&E->V1, &E->V2, &E->Weight);
			E->V1--;
			E->V2--;
			MGraphInsertEdge(Graph, E);
		}
	}
	return Graph;
}

void FindAnimal(MGraph Graph) {
	WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
	Vertex Animal, i;
	Floyd(Graph, D);
	MinDist = INFINITY;
	for (i = 0; Graph->Nv > i; i++) {
		MaxDist = FindMaxDist(D, i, Graph->Nv);
		if (MaxDist == INFINITY) {
			printf("0\n");
			return;
		}
		if (MinDist > MaxDist) {
			MinDist = MaxDist;
			Animal = i + 1;
		}
	}
	printf("%d %d\n", Animal, MinDist);
}

WeightType FindMaxDist(WeightType D[][MaxVertexNum],
	Vertex i, int N) {
	WeightType MaxDist;
	Vertex j;
	MaxDist = 0;
	for (j = 0; N > j; j++)
		if ((i != j) && (D[i][j] > MaxDist))
			MaxDist = D[i][j];
	return MaxDist;
}
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum]) {
	Vertex i, j, k;
	for (i = 0; Graph->Nv > i; i++)
		for (j = 0; Graph->Nv > j; j++)
			D[i][j] = Graph->G[i][j];
	for (k = 0; Graph->Nv > k; k++)
		for (i = 0; Graph->Nv > i; i++)
			for (j = 0; Graph->Nv > j; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}

}