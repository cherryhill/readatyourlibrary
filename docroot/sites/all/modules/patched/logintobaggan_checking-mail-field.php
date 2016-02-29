diff --git a/docroot/sites/all/modules/contrib/logintoboggan/logintoboggan.module b/docroot/sites/all/modules/contrib/logintoboggan/logintoboggan.module
index 55b93fe..dad62d7 100755
--- a/docroot/sites/all/modules/contrib/logintoboggan/logintoboggan.module
+++ b/docroot/sites/all/modules/contrib/logintoboggan/logintoboggan.module
@@ -502,7 +502,12 @@ function logintoboggan_user_register_submit($form, &$form_state) {
   //   1. Users can set their own password.
   //   2. The pre-auth role isn't the auth user.
   //   3. Visitors can create their own accounts.
-  $message = t('Further instructions have been sent to your e-mail address.');
+  $mail = $form_state['user'];
+  $mailq = $mail->mail;
+  // showing message if user has email associated with the account
+  if (!empty($mailq)){
+    $message = t('Further instructions have been sent to your e-mail address.');
+  }
   if($reg_pass_set && $pre_auth && variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) == USER_REGISTER_VISITORS) {
     $message = t('A validation e-mail has been sent to your e-mail address. You will need to follow the instructions in that message in order to gain full access to the site.');
   }
