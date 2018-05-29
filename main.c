#include "ordini.h"

int main (void) {

	char *fileName = "ordini.txt";
	char *fileName1 = "costi.txt";
	int dim;
	Ordine * result;
	list caccola = emptylist();

	result = leggiTutti(fileName, &dim);
	stampaOrdine(result, dim);
	ordina(result, dim);
	printf("\nArray ordinato:______________________________________________\n");
	stampaOrdine(result, dim);


	printf("\nlista:______________________________________________\n");
	caccola = leggiCosti(fileName1);
	stampaLista(caccola);

	printf("\nFattura:________________________________________________\n");
	fatture(result, dim, caccola);

	free(result);
	return 0;
}