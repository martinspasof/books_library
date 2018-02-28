<?php

define('ROOT', dirname($_SERVER['SCRIPT_FILENAME']));
$WEB_ROOT = "http://" . $_SERVER['HTTP_HOST'] . dirname($_SERVER['PHP_SELF']) . "/";
define('WEB_ROOT', $WEB_ROOT);
define('SITE_ROOT', realpath(dirname(__FILE__)));

include ROOT . '/html/header.inc';
require_once("modules/AutoLoader/Classes/AutoLoader.inc");
require './Db.inc';

//load login form if user is not authentication
if (!isset($_SESSION['username'])) {
  include ROOT . '\modules\LoginForm\Controllers\LoginController.inc';
}
else {
  if (isset($_GET['location'])) {
    switch ($_GET['location']) {
      case 'book_list':
      default:
        include ROOT . '\modules\Books\Controllers\BooksController.inc';
        break;
      case 'new_book_form':
        include ROOT . '\modules\BookForm\Controllers\BookFormController.inc';
        break;
    }
  }
  else {
    include ROOT . '\modules\Books\Controllers\BooksController.inc';
  }

}

include ROOT . '/html/footer.inc';
