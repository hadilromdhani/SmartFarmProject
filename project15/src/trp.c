#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trp.h"
#include <gtk/gtk.h>

enum
{
EID,
ETYPE,
ESEXE,
EZONE,
EJJ,
EMM,
EAA,

COLUMNS
};


void ajouter_animal(animal a)
{
FILE* f;
f=fopen("troupeaux.txt","a+");
fprintf(f,"%s %s %s %s %d %d %d \n",a.id,a.type,a.sexe,a.zone,a.ddn.jj,a.ddn.mm,a.ddn.aa);
fclose(f);
}


void supprimer_animal(char id[])
{
FILE*f=NULL;
FILE*f1=NULL;
animal a ;
f=fopen("troupeaux.txt","r");

f1=fopen("tmp.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d %d \n",a.id,a.type,a.sexe,a.zone,&a.ddn.jj,&a.ddn.mm,&a.ddn.aa)!=EOF)
{
if(strcmp(id,a.id)!=0)
	fprintf(f1,"%s %s %s %s %d %d %d \n", a.id,a.type,a.sexe,a.zone,a.ddn.jj,a.ddn.mm,a.ddn.aa);
}
fclose(f);
fclose(f1);
remove("troupeaux.txt");
rename("tmp.txt", "troupeaux.txt");
}


void modifier_animal(char id[],animal a)
{
FILE*f=NULL;
FILE*f1=NULL;
animal b ;
f=fopen("troupeaux.txt","r");
f1=fopen("tmp.txt","w+");

while(fscanf(f,"%s %s %s %s %d %d %d \n",b.id,b.type,b.sexe,a.zone,&b.ddn.jj,&b.ddn.mm,&b.ddn.aa)!=EOF){
if(strcmp(id,b.id)!=0)
{
fprintf(f1,"%s %s %s %s %d %d %d \n",b.id,b.type,b.sexe,a.zone,b.ddn.jj,b.ddn.mm,b.ddn.aa); 
}
else 
{
fprintf(f1,"%s %s %s %s %d %d %d \n",a.id,a.type,a.sexe,a.zone,a.ddn.jj,a.ddn.mm,a.ddn.aa);}
}
fclose(f);
fclose(f1);
remove("troupeaux.txt");
rename("tmp.txt", "troupeaux.txt");
}




animal chercher_animal (char id[])
{
FILE*f=NULL;
animal a ;
strcpy(a.id,"-1");
f=fopen("troupeaux.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d \n",a.id,a.type,a.sexe,a.zone,&a.ddn.jj,&a.ddn.mm,&a.ddn.aa)!=EOF)
{
	if(strcmp(id,a.id)==0) 
	{
		return a;
	}
}
return a;
}



void afficher_animal(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[10] ;
char type[10] ;
char sexe[10] ;
char zone[10];
int jj;
int mm;
int aa;

store=NULL;
FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("zone", renderer, "text",EZONE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jj", renderer, "text",EJJ, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mm", renderer, "text",EMM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("aa", renderer, "text",EAA, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f = fopen("troupeaux.txt","r");

if(f==NULL)
{

    return;
}
else
{
f = fopen("troupeaux.txt","a+");
while(fscanf(f,"%s %s %s %s %d %d %d \n", id, type, sexe, zone, &jj, &mm, &aa)!=EOF)
{ 
gtk_list_store_append (store,&iter);
gtk_list_store_set (store, &iter, EID, id, ETYPE, type, ESEXE, sexe, EZONE, zone, EJJ, jj, EMM, mm, EAA, aa, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}


int calculer_animal ( char typeCal[]) 
{
FILE*f=NULL;
animal a ;
int nb;
nb=0;
f=fopen("troupeaux.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d \n",a.id,a.type,a.sexe,a.zone,&a.ddn.jj,&a.ddn.mm,&a.ddn.aa)!=EOF)
{
if(strcmp(typeCal,a.type)==0) 
{
nb++;
}
}
return nb ;
}

int verif(char login[], char pasw[])
{
int trouve;
if (strcmp(login,"admin")==0)
{
trouve=1;}
else
{trouve=0;}
return trouve;
}
