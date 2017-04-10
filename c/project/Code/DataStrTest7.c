#include <stdio.h>
#define Null -1
#define MaxTree 10
typedef struct _TreeNote{
	char Data;
	int Left;
	int Right;
} TreeNote;
int ReadTree(TreeNote * T1);
void FindLeaf(TreeNote * T1,int Root1);
void FindLeaf1(TreeNote * T1,int Root1);
int main(){
	TreeNote T1[MaxTree];
	int Root1;
	Root1=ReadTree(T1);
	FindLeaf1(T1,Root1);
	return 0;
}
int ReadTree(TreeNote * T1){
	int NoteNumber,i,check[MaxTree]={0},Root=Null; 
	scanf("%d",&NoteNumber);
	if(MaxTree>=NoteNumber&&0<NoteNumber){
		for(i=0;NoteNumber>i;i++){
			char TmpL,TmpR;	
			scanf(" %c %c",&TmpL,&TmpR);
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

void FindLeaf(TreeNote * T1,int Root1){
	if (Root1!=-1){
		if (T1[Root1].Left==Null&&T1[Root1].Right==Null){
			printf("%d",Root1);
			return;	
		}
		else {
			FindLeaf(T1,T1[Root1].Left);
			FindLeaf(T1,T1[Root1].Right);
		}		
	}
return;
}
void FindLeaf1(TreeNote * T1,int Root1){
	int queue[MaxTree];
	int leaves=0,head=0,tail=0;
	queue[tail++]=Root1;
	while(tail-head){
		int tmp = queue[head++];
		if (T1[tmp].Left==Null&&T1[tmp].Right==Null){
			if(leaves){
			 printf(" ");
			}
			printf("%d",tmp);
			leaves++;
		}
		if(T1[tmp].Left!=Null){
			queue[tail++]=T1[tmp].Left;
		}
		if(T1[tmp].Right!=Null){
			queue[tail++]=T1[tmp].Right;
		}
	}
return;
}
