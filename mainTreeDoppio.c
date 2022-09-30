#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

#define BUFSIZE 8
#define LETTERE 26

int mainAlberoDoppio(char * input){
	tree * albero = newTree(0,0,0);
	{
		FILE * f = fopen("tabella","r");
		for(int i=0; i<LETTERE; i++){
			char tmp[BUFSIZE];
			fscanf(f,"%s\n",tmp);
			int len = strlen(tmp);
			add(albero,tmp[0],tmp+1,len-2);
		}
		fclose(f);
	}
 
	//printTree(albero,0);
	{
		int dimInput = strlen(input);
		printf("\nInput: '%s'\nDimInput: '%d'\n\n", input, dimInput); // <- ho aggiunto '' attorno alle string per leggibilità mia
		tree * t = albero;
		for(int i=0; i < dimInput; i++){
			if(input[i] == '$'){
				printf("%c",t->i);
			}else{
				t = getNext(t,input[i] == '-');
				tree * toPrint = NULL;
				makeShallowCopySorted(t,&toPrint);
				printSymmetric(toPrint);
				deleteTree(&toPrint);
			}
			printf("\n");
		}
	}

	deleteTree(&albero);
	return 0;
}
