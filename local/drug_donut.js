google.load("visualization", "1", {packages:["corechart"]});

google.setOnLoadCallback(drawChart);

function drawChart() {
    var data = google.visualization.arrayToDataTable([
        ['Category', 'Landmark Publications'],
        ['Reproducible',     6],
        ['Irreproducible',      47]
    ]);

    var options = {
        title: '53 Selected Studies',
	legend:'none',
        width: '100%',
        height: '100%',
        pieHole: 0.2,
	pieSliceText: 'label',
	colors: ['#0598d8', '#f97263'],
	fontSize: 20,
        chartArea: {
            left: "3%",
	    right: "3%",
            top: "3%",
            height: "94%",
            width: "94%"
        }
    };

    var chart = new google.visualization.PieChart(document.getElementById('donutchart'));
    chart.draw(data, options);
}
