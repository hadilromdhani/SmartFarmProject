#include<gtk/gtk.h>

typedef struct{
int jour;
int mois;
int annee;
}Date ;
typedef struct{
char nom[20];
char type[20];
char date1[20];
char date2[20];
char iden[20];
char place[20];
char  quantite[20];
char caractere[20];

}plante;

void ajouter_plante(plante o);
void supprimer_plante(plante o);
void modifier_plante(plante o);
void afficher_plante(GtkWidget *liste);
int rechercher_plante( plante v);
void afficher_rechercher1(GtkWidget *liste);
