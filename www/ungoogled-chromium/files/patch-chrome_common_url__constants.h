--- chrome/common/url_constants.h.orig	2023-07-21 09:49:17 UTC
+++ chrome/common/url_constants.h
@@ -512,7 +512,7 @@ extern const char kOutdatedPluginLearnMoreURL[];
 extern const char kPhoneHubPermissionLearnMoreURL[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 // "Learn more" URL for the chrome apps deprecation dialog.
 extern const char kChromeAppsDeprecationLearnMoreURL[];