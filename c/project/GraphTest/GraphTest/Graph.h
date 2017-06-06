#ifndef __Graph_H__
#define __Graph_H__
#define MaxVertexNum 10
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

typedef struct AdjLVNode * PtrToAdjLVNode;
struct AdjLVNode
{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjLVNode Next;
};

typedef struct LVNode
{
	PtrToAdjLVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];

typedef struct LGNode * PtrToLGNode;
struct LGNode
{
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToLGNode LGraph;

MGraph CreatMGraph(int VertexNum);
void MGraphInsertEdge(MGraph Graph, Edge E);
MGraph BuildMGraph();

LGraph CreatLGraph(int VertexNum);
void LGraphInserEdge(LGraph Graph, Edge E);
LGraph BuildLGraph();
#endif // __Graph_H__