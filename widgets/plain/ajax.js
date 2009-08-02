// $Id$

Drupal.behaviors.vudPlainWidget = function () {
    $('.vud-widget-plain span.up-inactive, span.down-inactive, span.up-active, span.up-inactive').each(function () {
	voteurl = $(this).find('a').attr('href');
	$(this).html('');
    });
    $('.vud-widget-plain span.up-inactive, .vud-widget-plain span.down-inactive').click(function () {
	$.get(voteurl, function (data) {
	    data = Drupal.parseJson(data);
	    newVotes = data.votes.toString();
	    console.log(newVotes);
	});
    });
};
