#ifndef ELEMENT_H
#define ELEMENT_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

#define DIM_TYPE 8
#define DIM_TASTE 256

typedef struct Data {

	int year;
	int month;
	int day;

} Data;

typedef struct Ordine {

	Data data;
	char type[DIM_TYPE];
	char taste[DIM_TASTE];
	int num;
	int id;

} Ordine;

typedef struct Costi {

	char type[DIM_TYPE];
	char taste[DIM_TASTE];
	float price;

} Costi;

typedef Costi element;

extern void merge (Ordine v[], int i1, int i2, int fine, Ordine vout[]);

extern void mergeSort (Ordine v[], int first, int last, Ordine vout[]);

extern int compare (Ordine, Ordine);

#endif /*ELEMENT_H*/