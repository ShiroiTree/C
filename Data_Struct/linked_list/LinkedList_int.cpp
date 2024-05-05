#include <stdlib.h>
#include <iostream>

typedef struct listNode
{
	listNode() : pre(nullptr), next(nullptr) {}
	int value;
	struct listNode *pre, *next;
} listNode, node;

/*
 * linkedList class
 *
 *
 */

class linkedList_int
{
public:
	// init without argument and with argument
	linkedList_int(); //
	linkedList_int(int length);
	//
	int insert(int val, int pos);
	int push_back(int val);	 //
	int push_front(int val); //
	int pop_back();			 //
	int pop_front();		 //
	int del(int pos);
	//
	int length();
	int empty(); //
	int front(); //
	int back();	 //
	int getVal(int pos);
	int setVal(int n, int pos);
	//
	listNode *begin();
	listNode *end();
	listNode *getNode(int pos);

private:
	listNode *head = NULL, *tail = NULL;
};

/*
 * Initialize the linkedList
 * with length or val or not
 *
 *
 * return val -1 error 0 no error
 *
 */
linkedList_int::linkedList_int()
{
	this->head = (node *)malloc(sizeof(node));
	if (this->head == NULL)
	{
		exit(-1);
	}
	this->tail = this->head;
}

linkedList_int::linkedList_int(int length)
{
	node *p1 = NULL, *p2 = NULL;
	this->head = (node *)malloc(sizeof(node));
	if (this->head == NULL)
	{
		exit(-1);
	}
	this->head->pre = NULL;
	p1 = this->head;
	for (int i = 1; i < length; i++)
	{
		p2 = (node *)malloc(sizeof(node));
		if (this->head == NULL)
		{
			exit(-1);
		}
		p1->next = p2;
		p1->value = -1;
		p2->pre = p1;
		p1 = p2;
	}
	p2->next = NULL;
	this->tail = p2;
}

int linkedList_int::empty()
{
	if (this->head == NULL || this->head == this->tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int linkedList_int::length()
{
	if (this->empty())
	{
		return 0;
	}
	node *p1 = head;
	int length = 1;
	while (p1->next)
	{
		p1 = p1->next;
		length++;
	}
	return length;
}

int linkedList_int::front()
{
	return this->head->value;
}

int linkedList_int::back()
{
	return this->tail->value;
}

int linkedList_int::setVal(int n, int pos)
{
	node *p1 = this->getNode(pos);
	if (p1 == NULL)
	{
		return -1;
	}
	else
	{
		p1->value = n;
		return 1;
	}
}

int linkedList_int::getVal(int pos)
{
	node *p1 = this->getNode(pos);
	if (p1 == NULL)
	{
		return 0;
	}
	else
	{
		return p1->value;
	}
}

node *linkedList_int::begin()
{
	return this->head;
}

node *linkedList_int::end()
{
	return this->tail;
}

node *linkedList_int::getNode(int pos)
{
	if (pos == -1)
	{
		return this->tail;
	}
	else
	{
		node *p1 = this->head;
		while (pos > 0)
		{
			if (p1->next)
			{
				p1 = p1->next;
				pos--;
			}
			else
			{
				return NULL;
			}
		}
		return p1;
	}
}

int linkedList_int::pop_back()
{
	if (this->empty())
	{
		return -1;
	}
	node *p1;
	p1 = this->tail;
	this->tail = this->tail->pre;
	this->tail->next = NULL;
	free(p1);
	return 1;
}

int linkedList_int::pop_front()
{
	if (this->empty())
	{
		return -1;
	}
	node *p1;
	p1 = this->head;
	this->head = this->head->next;
	this->head->pre = NULL;
	free(p1);
	return 1;
}

int linkedList_int::del(int pos)
{
	if (this->empty())
	{
		return -1;
	}
	switch (pos)
	{
	case 0:
	{
		return this->pop_front();
		break;
	}
	case -1:
	{
		return this->pop_back();
		break;
	}
	default:
	{
		node *p1 = this->getNode(pos), *p_pre, *p_next;
		if (p1 == NULL)
		{
			return -1;
		}
		p_next = p1->next;
		p_pre = p1->pre;
		p_pre->next = p_next;
		p_next->pre = p_pre;
		free(p1);
		return 1;
		break;
	}
	}
}

int linkedList_int::push_back(int val)
{
	node *p1 = (node *)malloc(sizeof(node));
	if (p1 == NULL)
	{
		return -1;
	}
	p1->value = val;
	// insert
	p1->pre = this->tail;
	p1->next = NULL;
	this->tail->next = p1;
	this->tail = p1;
	return 1;
}

int linkedList_int::push_front(int val)
{
	node *p1 = (node *)malloc(sizeof(node));
	if (p1 == NULL)
	{
		return -1;
	}
	p1->value = val;
	// insert
	p1->next = this->head;
	p1->pre = NULL;
	this->head->pre = p1;
	this->head = p1;
	return 1;
}

int linkedList_int::insert(int pos, int val)
{
	// if head or tail
	switch (pos)
	{
	case 0:
	{
		return this->push_front(val);
		break;
	}
	case -1:
	{
		return this->push_back(val);
		break;
	}
	default:
	{
		node *p_next, *p_pre, *p_in;
		p_next = this->getNode(pos);
		p_in = (node *)malloc(sizeof(node));
		if (p_next == NULL || p_in == NULL)
		{
			return -1;
		}
		p_pre = p_next->pre;
		p_in->value = val;
		// insert
		p_pre->next = p_in;
		p_in->next = p_next;
		p_next->pre = p_in;
		p_in->pre = p_pre;
		return 1;
		break;
	}
	}
	// not head or tail
}

void test_linkedList()
{
}
