--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.cc
@@ -19,7 +19,7 @@
 
 #if defined(OS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "mojo/public/cpp/bindings/pending_remote.h"
 #endif
@@ -34,7 +34,7 @@ PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
 namespace content {
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   ChildThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -52,7 +52,7 @@ blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetS
 void PpapiBlinkPlatformImpl::Shutdown() {}
 
 blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
