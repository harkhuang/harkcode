//laber_demo.c
#include <stdio.h>
#include <gtk/gtk.h>



int main(int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *label;     //标签
    GtkWidget *frame;     //框架
    GtkWidget *main_vbox; //组装盒
    
    gtk_init(&argc,&argv);
    
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);//参数表示创建主窗口
    g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),G_OBJECT(window));
    
    gtk_window_set_title(GTK_WINDOW(window),"Label Demo");
    
    main_vbox=gtk_vbox_new(TRUE,6);
    gtk_container_set_border_width(GTK_CONTAINER(window),20);
    
    label=gtk_label_new("LABEL");
    gtk_box_pack_start(GTK_BOX(main_vbox),label,FALSE,FALSE,0);
    
    
    frame=gtk_frame_new("Normal label");
    label=gtk_label_new("this is a label");
    gtk_container_add(GTK_CONTAINER(frame),label);
    gtk_box_pack_start(GTK_BOX(main_vbox),frame,FALSE,FALSE,0);
    
    frame=gtk_frame_new("multi-line label");
    label=gtk_label_new("this is a multi-line label.\nsecond line.\nthird line.");
    gtk_container_add(GTK_CONTAINER(frame),label);
    gtk_box_pack_start(GTK_BOX(main_vbox),frame,FALSE,FALSE,0);
    
    frame=gtk_frame_new("line wrapped label");
    label=gtk_label_new("this is a line wrapped label."\
                        "second line."\
                        "third line.");
    gtk_label_set_line_wrap(GTK_LABEL(label),TRUE);
    gtk_container_add(GTK_CONTAINER(frame),label);
    gtk_box_pack_start(GTK_BOX(main_vbox),frame,FALSE,FALSE,0);
    
    gtk_container_add(GTK_CONTAINER(window),main_vbox);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}