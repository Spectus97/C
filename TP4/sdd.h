#ifndef SDD_H_INCLUDED
#define SDD_H_INCLUDED

#define TAILLE 100


typedef struct {
	int  debut ;
	int  fin ;
	char id ;
} intervalle ;

typedef struct cell
{
  intervalle *i;
  struct cell * next;
} cell;

extern int taille(intervalle i) ;
extern void afficherListe(intervalle t[], int n) ;
extern int maximumListe(intervalle t[], int n) ;
extern void trierListe(intervalle t[], int n) ;
extern void trierListe2(intervalle t[], int ordre[], int n) ;
extern void afficherListe2(intervalle t[], int ordre[], int n) ;
extern void trierListe3(intervalle* t[], int n);
extern void afficherListe3(intervalle* t[], int n);
cell *new_cell(intervalle *i, cell *next);
cell *tab2liste (intervalle *t[], int n);
extern void afficherListe4(cell* c);
cell *insert(cell *c, cell *l);
extern cell* trierListe4(cell* c);
#endif // SDD_H_INCLUDED
