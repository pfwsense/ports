Hack to avoid "UnicodeDecodeError: 'utf-8' codec can't decode byte 0xb0 in position 45: invalid start byte"
in src/._xmlgen.cpp which is binary. This doesn't seem like it should be present at the time the docs
are generated, but this is simpler for now.
--- doc/translator.py.orig	2023-01-07 08:48:38 UTC
+++ doc/translator.py
@@ -1459,10 +1459,13 @@ class TrManager:
 
         # Read content of the file as one string.
         assert os.path.isfile(fname)
-        f = xopen(fname)
-        cont = f.read()
-        cont = ''.join(cont.split('\n')) # otherwise the 'match' function won't work.
-        f.close()
+        try:
+            with xopen(fname) as f:
+                cont = f.read()
+                cont = ''.join(cont.split('\n')) # otherwise the 'match' function won't work.
+        except UnicodeDecodeError:
+            print("Skipping {0} because of decoding errors".format(fname))
+            return
 
         # Remove the items for identifiers that were found in the file.
         while lst_in:
