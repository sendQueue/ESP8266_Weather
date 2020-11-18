
function loadGraph(){
  var dataPoints = [];
  const d = new Date();
  var mon = parseInt(d.getMonth());
  var day = d.getDate();
  if(day < 10){
    day = "0" + day;
  }
  mon += 1;
  if(mon < 10){
    mon = "0" + mon;
  }
  const dataFile = "https://vinii.xyz/esp/data/"+ d.getFullYear() + "-" + mon + "-" + day + "-" + document.getElementById("choose").value + ".txt";

  //query and process dataFile
  $.get(dataFile, function(data) {
    var content = data.split('\n');
    if(content.length > 0) {
  	   for(var i = 1; i< content.length; i++) {
         //only add every second value to the graph for performance reasons -> 1440 values / 2
         if(i % 2 == 0){
           var cur = parseFloat(content[i].split('-')[0]);
           //date gets send every 60 seconds
           dataPoints.push({y: cur, x: i / 60 });
           console.log(cur);
         }
  	    }
      }
  });
  setTimeout(function() {
    var chart = new CanvasJS.Chart("chartContainer", {
      animationEnabled: true,
      theme: "dark2",
      title: {
        text: "Weather of today"
      },
      data: [{
        name: "Today",
        type: "line",
        dataPoints: dataPoints
      }]
    });
    chart.render();
    //give 0.5 secs to display data
  },500);
}
