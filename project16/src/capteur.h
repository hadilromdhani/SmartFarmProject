#include <gtk/gtk.h>
typedef struct{
int jour;
char mois[30];
int annee;
}DateCapt;

typedef struct{
char nom[20];
char marque[20];
char reference[20];
char type[20];
DateCapt dt;
}capteur;


void ajouter_capteur(capteur c);
void afficher_capteur(GtkWidget* treeview1,char*l);
void supprimer_capteur(char *reference);
int Cherchercapteur (GtkWidget* treeview1 ,char l[] ,char *reference);
void modifier_capteur(capteur c);

