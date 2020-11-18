

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Weather inside</title>
    <link rel="stylesheet" href="main.css"</noscript>
  </head>
  <body>
    <script type="text/javascript">
    window.onload = function(){
      loadGraph();
    }
    </script>
    <select id="choose" onchange="loadGraph()">
      <option value="t">Temperatur</option>
      <option value="p">Druck</option>
      <option value="h">Luftfeuchtigkeit</option>
    </select>
    <br>
    <br>
    <br>
    <div id="chartContainer" style="height: 370px; width: 100%;" onload="loadGraph()"></div>
    <br>
    Shows every second data point | If empty, use https!
    <script src="load.js"></script>
    <script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
    <script src="https://code.jquery.com/jquery-1.9.1.js"></script>
  </body>
</html>
