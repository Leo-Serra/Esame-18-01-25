#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h" 

list emptylist(void) { /* costruttore lista vuota */
 return NULL;
}

boolean empty(list l) { /* verifica se lista vuota */
 return (l==NULL);
}

list cons(element e, list l) {
 list t; /* costruttore che aggiunge in testa alla lista */
 t=(list)malloc(sizeof(item));
 t->value=e;
 t->next=l;
 return(t);
}

element head(list l) { /* selettore testa lista */
 if (empty(l)) exit(-2);
 else return (l->value);
}

list tail(list l) { /* selettore coda lista */
 if (empty(l)) exit(-1);
 else return (l->next);
} 

void freelist(list l) {
 if (empty(l))
 return;
 else {
 freelist(tail(l));
 free(l);
 }
 return; 
}

int equals (element e1, element e2) {

	return 0;
}

int member(element el, list l) {
 
	int result = 0;
 
	while (!empty(l) && !result) {
	
		result = equals(el, head(l));
		if (!result)
 
			l = tail(l);
	}
 
	return result;
} 
