/**
 * @file
 * Vote Up/Down behavior service
 */
(function ($, Drupal) {

  window.voteUpDownService = (function() {
    function voteUpDownService() {}
    voteUpDownService.vote = function(baseWidget, url, operation, basePath, points, uservote) {
      $.ajax({
        type: "GET",
        url: url,
        success: function(response) {
          baseWidget.find('.throbber').remove();
          baseWidget.find('.reset').addClass('element-invisible');
          baseWidget.find('.up.active').each(function () {
            $(this).removeClass('active').addClass('inactive');
          });
          baseWidget.find('.down.active').each(function () {
            $(this).removeClass('active').addClass('inactive');
          });
          if(operation !== 'reset') {
            baseWidget.find('.' + operation).each(function () {
              $(this).removeClass('inactive').addClass('active');
            });
            baseWidget.find('.reset').removeClass('element-invisible');
          }
          switch (operation) {
            case 'up':
              points -= uservote;
              points += 1;
              uservote = 1;
              break;
            case 'down':
              points -= uservote;
              points -= 1;
              uservote = -1;
              break;
            case 'reset':
              points -= uservote;
              uservote = 0;
              break;
          }
          baseWidget.find('.vote-current-score strong').text(points);

          var data = url.split('?');
          var url_data = data[0].split('/');
          var entity_type = url_data[2];
          var entity_id = url_data[3];

          drupalSettings.points[entity_type][entity_id] = points;
          drupalSettings.uservote[entity_type][entity_id] = uservote;
        }
      });
    };
    return voteUpDownService;
  })();

})(jQuery, Drupal);
