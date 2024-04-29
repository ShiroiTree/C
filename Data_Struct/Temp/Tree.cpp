typedef struct treeNode {
	treeNode() :parent(nullptr), left(nullptr), right(nullptr) {}
	int value;
	struct treeNode* parent, * left, * right;
}treeNode;

typedef struct listNode {
	listNode() :pre(nullptr), next(nullptr) {}
	int value;
	struct listNode* pre, * next;
}listNode;

class linkedList_int {
public:
	// init without argument and with argument
	linkedList_int();//
	linkedList_int(int length);
	//
	int insert(int val, int pos);
	int push_back(int val);//
	int push_front(int val);//
	int pop_back();//
	int pop_front();//
	int del(int pos);
	//
	int length();
	int empty();//
	int front();//
	int back();//
	int getVal(int pos);
	int setVal(int n, int pos);
	//
	listNode* begin();
	listNode* end();
	listNode* getNode(int pos);

private:
	listNode* head = nullptr, * tail = nullptr;

};

class binTree_int{
public:
	binTree_int();

	//


	// Traversal
	linkedList_int* preOrder();
	linkedList_int* inOrder();
	linkedList_int* postOrder();

	//



private:
	treeNode* root;



};


binTree_int::binTree_int(){
	this->root = new treeNode;
}


void preOrderTraversal(linkedList_int* out, treeNode* currentNode);
void inOrderTraversal(linkedList_int* out, treeNode* currentNode);
void postOrderTraversal(linkedList_int* out, treeNode* currentNode);

linkedList_int* binTree_int::preOrder() {
	linkedList_int* Traversal = new linkedList_int;
	preOrderTraversal(Traversal, root);
	return Traversal;
}

linkedList_int* binTree_int::inOrder() {
	linkedList_int* Traversal = new linkedList_int;
	inOrderTraversal(Traversal, root);
	return Traversal;
}

linkedList_int* binTree_int::postOrder() {
	linkedList_int* Traversal = new linkedList_int;
	postOrderTraversal(Traversal, root);
	return Traversal;
}








void preOrderTraversal(linkedList_int* out, treeNode* currentNode) {
	out->push_back(currentNode->value);
	if (currentNode->left != nullptr) {
		preOrderTraversal(out, currentNode->left);
	}
	if (currentNode->right != nullptr) {
		preOrderTraversal(out, currentNode->right);
	}
}

void inOrderTraversal(linkedList_int* out, treeNode* currentNode) {
	if (currentNode->left != nullptr) {
		preOrderTraversal(out, currentNode->left);
	}
	out->push_back(currentNode->value);
	if (currentNode->right != nullptr) {
		preOrderTraversal(out, currentNode->right);
	}
}

void postOrderTraversal(linkedList_int* out, treeNode* currentNode) {
	if (currentNode->left != nullptr) {
		preOrderTraversal(out, currentNode->left);
	}
	if (currentNode->right != nullptr) {
		preOrderTraversal(out, currentNode->right);
	}
	out->push_back(currentNode->value);
}
