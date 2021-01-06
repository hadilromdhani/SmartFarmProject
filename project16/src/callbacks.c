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
#include "plante.h"
#include "fonct.h"
#include "ouvrier.h"
#include "capteur.h"

int radio;
int choix_sexe[2]={0,0};

int x;
int t[3]={0,0,0};

int radio1;
int choix[2]={0,0};


GtkTreeSelection *selection1;
GtkWidget *gestion ,*fenetre_Modifier;
capteur e;
int z=0 ,y=0,validmodif=0;

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
output=lookup_widget (objet_graphique,"label46_message");
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
on_button2_ouvrier_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestionSM;
GtkWidget *fenetreMenu;
GdkColor color;

fenetreMenu=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetreMenu);

fenetreGestionSM=lookup_widget(objet_graphique,"gestion_ouvrier");
fenetreGestionSM=create_gestion_ouvrier();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestionSM, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestionSM);
}


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
on_button4_calendrier_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestionFK;
GtkWidget *fenetreMenu;
GdkColor color;

fenetreMenu=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetreMenu);

fenetreGestionFK=lookup_widget(objet_graphique,"gestionFK");
fenetreGestionFK=create_gestionFK();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestionFK, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestionFK);
}


void
on_button5_equipement_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_capteurs_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetreGestion;
GtkWidget *fenetreMenu;
GdkColor color;

fenetreMenu=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetreMenu);

fenetreGestion=lookup_widget(objet_graphique,"fenetre_acceuil");
fenetreGestion=create_fenetre_acceuil();
color.red = 0xcccc;
color.green = 0xd645;
color.blue = 0xd900;
gtk_widget_modify_bg(fenetreGestion, GTK_STATE_NORMAL, &color);
gtk_widget_show(fenetreGestion);
}


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


void
on_radiobutton1_male_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{radio=1;}
}


void
on_radiobutton2_femelle_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{radio=2;}
}


void
on_checkbutton1_zoneA_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_sexe[0]=1;}
}


void
on_checkbutton2_zoneB_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_sexe[1]=1;}
}


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

treeview=lookup_widget(fenetreAfficher,"treeviewHR");

afficher_animal(treeview);
}


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


void
on_treeviewHR_row_activated            (GtkTreeView     *treeview,
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


void
on_button17_retourAff_clicked          (GtkButton       *object,
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


void
on_SMbuttonModifierFK_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierFK;
GtkWidget *gestionFK;
gestionFK=lookup_widget(objet,"gestionFK");
gtk_widget_destroy(gestionFK);
modifierFK=create_modifierFK();
gtk_widget_show(modifierFK);
}


void
on_SMbuttonAjouterFK_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *AjouterFK;
GtkWidget *gestionFK;
gestionFK=lookup_widget(objet,"gestionFK");
gtk_widget_destroy(gestionFK);
AjouterFK=create_AjouterFK();
gtk_widget_show(AjouterFK);
}


void
on_SM_consulterFK_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionFK;
GtkWidget *consulterFK;
GtkWidget *treeview1FK;
gestionFK=lookup_widget(objet,"gestionFK");
gtk_widget_destroy(gestionFK);
consulterFK=lookup_widget(objet,"consulterFK");
consulterFK=create_consulterFK();
gtk_widget_show(consulterFK);
treeview1FK=lookup_widget(consulterFK,"treeview1FK");
afficher_plante(treeview1FK);
}


void
on_Supprimer_ouvFK_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerFK;
GtkWidget *gestionFK;
gestionFK =lookup_widget(objet,"gestionFK");
gtk_widget_destroy(gestionFK);
supprimerFK=create_supprimerFK();
gtk_widget_show(supprimerFK);
}


void
on_rechercher_planteFK_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *rechercher1FK;
GtkWidget *gestionFK;
rechercher1FK =lookup_widget(objet,"rechercher1FK");
gtk_widget_destroy(gestionFK);
rechercher1FK=create_rechercher1FK();
gtk_widget_show(rechercher1FK);
}


void
on_Retour_OuvFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionFK;
GtkWidget *MenuFK;
gestionFK=lookup_widget(objet,"gestionFK");
gtk_widget_destroy(gestionFK);
MenuFK=create_menu();
gtk_widget_show(MenuFK);
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_checkbutton1_clicked                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[2]=1;}
}


