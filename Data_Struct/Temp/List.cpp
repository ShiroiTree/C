#include<stdlib.h>

typedef struct node
{
	int value;
	struct node* next, * pre;
}*chainList, node;

node* init_chainList(int n);
node* tail(chainList head);
int length(chainList head);
int insert(chainList head, int value, int pos);
int freeNode(chainList head, int pos);
int delList(chainList head);


node* init_chainList(int n)
{
	// init head
	chainList head;
	node* p1, * p2;

	head = (node*)malloc(sizeof(node));
	head->value = 0;
	head->pre = NULL;
	p1 = head;
	// init body
	for (int i = 1;i < n;i++)
	{
		p2 = (node*)malloc(sizeof(node));
		p1->next = p2;
		p2->pre = p1;
		p2->value = 0;
		p1 = p2;
	}
	// init tail
	p1->next = NULL;
	return head;
}

node* getTail(chainList head)
{
	node* p1 = head;
	while (p1->next)
	{
		p1 = p1->next;
	}
	return p1;
}


node* chainNode(chainList head, int pos)
{
	node* p1 = head;
	for (int i = 0;i < pos;i++)
	{
		if (p1->next == NULL)
		{
			return NULL;
		}
		p1 = p1->next;
	}
	return p1;
}

int insert(chainList head, int value, int pos)
{
	// pos -1 tail 0 head
	node* p1, * p2, * p3;
	p3 = (node*)malloc(sizeof(node));
	p3->value = value;

	if (pos == -1)
	{
		p1 = tail(head);
		p1->next = p3;
		p3->pre = p1;
		p3->next = NULL;
	}
	if (pos == 1)
	{
		p1->pre = p3;
		p3->next = p1;
		p3->pre = NULL;
	}
	else
	{
		p2 = chainNode(head, pos);
		if (p2 == NULL)
		{
			return -1;
		}
		p1 = p2->pre;
		//
		p1->next = p3;
		p3->next = p2;
		p2->pre = p3;
		p3->pre = p2;
	}
	return 0;
}

int delList(chainList head)
{
	node* p1 = head;
	while (p1->next)
	{
		p1 = p1->next;
		free(p1->pre);
	}
	free(p1);
	return 0;
}

int freeNode(chainList head, int pos)
{
	// -1 tail 0 head
	node* p_now, * p_pre, * p_next;
	p_now = chainNode(head, pos);
	if (p_now == NULL)
	{
		return -1;
	}
	if (pos == -1)
	{
		p_pre = p_now->pre;
		p_pre->next = NULL;
		free(p_now);
	}
	else if (pos == 1)
	{
		p_next = p_now->next;
		p_next->pre = NULL;
		free(p_now);
	}
	else
	{
		p_next = p_now->next;
		p_pre = p_now->pre;
		p_next->pre = p_pre;
		p_pre->next = p_next;
		free(p_now);
	}
	return 0;
}

int length(chainList head)
{
	node* p1 = head;
	int length = 1;
	while (p1->next)
	{
		p1 = p1->next;
		length++;
	}
	return length;
}

int getVal(chainList head, int pos)
{
	node* p1 = chainNode(head, pos);
	return p1->value;
}
