#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8
#define LETTERE 26
#define LOW 0
#define HIGH LETTERE-1

typedef struct hash_struct{
	char c;
	double hash;
} HashObj;
void printHashObj(HashObj * ho){
	printf("{%c,%f}\n",ho->c, ho->hash);
}
HashObj stackNewHashObj(char c, double h){
	HashObj o;
	o.c=c;
	o.hash = h;
	return o;
}
void moveRange(double * low, double * high, int b){
	double m = ((*high)+(*low))/2;
	if(b){ *low = m; }
	else{ *high = m; }
}
double calculateHashMorse(double low, double high, char * idx, int idxlen){
	for(int i= 0; i < idxlen; i++){
		moveRange(&low,&high,idx[i]=='-');
	}
	double m = (high+low)/2;
	return m;
}
void printRec(HashObj ** map, int low, int high){
}

int mainHash(char *input){
	//HashObj linemap[LETTERE];
	//double min,max;
	//{
	//	FILE * f = fopen("tabella","r");
	//	for(int i=0; i<LETTERE; i++){
	//		char tmp[BUFSIZE];
	//		fscanf(f,"%s\n",tmp);
	//		int len = strlen(tmp);
	//		linemap[i]=stackNewHashObj(tmp[0],calculateHashMorse(LOW,HIGH,tmp+1,len-2));
	//		double h = linemap[i].hash;
	//		if(i == 0){
	//			min = h;
	//			max = h;
	//		}else{
	//			min = min < h ? min : h;
	//			max = max > h ? max : h;
	//		}
	//	}
	//	fclose(f);
	//}
	//for(int i = 0; i<LETTERE; i++){
	//	printHashObj(&linemap[i]);
	//}

	//int len=(int)(max/min);;
	//HashObj * map[(int)(max/min)];
	//for(int i=0; i < len; i++){
	//	map[i]  = NULL;
	//}
	//for(int i = 0; i < LETTERE; i++){
	//	int idx = (int)(linemap[i].hash/min)-1;
	//	map[idx] = &(linemap[i]);
	//}

	//int dimInput = 0;
	//dimInput = strlen(input);
	//printf("\nInput: '%s'\nDimInput: '%d'\n\n", input, dimInput);
 	//int low=LOW, high=HIGH;
	//double m = ( HIGH + LOW ) / 2;
	//char out[len];
	//for(int i=0; i<dimInput; i++){
	//	if(input[i] == '-'){
	//		high = (int)m;
	//	}else{
	//		low = (int)m;
	//	}
	//}
	return 0;
}
