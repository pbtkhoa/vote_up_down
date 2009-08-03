// $Id$

Drupal.behaviors.vudPlainWidget = function () {
    $('.vud-widget-plain span.up-inactive, span.down-inactive, span.up-active, span.down-active').click(function () {
	voteurl = $(this).find('a').attr('href');
	$.ajax({
	    type: 'GET',
	    url: voteurl,
	    success: function (data) {
		data = Drupal.parseJson(data);
		var newvotes = data.votes;
		var type = data.type;
		var id = data.id;
		$("#total-votes-" + type + "-" + id + " .total").html(newvotes);
	    },
	    error: function (xmlhttp) {
		alert('An HTTP '+ xmlhttp.status +' error occured. Your vote was not submitted!\n');
	    }
	});
	return false;
    });
};