void
on_confirmer_ajoutFK_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char caractere[20]="fruits";
char place[100]="";
plante o;
GtkWidget *quantite;
GtkWidget *id;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Combobox4;
GtkWidget *Combobox1;
GtkWidget *AjouterFK , *gestionFK;
AjouterFK=lookup_widget(objet_graphique, "AjouterFK");
quantite=lookup_widget(objet_graphique,"spinbutton1FK");
Combobox4=lookup_widget(objet_graphique,"combobox4FK");
Combobox1=lookup_widget(objet_graphique,"combobox1FK");
input3=lookup_widget(objet_graphique ,"entry2FK");
input4=lookup_widget(objet_graphique ,"entry1FK");
id=lookup_widget(objet_graphique ,"entry3FK");


strcpy(o.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox4)));
strcpy(o.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
strcpy(o.date1,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.date2,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.iden,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(o.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));

if(t[0]==1)
strcat(place,"\t A");
else
if(t[1]==1)
strcat(place,"\t B");
else
if(t[2]==1)
strcat(place,"\t C ");

strcpy(o.place,place);
if(x==1)
strcpy(o.caractere,"fruits");
if(x==2)
strcpy(o.caractere,"legumes");
ajouter_plante(o);

gtk_widget_destroy(AjouterFK);
gestionFK=create_gestionFK();
gtk_widget_show(gestionFK);
}


void
on_Retour_AjoutFK_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionFK;
GtkWidget *AjouterFK;
AjouterFK=lookup_widget(objet,"AjouterFK");
gtk_widget_destroy(AjouterFK);
gestionFK=create_gestionFK();
gtk_widget_show(gestionFK);
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}


void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[2]=1;}
}


void
on_Confirmer_modifFK_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char caractere[20]="";
char place[100]="";
plante o;
GtkWidget *quantite;
GtkWidget *id;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Combobox3;
GtkWidget *Combobox2;
GtkWidget *modifierFK , *gestionFK;
modifierFK=lookup_widget(objet_graphique, "spinbutton2FK");
Combobox3=lookup_widget(objet_graphique,"combobox3FK");
Combobox2=lookup_widget(objet_graphique,"combobox2FK");
input3=lookup_widget(objet_graphique ,"entry2_specFK");
input4=lookup_widget(objet_graphique ,"SM_entry_adresseFK");
id=lookup_widget(objet_graphique ,"entry2_numFK");
quantite=lookup_widget(objet_graphique ,"entry_quantiteFK");


strcpy(o.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
strcpy(o.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
strcpy(o.date1,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.date2,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.iden,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(o.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));


if(t[0]==1)
strcat(place,"\t A");
else
if(t[1]==1)
strcat(place,"\t B");
else
if(t[2]==1)
strcat(place,"\t C");
strcpy(o.place,place);
if(x==1)
strcpy(o.caractere,"fruits");
else
if(x==2)
strcpy(o.caractere,"legumes");
modifier_plante(o);

gtk_widget_destroy(modifierFK);
gestionFK=create_gestionFK();
gtk_widget_show(gestionFK);

}


void
on_retour_modFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierFK;
	GtkWidget *consulterFK;
	GtkWidget *treeview1FK;
	modifierFK=lookup_widget(objet,"modifierFK");
        gtk_widget_destroy(modifierFK);
        consulterFK=lookup_widget(objet,"consulterFK");
	consulterFK=create_consulterFK();
         gtk_widget_show(consulterFK);
	
	treeview1FK=lookup_widget(consulterFK,"treeview1FK");
         afficher_plante(treeview1FK);
}


void
on_Spprimer_confFK_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerFK ,*gestionFK;
       
	plante o;
        GtkWidget *input1;
	supprimerFK=lookup_widget(objet,"supprimerFK");
	
	input1=lookup_widget(supprimerFK,"SMentry_suppFK");
	strcpy(o.iden,gtk_entry_get_text(GTK_ENTRY(input1)));
	supprimer_plante(o);
}


