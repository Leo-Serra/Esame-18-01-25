#include "ordini.h"

int dimFile (FILE *fp) {

	int result = 0;
	Ordine tmp;

	while (fscanf(fp, "%d/%d/%d %s %s %d %d", &(tmp.data.year), &(tmp.data.month), &(tmp.data.day), tmp.type, tmp.taste, &(tmp.num), &(tmp.id)) == 7) {

		result++;
	}

	rewind(fp);
	return result;
}

Ordine * leggiTutti (char * fileName, int *dim) {

	FILE *fp = fopen(fileName, "r");
	Ordine * result = NULL;
	Ordine tmp;
	int i;

	*dim = 0;
	
	if (fp == NULL) {

		printf("Impossibile aprire il file!");
		return result;	
	}

	*dim = dimFile(fp);

	result = (Ordine*)malloc(sizeof(Ordine) * (*dim));

	for (i = 0; i < *dim; i++) {

		if (fscanf(fp, "%d/%d/%d %s %s %d %d", &(tmp.data.year), &(tmp.data.month), &(tmp.data.day), tmp.type, tmp.taste, &(tmp.num), &(tmp.id)) == 7) {

			result[i] = tmp;
		}
	}

	fclose(fp);
	return result;
}

void stampaOrdine (Ordine *v, int dim) {

	int i;

	for (i = 0; i < dim; i++) {
		
		printf("Data: %d/%d/%d,", v[i].data.day, v[i].data.month, v[i].data.year);
		printf("tipo: %s, gusto: %s, quantita': %d, cliente: %d.\n",  v[i].type, v[i].taste, v[i].num, v[i].id);
	}
}

void ordina(Ordine * v, int dim) {

	Ordine * tmp = (Ordine *)malloc(sizeof(Ordine) * dim);
	mergeSort(v, 0, dim-1, tmp);
	free(tmp);
}

list leggiCosti (char *fileName) {	FILE *fp = fopen(fileName, "r");	list result = emptylist();	Costi tmp;	if (fp == NULL) {		printf("Impossibile aprire il file!");		return result;	}	while (fscanf(fp, "%s%s%f", tmp.type, tmp.taste, &(tmp.price)) == 3) {			result = cons(tmp, result);	}	fclose(fp);	return result;}void stampaLista (list l) {	while (!empty(l)) {		printf("tipo: %s, gusto: %s, prezzo: %f\n", l->value.type, l->value.taste, l->value.price);		l = l->next;	}}float totOrdine (Ordine o, list l) {	float result = 0;	int ctrl = FALSE;	while (!empty(l) && !ctrl) {		if (strcmp(o.type,l->value.type) == 0 && strcmp(o.taste, l->value.taste) == 0) { ctrl = TRUE; }		else { l = l->next; }	}	if (ctrl) { result = o.num * l->value.price; }	return result;}void fatture(Ordine * v, int dim, list costi) {	Ordine tmp = v[0];	float tot = 0;	int i = 0;	if (dim <= 0) { 				printf("Ordine vuoto!");		return;	}	ordina(v, dim);	tot = totOrdine(tmp, costi);	for (i = 1; i < dim; i++) {		if (v[i].data.year != tmp.data.year || v[i].data.month != tmp.data.month || v[i].id != tmp.id) {			printf("Cliente: %d, mese: %d/%d, totale: %f.\n", tmp.id, tmp.data.month, tmp.data.year, tot);			tmp = v[i];			tot = totOrdine(v[i], costi);		}		else { tot = tot + totOrdine(v[i], costi);}	}	printf("Cliente: %d, mese: %d/%d, totale: %f.\n", tmp.id, tmp.data.month, tmp.data.year, tot);	return;}