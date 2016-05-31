#include <stdio.h>
#include "sdd.h"

int taille(intervalle i){
	return (i.fin - i.debut);
}

void afficherListe(intervalle t[], int n){
	int i = 0;
	while(i < n){
		printf("intervalle %d : %d  à %d , %c \n", i, t[i].debut, t[i].fin, t[i].id);
		i++;
	}
}

int maximumListe(intervalle t[], int n){
	  int i = 0;
	  int valIndice = 0;
 	  int indice;
          while(i < n){
                if((t[i].fin - t[i].debut) > valIndice){
			valIndice = (t[i].fin - t[i].debut);
			indice = i;
		}
                  i++;
          }
	return indice;
}

void trierListe(intervalle t[], int n) {
	int boolean;
	int cpt;
	intervalle tmp;
	do {
	  boolean = 0;
	  for(cpt=0; cpt<n-1; cpt++){
	    if(taille(t[cpt]) > taille(t[cpt+1])){
	       tmp=t[cpt];
	       t[cpt]=t[cpt+1];
	       t[cpt+1]=tmp;
	       boolean = 1;
            }
	  }
	} while(boolean==1);
}

void trierListe2(intervalle t[], int ordre[], int n){
	int boolean;
	int cpt;
	int tmp;
	for(cpt=0; cpt<n; cpt++){
	  ordre[cpt]=cpt;
	}
	cpt=0;
	do {
	   boolean = 0;
	   for(cpt=0; cpt<n-1; cpt++){
	      if(taille(t[ordre[cpt]]) > taille(t[ordre[cpt+1]])){
	        tmp=ordre[cpt];
		ordre[cpt]=ordre[cpt+1];
		ordre[cpt+1]=tmp;
		boolean = 1;
	      }
	   }
	 }while(boolean==1);
}

void afficherListe2(intervalle t[],int ordre[], int n) {
     int i,j;
     for(i=0; i<n; i++){    	  
        printf("debut : %d - fin : %d - id : %c\n",t[ordre[i]].debut,t[ordre[i]].fin,t[ordre[i]].id);
     }   
     printf("\n");
}