void
on_retour_supFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerFK;
GtkWidget *gestionFK;
supprimerFK=lookup_widget(objet,"supprimerFK");
gtk_widget_destroy(supprimerFK);
gestionFK=create_gestionFK();
gtk_widget_show(gestionFK);
}


void
on_rechercherFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *rechercherFK ;
GtkWidget *input1;
	plante o;
	
	rechercherFK=lookup_widget(objet,"rechercherFK");
	input1=lookup_widget(rechercherFK,"entry4FK");
	strcpy(o.iden,gtk_entry_get_text(GTK_ENTRY(input1)));
	rechercher_plante(o);

GtkWidget *afficher_rechercherFK;
afficher_rechercherFK =lookup_widget(objet,"afficher_rechercherFK");
gtk_widget_destroy(rechercherFK);
afficher_rechercherFK=create_afficher_rechercherFK();
gtk_widget_show(afficher_rechercherFK);
}


void
on_treeview2FK_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
       int jour, mois, annee;
       gchar *nom;
       gchar *type;
       gchar *date1;
       gchar *date2;
       gchar *iden; 
       gchar *place;
       gchar *quantite;
       gchar *caractere;
       plante o;
	
	GtkTreeModel *model =gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
	//gtk_tree_model_get_iter(model,&iter,path);
 if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&type,2,&date1,3,&date2,4,&iden,5,&place,6,&quantite,7,&caractere,-1);
	
strcpy(o.nom,nom);
strcpy(o.type,type);
strcpy(o.date1,date1);
strcpy(o.date2,date2);
strcpy(o.iden,iden);
strcpy(o.place,place);
strcpy(o.quantite,quantite);
strcpy(o.caractere,caractere);
//supprimer_ouvrier(o);
afficher_plante(treeview);
}
}


void
on_retour_rechercherFK_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionFK;
GtkWidget *afficher_rechercherFK;
afficher_rechercherFK=lookup_widget(objet,"afficher_rechercherFK");
gtk_widget_destroy(afficher_rechercherFK);
gestionFK=create_gestionFK();
gtk_widget_show(gestionFK);
}


void
on_treeview1FK_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
       int jour, mois, annee;
       gchar *nom;
       gchar *type;
       gchar *date1;
       gchar *date2;
       gchar *iden; 
       gchar *place;
       gchar *quantite;
       gchar *caractere;
       plante o;
	
	GtkTreeModel *model =gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
	//gtk_tree_model_get_iter(model,&iter,path);
 if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&type,2,&date1,3,&date2,4,&iden,5,&place,6,&quantite,7,&caractere,-1);
	
strcpy(o.nom,nom);
strcpy(o.type,type);
strcpy(o.date1,date1);
strcpy(o.date2,date2);
strcpy(o.iden,iden);
strcpy(o.place,place);
strcpy(o.quantite,quantite);
strcpy(o.caractere,caractere);
//supprimer_ouvrier(o);
afficher_plante(treeview);
}
}


void
on_retour_consulterFK_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionFK;
GtkWidget *consulterFK;
consulterFK=lookup_widget(objet,"consulterFK");
gtk_widget_destroy(consulterFK);
gestionFK=create_gestionFK();
gtk_widget_show(gestionFK);
}


void
on_button_alarmentes_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *accueil;
accueil=lookup_widget(button,"fenetre_Accueil");
gtk_widget_destroy(accueil);
GtkWidget *alarmente;
alarmente = create_fenetre_Alarmente ();
  gtk_widget_show (alarmente);
}


void
on_button_acceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *waccueil;
waccueil=lookup_widget(button,"fenetre_Accueil");
gtk_widget_destroy(waccueil);
GtkWidget *capteur;
capteur = create_gestion_capteur ();
  gtk_widget_show (capteur);
}


void
on_button_quitter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewCapteur_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *reference;
        gchar *nom;
        gchar *type;
        gchar *marque;
        gint  *jour;
	gint  *mois;
	gint  *annee;
	capteur c;
      
       GtkTreeIter iter;
	
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &nom, 1, &marque,2,&reference,3,&type,4,&jour,5,&mois,6,&annee,-1);
	strcpy(e.reference,reference);
	strcpy(e.nom,nom);
	strcpy(e.marque,marque);  
	
	}
}


