<link rel="stylesheet" type="text/css" href="<?php echo WEB_ROOT ?>/modules/Books/css/book_list.css">

<div class="container">
    <div id="new_book_button">
        <button  type="button" style="border: 0; background: transparent" onclick="window.location.href='<?php echo WEB_ROOT ?>?location=new_book_form'">
            <img id="new_book_btn" src="<?php echo WEB_ROOT ?>/modules/Books/images/new_book_button.png"
                 alt="button" />
        </button>
    </div>

    <table id="book_list_table" class="table">
        <tbody>
            <?php
            $row=0;
            foreach ($this->get('slice_get_books') as $key => $data) {

                 $book_title = trim(strtolower($data['book_title']));
                 $book_title = str_replace(' ', '_', $book_title);
                 $path = ROOT . '/media/cover/uploads/'.$book_title;
                 $web_root = WEB_ROOT . '/media/cover/uploads/'.$book_title;

                 $files = scandir($path);
              ?>
              <?php
              //$row = ($row === 4) ? 0 : $row;
              if($row%4===0){ ?>
              <tr id="<?= 'book_' . $data['book_id']; ?>">
              <?php } ?>
                  <td>
                      <img src="<?= $web_root.'/'.$files[2] ?>" alt="<?php echo $book_title; ?>" style="width:150px;height:128px;">
                      <div>
                          <div><?= $data['book_title']; ?></div>
                          <div><?= $data['author']; ?></div>
                          <div>Pages: <?= $data['page_count']; ?></div>
                          <div>Format: <?= $data['book_format']; ?></div>
                          <div>ISBN: <?= $data['isbn']; ?></div>
                          <div>Publish Date: <?= date('m/d/Y', strtotime($data['publish_date'])); ?></div>
                      </div>
                  </td>
              <?php
              $row++;
              if($row%4===0 && $row !==0){
                  $row = 0;
                  ?>
              </tr>
              <?php }

              ?>

    <?php } ?>
        </tbody>
    </table>

<?php

$get_next_page = ($this->get('paging')['page'] < $this->get('paging')['max_pages']) ? $this->get('paging')['page'] : ($this->get('paging')['max_pages'] - 1);
$get_previous_page = $this->get('paging')['page'] > 1 ? $this->get('paging')['page'] : 2;

?>
    <span style='display:none' id="previous_number"><?php echo $get_previous_page ?></span>
    <span style='display:none' id="next_number"><?php echo $get_next_page ?></span>
    <span style='display:none' id="max_pages"><?php echo $this->get('paging')['max_pages'] ?></span>

<div id="pager">
    <button id="previousNumber" type="button" style="border: 0; background: transparent" onclick="get_page(this)">
        <img  src="<?php echo WEB_ROOT ?>/modules/Books/images/previous_btn.png" alt="previous button" />
    </button>

    <button id="nextNumber" type="button" type="submit" style="border: 0; background: transparent" onclick="get_page(this)">
        <img  src="<?php echo WEB_ROOT ?>/modules/Books/images/next_btn.png" alt="next button" />
    </button>
</div>
</div>

<script>
    function get_page(element) {


         if(element.id == 'previousNumber'){
            pageId =parseInt($('#previous_number').text(),10) - 1 ;

         }else if(element.id == 'nextNumber'){
            pageId = parseInt($('#next_number').text(),10) + 1 ;

         }

        $.ajax({
            url: "index.php",
            type: "get",
            data: {action: 'get_page_id', page: pageId, location: 'book_list'},
            success: function (response) {
                var table = $(response).find('table');
                $('#book_list_table').empty();
                table.map(function(elem, index) {
                    table_content = $(this).html();
                    $('#book_list_table').append('' + table_content + '');
                })

                var max_pages = parseInt($('#max_pages').text(),10);

                if(element.id == 'previousNumber'){
                    $page_id =(pageId > 1) ? pageId : 2;
                    $('#previous_number').text($page_id) ;
                    $('#next_number').text(pageId+1);

                }else if(element.id == 'nextNumber'){
                    $page_id = (pageId < max_pages) ? pageId : (max_pages - 1);
                    $('#next_number').text($page_id);
                    $('#previous_number').text( pageId - 1) ;
                }

            },
            error: function (jqXHR, textStatus, errorThrown) {
                console.log(textStatus, errorThrown);
            }
        });
    }

</script>