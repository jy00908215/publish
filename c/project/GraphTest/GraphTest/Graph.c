#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
MGraph CreatMGraph(int VertexNum) {
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct MGNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; Graph->Nv > V; V++)
		for (W = 0; Graph->Nv > W; W++)
			Graph->G[V][W] = 0;
	return Graph;
}

void MGraphInsertEdge(MGraph Graph, Edge E) {
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildMGraph() {
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreatMGraph(Nv);
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; Graph->Ne > i; i++) {
			scanf("%d %d %d",
				&E->V1, &E->V2, &E->Weight);
			MGraphInsertEdge(Graph, E);
		}
	}
	for (V = 0; Graph->Nv > V; V++)
		scanf("%d", &(Graph->Data[V]));
	return Graph;
}

LGraph CreatLGraph(int VertexNum) {
	Vertex V, W;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct LGNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; Graph->Nv > V; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}

void LGraphInserEdge(LGraph Graph, Edge E) {
	PtrToAdjLVNode NewNode;
	NewNode = (PtrToAdjLVNode)malloc(sizeof(struct AdjLVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	PtrToAdjLVNode NewNode;
	NewNode = (PtrToAdjLVNode)malloc(sizeof(struct AdjLVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildLGraph() {
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreatLGraph(Nv);
	scanf("%d", &(Graph->G));
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; Graph->Ne > i; i++) {
			scanf("%d %d %d",
				&E->V1, &E->V2, &E->Weight);
			LGraphInsertEdge(Graph, E);
		}
	}
	for (V = 0; Graph->Nv > V; V++)
		scanf("%d", &(Graph->G[V].Data));
	return Graph;
}