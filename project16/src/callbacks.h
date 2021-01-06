#include <gtk/gtk.h>


void
on_button1_validerAcceuil_clicked      (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_ouvrier_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button3_troupeau_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button4_calendrier_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button5_equipement_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_capteurs_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button7_calculer_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton1_male_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_femelle_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_zoneA_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_zoneB_toggled          (GtkToggleButton *togglebutton,
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
on_button14_entrerCher_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button15_quitterCher_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button16_entrerCal_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button17_quitterCal_clicked         (GtkButton       *object,
                                        gpointer         user_data);

void
on_treeviewHR_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button17_retourAff_clicked          (GtkButton       *object,
                                        gpointer         user_data);

void
on_button13_confirmerSupp_clicked      (GtkButton       *object,
                                        gpointer         user_data);

void
on_SMbuttonModifierFK_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SMbuttonAjouterFK_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SM_consulterFK_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Supprimer_ouvFK_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_rechercher_planteFK_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Retour_OuvFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_clicked                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmer_ajoutFK_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_Retour_AjoutFK_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Confirmer_modifFK_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_modFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Spprimer_confFK_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_retour_supFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_rechercherFK_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeview2FK_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_rechercherFK_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeview1FK_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_consulterFK_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_alarmentes_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_acceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_quitter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewCapteur_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonRechercher_clicked            (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAfficher_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRetour_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonOk_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnuler_clicked               (GtkButton       *button,
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
on_treeviewAlarmente_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonRetour2_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_verifierDeff_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button2_afficherMarque_clicked      (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button2_retourMarque_clicked        (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button1_afficherMarqueDeff_clicked  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SMbuttonModifier_clicked            (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SMbuttonAjouter_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SM_consulter_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SMbuttonPresence_clicked            (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Supprimer_ouv_clicked               (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_taux_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Retour_Ouv_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SM_radiobutton_femelle_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SM_radiobutton_male_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmer_ajout_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Retour_Ajout_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Confirmer_modif_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_retour_mod_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SMbutton_rech_clicked               (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Spprimer_conf_clicked               (GtkButton       *objet,
                                        gpointer         user_data);

void
on_retour_sup_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeviewSM_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_consulter_clicked            (GtkButton       *objet,
                                        gpointer         user_data);


void
on_button_valider_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SM_retour_presence_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttoncalcul_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_retour_cal_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_SM_checkbutton_pres_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SM_checkbutton_abs_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_retourMenuHR_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);
