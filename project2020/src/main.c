/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *acceuil;
  /*GtkWidget *menu;
  GtkWidget *gestionTrp;
  GtkWidget *supprimerTrp;
  GtkWidget *chercherTrp;
  GtkWidget *calculerTrp;
  GtkWidget *afficherTrp;*/
  GdkColor color;
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  acceuil = create_acceuil ();
  color.red = 0xcccc;
  color.green = 0xd645;
  color.blue = 0xd900;
  gtk_widget_modify_bg(acceuil, GTK_STATE_NORMAL, &color);
  gtk_widget_show (acceuil);
  /*menu = create_menu ();
  gtk_widget_show (menu);
  gestionTrp = create_gestionTrp ();
  gtk_widget_show (gestionTrp);
  supprimerTrp = create_supprimerTrp ();
  gtk_widget_show (supprimerTrp);
  chercherTrp = create_chercherTrp ();
  gtk_widget_show (chercherTrp);
  calculerTrp = create_calculerTrp ();
  gtk_widget_show (calculerTrp);
  afficherTrp = create_afficherTrp ();
  gtk_widget_show (afficherTrp);*/

  gtk_main ();
  return 0;
}

