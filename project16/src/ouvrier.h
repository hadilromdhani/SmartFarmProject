#include<gtk/gtk.h>

/*typedef struct{
int jour;
int mois;
int annee;
}Date ;
*/
typedef struct{
char cin[20];
int jour;
int mois;
int annee;
int p;
}presence;

typedef struct{
char nom[20];
char prenom[20];
char specialite[20];
char cin[20];
char adresse[20];
char ntel[20];
char sexe[30];
char ville[30];
}ouvrier;

void ajouter_ouvrier(ouvrier o);
void supprimer_ouv(ouvrier o1);
void modifier_ouvrier(ouvrier o);
ouvrier rechercher_ouvrier(ouvrier o);
void afficher_ouvrier(GtkWidget *liste);
void ajouter_presence(presence a);
void afficher_tab(GtkWidget *liste);
float taux_absenteisme(int mois,int annee);





