#include "expr_assert.h"
#include "tree.h"

#define say(test_description) int say = printf("**  Description->%s\n\n", test_description)
typedef void (*logger)(char*);

struct con{
	logger log;
};
void log(char* desc){
	printf("%s\n",desc);
}
struct con console = {&log};
void cout(char * d){
	console.log(d);
}
struct system{
	struct{
		void(*println)(char*);
	} out;
};
struct system System = {{cout}};
// ====================================================================================================
void test_createTreeNode_001() {
	say("createTreeNode creates a tree node with given data");
	Node *a = createTreeNode(8);
	assertEqual(a->data,8);
	assertEqual(a->leftChild,0);
	assertEqual(a->rightChild,0);
} 

void test_createTreeNode_002() {
	say("createTreeNode creates a tree node with given data");
	Node *a = createTreeNode(34);
	assertEqual(a->data,34);
	assertEqual(a->leftChild,0);
	assertEqual(a->rightChild,0);
}

void test_createBSTree_001() {
	say("creates a blank tree");
	BSTree tree = createBSTree();
	assertEqual(tree.count,0);
	assertEqual(tree.root,0);
}

void test_insert_001() {
	say("insert returns 1 for insertion");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
}

void test_insert_002() {
	say("insert puts the value in top if the tree is empty");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
}

void test_insert_003() {
	say("insert puts the value in left if the value of top is greater than the root value");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
}

void test_insert_004() {
	say("insert puts the value in right if the value of top is greater than the root value");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.count,3);
	assertEqual(tree.root->rightChild->data,10);
}

void test_insert_005() {
	say("insert puts the value in next row if the value of top is greater than the root value and first level is full");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.count,3);
	assertEqual(tree.root->rightChild->data,10);
	assertEqual(insert(&tree,6),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->leftChild->data,6);
}

void test_insert_006() {
	say("insert puts the value in next row if the value of top is greater than the root value and first level is full");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.count,3);
	assertEqual(tree.root->rightChild->data,10);
	assertEqual(insert(&tree,12),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->rightChild->rightChild->data,12);
}

void test_insert_007() {
	say("insert puts the value in next row if the value of top is greater than the root value and first level is full");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.count,3);
	assertEqual(tree.root->rightChild->data,10);
	assertEqual(insert(&tree,9),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->rightChild->leftChild->data,9);
}

void test_find_001() {
	say("returns -1 if node not found");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.count,3);
	assertEqual(tree.root->rightChild->data,10);
	assertEqual(insert(&tree,9),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->rightChild->leftChild->data,9);
	assertEqual(find(tree,56),0);
}

void test_find_002() {
	say("returns the node if node not found");
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(tree.root->data,8);
	assertEqual(tree.count,1);
	assertEqual(insert(&tree,7),1);
	assertEqual(tree.count ,2);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->leftChild->data,7);
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.count,3);
	assertEqual(tree.root->rightChild->data,10);
	assertEqual(insert(&tree,9),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->rightChild->leftChild->data,9);
	assertEqual(find(tree,8)->data,8);
}
















