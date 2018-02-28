<?php

class LoginForm {

  function __construct() {
    
  }

  public function getUserData($stack = array()) {
    $clause_user_id = '';
    $is_user_id = false;
    if (isset($stack['user_id']) && $stack['user_id']) {
      $is_user_id = true;
      $clause_user_id = " AND us.id='{$stack['user_id']}' ";
    }    
    
    $clause_username = '';
    $is_username = false;
    if (isset($stack['username']) && $stack['username']) {
      $is_username = true;
      $username = strtolower($stack['username']);
      $clause_username = " AND LOWER(us.username)='{$username}' ";
    }

    $clause_password = '';
    $is_pass = false;
    if (isset($stack['pass']) && $stack['pass']) {
      $is_pass = true;
      $clause_password = " AND us.pass='{$stack['pass']}' ";
    }

    $sql_get_user_data = "SELECT us.* 
                            FROM users as us
                          WHERE 1=1
                          $clause_user_id
                          $clause_username
                          $clause_password
                          ORDER BY us.user_id";

    $db = new Db();
    $get_user_data = $db->select($sql_get_user_data);

//    if (isset($id) && $id) {
//      echo '<user_info style="display:none">' . json_encode($get_data) . '</user_info>';
//    }

    $user_data = array();
    $user_data['is_auth'] = $is_username && $is_pass;
    $user_data['get_user_data'] = $get_user_data;
    
    return $user_data;
  }

}
