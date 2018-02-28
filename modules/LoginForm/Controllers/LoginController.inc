<?php

$stack = array();
$stack['user_id'] = isset($_POST['user_id']) && $_POST['user_id'] ? $_POST['user_id'] : '';
$stack['username'] = isset($_POST['username']) && $_POST['username'] ? $_POST['username'] : '';
$stack['pass'] = isset($_POST['pass']) && $_POST['pass'] ? $_POST['pass'] : '';
$user_id = isset($stack['user_id']) && $stack['user_id'] ? $stack['user_id'] : '';
$pass = isset($stack['pass']) && $stack['pass'] ? $stack['pass'] : '';
print_r($stack);
$login_form = new LoginForm();
$user_data = $login_form->getUserData($stack);

if (isset($user_data['get_user_data']) && $user_data['get_user_data'] && isset($user_data['is_auth']) && $user_data['is_auth']) {

  // Successfully verified login information
  // Register user's name and USER_ID
  if (!isset($_SESSION['user_id'])) {
    $_SESSION['user_id'] = $user_data['get_user_data'][0]['user_id'];
  }
  if (!isset($_SESSION['username'])) {
    $_SESSION['username'] = $user_data['get_user_data'][0]['username'];
  }

//  if (!isset($_SESSION['password'])) {
//    $_SESSION['password'] = $stack['pass'];
//  }
  

   header("Location: ".WEB_ROOT."/index.php");

}
else {
  // Not logged in. Redirect back to login page
  $login_form = new BaseModuleTemplater(ROOT . '/modules/LoginForm/tpl/login_form.tpl.inc');
  $login_form->publish();
}


