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

int isLeafNode(Node* node) {
	return !node->leftChild && !node->rightChild ? 1 :0;
}

Node* find(BSTree tree,int data) {
	BSTree subTree = createBSTree();
	if(!tree.root) return NULL;
	if(data == tree.root->data)
		return tree.root;
	tree.root->rightChild && (data > tree.root->data) && (subTree.root = tree.root->rightChild);
	tree.root->leftChild && (data < tree.root->data) && (subTree.root = tree.root->leftChild);
	return find(subTree,data);
}

int swap(Node* a,Node* b) {
	int temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
	return 1;
}

Node* delete(BSTree* tree,int data) {
	BSTree subTree = createBSTree();
	Node *node = NULL,*root,*right,*left;
	root = tree->root;
	right = root->rightChild;
	left = root->leftChild;
	if(root->data == data) {
		!isLeafNode(root) && right && swap(right,root) && (subTree.root = right)
		&& (node = delete(&subTree,data));
		isLeafNode(root) && (node = root) && (tree->root = NULL);
		return node;
	}
	if(!node){
		left && data < root->data && (subTree.root = left) && (node = delete(&subTree,data));
		right && data > root->data && (subTree.root = right) && (node = delete(&subTree,data));
	}
	if(right && data == right->data)
		isLeafNode(root->rightChild) && (node = root->rightChild) &&  (root->rightChild = NULL);
	if(left && data == left->data)
		isLeafNode(root->leftChild) && (node = root->leftChild) &&  (root->leftChild = NULL);
	return node;
}

void traverse(BSTree tree,traverser a) {
	BSTree subTree = createBSTree();
	if(tree.root) {
		if(tree.root->leftChild) {
			subTree.root = tree.root->leftChild;
			traverse(subTree,a);
		}
		a(tree.root->data);
		if(tree.root->rightChild) {
			subTree.root = tree.root->rightChild;
			traverse(subTree,a);
		}
	}
}

void postOrderTraversal(BSTree tree,traverser a) {
	BSTree subTree = createBSTree();
	if(tree.root) {
		if(tree.root->rightChild) {
			subTree.root = tree.root->rightChild;
			traverse(subTree,a);
		}
		if(tree.root->leftChild) {
			subTree.root = tree.root->leftChild;
			traverse(subTree,a);
		}
		a(tree.root->data);
	}
}