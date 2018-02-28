<?php

  $insert_books = '';
  if(isset($_GET['location']) && ($_GET['location'] == 'new_book_form')){
    new BookForm('upload_cover_book_image');
    $insert_books = new BookForm('insert_books');
  }elseif (isset($_GET['action']) && ($_GET['action'] == 'upload_cover_book_image')){
    new BookForm('upload_cover_book_image');
  }

  $format_size = array("A0","A1","A2","A3","A4","A5","A6","A7","A8");  
  $book_form = new BaseModuleTemplater(ROOT . '/modules/BookForm/tpl/book_form.tpl.inc');
  $book_form->set('format_size',$format_size);
  $book_form->set('insert_books',$insert_books);
  $book_form->publish();

