// $Id$

Drupal.behaviors.vudUpdownWidget = function () {
  $('.vud-widget-updown .up-active, .up-inactive, .down-active, .down-inactive').click(function () {
    if ($(this).hasClass('denied')) {
      alert(Drupal.settings.vud_node.widget_message);
      return false;
    }
    voteurl = $(this).parent().attr('href');
    $.ajax({
        type: 'GET',
        url: voteurl,
        success: function (data) {
          data = Drupal.parseJson(data);
          var shrtvotes = data.votes;
          var type = data.type;
          var id = data.id;
          var value = data.value;
          if (value == 1) {
              $('#updown-up-' + type + '-' + id).removeClass('up-inactive').addClass('up-active');
              $('#updown-down-' + type + '-' + id).removeClass('down-active').addClass('down-inactive');
          }
          if (value == -1) {
              $('#updown-down-' + type + '-' + id).removeClass('down-inactive').addClass('down-active');
              $('#updown-up-' + type + '-' + id).removeClass('up-active').addClass('up-inactive');
          }
          $("span#total-votes-" + type + "-" + id).html(shrtvotes);
        },
        error: function (xmlhttp) {
          alert('An HTTP '+ xmlhttp.status +' error occured. Your vote was not submitted!');
        }
    });
    return false;
  });
};
