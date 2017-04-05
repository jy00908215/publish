#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
	int value;
	struct _node *next;
} Node;
typedef struct _list
{
	Node * head;
} List;
void add(List * pList, int number);
void print_List(List * pList);

int main()
{
	List list;
	list.head = NULL;
	int number;
	do 
	{
		scanf_s("%d", &number);
		if (number != -1)
		{
			add(&list, number);
		}
	} while (number != -1);
	print_List(&list);
	system("pause");
	return 0;
}
void add(List * pList, int number) 
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node * last= pList->head;
	if (last) 
	{
		while (last->next)
		{
			last = last->next;
		}
		last->next = p;
	}
	else
	{
		pList->head = p;
	}
}
void print_List(List * pList)
{
	Node * last = pList->head;
	Node *q = NULL;
	while (last)
	{
		while (last->next)
		{
				q = last;
				last = last->next;
		}
		
		printf("%d ", last->value);
		if (q->next)
		{
			free(last);
			q->next = NULL;
			last = pList->head;
		}
		else
		{
			free(last);
			last = NULL;
		}
	}
}