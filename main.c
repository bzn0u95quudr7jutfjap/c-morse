#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8
#define LETTERE 26

int mainOriginale(char*);
int mainCicloDoppio(char*);
int mainAlbero(char*);
int mainAlberoDoppio(char*);
int mainHash(char *);

int main(int argc, char ** argv){
	int (*mains[5])(char *) = { mainOriginale, mainCicloDoppio, mainAlbero, mainAlberoDoppio, mainHash };
	if(argc == 3){
		return mains[atoi(argv[1])](argv[2]);
	}else{
		printf("USAGE\n");
		printf("./bin <int> <str>\n\n");
		printf("str -> la lettera in morse\n\n");
		printf("int -> metodo di risoluzione\n");
		printf("\t0: 3 cicli innestati (originale)\n");
		printf("\t1: 2 cicli innestati (l'originale ma senza un ciclo innestato)\n");
		printf("\t2: 1 ciclo con un albero\n");
		printf("\t3: 1 ciclo con 2 alberi\n");
		printf("\t4: mappa <- rotto, non fa niente\n");
		printf("\n");
		return 1;
	}
}
