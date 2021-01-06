#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "ouvrier.h"



enum
{ NOM,
  PRENOM,
  CIN,
  ADRESSE,
  SPECIALITE,
  NTEL,
  SEXE,
  VILLE,

  COLUMNS
};

/*enum
{ ID,
  JOUR,
  MOIS,
  ANNEE,
  P,
  COLUMNS1
};
*/
void ajouter_ouvrier(ouvrier o)
{
FILE * f;

f=fopen("Employe.txt","a+");

  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s %s %s \n",o.nom,o.prenom,o.cin,o.adresse,o.specialite,o.ntel,o.sexe,o.ville);
	fclose(f);

   }

}



void modifier_ouvrier(ouvrier o1)
{
 
ouvrier v;
FILE * f;
FILE * aux;
aux=NULL;
f=fopen("Employe.txt","r");
aux=fopen("tmp.txt","w+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",v.nom,v.prenom,v.cin,v.adresse,v.specialite,v.ntel,v.sexe,v.ville)!=EOF)
 {
	if(strcmp(o1.cin,v.cin)==0) v=o1;
          

       fprintf(aux,"%s %s %s %s %s %s %s %s \n",v.nom,v.prenom,v.cin,v.adresse,v.specialite,v.ntel,v.sexe,v.ville);
 }         
/*else
       {
fprintf(aux,"%s %s %s %s %s %s  \n",o.nom,o.prenom,o.cin,o.adresse,o.specialite,o.ntel);

       }*/
//}
 fclose(aux);
 fclose(f);
//}
	remove("Employe.txt");
      rename("tmp.txt","Employe.txt");
}}



void supprimer_ouv(ouvrier o1)
{
ouvrier o;

//char cin[30];	
FILE * f;
FILE * g;
f=fopen("Employe.txt","r");
g=fopen("tmp.txt","w");

if(f!=NULL )
   {
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",o.nom,o.prenom,o.cin,o.adresse,o.specialite,o.ntel,o.sexe,o.ville)!=EOF)
  {
if (strcmp(o.cin,o1.cin)!=0 )
 fprintf(g,"%s %s %s %s %s %s %s %s \n",o.nom,o.prenom,o.cin,o.adresse,o.specialite,o.ntel,o.sexe,o.ville);
 } 
fclose(f);
fclose(g);
}
remove("Employe.txt");
rename("tmp.txt","Employe.txt");
}


void afficher_ouvrier(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char nom[30];
    char prenom[30];
    char cin[30];
    char adresse[30];
    char specialite[30];
    char ntel[30];
    char sexe[30];
    char ville[30];
    store=NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("specialite",renderer,"text",SPECIALITE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("ntel",renderer,"text",NTEL,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("ville",renderer,"text",VILLE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f =fopen("Employe.txt","r");
    if(f==NULL)
    {

        return;
    }
    else
    {
        f =fopen("Employe.txt","a+");
        while(fscanf(f,"%s %s %s %s %s %s %s %s ",nom,prenom,cin,adresse,specialite,ntel,sexe,ville)!=EOF)
        {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,ADRESSE,adresse,SPECIALITE,specialite,NTEL,ntel,SEXE,sexe,VILLE,ville ,-1);
        }

        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}

void ajouter_presence(presence a)
{
FILE * g;

g= fopen("presence.txt","a");

  if(g!=NULL)
   {
   fprintf(g,"%s %d %d %d %d \n",a.cin,a.jour,a.mois,a.annee,a.p);
	fclose(g);

   }

}


ouvrier rechercher_ouvrier(ouvrier o)
{
ouvrier o1;
//char cin[20];
FILE * f;
//strcpy(o.cin,"1");
f=fopen("Employe.txt","r");

if(f!=NULL )
   {
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",o1.nom,o1.prenom,o1.cin,o1.adresse,o1.specialite,o1.ntel,o1.sexe,o1.ville)!=EOF)
  {
     if (strcmp(o.cin,o1.cin)==0 )
       {
         return o1;
       } 
  }

fclose(f);
}
return o1;
}
//fprintf(f,"%s %s %s %s %s %s %s %s \n",o.nom,o.prenom,o.cin,o.adresse,o.specialite,o.ntel,o.sexe,o.ville);


float taux_absenteisme(int mois ,int annee)
{

ouvrier o;
presence a;
//int mois;
//int annee;
float taux;
int nbabs;
int nbo;
nbabs=0;
nbo=0;
FILE * f;
FILE * g;
f=fopen("Employe.txt","r");
g=fopen("presence.txt","r");

if((f!=NULL )||(g!=NULL))
  {
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",o.nom,o.prenom,o.cin,o.adresse,o.specialite,o.ntel,o.sexe,o.ville)!=EOF)
  {
 nbo++;
  }

while(fscanf(g,"%s %d %d %d %d \n",a.cin,&a.jour,&a.mois,&a.annee,&a.p)!=EOF)
   {
 if((mois==a.mois) && (annee==a.annee) && (a.p==0))
      nbabs++;
   }
taux= (float)nbabs/(nbo*30)*100;
fclose(f);
fclose(g);
}
//taux=(float) nbabs*30/nbo*100;
return taux;

}






