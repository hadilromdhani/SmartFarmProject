#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "trp.h"
#include <stdlib.h>
#include <stdio.h>

int radio;
int choix_sexe[]={0,0};
//hadil
void
on_button1_validerAcceuil_clicked      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreAcceuil;
GtkWidget *fenetreMenu;
GtkWidget *login; 
GtkWidget *password;
GtkWidget *output;
GdkColor color;

char user[20];
char pasw[20];
int trouve;
login=lookup_widget (objet_graphique,"entry1_loginAcceuil");
password=lookup_widget (objet_graphique,"entry2_mdpAcceuil");
output=lookup_widget (objet_graphique,"label47_message");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);

if(trouve==1)
{

fenetreAcceuil=lookup_widget(objet_graphique,"acceuil");

gtk_widget_destroy(fenetreAcceuil);

fenetreMenu=lookup_widget(objet_graphique,"menu");
fenetreMenu=create_menu();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreMenu, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreMenu);
}
else
{
gtk_label_set_text(GTK_LABEL(output),"login ou mot de passe incorrect ! ");
}
}


void
on_button2_ouvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}

//hadil
void
on_button3_troupeau_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreMenu;
GdkColor color;

fenetreMenu=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetreMenu);

fenetreGestion=lookup_widget(objet_graphique,"gestionTrp");
fenetreGestion=create_gestionTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestion, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestion);
}


void
on_button4_calendrier_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5_equipement_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_capteurs_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}

//hadil
void
on_button7_calculer_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreCalculer;
GdkColor color;

fenetreGestion=lookup_widget(objet_graphique,"gestionTrp");

gtk_widget_destroy(fenetreGestion);

fenetreCalculer=lookup_widget(objet_graphique,"calculerTrp");
fenetreCalculer=create_calculerTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreCalculer, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreCalculer);
}

//hadil
void
on_radiobutton1_male_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{radio=1;}
}

//hadil
void
on_radiobutton2_femelle_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{radio=2;}
}

//hadil
void
on_checkbutton2_zoneB_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_sexe[0]=1;}
}

//hadil
void
on_checkbutton1_zoneA_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_sexe[1]=1;}
}

//hadil
void
on_button8_ajouter_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *combobox2;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *checkbox1;
GtkWidget *checkbox2;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;

animal a;

identifiant=lookup_widget(objet_graphique, "entry3_id");
combobox2=lookup_widget(objet_graphique, "combobox1_type");
spinbutton1=lookup_widget(objet_graphique, "spinbutton1_jj");
spinbutton2=lookup_widget(objet_graphique, "spinbutton2_mm");
spinbutton3=lookup_widget(objet_graphique, "spinbutton3_aa");

strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(a.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
a.ddn.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
a.ddn.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));
a.ddn.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));

if(radio==1)
{strcpy(a.sexe,"Male");}
else if(radio==2)
{strcpy(a.sexe,"Femelle");}

if(choix_sexe[0]==1)
{strcpy(a.zone,"ZoneA");}
else if(choix_sexe[1]==1)
{strcpy(a.zone,"ZoneB");}

ajouter_animal(a);
}

//hadil
void
on_button9_modifier_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *combobox2;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *checkbox1;
GtkWidget *checkbox2;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;

animal a;

identifiant=lookup_widget(objet_graphique, "entry3_id");
combobox2=lookup_widget(objet_graphique, "combobox1_type");
spinbutton1=lookup_widget(objet_graphique, "spinbutton1_jj");
spinbutton2=lookup_widget(objet_graphique, "spinbutton2_mm");
spinbutton3=lookup_widget(objet_graphique, "spinbutton3_aa");

strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(a.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
a.ddn.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
a.ddn.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));
a.ddn.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));

if(radio==1)
{strcpy(a.sexe,"Male");}
else if(radio==2)
{strcpy(a.sexe,"Femelle");}

if(choix_sexe[0]==1)
{strcpy(a.zone,"ZoneA");}
else if(choix_sexe[1]==1)
{strcpy(a.zone,"ZoneB");}


modifier_animal(a.id,a);
}

//hadil
void
on_button10_supprimer_clicked          (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreSupprimer;
GdkColor color;
fenetreGestion=lookup_widget(object,"gestionTrp");

gtk_widget_destroy(fenetreGestion);

fenetreSupprimer=lookup_widget(object,"supprimerTrp");
fenetreSupprimer=create_supprimerTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreSupprimer, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreSupprimer);
}

//hadil
void
on_button11_chercher_clicked           (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreChercher;
GdkColor color;
fenetreGestion=lookup_widget(object,"gestionTrp");

gtk_widget_destroy(fenetreGestion);

fenetreChercher=lookup_widget(object,"chercherTrp");
fenetreChercher=create_chercherTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreChercher, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreChercher);
}

