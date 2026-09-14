var colour_code_classes = ['fail', 'pass', 'avg', 'stat', 'invalid']

var table = $('#utr-table')
var header = table.find('.header')

var header_data = utr_data['header']
var stat_count = header_data.length
var conts_width_percent = 100/stat_count+'%'
console.log(conts_width_percent)
for (var i = 0; i < stat_count; i++) {
	var text = $('<p>').text(header_data[i])
	var header_cont = $('<div>').addClass('header-cont valign-wrapper')
	header_cont.css({
		"width": conts_width_percent,
		"border-color": table.css('background-color')
	})
	header_cont.append(text)
	header.append(header_cont)
}

var result_data = utr_data['data']
for (var i = 0; i < result_data.length; i++) {
	var row_elem = $('<div>').addClass('row')

	results = result_data[i]
	for (var j = 0; j < stat_count; j++) {		
		var text = $('<p>').text(results['stats'][j])
		var row_cont = $('<div>').addClass('row-cont valign-wrapper')
		row_cont.addClass(colour_code_classes[results['color-code'][j]])
		row_cont.css({
			"width": conts_width_percent,
			"border-color": table.css('background-color')
		})
		row_cont.append(text)
		row_elem.append(row_cont)
	}

	table.append(row_elem)
}

