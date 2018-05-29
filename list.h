#ifndef LIST_H
#define LIST_H

#include "element.h"

typedef struct list_element {

	element value;
	struct list_element *next;
} item;

typedef item* list;
typedef int boolean;

extern list emptylist (void);

extern boolean empty (list);

extern list cons (element, list);

extern element head (list);

extern list tail (list);

extern void showlist (list l);

extern void freelist (list l); 

extern int member(element, list);

#endif /*LIST_H*/