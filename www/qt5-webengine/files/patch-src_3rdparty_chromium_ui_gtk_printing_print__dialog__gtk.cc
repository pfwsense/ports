--- src/3rdparty/chromium/ui/gtk/printing/print_dialog_gtk.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gtk/printing/print_dialog_gtk.cc
@@ -388,7 +388,7 @@ void PrintDialogGtk::ShowDialog(
   // Since we only generate PDF, only show printers that support PDF.
   // TODO(thestig) Add more capabilities to support?
   GtkPrintCapabilities cap = static_cast<GtkPrintCapabilities>(
-      GTK_PRINT_CAPABILITY_GENERATE_PDF | GTK_PRINT_CAPABILITY_PAGE_SET |
+      GTK_PRINT_CAPABILITY_GENERATE_PS | GTK_PRINT_CAPABILITY_GENERATE_PDF | GTK_PRINT_CAPABILITY_PAGE_SET |
       GTK_PRINT_CAPABILITY_COPIES | GTK_PRINT_CAPABILITY_COLLATE |
       GTK_PRINT_CAPABILITY_REVERSE);
   gtk_print_unix_dialog_set_manual_capabilities(GTK_PRINT_UNIX_DIALOG(dialog_),
