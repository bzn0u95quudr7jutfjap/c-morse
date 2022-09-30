#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

#define BUFSIZE 8
#define LETTERE 26

int mainAlbero(char * input){
	tree * albero = newTree(0,0,0);
	char * output = NULL;
	int depth = 0;
	{
		FILE * f = fopen("tabella","r");
		for(int i=0; i<LETTERE; i++){
			char tmp[BUFSIZE];
			fscanf(f,"%s\n",tmp);
			int len = strlen(tmp);
			depth = len > depth ? len : depth;
			add(albero,tmp[0],tmp+1,len-2);
		}
		fclose(f);
	}
	const int OUTLEN = depth * (1 + LETTERE);
	output = calloc(OUTLEN,sizeof(char));
 
	//printTree(albero,0);
	{
		int dimInput = strlen(input);
		printf("\nInput: '%s'\nDimInput: '%d'\n\n", input, dimInput); // <- ho aggiunto '' attorno alle string per leggibilità mia
		tree * t = albero;
		for(int i=0; i < dimInput; i++){
			int row_start = (i*(LETTERE+1));
			if(input[i] == '$'){
				output[row_start] = t->i;
				output[row_start+1] = '\n';
			}else{
				t = getNext(t,input[i] == '-');
				printMorse(t,output + row_start);
				output[row_start + LETTERE] = '\n';
			}
		}
		for(int i=0;i<OUTLEN;i++){
			if(output[i] != 0){
				printf("%c",output[i]);
			}
		};
	}

	deleteTree(&albero);
	free(output);
	return 0;
}