void
on_buttonRechercher_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelreference;
GtkWidget *nbResultat;
GtkWidget *message;
char reference[30];
char chnb[30];
int flag=0,nb;  
entry=lookup_widget(objet,"entry10");
labelreference=lookup_widget(objet,"label28");
p1=lookup_widget(objet,"treeviewCapteur");
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(reference,"")==0){
  gtk_widget_show (labelreference);flag=0;
}else{
flag=1;
gtk_widget_hide (labelreference);}

if(flag==0)
    {return;
    }
    else
    {

nb=Cherchercapteur(p1,"fichier.txt",reference);
// afficher le nombre de resultats obtenue par la recherche */

sprintf(chnb,"%d",nb);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(objet,"label27");
message=lookup_widget(objet,"label26");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);
}
}


void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *capteur;
capteur=lookup_widget(button,"gestion_capteur");
gtk_widget_destroy(capteur);
GtkWidget *modifier;

modifier = create_fenetre_Modifier ();

  gtk_widget_show (modifier);
GtkWidget* msgRef=lookup_widget(modifier,"label34");
gtk_label_set_text(GTK_LABEL(msgRef),e.reference);
                gtk_widget_show(msgRef);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entryNom1")),e.nom);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entryMarque1")),e.marque);
if (strcmp(e.type,"temperature")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton3")),TRUE);
}
else if (strcmp(e.type,"humidite")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton4")),TRUE);
}
}


void
on_buttonAfficher_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
capteur c;
GtkWidget *afficher;

  afficher=lookup_widget(objet_graphique,"gestion_capteur");
afficher_capteur(lookup_widget(afficher,"treeviewCapteur"),"fichier.txt");
}


void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *capteur;
capteur=lookup_widget(button,"gestion_capteur");
gtk_widget_destroy(capteur);
GtkWidget *ajouter;
ajouter = create_fenetre_Ajouter ();
  gtk_widget_show (ajouter);

}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char r[30];


strcpy(r,e.reference);
	supprimer_capteur(r);
GtkWidget *confirmesupprimer;
confirmesupprimer=lookup_widget(button,"gestion_capteur");

afficher_capteur(lookup_widget(button,"treeviewCapteur"),"fichier.txt");
}


void
on_buttonRetour_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur;
GtkWidget *wacceuil;
gestion_capteur = lookup_widget(button,"gestion_capteur");
 gtk_widget_destroy (gestion_capteur);


wacceuil = create_fenetre_acceuil ();
  gtk_widget_show (wacceuil);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=2;}
}


void
on_buttonOk_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
capteur c;

GtkWidget *entryNom, *entryMarque, *entryReference, *entryType ,*Jour , *entryMois ,*Annee;
GtkWidget *fenetre_ajouter;
fenetre_ajouter=lookup_widget(objet_graphique,"fenetre_Ajouter");


entryNom=lookup_widget(objet_graphique,"entryNom");
entryMarque=lookup_widget(objet_graphique,"entryMarque");
entryReference=lookup_widget(objet_graphique,"entryReference");
Jour=lookup_widget(objet_graphique,"spinbuttonJour");
entryMois=lookup_widget(objet_graphique,"combobox1");
Annee=lookup_widget(objet_graphique,"spinbuttonAnne");


 strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
 strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entryMarque) ) );
 strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryReference) ) );
 if (x==1){
strcpy(c.type,"temperature");}
else 
if (x==2){
strcpy(c.type,"humidite");}
 c.dt.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
 strcpy( c.dt.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryMois)) ) ;
 c.dt.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


ajouter_capteur(c);
GtkWidget *gestion;
gestion = create_gestion_capteur ();
  gtk_widget_show (gestion);
gtk_widget_destroy(fenetre_ajouter);
}


void
on_buttonAnnuler_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
ajouter=lookup_widget(button,"fenetre_ajouter");
gtk_widget_destroy(ajouter);
GtkWidget *gestion;
gestion = create_gestion_capteur ();
  gtk_widget_show (gestion);
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{validmodif=1;}
else
{validmodif=0;}
}


