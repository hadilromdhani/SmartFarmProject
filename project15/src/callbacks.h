#include <gtk/gtk.h>


void
on_button1_validerAcceuil_clicked      (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_ouvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_troupeau_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button4_calendrier_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_equipement_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_capteurs_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_calculer_clicked            (GtkButton       *object,
                                        gpointer         user_data);

void
on_radiobutton1_male_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_femelle_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_zoneB_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_zoneA_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button8_ajouter_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button9_modifier_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button10_supprimer_clicked          (GtkButton       *object,
                                        gpointer         user_data);

void
on_button11_chercher_clicked           (GtkButton       *object,
                                        gpointer         user_data);

void
on_button12_afficher_clicked           (GtkButton       *object,
                                        gpointer         user_data);

void
on_button13_confirmerSupp_clicked      (GtkButton       *object,
                                        gpointer         user_data);

void
on_button14_entrerCher_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button15_quitterCher_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button17_quitterCal_clicked         (GtkButton       *object,
                                        gpointer         user_data);

void
on_button16_entrerCal_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button18_retourAff_clicked          (GtkButton       *object,
                                        gpointer         user_data);

void
on_button1_retourGestion_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data);
