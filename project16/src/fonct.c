#include <stdio.h>
#include <stdlib.h>
#include"fonct.h"
/*enum
{ 
  MARQUE,
  COLUMNS
  
};
void valeur_cap(capteur v)
{

//capteur v;
FILE* f;
FILE* g;
f=fopen("humidite.txt","r");
g=fopen("iden.txt","w+");
if(f!=NULL)
{
while(fscanf(f," %s %s %s %s %s  \n",v.iden, v.jour,v.mois,v.annee,v.valeur)!=EOF)
          
       if (strcmp(v.valeur,"366.00")==0)
       {fprintf(g," %s   \n",v.iden);}
}
fclose(f);
fclose(g);
}
void marque1()
{
capteur y;
capteur v;
FILE* f;
FILE* g;
FILE* k;
f=fopen("capteur.txt","r");
g=fopen("iden.txt","r");
k=fopen("marq.txt","w+");
if(f!=NULL)
{while(fscanf(g," %s    \n",v.iden)!=EOF)
	{while(fscanf(f," %s %s %s   \n",y.iden, y.nom,y.marque)!=EOF)
		if (strcmp(v.iden,y.iden)==0) 
		{fprintf(k,"%s \n",y.marque);} 
   	}
}
fclose(f);
fclose(g);
fclose(k);
}



void afficher_capt(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char marque[30];
    

    store=NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

       
        
    }
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING);
    f =fopen("marq.txt","r");
    if(f==NULL)
    {

        return;
    }
    else
    {
        f =fopen("marque.txt","a+");
        while(fscanf(f,"  %s",marque)!=EOF)
        {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,MARQUE,marque ,-1);
        }

        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
*/        