void
on_buttonOk1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
capteur c;

GtkWidget *entryNom, *entryMarque, *entryReference, *entryType ,*Jour , *entryMois ,*Annee;



entryNom=lookup_widget(button,"entryNom1");
entryMarque=lookup_widget(button,"entryMarque1");
//entryReference=lookup_widget(objet_graphique,"entryReference");
Jour=lookup_widget(button,"spinbuttonDate1");
entryMois=lookup_widget(button,"combobox2");
Annee=lookup_widget(button,"spinbuttonAnne1");

strcpy(c.reference,e.reference);
 strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
 strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entryMarque) ) );
 //strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryReference) ) );
 if (y==1){
strcpy(c.type,"temperature");}
else 
if (y==2){
strcpy(c.type,"humidite");}
 c.dt.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
 strcpy( c.dt.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryMois)) ) ;
 c.dt.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
if (validmodif==1)
{
     modifier_capteur(c);

GtkWidget *capteur;
GtkWidget *modifier;
modifier=lookup_widget(button,"fenetre_Modifier");
gtk_widget_destroy(modifier);

capteur = create_gestion_capteur ();
  gtk_widget_show (capteur);
}
}


void
on_buttonAnnuler1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
modifier=lookup_widget(button,"fenetre_Modifier");
gtk_widget_destroy(modifier);
GtkWidget *gestion;
gestion = create_gestion_capteur ();
  gtk_widget_show (gestion);
}


void
on_treeviewAlarmente_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonRetour2_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *alarmente;
alarmente=lookup_widget(button,"fenetre_Alarmente");
gtk_widget_destroy(alarmente);
GtkWidget *wacceuil;
wacceuil = create_fenetre_acceuil ();
  gtk_widget_show (wacceuil);
}


/*
void
on_button_verifierDeff_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *deffectueux ;
GtkWidget *output;
       
	capteur v;
	char text[20]="";
        GtkWidget *input1;
	deffectueux=lookup_widget(objet,"deffectueuxFK");
	output=lookup_widget(objet,"label124_message");
	input1=lookup_widget(deffectueux,"entry11_valeur");
	strcpy(v.valeur,gtk_entry_get_text(GTK_ENTRY(input1)));
if(strcmp(v.valeur,"347.30")==0)
{strcpy(text,"deffectueux\n");}
else 
if(strcmp(v.valeur,"347.30")!=0)
{strcpy(text,"non deffectueux\n");}
FILE* f;
FILE* g;
f=fopen("humidite.txt","r");
g=fopen("iden.txt","w+");
if(f!=NULL)
{
while(fscanf(f," %s %s %s %s %s  \n",v.iden, v.jour,v.mois,v.annee,v.valeur)!=EOF)
          
       if (strcmp(v.valeur,"347.30")==0)
       	{fprintf(g," %s   \n",v.iden);}
	
}
fclose(f);
fclose(g);
	
gtk_label_set_text(GTK_LABEL(output),text);
}


void
on_button2_afficherMarque_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
GtkWidget *deffectueux ;
GtkWidget *marque;
char text[20]="";
deffectueux=lookup_widget(objet,"deffectueuxFK");
output=lookup_widget(objet,"label126_message");
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
gtk_widget_destroy(deffectueux);
marque=create_marqueFK();
gtk_widget_show(marque);
}


void
on_button2_retourMarque_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *deffectueux;
GtkWidget *marque;
marque=lookup_widget(objet,"marqueFK");
gtk_widget_destroy(marque);
deffectueux=create_deffectueuxFK();
gtk_widget_show(deffectueux);
}


void
on_button1_afficherMarqueDeff_clicked  (GtkButton       *objet,
                                        gpointer         user_data)
{
char text[20]="";
GtkWidget *output;
output=lookup_widget(objet,"label126_message");
capteur y;
FILE* k;
k=fopen("marq.txt","r");
if(k!=NULL)
{while(fscanf(k," %s    \n",y.marque)!=EOF)
	gtk_label_set_text(GTK_LABEL(output),y.marque);
}
fclose(k);
}*/


