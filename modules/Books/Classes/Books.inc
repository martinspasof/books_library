<?php

class Books {

  function __construct($value = null) {

    switch ($value) {
      default:
        break;
    }
  }

  public function getBooks($id = null, $get_val = null) {


    $sql_get_data = "SELECT * 
                          FROM books as bk
                        LEFT JOIN users_books u_bk 
                        ON bk.book_id = u_bk.book_id
                        ORDER BY bk.publish_date DESC";


    $db = new Db();
    $get_data = $db->select($sql_get_data);


    return $get_data;
  }

  public function pagination($stack = array()) {
    $max_count = $stack['max_count'];
    $limit = $stack['limit'];
    if (isset($_GET['page']) && (int) $_GET['page'] > 0) {
      $page = (int) $_GET['page'];
    }
    else {
      $page = 1;
    }
    $max_pages = ceil($max_count / $limit);
    $get_limit_page = $limit * $page;
    $start = $get_limit_page - $limit;
    $row = $start + 1;
    $stack['page'] = $page;
    $stack['max_pages'] = $max_pages;
    $stack['row'] = $row;
    $stack['start'] = $start;

    return $stack;
  }



}
