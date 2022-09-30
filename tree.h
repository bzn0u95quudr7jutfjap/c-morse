#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

typedef struct tree_node{
	char i;
	struct tree_node* l;
	struct tree_node* r;
} tree;

tree * newTree(char c,tree *l , tree *r);
tree * getNext(tree * r, int i);
void setNext(tree *r, int idx, tree * t);
void add(tree * r, char c, char * path,unsigned int idx);
void addByValue(tree ** dst, char v);
void makeShallowCopySorted(tree * src, tree ** dst);
void deleteTree(tree ** r);
void printTree(tree *r, int indentation);
void printSymmetric(tree * t);
void printMorse(tree * r,char * str);
