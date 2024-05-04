#include<stdlib.h>
#include<algorithm>
#include<iostream>

typedef struct node_int
{
	int val;
}node;

class seqList_int
{
public:
	seqList_int(){};
	seqList_int(int len);

	int push_back(int val);
	int pop_back();

	int back();
	int getVal(int pos);

	int empty();
	
private:
	int length = 0, currentLen = -1;
	node* list = NULL;

	void sizeManagement();
};

seqList_int::seqList_int(int len)
{
	if (len < 0)
	{
		return;
	}
	node* p1;
	p1 = (node*)malloc(sizeof(node) * len);
	if (p1 == NULL)
	{
		exit(0);
	}
	list = p1;
}

int seqList_int::push_back(int val)
{
	if (this->length == 0 || currentLen == length - 1)
	{
		this->sizeManagement();
	}
	this->currentLen++;
	this->list[this->currentLen].val = val;
	return 0;
}

int seqList_int::pop_back()
{
	if (currentLen == -1)
	{
		return -1;
	}
	else
	{
		this->currentLen--;
		return 1;
	}
}

int seqList_int::back()
{
	if (this->currentLen == -1)
	{
		return -1;
	}
	else
	{
		return this->list[this->currentLen].val;
	}
}

int seqList_int::getVal(int pos)
{
	return this->list[pos].val;
}

int seqList_int::empty()
{
	if (currentLen == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void seqList_int::sizeManagement()
{
	if (this->length == 0)
	{
		this->list = (node*)malloc(sizeof(node));
		if (this->list == NULL)
		{
			exit(-1);
		}
		length = 1;
	}
	else if (this->currentLen == this->length - 1)
	{
		node* p1;
		p1 = (node*)malloc(sizeof(node) * ((2 * this->length)));//����˫���ռ�
		this->length *= 2;
		//std::copy(std::begin(this->list), std::end(this->list), std::begin(this->length));
		for (int i = 0;i < this->length;i++)
		{
			p1[i].val = this->list[i].val;
		}
		free(this->list);
		this->list = p1;
	}
}

void test_seqList()
{
	seqList_int a;
	for (int i = 0;i < 64;i++)
	{
		a.push_back(i);
	}
	while (!a.empty())
	{
		std::cout << a.back() << ' ';
		a.pop_back();
	}
}