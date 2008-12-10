// $Id$

/**
 * Pre-processing for the vote database object creation.
 */
Drupal.voteUpDownAutoAttach = function() {
  var vdb = [];
  $('span.vote-up-inact, span.vote-down-inact, span.vote-up-act, span.vote-down-act').each(function () {
    // Read in the path to the PHP handler.
    uri = $(this).attr('title');
    // Remove the title, so no tooltip will displayed.
    $(this).removeAttr('title');
    // Remove the href link.
    $(this).html('');
    // Create an object with this uri, so that we can attach events to it.
    if (!vdb[uri]) {
      vdb[uri] = new Drupal.VDB(this, uri);
    }
  });
}

/**
 * The Vote database object
 */
Drupal.VDB = function(elt, uri, id) {
  var db = this;
  this.elt = elt;
  this.uri = uri;
  this.id = $(elt).attr('id');
  this.dir1 = this.id.indexOf('vote_up') > -1 ? 'up' : 'down';
  this.dir2 = this.dir1 == 'up' ? 'down' : 'up';
  $(elt).click(function() {
    // Ajax POST request for the voting data
    $.ajax({
      type: "POST",
      url: db.uri,
      success: function (data) {
        // Extract the cid so we can change other elements for the same cid
        var cid = db.id.match(/[0-9]+$/);
        var pid = 'vote_points_' + cid;
        // Update the voting arrows
        $('#' + db.id + '.vote-' + db.dir1 + '-inact').removeClass('vote-' + db.dir1 + '-inact').addClass('vote-' + db.dir1 + '-act');
        $('#' + 'vote_' + db.dir2 + '_' + cid).removeClass('vote-' + db.dir2 + '-act').addClass('vote-' + db.dir2 + '-inact');
        // Update the points
        $('#' + pid).html(data);
      },
      error: function (xmlhttp) {
        alert('An HTTP '+ xmlhttp.status +' error occured. Your vote was not submitted!\n');
      }
    });
  });
}

// Global killswitch
if (Drupal.jsEnabled) {
  $(document).ready(Drupal.voteUpDownAutoAttach);
}
