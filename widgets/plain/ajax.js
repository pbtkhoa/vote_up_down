// $Id$

Drupal.behaviors.vudPlainWidget = function () {
  $('.vud-widget-plain span.up-inactive, .vud-widget-plain span.down-inactive, .vud-widget-plain span.up-active, .vud-widget-plain span.down-active').click(function () {
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
          var longvotes = data.fullvotes;
          var shrtvotes = data.votes;
          var type = data.type;
          var id = data.id;
          var value = data.value;
          if (value == 1) {
              $('#vote-up-' + type + '-' + id).removeClass('up-inactive').addClass('up-active');
              $('#vote-down-' + type + '-' + id).removeClass('down-active').addClass('down-inactive');
          }
          if (value == -1) {
              $('#vote-down-' + type + '-' + id).removeClass('down-inactive').addClass('down-active');
              $('#vote-up-' + type + '-' + id).removeClass('up-active').addClass('up-inactive');
          }
          if (type == 'term') {
              $("#total-votes-" + type + "-" + id).html(shrtvotes);
          } else {
              $("#total-votes-" + type + "-" + id + " .total").html(longvotes);
          }
        },
        error: function (xmlhttp) {
          alert('An HTTP '+ xmlhttp.status +' error occured. Your vote was not submitted!');
        }
    });
	  return false;
  });
};
