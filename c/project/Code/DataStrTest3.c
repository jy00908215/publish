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
List * add_List(List *l1,List *l2);
List * multi_List(List *l1,List *l2);
List * multi_List_Node(List *l1,Node *n1);
int main(){
	List *L1, *L2,*Ladd,*Lmulti;
	L1 = read();
	L2 = read();
	Ladd= add_List(L1,L2);
	Lmulti=multi_List(L1,L2);
	print_List(Lmulti);	
	print_List(Ladd);
	return 0;
}
List * read(){
	int cnt,i;
	List * l=(List *)malloc(sizeof(List));
	l->head=NULL;
	scanf("%d",&cnt);
	if (0<cnt){
		Node * last = (Node *)malloc(sizeof(Node));
		last->next = NULL;
		l->head = last;
		for(i=0;cnt>i;i++){
			Node *tmp = (Node *)malloc(sizeof(Node));
			scanf("%d%d", &(tmp->value), &(tmp->expon));
			if (i==0) {
				last->next = NULL;
				last->value = tmp->value;
				last->expon = tmp->expon;
			}
			else
			{
				tmp->next = NULL;
				last->next = tmp;
				last = tmp;
			}
		}
	}
	return l;
}
void print_List(List * pList){
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
List * add_List(List *l1,List *l2){
	Node *p1=l1->head,*p2=l2->head;
	List * l=(List *)malloc(sizeof(List));
	l->head=NULL;
	if(p1!=NULL||p2!=NULL){
		Node * last = (Node *)malloc(sizeof(Node));
		last->next = NULL;
		l->head = last;
		int i=0;
		if (i==0){
			if(p1!=NULL&&p2!=NULL) {
				if(p1->expon>p2->expon){
					last->expon=p1->expon;
					last->value=p1->value;
					p1=p1->next;
				}
				else if(p1->expon<p2->expon){
					last->expon=p2->expon;
					last->value=p2->value;
					p2=p2->next;
				}
				else if (p1->expon==p2->expon){
					if((p1->value+p2->value)==0){
						p1=p1->next;
						p2=p2->next;
					}
					else{
						last->value=(p1->value+p2->value);
						last->expon=p1->expon;
						p1=p1->next;
						p2=p2->next;					
					}
				}
			}
			else if (p1==NULL){
				last->value=p2->value;
				last->expon=p2->expon;
				p2=p2->next;
			}
			else if (p2==NULL){
				last->value=p1->value;
				last->expon=p1->expon;
				p1=p1->next;
			}
			i++;
		}
		while(p1!=NULL&&p2!=NULL){
			Node * tmp=(Node *)malloc(sizeof(Node));
			tmp->next=NULL;
			if(p1->expon>p2->expon){
				tmp->expon=p1->expon;
				tmp->value=p1->value;
				last->next=tmp;
				last=tmp;
				p1=p1->next;
			}
			else if (p1->expon<p2->expon){
				tmp->expon=p2->expon;
				tmp->value=p2->value;
				last->next=tmp;
				last=tmp;
				p2=p2->next;
			}
			else if (p1->expon==p2->expon){
				if((p1->value+p2->value)==0){
					p1=p1->next;
					p2=p2->next;
				}
				else{
					tmp->expon=p1->expon;
					tmp->value=(p1->value+p2->value);
					last->next=tmp;
					last=tmp;
					p1=p1->next;
					p2=p2->next;
				}
			}
		}
		if(p1==NULL){
			last->next=p2;
		}
		else if(p2==NULL){
			last->next=p1;
		}			
	}
	return l;
}
List * multi_List_Node(List *l1, Node *n1){
	List *l;
	if (l1->head!=NULL&&n1!=NULL){
		Node *p1 =l1->head;
		l=(List *)malloc(sizeof(List));
		Node *last=(Node *)malloc(sizeof(Node));
		last->next=NULL;
		l->head=last;
		int i=0;
		while(p1){
			if(i==0){
				last->expon=(p1->expon+n1->expon);
				last->value=(p1->value*n1->value);
				p1=p1->next;
				i++;
			}	
			else{
				Node * tmp=(Node *)malloc(sizeof(Node));
				tmp->expon=(p1->expon+n1->expon);
				tmp->value=(p1->value*n1->value);
				tmp->next=NULL;
				last->next=tmp;
				last=tmp;
				p1=p1->next;
			}
		}
	}
	else{
		l->head=NULL;
	}
	return l;
}
List * multi_List(List *l1,List *l2){
	List *t1,*t2;
	List *l=(List *)malloc(sizeof(List));
	Node * p1=l1->head;
	l->head=NULL;
	if(l1->head!=NULL&&l2->head!=NULL){
		while (p1){
			t1=multi_List_Node(l2,p1);		
			l=add_List(l,t1);
			p1=p1->next;
			free(t1);
		}
	}
	return l;
}

