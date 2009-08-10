// $Id$

Drupal.behaviors.vudAlternateWidget = function () {
    $('.vud-widget-alternate .up-inactive, .up-active').click(function () {
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
		}
		$("#total-votes-" + type + "-" + id).html(shrtvotes);
	    },
	    error: function (xmlhttp) {
		alert('An HTTP '+ xmlhttp.status +' error occured. Your vote was not submitted!');
	    }
	});
	return false;
    });
};