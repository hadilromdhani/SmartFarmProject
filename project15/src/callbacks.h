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
on_modifierFK_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouterFK_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_consulterFK_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerFK_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_rechercherFK_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourFK_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_legumes_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_fruit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_emA_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_emB_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_emC_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button7_confirmerAjout_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_retourAjout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_legumeModif_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_fruitModif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4emAmodif_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_emBmodif_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6_emCmodif_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button9_confirmerModif_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_retourModif_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_supprimerSupp_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_retourSupp_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_rechercherRech_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_affRech_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button14_retourAffRech_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_consult_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button15_retourConsult_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmentes_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_quitter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonOk_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnuler_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonOk1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnuler1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttoRetour2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAfficher_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Retour_gestion_clicked       (GtkButton       *button,
                                        gpointer         user_data);
