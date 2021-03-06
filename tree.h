struct NODE {
	int data;
	struct NODE* leftChild;
	struct NODE* rightChild;
};
typedef struct NODE Node;
typedef Node* n_ptr;
struct BStree{
	n_ptr root;
	int count;	
};
typedef struct BStree BSTree;
typedef void (*traverser)(int);

int add(int,int);

Node* createTreeNode(int);
BSTree createBSTree(void);
int insert(BSTree*,int);
Node* find(BSTree,int);
Node* findRight(BSTree*,int);
Node* findLeft(BSTree*,int);
Node* delete(BSTree*,int); 
int isLeafNode(Node*);
void traverse(BSTree,traverser);
void postOrderTraversal(BSTree,traverser);