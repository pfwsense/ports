--- v8/src/diagnostics/perf-jit.cc.orig	2022-10-01 07:40:07 UTC
+++ v8/src/diagnostics/perf-jit.cc
@@ -30,7 +30,7 @@
 #include "src/common/assert-scope.h"
 
 // Only compile the {LinuxPerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