void
on_SMbuttonModifier_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_ouvrier;
GtkWidget *gestion_ouvrier;
gestion_ouvrier=lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
modifier_ouvrier=create_modifier_ouvrier();
gtk_widget_show(modifier_ouvrier);
}


void
on_SMbuttonAjouter_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_ouvrier;
GtkWidget *gestion_ouvrier;
gestion_ouvrier=lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
Ajouter_ouvrier=create_Ajouter_ouvrier();
gtk_widget_show(Ajouter_ouvrier);
}


void
on_SM_consulter_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_ouvrier;
GtkWidget *consulter_ouvrier;
GtkWidget *treeview1;
gestion_ouvrier=lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
consulter_ouvrier=lookup_widget(objet,"consulter_ouvrier");
consulter_ouvrier=create_consulter_ouvrier();
gtk_widget_show(consulter_ouvrier);
treeview1=lookup_widget(consulter_ouvrier,"treeviewSM");
afficher_ouvrier(treeview1);
}


void
on_SMbuttonPresence_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Presence_ouvrier;
GtkWidget *gestion_ouvrier;
gestion_ouvrier =lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
Presence_ouvrier =create_Presence_ouvrier();
gtk_widget_show(Presence_ouvrier);
}


void
on_Supprimer_ouv_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_ouvrier;
GtkWidget *gestion_ouvrier;
gestion_ouvrier =lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
supprimer_ouvrier=create_supprimer_ouvrier();
gtk_widget_show(supprimer_ouvrier);
}


void
on_button_taux_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *calcul_taux;
GtkWidget *gestion_ouvrier;
gestion_ouvrier=lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
calcul_taux=create_calcul_taux();
gtk_widget_show(calcul_taux);
}


void
on_Retour_Ouv_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_ouvrier;
GtkWidget *Menu_ouvrier;
gestion_ouvrier=lookup_widget(objet,"gestion_ouvrier");
gtk_widget_destroy(gestion_ouvrier);
Menu_ouvrier=create_menu();
gtk_widget_show(Menu_ouvrier);
}


void
on_SM_radiobutton_femelle_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radio1=2;
}


void
on_SM_radiobutton_male_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radio1=1;
}


void
on_confirmer_ajout_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
ouvrier o;
//o.sexe="Femme";
GtkWidget *input1 ,*input2,*input3,*input4,*input5,*input6;
GtkWidget *radiobutton_male , *radiobutton_femelle;
GtkWidget *combobox;
GtkWidget *Ajouter_ouvrier , *gestion_ouvrier;
Ajouter_ouvrier=lookup_widget(objet, "Ajouter_ouvrier");

input1=lookup_widget(Ajouter_ouvrier,"SM_ajout_cin");
input2=lookup_widget(Ajouter_ouvrier,"SM_ajout_nom");
input3=lookup_widget(Ajouter_ouvrier,"SM_ajout_prenom");
input4=lookup_widget(Ajouter_ouvrier,"SM_ajout_Specialite");
input5=lookup_widget(Ajouter_ouvrier,"SM_ajout_adresse");
input6=lookup_widget(Ajouter_ouvrier,"entry15");
combobox=lookup_widget(Ajouter_ouvrier,"SMcombobox1");

strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.specialite,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(o.ntel,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(o.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

strcpy(o.sexe,"Femme");
if(radio1==1)
{
strcpy(o.sexe,"Homme");
}
else if(radio1==2)
{
strcpy(o.sexe,"Femme");
}

ajouter_ouvrier(o);

gtk_widget_destroy(Ajouter_ouvrier);
gestion_ouvrier=create_gestion_ouvrier();
gtk_widget_show(gestion_ouvrier);
}


void
on_Retour_Ajout_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_ouvrier;
GtkWidget *Ajouter_ouvrier;
Ajouter_ouvrier=lookup_widget(objet,"Ajouter_ouvrier");
gtk_widget_destroy(Ajouter_ouvrier);
gestion_ouvrier=create_gestion_ouvrier();
gtk_widget_show(gestion_ouvrier);
}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radio1=2;
}


void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
radio1=1;
}


