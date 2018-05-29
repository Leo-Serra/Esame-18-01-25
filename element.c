#include "element.h"

int compareData (Data d1, Data d2) {

	int year = d1.year - d2.year;
	int month = d1.month - d2.month;
	int day = d1.day - d2.day;

	if (year == 0) {

		if (month == 0) {

			return day;
		}
		return month;
	}

	return year;
}

int compare (Ordine o1, Ordine o2) {

	int tmp = o1.id - o2.id;

	if (tmp == 0) { return compareData(o1.data, o2.data); }

	return tmp;
}

void merge (Ordine v[], int i1, int i2, int fine, Ordine vout[]) {
 
	int i=i1, j=i2, k=i1;
 
	while ( i <= i2-1 && j <= fine ) {
 
		if (compare(v[i], v[j])<0) { vout[k] = v[i++]; } 
		else { vout[k] = v[j++]; } 
		k++;
	}
 
	while (i<=i2-1) { vout[k] = v[i++]; k++; }
	while (j<=fine) { vout[k] = v[j++]; k++; }
	for (i=i1; i<=fine; i++) v[i] = vout[i];
}

void mergeSort (Ordine v[], int first, int last, Ordine vout[]) {

	int mid;
 
	if ( first < last ) {
	
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid+1, last, vout);
		merge(v, first, mid+1, last, vout);
	}
} 