#include <gtk/gtk.h>

typedef struct {
int jj;
int mm;
int aa;
}date;
typedef struct {
char id[10];
char type[10] ;
char sexe[10] ;
char zone[10];				
date ddn;

}animal;

void ajouter_animal(animal a) ;
void modifier_animal(char id[],animal a) ;
void supprimer_animal(char id[]) ;
animal chercher_animal (char id[] ) ; 
void afficher_animal(GtkWidget *liste);
int calculer_animal( char typeCal[]);
int verif(char login[], char pasw[]);