void
on_Confirmer_modif_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
ouvrier o;
	//o.sexe="Femme";
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *output1;
	GtkWidget *combobox2;
        GtkWidget *radiobutton_femme ;
        GtkWidget *radiobutton_homme;
	char succes[30];

        //GtkWidget *modifier;
       // GtkWidget *gestion;
        //modifier =lookup_widget(objet,"modifier");
	
	input1=lookup_widget(objet ,"SMentrycin");
	input2=lookup_widget(objet ,"SMentrynom");
	input3=lookup_widget(objet ,"SMentryprenom");
	input4=lookup_widget(objet ,"SMentryspec");
        input5=lookup_widget(objet ,"SMentryadresse");
	input6=lookup_widget(objet ,"SMentrynumero");
	combobox2=lookup_widget(objet ,"SMcombobox");

        output1=lookup_widget(objet ,"SM_label");
	strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(o.specialite,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(o.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(o.ntel,gtk_entry_get_text(GTK_ENTRY(input6)));
        strcpy(o.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	  strcpy(succes,"Modification avec succés");
         gtk_label_set_text(GTK_LABEL (output1), succes);
	strcpy(o.sexe,"Femme");
        if(radio1==1)
             {
            strcpy(o.sexe,"Homme");
             }
        else if(radio1==2)
            {
            strcpy(o.sexe,"Femme");
             }

	modifier_ouvrier(o);
     /* GdkColor color;
      gdk_color_parse("red",&color);
      gtk_widget_modify_fg( output1 ,GTK_STATE_NORMAL ,&color);*/
      strcpy(succes,"Modification avec succés");
         gtk_label_set_text(GTK_LABEL (output1), succes);
      // gtk_widget_destroy(modifier);
      // gestion =create_gestion();
      //gtk_widget_show(gestion);
}


void
on_retour_mod_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_ouvrier;
	GtkWidget *consulter_ouvrier;
	GtkWidget *treeview1;
	modifier_ouvrier=lookup_widget(objet,"modifier_ouvrier");
        gtk_widget_destroy(modifier_ouvrier);
        consulter_ouvrier=lookup_widget(objet,"consulter_ouvrier");
	consulter_ouvrier=create_consulter_ouvrier();
         gtk_widget_show(consulter_ouvrier);
	
	treeview1=lookup_widget(consulter_ouvrier,"treeviewSM");
         afficher_ouvrier(treeview1);
}


void
on_SMbutton_rech_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_ouvrier ;
       
	ouvrier o;
        GtkWidget *input1;
	GtkWidget *output1;
        GtkWidget *output2;
        GtkWidget *output3;
        GtkWidget *output4;
        GtkWidget *output5;
        GtkWidget *output6;
        //GtkWidget *output6;
        GtkWidget *combobox2;
        GtkWidget *radiobutton_femme ;
        GtkWidget *radiobutton_homme;
        GtkWidget *comboOccupation;
	modifier_ouvrier=lookup_widget(objet,"modifier_ouvrier");
	
	input1=lookup_widget(modifier_ouvrier,"SMentrycin");
        
	output1=lookup_widget(modifier_ouvrier ,"SMentrynom");
	output2=lookup_widget(modifier_ouvrier ,"SMentryprenom");
	output3=lookup_widget(modifier_ouvrier ,"SMentryspec");
        output4=lookup_widget(modifier_ouvrier ,"SMentryadresse");
        output5=lookup_widget(modifier_ouvrier ,"SMentrynumero");
	//radiobutton_femme =lookup_widget(modifier ,"radiobutton_femme");
	//radiobutton_homme=lookup_widget(modifier ,"radiobutton_homme");
	combobox2=lookup_widget(modifier_ouvrier ,"SMcombobox");

	
        strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
        o=rechercher_ouvrier(o);
	gtk_entry_set_text(GTK_ENTRY(output1),o.nom);
	gtk_entry_set_text(GTK_ENTRY(output2),o.prenom);
	gtk_entry_set_text(GTK_ENTRY(output3),o.specialite);
	gtk_entry_set_text(GTK_ENTRY(output4),o.adresse);
	gtk_entry_set_text(GTK_ENTRY(output5),o.ntel);
        comboOccupation=lookup_widget(modifier_ouvrier,"SMcombobox");
}


