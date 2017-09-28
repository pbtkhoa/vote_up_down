/**
 * @file
 * Vote Up/Down behavior.
 */
(function ($, Drupal) {

  Drupal.behaviors.voteUpDown = {
    attach: function (context, settings) {
      $('.vud-widget a').click(function (e) {
        e.preventDefault();
        var baseWidget = $(this).parents('.vud-widget');
        var routeUrl = $(this).is('a') ? $(this).attr('href') : $(this).parent().attr('href');
        var operation;

        if($(this).is('.inactive'))
          baseWidget.append('<img class="throbber" src="' + location.protocol + '//' + location.host + '/' +
              (drupalSettings.path.baseUrl == '/' ? '' : drupalSettings.path.baseUrl + '/') + settings.basePath + '/img/status-active.gif">');

        if($(this).is('a.up.inactive'))
          operation = 'up';
        else if($(this).is('a.down.inactive'))
          operation = 'down';
        else
          operation = 'reset';

        var data = routeUrl.split('?');
        var url_data = data[0].split('/');
        var entity_type = url_data[2];
        var entity_id = url_data[3];
        var points = settings.points[entity_type][entity_id];
        var uservote = settings.uservote[entity_type][entity_id] == undefined ? 0 : settings.uservote[entity_type][entity_id];
        voteUpDownService.vote(baseWidget, routeUrl, operation, settings.basePath, points, uservote);
      });
    }
  };

})(jQuery, Drupal);
