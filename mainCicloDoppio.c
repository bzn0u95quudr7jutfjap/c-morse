
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8
#define LETTERE 26

int mainCicloDoppio(char * input){
	char matrice[LETTERE][BUFSIZE];
	{
		FILE * f = fopen("tabella","r");
		for(int i=0; i<LETTERE; i++){
			fscanf(f,"%s\n",matrice[i]);
		}
		fclose(f);
	}

	int dimInput = 0;
	//for (int i = 0; input[i] != '\0'; i++, dimInput++) { }; // <- originale
	//for(dimInput = 0; input[i] != '\0'; dimInput++); // alternative
	//for(dimInput = 0; input[i] != 0; dimInput++);
	//for(dimInput = 0; input[i]; dimInput++);
	dimInput = strlen(input); // <- richiede #include <string.h>

	printf("\nInput: '%s'\nDimInput: '%d'\n\n", input, dimInput); // <- ho aggiunto '' attorno alle string per leggibilità mia

	//int checkers[LETTERE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // <- prima idea che mi è venuta
	//int * exclude = calloc(LETTERE,sizeof(int)); 									// <- seconda idea
	int exclude[LETTERE]; for(int i = 0; i < LETTERE;i++){ exclude[i] = 0 ;};		// <- ho optato per questa perché è in stack
	for(int i = 0; i< dimInput; i++){
		for(int j = 0; j< LETTERE; j++){
			if(exclude[j] == 0 && input[i] == matrice[j][i+1]){
				printf("%c", matrice[j][0]);
			}else{
				exclude[j] = 1;
			}
		}
		printf("\n");
	}
	//free(exclude);	// <- free della seconda idea

	return 0;
}
