--- src/third_party/abseil-cpp/dist/absl/base/internal/unscaledcycleclock.cc.orig	2023-05-10 10:35:21 UTC
+++ src/third_party/abseil-cpp/dist/absl/base/internal/unscaledcycleclock.cc
@@ -24,8 +24,9 @@
 #ifdef __GLIBC__
 #include <sys/platform/ppc.h>
 #elif defined(__FreeBSD__)
-#include <sys/sysctl.h>
+#include "absl/base/call_once.h"
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #endif
 
