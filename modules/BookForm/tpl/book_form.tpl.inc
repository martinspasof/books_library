<link rel="stylesheet" type="text/css" href="<?php echo WEB_ROOT ?>/modules/BookForm/css/new_book_form.css">
<div class="container">
    <div id="all_books">
        <button  type="button" style="border: 0; background: transparent"  onclick="window.location.href='<?php echo WEB_ROOT ?>?location=book_list'">
            <img id="all_books_btn" src="<?php echo WEB_ROOT ?>/modules/BookForm/images/all_books_btn.png" alt="button"/>
        </button>
    </div>
    <div style="display: none" id="success_message" class="alert alert-success">Success record!</div>

    <div class="row">
        <form  method="post" id="book-form" enctype="multipart/form-data" accept-charset="UTF-8" role="form">
            <div class="form-group col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <input type="text" class="form-control" id="book_title" name="book_title" placeholder="Book Title">
            </div>
            <div class="form-group col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <div class="input-group" id="publish_date">
                    <input type="text" class="form-control" name="publish_date" placeholder="Publish Date">
                </div>
            </div>
            <div class="clearfix"></div>
            <div class="form-group col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <input type="text" class="form-control" id="author" name="author" placeholder="Author">
            </div>
            <div class="form-group col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <select id="format_size" name="format_size" class="form-control">
                    <option value="">Select Format</option>
                    <?php foreach ($this->get('format_size') as $key=>$format_size){ ?>
                    <option value="<?php echo $format_size ?>"><?php echo $format_size; ?></option>
                    <?php }?>
                </select>                
            </div>     
            <div class="clearfix"></div>
            <div class="form-group col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <input type="text" class="form-control" id="page_count" name="page_count" placeholder="Page Count">
            </div>
            <div class="form-group col-xs-10 col-sm-10 col-md-4 col-lg-4" >
                <textarea id="resume" name="resume" class="form-control custom-control" rows="5" cols="10" placeholder="Resume"></textarea>
            </div>        
            <div class="clearfix"></div>
            <div style="margin-top: -60px;" class="form-group col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <input type="text" class="form-control" id="isbn" name="isbn" placeholder="ISBN">
            </div> 
            <div class="clearfix"></div>
            <div class="form-group col-xs-10 col-sm-10 col-md-6 col-lg-4">
                <img id="image_icon" src="<?= WEB_ROOT . '/modules/images/image_icon.png' ?>" alt="image_icon" style="width:50px;height:41px;">
                <input type="file" id="input_file" name="input_file">
            </div>
            <div class="clearfix"></div>
            <div style="float:right;margin-right:100px;margin-top: -40px;" class="col-xs-10 col-sm-4 col-md-4 col-lg-4">
                <button  type="submit" style="border: 0; background: transparent">
                    <img id="sbm_btn" src="<?php echo WEB_ROOT ?>/modules/BookForm/images/submit_button.png" alt="submit" />
                </button>
                <input type="hidden" id="user_id" name="user_id" value="<?php echo isset($_SESSION['user_id'])? $_SESSION['user_id'] : '';?>" />  
            </div>
        </form>
        <div class="clearfix"></div>

        <br /><br />
    </div>
</div>


<script type="text/javascript">



  $(document).ready(function () {

      $('#publish_date input').datetimepicker({
          format: 'YYYY/MM/DD'
      })

      $('#book-form').bootstrapValidator({
          // To use feedback icons, ensure that you use Bootstrap v3.1.0 or later
          feedbackIcons: {
              valid: 'glyphicon glyphicon-ok',
              invalid: 'glyphicon glyphicon-remove',
              validating: 'glyphicon glyphicon-refresh'
          },
          fields: {
              book_title: {
                  validators: {
                      stringLength: {
                          min: 2,
                      },
                      notEmpty: {
                          message: 'Please supply book_title'
                      }
                  }
              },
              publish_date: {
                  validators: {
                      date: {
                          format: 'YYYY/MM/DD',
                          message: 'The publish date is not valid'
                      }
                  }
              },
              author: {
                  validators: {
                      notEmpty: {
                          message: 'Please supply the author'
                      }
                  }
              },
              format_size: {
                  validators: {
                      notEmpty: {
                          message: 'Please choose format size'
                      }
                  }
              },
              page_count: {
                  validators: {
                      notEmpty: {
                          message: 'Please supply page_count'
                      }
                  }
              },
              resume: {
                  validators: {
                      notEmpty: {
                          message: 'Please supply resume'
                      }
                  }
              },
              isbn: {
                  validators: {
                      notEmpty: {
                          message: 'Please supply ISBN'
                      }
                  }
              },
              input_file: {
                  validators: {
                      notEmpty: {
                          message: 'Please choose image file'
                      }
                  }
              }


          }
      });

      $('#book-form').submit(function(e) {
          $('#success_message').slideDown().show();
          setTimeout(function(){
           location.reload();
          }, 3000);
      });

  });

</script>
