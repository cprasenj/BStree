#include "tree.h"
#include <stdio.h>

Node* createTreeNode (int data) {
	Node *point; 
	point = calloc(sizeof(Node),1);
	point->data = data;
	return point;
} 
BSTree createBSTree(void) {
	BSTree *tree;
	tree = calloc(sizeof(BSTree),1);
	return *tree;
}
int insert(BSTree* tree,int data) {
	BSTree subTree = createBSTree();
	Node *node = createTreeNode(data);
	!tree->root && (tree->root = node);
	if(data < tree->root->data) {
		tree->root->leftChild && (subTree.root = tree->root->leftChild) && insert(&subTree,data);
		!tree->root->leftChild &&(tree->root->leftChild = node);
	}
	if(data > tree->root->data) {
		tree->root->rightChild && (subTree.root = tree->root->rightChild) && insert(&subTree,data);	
		!tree->root->rightChild && (tree->root->rightChild = node);
	}
	tree->count++; 
	return 1;
}
Node* find(BSTree tree,int data) {
	BSTree subTree = createBSTree();
	Node* node = NULL;
	data == tree.root->data && (node = tree.root);
	tree.root->rightChild && data > tree.root->data && (subTree.root = tree.root->rightChild) && find(subTree,data);
	tree.root->leftChild && data < tree.root->data && (subTree.root = tree.root->leftChild) && find(subTree,data); 
	return node;
}