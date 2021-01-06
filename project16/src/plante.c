#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "plante.h"



enum
{ NOM,
  TYPE,
  DATE1,
  DATE2,
  IDEN,
  PLACE,
  QUANTITE,
  CARACTERE,
  COLUMNS
};

void ajouter_plante(plante o)
{
FILE * f;

f=fopen("plante.txt","a+");

  if(f!=NULL)
   {
   fprintf(f," %s %s %s %s %s %s %s %s\n",o.nom,o.type,o.date1,o.date2 ,o.iden, o.place ,o.quantite, o.caractere);
	fclose(f);

   }

}



void modifier_plante(plante o)
{
 
plante v;
FILE * f;
FILE * aux;
aux=NULL;
f=fopen("plante.txt","r");
aux=fopen("tmp.txt","w+");
if(f!=NULL)
{
while(fscanf(f," %s %s %s %s  %s %s %s %s %s \n",v.nom,v.type,v.date1, v.date2,v.iden, v.place,v.quantite ,v.caractere)!=EOF)
 {
	if(strcmp(o.iden,v.iden)==0) v=o;
          

       fprintf(aux," %s %s %s %s  %s %s %s %s  \n",v.nom,v.type,v.date1,v.date2,v.iden, v.place, v.quantite , v.caractere);
 }         

 fclose(aux);
 fclose(f);

	remove("plante.txt");
      rename("tmp.txt","plante.txt");
}}



void supprimer_plante(plante o1)
{
plante o;

//char cin[30];	
FILE * f;
FILE * g;
f=fopen("plante.txt","r");
g=fopen("tmp.txt","w");

if(f!=NULL )
   {
while (fscanf(f," %s %s %s %s %s %s %s  %s\n",o.nom,o.type,o.date1,o.date2,o.iden,o.place,o.quantite,o.caractere)!=EOF)
  {
if (strcmp(o.iden,o1.iden)!=0 )
 fprintf(g," %s %s %s %s %s %s %s %s\n",o.nom,o.type,o.date1, o.date2,o.iden , o.place ,o.quantite, o.caractere);
 } 
fclose(f);
fclose(g);
}
remove("plante.txt");
rename("tmp.txt","plante.txt");
}

int rechercher_plante( plante v)
{
plante o;
FILE * f;
FILE * g;
f=fopen("plante.txt","r");
g=fopen("rechercher.txt","w+");
if(f!=NULL )
   {
while (fscanf(f," %s %s %s %s %s %s %s  %s\n",o.nom,o.type,o.date1,o.date2,o.iden,o.place,o.quantite,o.caractere)!=EOF)
if (strcmp(o.iden,v.iden)==0 )
 fprintf(g," %s %s %s %s %s %s %s %s\n",o.nom,o.type,o.date1, o.date2,o.iden,o.place,o.quantite,o.caractere );
 } 
fclose(f);
fclose(g);	
}

void afficher_plante(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char nom[30];
    char type[30];
    char date1[30];
    char date2[30];
    char iden[30];
    char place[30];
    char quantite[30];
    char caractere[30];

    store=NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("date1",renderer,"text",DATE1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("date2",renderer,"text",DATE2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("iden",renderer,"text",IDEN,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("place",renderer,"text",PLACE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
        
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
        
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("caractere",renderer,"text",CARACTERE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
        
    }
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f =fopen("plante.txt","r");
    if(f==NULL)
    {

        return;
    }
    else
    {
        f =fopen("plante.txt","a+");
        while(fscanf(f," %s %s %s %s %s %s %s %s",nom,type,date1,date2,iden,place, quantite, caractere)!=EOF)
        {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOM,nom,TYPE,type,DATE1,date1,DATE2,date2,IDEN,iden,PLACE,place,QUANTITE,quantite, CARACTERE,caractere ,-1);
        }

        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
enum
{ NOM1,
  TYPE1,
  DATE11,
  DATE21,
  IDEN1,
  PLACE1,
  QUANTITE1,
  CARACTERE1,
  COLUMNS1
};

void afficher_rechercher1(GtkWidget *liste1)
{
    GtkCellRenderer *renderer1;
    GtkTreeViewColumn *column1;
    GtkTreeIter iter1;
    GtkListStore *store;

    char nom1[30];
    char type1[30];
    char date11[30];
    char date21[30];
    char iden1[30];
    char place1[30];
    char quantite1[30];
    char caractere1[30];

    store=NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste1);
    if(store==NULL)
    {
        renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("nom1",renderer1,"text",NOM1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);

        renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("type1",renderer1,"text",TYPE1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);

        renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("date11",renderer1,"text",DATE11,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);

        renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("date21",renderer1,"text",DATE21,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);

        renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("iden1",renderer1,"text",IDEN1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);

	renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("place1",renderer1,"text",PLACE1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);
        
	renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("quantite1",renderer1,"text",QUANTITE1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);
        
	renderer1=gtk_cell_renderer_text_new();
        column1=gtk_tree_view_column_new_with_attributes("caractere1",renderer1,"text",CARACTERE1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste1),column1);
        
    }
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f =fopen("rechercher.txt","r");
    if(f==NULL)
    {

        return;
    }
    else
    {
        f =fopen("rechercher.txt","a+");
        while(fscanf(f," %s %s %s %s %s %s %s %s",nom1,type1,date11,date21,iden1,place1, quantite1, caractere1)!=EOF)
        {
            gtk_list_store_append(store,&iter1);
            gtk_list_store_set(store,&iter1,NOM1,nom1,TYPE1,type1,DATE11,date11,DATE21,date21,IDEN1,iden1,PLACE1,place1,QUANTITE1,quantite1, CARACTERE1,caractere1 ,-1);
        }

        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste1),GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}


