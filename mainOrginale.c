#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8
#define LETTERE 26

char** crea_matrice_conversione(const char* fileme);
void stampa_matrice(char** matrice);
void free_matrice(char** matrice);
void get_keyboard_input(char * input);

int mainOriginale(char * input){
	char** matrice = crea_matrice_conversione("tabella"); // <- orginale
	//stampa_matrice(matrice); // <- originale

	int dimInput = 0;
	//char input[BUFSIZE]; // <- originale | gli passo la stringa dagli args per automatizzare i test
	//get_keyboard_input(input);

	for (int i = 0; input[i] != '\0'; i++, dimInput++) { }; // <- originale
	//for(dimInput = 0; input[i] != '\0'; dimInput++); // alternative
	//for(dimInput = 0; input[i] != 0; dimInput++);
	//for(dimInput = 0; input[i]; dimInput++);
	//dimInput = strlen(input); // <- richiede #include <string.h>

	printf("\nInput: '%s'\nDimInput: '%d'\n\n", input, dimInput); // <- ho aggiunto '' attorno alle string per leggibilità mia

	int k = 1; // l'originale era sopra la cattura dell'imput, l'ho spostato qua sotto
	for (int j = 0; j < dimInput; j++) {
		for (int i = 0; i < LETTERE; i++) {
			for (int l = 0; l < j + 1; l++) {
				if (input[l] != matrice[i][k + l]) break;
				if (l == j) printf("%c", matrice[i][0]);
			}
		}
		printf("\n");
	}

	free_matrice(matrice); // <- originale | non più richiesto perché la matrice è allocata in stack
    //exit(EXIT_SUCCESS); // tolto perché non mi funzionava il debugger
	return 0;
}



// CODICE ORIGINALE
// Sposato sotto solo per manovrabilità

char** crea_matrice_conversione(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char** matrice = (char**)malloc(LETTERE * sizeof(char*));

    for (int i = 0; i < LETTERE; i++) {
        matrice[i] = (char*)malloc(BUFSIZE * sizeof(char));
        if (matrice[i] == NULL) exit(EXIT_FAILURE);

        // riempo ciascuna riga della matrice con i caratteri del file tabella
        fgets(matrice[i], BUFSIZE, fp);
    }
	//FILE * f = fopen("tabella","r"); // <- mia implementazione
	//for(int i=0; i<LETTERE; i++){
	//	fscanf(f,"%s\n",matrice[i]);
	//}
	//fclose(f);
    return matrice;
}

void stampa_matrice(char** matrice) {
    for (int i = 0; i < LETTERE; i++)
        for (int j = 0; matrice[i][j]; j++)  // continua finche' non trova "\0"
            printf("%c", matrice[i][j]);

	//for(int i=0; i < LETTERE; i++){  // <- Mia implementazione del metodo
	//	printf("%s\n",matrice[i]);	
	//}

}

void free_matrice(char** matrice) {
    for (int i = 0; i < LETTERE; i++)
        free(matrice[i]);
    free(matrice);
}

void get_keyboard_input(char * input){
	int errore;
	do {
		printf("Inserisci una lettera in morse: ");
		scanf("%s", input);
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] != '-' && input[i] != '.' && input[i] != '$') {
				printf("Hai inserito caratteri non ammessi!\nReinserisci\n");
				errore = 1;
				break;
			}
			errore = 0;
		}
	} while (errore);
}