void
on_Spprimer_conf_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_ouvrier ,*gestion_ouvrier;
       
	ouvrier o;
        GtkWidget *input1;
	supprimer_ouvrier=lookup_widget(objet,"supprimer_ouvrier");
	
	input1=lookup_widget(supprimer_ouvrier,"SMentry_supp");
	strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
	supprimer_ouv(o);
}


void
on_retour_sup_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_ouvrier;
GtkWidget *consulter_ouvrier;
GtkWidget *treeview1;
supprimer_ouvrier=lookup_widget(objet,"supprimer_ouvrier");
gtk_widget_destroy(supprimer_ouvrier);

consulter_ouvrier=lookup_widget(objet,"consulter_ouvrier");
consulter_ouvrier=create_consulter_ouvrier();
 gtk_widget_show(consulter_ouvrier);
treeview1=lookup_widget(consulter_ouvrier,"treeviewSM");
 afficher_ouvrier(treeview1);
}


void
on_treeviewSM_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;

       gchar *nom;
       gchar *prenom;
       gchar *cin;
       gchar *adresse;
       gchar *specialite; 
       gchar *ntel;
       gchar *sexe;
       gchar *ville;
       ouvrier o;
	
	GtkTreeModel *model =gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
	//gtk_tree_model_get_iter(model,&iter,path);
 if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&specialite,4,&adresse,5,&ntel,6,&sexe,7,&ville,-1);
	
strcpy(o.nom,nom);
strcpy(o.prenom,prenom);
strcpy(o.cin,cin);
strcpy(o.adresse,adresse);
strcpy(o.specialite,specialite);
strcpy(o.ntel,ntel);
strcpy(o.sexe,sexe);
strcpy(o.ville,ville);
//supprimer_ouvrier(o);
afficher_ouvrier(treeview);
}
}


void
on_retour_consulter_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_ouvrier;
GtkWidget *consulter_ouvrier;
consulter_ouvrier=lookup_widget(objet,"consulter_ouvrier");
gtk_widget_destroy(consulter_ouvrier);
gestion_ouvrier=create_gestion_ouvrier();
gtk_widget_show(gestion_ouvrier);
}



void
on_button_valider_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
presence a;
GtkWidget *input1;
GtkWidget *checkbox1;
GtkWidget *checkbox2;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;

input1=lookup_widget(objet,"SMentryid");
spinbutton1=lookup_widget(objet,"SMjour");
spinbutton2=lookup_widget(objet,"SMmois");
spinbutton3=lookup_widget(objet,"SMannee");

strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
a.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
a.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));
a.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));

if(choix[0]==1)
{ a.p=0;}
else
if(choix[1]==1)
{ a.p=1;}

ajouter_presence(a);
}


void
on_SM_retour_presence_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_ouvrier;
GtkWidget *Presence_ouvrier;
Presence_ouvrier=lookup_widget(objet,"Presence_ouvrier");
gtk_widget_destroy(Presence_ouvrier);
gestion_ouvrier=create_gestion_ouvrier();
gtk_widget_show(gestion_ouvrier);
}


void
on_buttoncalcul_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget calcul_taux;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *output1;

float taux;
char ch1[30];
int mois;
int annee;
presence a;
ouvrier o;
output1=lookup_widget(objet,"taux_abs");
Mois=lookup_widget(objet,"spinbutton_mo");
Annee=lookup_widget(objet,"spinbutton_an");
a.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
a.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
 

if(mois!=a.mois && annee!=a.annee)
{
taux = taux_absenteisme(a.mois,a.annee);
}
sprintf(ch1,"le taux vaut %f \n ",taux);

gtk_label_set_text(GTK_LABEL(output1),ch1);
}


void
on_button_retour_cal_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_ouvrier;
GtkWidget *calcul_taux;
calcul_taux=lookup_widget(objet,"calcul_taux");
gtk_widget_destroy(calcul_taux);
gestion_ouvrier=create_gestion_ouvrier();
gtk_widget_show(gestion_ouvrier);
}


void
on_SM_checkbutton_pres_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}
}


void
on_SM_checkbutton_abs_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}
}


void
on_button1_retourMenuHR_clicked        (GtkButton       *objet_graphique,
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

