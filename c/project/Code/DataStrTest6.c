#include <stdio.h>
#define Null -1
#define MaxTree 10
typedef struct _TreeNote{
	char Data;
	int Left;
	int Right;
} TreeNote;
int ReadTree(TreeNote * T1);
int Isomorphic(const TreeNote * T1,const TreeNote * T2,int Root1,int Root2);
int main(){
	TreeNote T1[MaxTree],T2[MaxTree];
	int Root1,Root2;
	Root1=ReadTree(T1);
	Root2=ReadTree(T2);
	if (Isomorphic(T1,T2,Root1,Root2))
		printf("Yes\n");
	else 
		printf("No\n");
	return 0;
} 
int ReadTree(TreeNote * T1){
	int NoteNumber,i,check[MaxTree]={0},Root=Null; 
	scanf("%d",&NoteNumber);
	if(MaxTree>=NoteNumber&&0<NoteNumber){
		for(i=0;NoteNumber>i;i++){
			char TmpL,TmpR;	
			scanf(" %c %c %c",&T1[i].Data,&TmpL,&TmpR);
			if(TmpL!='-'){
				T1[i].Left=TmpL-'0';
				check[T1[i].Left]=1;
			}
			else{
				T1[i].Left=Null;
			}
			if(TmpR!='-'){
				T1[i].Right=TmpR-'0';
				check[T1[i].Right]=1;
			}
			else{
				T1[i].Right=Null;
			}
		}		
	}
	else return Null;
	for (i=0;NoteNumber>i;i++){
		if(check[i]!=1) break; 
	}
	Root=i;
	return Root;
}
int Isomorphic(const TreeNote * T1,const TreeNote * T2,int Root1,int Root2){
	if (Root1==Null&&Root2==Null){
		return 1;
	}
	if ((Root1!=Null&&Root2==Null)||(Root1==Null&&Root2!=Null)) {
		return 0;
	}
	if (T1[Root1].Data!=T2[Root2].Data){
		return 0; 
	} 
	if (T1[Root1].Left==Null&&T2[Root2].Left==Null){
		return Isomorphic(T1,T2,T1[Root1].Right,T2[Root2].Right);
	}
	if (T1[Root1].Left!=Null&&T2[Root2].Left!=Null&&
	((T1[T1[Root1].Left].Data)==(T2[T2[Root2].Left].Data)))
	{
		return (Isomorphic(T1,T2,T1[Root1].Left,T2[Root2].Left)&&
			Isomorphic(T1,T2,T1[Root1].Right,T2[Root2].Right));
	}
	return (Isomorphic(T1,T2,T1[Root1].Left,T2[Root2].Right)&&
	Isomorphic(T1,T2,T1[Root1].Right,T2[Root2].Left));
}

