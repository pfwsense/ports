--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/threading_pthreads.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/threading_pthreads.cc
@@ -50,12 +50,17 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/syscall.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <unistd.h>
+#endif
+
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
 #endif
 
 namespace WTF {
