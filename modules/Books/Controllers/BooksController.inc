<?php

$books = new Books();
$get_books = $books->getBooks();
$stack = [];
$stack['max_count'] = count($get_books);
$stack['limit'] = 4;

$paging = $books->pagination($stack);
$slice_get_books = array_slice($get_books, $paging['start'], $paging['limit']);

$book_list = new BaseModuleTemplater(ROOT . '/modules/Books/tpl/book_list.tpl.inc');
$book_list->set('slice_get_books', $slice_get_books);
$book_list->set('paging', $paging);
$book_list->publish();


