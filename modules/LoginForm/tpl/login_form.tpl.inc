<link rel="stylesheet" type="text/css" href="<?php echo WEB_ROOT ?>/modules/LoginForm/css/login.css">



<div class="container">
  <div class="row">
    <div class="col-md-4 col-md-offset-4">
    <div class="panel-body">
      <form method="post" id="login-form" accept-charset="UTF-8" role="form">
        <fieldset>
          <div class="form-group">
            <input id="username" class="form-control input-sm" style="background-color: #dfdfdf; color: #000;" placeholder="Username" name="username" type="text">
          </div>
          <div class="form-group">
            <input id="pass" class="form-control input-sm" style="background-color: #dfdfdf; color: #000;" placeholder="Password" name="pass" type="password">
          </div>
          <div id="login_button">
              <input type="hidden" name="user_id" />
                <button id="sbm_btn" type="submit" style="border: 0; background: transparent">
                    <img  src="<?php echo WEB_ROOT ?>/modules/LoginForm/images/login_button.png" alt="submit" />
                </button>
           </div>
        </fieldset>
      </form>
    </div>
  </div>
  </div>
</div>

<script>
    $(document).ready(function () {
        $('#login-form').bootstrapValidator({
            // To use feedback icons, ensure that you use Bootstrap v3.1.0 or later
            feedbackIcons: {
                valid: 'glyphicon glyphicon-ok',
                invalid: 'glyphicon glyphicon-remove',
                validating: 'glyphicon glyphicon-refresh'
            },
            fields: {
                username: {
                    validators: {
                        stringLength: {
                            min: 2,
                        },
                        notEmpty: {
                            message: 'Please supply your User Name'
                        }
                    }
                },
                pass: {
                    validators: {
                        notEmpty: {
                            message: 'Please supply your password'
                        }
                    }
                }


            }
        })
            .on('success.form.bv', function (e) {
                $('#success_message').slideDown({opacity: "show"}, "slow") // Do something ...
                $('#login-form').data('bootstrapValidator').resetForm();

                // Prevent form submission
                e.preventDefault();

                // Get the form instance
                var $form = $(e.target);

                // Get the BootstrapValidator instance
                var bv = $form.data('bootstrapValidator');

                // Use Ajax to submit form data
                $.post($form.attr('action'), $form.serialize(), function (result) {
                    console.log(result);
                }, 'json');
            });
    });


</script>