//hadil
void
on_button12_afficher_clicked           (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreAfficher;
GtkWidget *treeview;
GdkColor color;
fenetreGestion=lookup_widget(object,"gestionTrp");

gtk_widget_destroy(fenetreGestion);

fenetreAfficher=lookup_widget(object,"afficherTrp");
fenetreAfficher=create_afficherTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreAfficher, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreAfficher);

treeview=lookup_widget(fenetreAfficher,"treeview1");

afficher_animal(treeview);
}

//hadil
void
on_button13_confirmerSupp_clicked      (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *fenetreSupprimer;
GtkWidget *fenetreGestion;
GdkColor color;
char id[10];

identifiant=lookup_widget(object, "entry4_idSupp");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(identifiant)));

supprimer_animal(id);

fenetreSupprimer=lookup_widget(object,"supprimerTrp");

gtk_widget_destroy(fenetreSupprimer);

fenetreGestion=lookup_widget(object,"gestionTrp");
fenetreGestion=create_gestionTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestion, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestion);
}

//hadil
void
on_button14_entrerCher_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *sortie1;
GtkWidget *sortie2;
GtkWidget *sortie3;
GtkWidget *sortie4;
GtkWidget *sortie5;
GtkWidget *sortie6;
GtkWidget *identifiant;


char id[10];
char jour[3],mois[3], annee[5];
animal a;

identifiant=lookup_widget(objet_graphique, "entry5_idCher");
sortie1=lookup_widget(objet_graphique, "label29_PtypeCher");
sortie2=lookup_widget(objet_graphique, "label31_PsexeCher");
sortie3=lookup_widget(objet_graphique, "label33_PzoneCher");
sortie4=lookup_widget(objet_graphique, "label35_jjCher");
sortie5=lookup_widget(objet_graphique, "label36_mmCher");
sortie6=lookup_widget(objet_graphique, "label37_aaCher");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(identifiant)));

a=chercher_animal(id);

gtk_label_set_text(GTK_LABEL(sortie1),a.type);
gtk_label_set_text(GTK_LABEL(sortie2),a.sexe);
gtk_label_set_text(GTK_LABEL(sortie3),a.zone);
//conversion des entiers en string
sprintf(jour,"%d",a.ddn.jj);
sprintf(mois,"%d",a.ddn.mm);
sprintf(annee,"%d",a.ddn.aa);

gtk_label_set_text(GTK_LABEL(sortie4),jour);
gtk_label_set_text(GTK_LABEL(sortie5),mois);
gtk_label_set_text(GTK_LABEL(sortie6),annee);
}

//hadil
void
on_button15_quitterCher_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreChercher;
GtkWidget *fenetreGestion;
GdkColor color;
fenetreChercher=lookup_widget(objet_graphique,"chercherTrp");

gtk_widget_destroy(fenetreChercher);

fenetreGestion=lookup_widget(objet_graphique,"gestionTrp");
fenetreGestion=create_gestionTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestion, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestion);
}

//hadil
void
on_button17_quitterCal_clicked         (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreCalculer;
GdkColor color;
fenetreCalculer=lookup_widget(object,"calculerTrp");

gtk_widget_destroy(fenetreCalculer);

fenetreGestion=lookup_widget(object,"gestionTrp");
fenetreGestion=create_gestionTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestion, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestion);
}

//hadil
void
on_button16_entrerCal_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *sortie;

char type[10];
int nbr;
char cnbr[10];

combobox1=lookup_widget(objet_graphique, "combobox2_typeCal");
sortie=lookup_widget(objet_graphique, "label42_resCal");
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

nbr=calculer_animal(type);
sprintf(cnbr,"%d",nbr);

gtk_label_set_text(GTK_LABEL(sortie),cnbr);
}

//hadil
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* type;
gchar* sexe;
gchar* zone;
gint* jj;
gint* mm;
gint* aa;


animal a;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path)) 
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &type, 2, &sexe, 3, &zone, 4, &jj, 5, &mm, 6, &aa, -1);

strcpy(a.id,id);
strcpy(a.type,type);
strcpy(a.sexe,sexe);
strcpy(a.zone,zone);
a.ddn.jj=jj;
a.ddn.mm=mm;
a.ddn.aa=aa;

supprimer_animal(a.id);

afficher_animal(treeview);
}
}

//hadil
void
on_button18_retourAff_clicked          (GtkButton       *object,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreAfficher;
GdkColor color;
fenetreAfficher=lookup_widget(object,"afficherTrp");

gtk_widget_destroy(fenetreAfficher);

fenetreGestion=lookup_widget(object,"gestionTrp");
fenetreGestion=create_gestionTrp();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestion, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestion);
}


void
on_button1_retourGestion_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreMenu;
GtkWidget *fenetreGestion;
fenetreGestion=lookup_widget(objet_graphique,"gestionTrp");

gtk_widget_destroy(fenetreGestion);

fenetreMenu=lookup_widget(objet_graphique,"menu");
fenetreMenu=create_menu();

gtk_widget_show(fenetreMenu);
}

