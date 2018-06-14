#include <gtk/gtk.h>

gboolean delete_event(GtkWidget* window, GdkEvent* event, gpointer data) {
  return FALSE;
}

void destroy(GtkWidget* window, gpointer data) {
  gtk_main_quit();
}

void button_add_clicked(GtkWidget* button, GtkWidget* entry) {
  g_printf("%s\n", gtk_entry_get_text(GTK_ENTRY(entry)));
}

gint main(gint argc, gchar** argv) {
  GtkWidget* box_add;
  GtkWidget* button_add;
  GtkWidget* button_box_add;
  GtkWidget* entry_add;
  GtkWidget* rows;
  GtkWidget* window;

  gtk_init(&argc, &argv);
  setvbuf(stdout, NULL, _IONBF, 0);

  entry_add = gtk_entry_new();

  button_add = gtk_button_new_with_label("Add\n");
  gtk_signal_connect(G_OBJECT(button_add), "clicked", G_CALLBACK(button_add_clicked), entry_add);
  gtk_widget_set_size_request(button_add, -1, 0);
  button_box_add = gtk_hbutton_box_new();
  gtk_button_box_set_layout(GTK_BUTTON_BOX(button_box_add), GTK_BUTTONBOX_START);
  gtk_container_add(GTK_CONTAINER(button_box_add), button_add);

  box_add = gtk_hbox_new(FALSE, 20);
  gtk_container_add(GTK_CONTAINER(box_add), entry_add);
  gtk_container_add(GTK_CONTAINER(box_add), button_box_add);

  rows = gtk_vbox_new(FALSE, 20);
  gtk_box_pack_start(GTK_BOX(rows), box_add, FALSE, NULL, 20);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width(window, 20);
  gtk_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  gtk_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  gtk_container_add(GTK_CONTAINER(window), rows);

  gtk_widget_show_all(window);
  gtk_main();
}
