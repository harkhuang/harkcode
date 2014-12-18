#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
    GtkWidget *window;
    gtk_init(&argc,&argv);
    
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);//参数表示创建主窗口
    
    g_signal_connect(G_OBJECT(window),"delete event",G_CALLBACK(gtk_main_quit),NULL);//空间和消息函数创建关联
    gtk_window_set_title(GTK_WINDOW(window),"test");
    gtk_widget_show(window);
    
    gtk_main();
    
    return 0;
}