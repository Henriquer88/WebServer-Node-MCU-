const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style type="text/css">
.button {
  background-color: #8B0000; /* Green */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
}
  
  <html>
<head>
  	<title>Botão Almost Flat em HTML</title>
	<style>
		.almost-flat-button {
			display: inline-block;
			padding: 10px 20px;
			background-color: transparent;
			border: 2px solid #d9534f;
			color: #d9534f;
			text-align: center;
			text-decoration: none;
			font-size: 16px;
			font-weight: bold;
			transition: background-color 0.3s ease;
			cursor: pointer;
		}

		.almost-flat-button:hover {
			background-color: #d9534f;
			color: #fff;
		}

		.almost-flat-button:active {
			background-color: #c9302c;
			color: #fff;
			border-color: #c9302c;
		}
	</style>
</head>

    	<title>Botão Almost Flat em HTML</title>
	<style>
		.almost-flat-button {
			display: inline-block;
			padding: 10px 20px;
			background-color: transparent;
			border: 2px solid #d534f;
			color: #d9534f;
			text-align: center;
			text-decoration: none;
			font-size: 16px;
			font-weight: bold;
			transition: background-color 0.3s ease;
			cursor: pointer;
		}

		.almost-flat-button:hover {
			background-color: #d9534f;
			color: #fff;
		}

		.almost-flat-button:active {
			background-color: #c9302c;
			color: #fff;
			border-color: #c9302c;
		}
	</style>
</head> 
    
    
    
  
  
  
  
</style>
<body style="background-color: #f9e79f ">
<center>
<div>
  
  
   <style>
        hr {
            height: 1px;
            background-color: red;
            border: none;
        }
    </style>
  
<h1>Node MCU WEBSERVER INSPER</h5>
  
  <html>
    
         <hr>
         <h3><marquee> Teste Controle de Motores <BR></marquee><h3>
         <hr>
           
 <h3>MOTORES</h3>
          
  <button class="almost-flat-button" onclick="send(1)">MOTOR X</button>
  <button class="almost-flat-button" onclick="send(0)">MOTOR Y</button> <BR>
  <BR>

  <button class="almost-flat-button" onclick="send(2)">MOTOR Z</button> <BR>
  <BR>   
    
  <hr>
  <h3> Acionamento do Rele  <BR><h3>
    <hr>
  <button class="almost-flat-button" onclick="send(3)">LIGAR</button> <BR>
<BR>   
<button class="almost-flat-button" onclick="send(4)">DESLIGAR</button> <BR>
  
</div>
 <br>
<div><h2>
   <hr>
        
         <h3>Leitura dos Passos  </h3>
           Motor X: <span id="adc_val">0</span><br><br>
           Motor Y: <span id="adc_val">0</span><br><br>
           Motor Z: <span id="adc_val">0</span><br><br>
      <hr>
        
  LED State: <span id="state">NA</span>
               
        <hr>
</h2>
</div>
<script>
function send(led_sts) 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "led_set?state="+led_sts, 0);
  xhttp.open("GET", "led_set?state="+led_sts, 1);
  xhttp.open("GET", "led_set?state="+led_sts, 2);
  xhttp.open("GET", "led_set?state="+led_sts, 3);
  xhttp.open("GET", "led_set?state="+led_sts, 4);
  xhttp.send();
}
setInterval(function() 
{
  getData();
}, 2000); 
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("adc_val").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "adcread", true);
  xhttp.send();
}
</script>
</center>
</body>
</html>
)=====";