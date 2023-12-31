--- src/rgw/rgw_asio_client.cc.orig	2021-06-29 22:09:10 UTC
+++ src/rgw/rgw_asio_client.cc
@@ -39,11 +39,11 @@ int ClientIO::init_env(CephContext *cct)
     const auto& value = header->value();
 
     if (field == beast::http::field::content_length) {
-      env.set("CONTENT_LENGTH", value.to_string());
+      env.set("CONTENT_LENGTH", value);
       continue;
     }
     if (field == beast::http::field::content_type) {
-      env.set("CONTENT_TYPE", value.to_string());
+      env.set("CONTENT_TYPE", value);
       continue;
     }
 
@@ -60,25 +60,25 @@ int ClientIO::init_env(CephContext *cct)
     }
     *dest = '\0';
 
-    env.set(buf, value.to_string());
+    env.set(buf, value);
   }
 
   int major = request.version() / 10;
   int minor = request.version() % 10;
   env.set("HTTP_VERSION", std::to_string(major) + '.' + std::to_string(minor));
 
-  env.set("REQUEST_METHOD", request.method_string().to_string());
+  env.set("REQUEST_METHOD", request.method_string());
 
   // split uri from query
   auto url = request.target();
   auto pos = url.find('?');
   if (pos != url.npos) {
     auto query = url.substr(pos + 1);
-    env.set("QUERY_STRING", query.to_string());
+    env.set("QUERY_STRING", query);
     url = url.substr(0, pos);
   }
-  env.set("REQUEST_URI", url.to_string());
-  env.set("SCRIPT_URI", url.to_string()); /* FIXME */
+  env.set("REQUEST_URI", url);
+  env.set("SCRIPT_URI", url); /* FIXME */
 
   char port_buf[16];
   snprintf(port_buf, sizeof(port_buf), "%d", local_endpoint.port());
