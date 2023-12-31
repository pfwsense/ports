--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -46,7 +46,7 @@ CONSTINIT const base::Feature kAudioServiceOutOfProces
              "AudioServiceOutOfProcess",
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -58,7 +58,7 @@ CONSTINIT const base::Feature kAudioServiceSandbox(
 // kAudioServiceOutOfProcess feature is enabled.
 CONSTINIT const base::Feature kAudioServiceSandbox(
              "AudioServiceSandbox",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1236,7 +1236,7 @@ BASE_FEATURE(kWebAssemblyCodeProtection,
              "WebAssemblyCodeProtection",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 // Use memory protection keys in userspace (PKU) (if available) to protect code
 // JITed for WebAssembly. Fall back to traditional memory protection if
 // WebAssemblyCodeProtection is also enabled.
@@ -1278,7 +1278,7 @@ CONSTINIT const base::Feature kWebAssemblyTrapHandler(
 CONSTINIT const base::Feature kWebAssemblyTrapHandler(
              "WebAssemblyTrapHandler",
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-      BUILDFLAG(IS_MAC)) &&                                                 \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                            \
      defined(ARCH_CPU_X86_64)) ||                                           \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -1353,7 +1353,11 @@ BASE_FEATURE(kWebUIReportOnlyTrustedTypes,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
