/*
* 
* 
* 
* 
*/


typedef struct node{
	int value;
	struct node* next;
}node;

class stack_int{
public:
	stack_int();

	int push_back(int val);
	int pop_back();

	int back();


private:
	node* head;
};

stack_int::stack_int(){
	this->head = nullptr;
}

int stack_int::push_back(int val){
	node* p1 = new node;
	p1->next = head;
	p1->value = val;
	head = p1;
	return 1;
}

int stack_int::pop_back(){
	if (this->head == nullptr){
		return 0;
	}
	else{
		node* p1 = this->head;
		this->head = p1->next;
		delete p1;
		return 1;
	}
}

int stack_int::back(){
	if (this->head == nullptr){
		return 0;
	}
	else{
		return this->head->value;
	}
}




