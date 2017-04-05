
List Merge( List L1, List L2 )
{
		List p1 = L1->Next;
		List p2 = L2->Next;
		List L = (List)malloc(sizeof(struct Node));//新链表头节点
		List p = L;
		while(p1!=NULL&&p2!=NULL)
		{
			if(p1->Data<p2->Data)
			{
				p->Next=p1;
				p1=p1->Next;
				L1->Next=p1;
				p=p->Next;
			 } 
			else
			{
				p->Next=p2;
				p2=p2->Next;
				L2->Next=p2;
				p=p->Next;
			}
		}
		if(p1!=NULL)
		{
			p->Next=p1;
			L1->Next=NULL; 
		}
		if(p2!=NULL)
		{
			p->Next=p2;
			L2->Next=NULL; 
		}
	return L;
} 
