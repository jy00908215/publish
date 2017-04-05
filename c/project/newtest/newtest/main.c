#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
	int value;
	int expon;
	struct _node *next;
} Node;
typedef struct  _list{
	Node* head; 
} List;
List * read();
void print_List(List * pList);
int main()
{
	List *L1, *L2;
	L1 = read();
	L2 = read();
	print_List(L1);
	print_List(L2);
	system("pause");
}
List * read(){
	int cnt,i;
	List * l=(List *)malloc(sizeof(List));
	Node * list = (Node *)malloc(sizeof(Node));
	list->next = NULL;
	l->head = list;
	scanf_s("%d",&cnt);
	if (0<cnt){
		for(i=0;cnt>i;i++){
			Node *tmp = (Node *)malloc(sizeof(Node));
			scanf_s("%d%d", &(tmp->value), &(tmp->expon));
			if (i==0) {
				list->next = NULL;
				list->value = tmp->value;
				list->expon = tmp->expon;
			}
			else
			{
				tmp->next = NULL;
				list->next = tmp;
				list = tmp;
			}
		}
	}
	return l;
}
void print_List(List * pList)
{
	Node * last = pList->head;
	if (!last) {
		printf("0 0\n");
	}
	else {
		while (last)
		{
			if (last->next != NULL) {
				printf("%d %d ", last->value, last->expon);
			}
			else
			{
				printf("%d %d\n", last->value, last->expon);
			}
			last = last->next;
		}
	}
}