#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8
#define LETTERE 26

char** crea_matrice_conversione(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char** matrice = (char**)malloc(LETTERE * sizeof(char*));

    for (int i = 0; i < LETTERE; i++) {
        matrice[i] = (char*)malloc(BUFSIZE * sizeof(char));
        if (matrice[i] == NULL) exit(EXIT_FAILURE);

        // riempo ciascuna riga della matrice con i caratteri del file tabella
        fgets(matrice[i], BUFSIZE, fp);
    }
    return matrice;
}

void stampa_matrice(char** matrice) {
    for (int i = 0; i < LETTERE; i++)
        for (int j = 0; matrice[i][j]; j++)  // continua finche' non trova "\0"
            printf("%c", matrice[i][j]);
}

void free_matrice(char** matrice) {
    for (int i = 0; i < LETTERE; i++)
        free(matrice[i]);
    free(matrice);
}

int main(){
	char** matrice = crea_matrice_conversione("tabella");
	// stampa_matrice(matrice);

	char input[BUFSIZE];
	int dimInput = 0;
	int k = 1;

	int errore;
	do {
		printf("Inserisci una lettera in morse: ");
		//scanf("%s", input);
		strcpy(input,".$");
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] != '-' && input[i] != '.' && input[i] != '$') {
				printf("Hai inserito caratteri non ammessi!\nReinserisci\n");
				errore = 1;
				break;
			}
			errore = 0;
		}
	} while (errore);

	for (int i = 0; input[i] != '\0'; i++, dimInput++) {
	};
	printf("\nInput: %s\nDimInput: %d\n\n", input, dimInput);

	for (int j = 0; j < dimInput; j++) {
		for (int i = 0; i < LETTERE; i++) {
			for (int l = 0; l < j + 1; l++) {
				if (input[l] != matrice[i][k + l]) break;
				if (l == j) printf("%c", matrice[i][0]);
			}
		}
		printf("\n");
	}
	
	free_matrice(matrice);
	//free(matrice);
    //exit(EXIT_SUCCESS);
	return 0;
}
