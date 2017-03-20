$('[data-timer]').each(function() {
  var start = moment();
  setInterval(_.bind(function() {
    var now = moment();
    var secs = now.diff(start, 'seconds');
    var rem = moment.duration(Math.max(parseInt($(this).data('timer')) - secs, 0), 'seconds');
    $(this).text(moment.utc(rem.as('milliseconds')).format('H:mm:ss'));
  }, this), 500);
});

$('[data-moment][data-moment-format').each(function() {
  $(this).text(moment(parseInt($(this).data('moment'))).format('lll'));
});

$('[data-moment][data-moment-humanize]').each(function() {
  $(this).text(moment.utc(parseInt($(this).data('moment'))).fromNow());
});

$('[data-snippet]').each(function() {
  $(this).addClass('pre-scrollable');
  $(this).css({
    overflowY: 'auto'
  });
  $(this).text($(this).text().split('\n').slice(0, 5).join('\n'));
  $(this).append(
    '<br>',
    '<br>',
    $('<a href="#">Show all..</a>').on('click', _.bind(function(event) {
      event.preventDefault();
      $.get($(this).data('whole'), _.bind(function(data) {
        $(this).text(data);
      }, this));
    }, this))
  );
});

$('[data-scroll]').each(function() {
  $(this).on('scroll', function() {
    $('[data-scroll="' + $(this).data('scroll') + '"]').scrollTop($(this).scrollTop());
  });
});

$('[data-automore]').each(function() {
  var baseEl = $(this);
  $('input, textarea', this).on('change', function() {
    var okay = true;
    var freeRows = [];
    $('> .row', baseEl).each(function(i) {
      var used = false;
      $('input, textarea', this).each(function() {
        if($(this).val() != '') {
          used = true;
        }

        $(this).attr('name', $(this).attr('name').replace(/\[\d*?\]$/, '[' + i + ']'));
      });
      if(!used) {
        freeRows.push(this);
        okay = false;
      }
    });

    _.each(freeRows.slice(1), function(row) {
      $(row).detach();
    });

    if(!okay) {
      return;
    }
    
    var rowEl = $('.row:first', baseEl).clone(true);
    $('input, textarea', rowEl).val('');
    $(baseEl).append(rowEl);
  }).trigger('change');
});

$('[data-showdown]').each(function() {
  var converter = new Showdown.converter();
  $(this).html(converter.makeHtml($(this).text()));
});

$('[data-confirm]').each(function() {
  $(this).on('click', function(event) {
    event.preventDefault();
    bootbox.confirm($(this).data('confirm'), _.bind(function(okay) {
      if(okay) {
        location = $(this).attr('href');
      }
    }, this));
  });
});

$('a[href="' + location.pathname + '"]').each(function() {
  $(this).parent('li').addClass('active');
});

$('select[data-value]').each(function() {
  $(this).val($(this).data('value'));
});

$('.disabled a').on('click', function(event) {
  event.preventDefault();
});
