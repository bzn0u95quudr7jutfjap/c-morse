#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

#define BUFSIZE 8
#define LETTERE 26

tree * newTree(char c,tree *l , tree *r){
	tree * t = (tree *) malloc(sizeof(tree));
	t->i = c;
	t->l = l;
	t->r = r;
	return t;
}

tree * getNext(tree * r, int i){
	return i ? r->r : r->l ;
}
void setNext(tree *r, int idx, tree * t){
	if(idx){
		r->r = t;
	}else{
		r->l = t;
	}
}

void add(tree * r, char c, char * path,unsigned int idx){
	for(int i = 0; i < idx; i++){
		int b = path[i] == '-';
		if(getNext(r,b) == NULL){
			setNext(r,b,newTree(0,0,0));
		}
		r = getNext(r,b);
	}
	r->i = c;
}
void addByValue(tree ** dst, char v){
	tree * dstv = *dst;
	if(*dst == NULL){
		*dst = newTree(v,0,0);
	}else if(v < dstv->i){
		addByValue(&(dstv->l),v);
	}else{
		addByValue(&(dstv->r),v);
	}
}
void makeShallowCopySorted(tree * src, tree ** dst){
	if(src != NULL){
		addByValue(dst,src->i);
		makeShallowCopySorted(src->l,dst);
		makeShallowCopySorted(src->r,dst);
	}
}
void deleteTree(tree ** r){
	if(*r != NULL){
		deleteTree(&((*r)->l));
		deleteTree(&((*r)->r));
		free(*r);
		*r = NULL;
	}
}
void printTree(tree *r, int indentation){
	char * indentStr = "-";
	for(int i = 0; i < indentation; i++){ printf("%s",indentStr); };
	if(r == NULL){
		printf("$\n");
	}else{
		char c = r->i;
		if(r->l == NULL && r->r == NULL){
			printf("%c\n",c == 0 ? '^' : c);
		}else{
			printf("%c\n",c == 0 ? '^' : c);
			printTree(r->l,indentation + 1);
			printTree(r->r,indentation + 1);
		}
	}
}
void printSymmetric(tree * t){
	if(t != NULL){
		printSymmetric(t->l);
		printf("%c",t->i);
		printSymmetric(t->r);
	}
}
void printMorse(tree * r,char * str){
	 if(r != NULL){
		 char c = r->i;
		 str[c-'A'] = c;
		 printMorse(r->l,str);
		 printMorse(r->r,str);
	 }
 }
