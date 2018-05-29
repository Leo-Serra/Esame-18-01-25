#ifndef ORDINI_H
#define ORDINI_H

#include "element.h"
#include "list.h"

extern Ordine * leggiTutti (char *, int *);

extern void stampaOrdine (Ordine *, int);

extern void ordina(Ordine *, int);

extern list leggiCosti(char *);

extern void fatture(Ordine *, int, list);

extern void stampaLista (list);

#endif /*ORDINI_H*/