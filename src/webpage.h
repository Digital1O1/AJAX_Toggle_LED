
String html_1 = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
      h1 {
        font-family: Arial, Helvetica, sans-serif;
        font-size: 22px;
        padding: 10px;
        color: #006666;
      }

      table {
        font-family: Arial, Helvetica, sans-serif;
        font-size: 17px;
        border-collapse: collapse;
        width: 35%;
        margin: 0 auto;
        padding: 10px;
      }

      td, th {
        border: 1px solid #d1e0e0;
        text-align: center;
        padding: 8px;
        width: 100px;
        height: 50px;
      }

      th {
        color: #006666;
        height: 30px;
      }

      #butO0, #butO1, #butO2, #butO3 {
        padding:10px 10px 10px 10px;
        width:60%;
        background-color: #e0ebeb;
        font-size: 80%;
        cursor: pointer;
        border-radius: 4px;
        transition-duration: 0.4s;
      }

      #butREAD {
        padding:10px 10px 10px 10px;
        width: 90px;
        height: 40px;
        background-color: #98e6e6;
        font-size: 80%;
        cursor: pointer;
        margin: 0 auto;
        border-radius: 4px;
      }

      p {
        padding: 1px;
      }
    </style>

    <!-- <script> tag is used to define a client-side script (JavaScript). -->
    <script>
      function switchO_0() 
      {
        var button_text = document.getElementById("butO0").value;
        //<!-- ajaxLoad manda estado (L o H) + salida (0, 1, 2, 3) -->
        if(button_text == "ON") 
        { 
          ajaxLoad('H0');  
        }
        else
        { 
          ajaxLoad('L0'); 
        }
      }

      function switchO_1() 
      {
        var button_text = document.getElementById("butO1").value;
        if(button_text == "ON") 
        {
           ajaxLoad('H1');  
        }
        else                    
        { 
          ajaxLoad('L1'); 
        }
      }

      function switchO_2() 
      {
        var button_text = document.getElementById("butO2").value;
        if(button_text == "ON") 
        { 
          ajaxLoad('H2'); 
        }
        else                   
         { 
            ajaxLoad('L2');
         }
      }

      function switchO_3() 
      {
        var button_text = document.getElementById("butO3").value;
        if(button_text == "ON") 
        { 
          ajaxLoad('H3');  
        }
        else
        {
           ajaxLoad('L3'); 
        }
      }

      function readSTATE() 
      {
        ajaxLoad('STATE');
      }

      var ajaxRequest = null;

      // XMLHttpRequest == object used to exchange data with server
      // Code to be used for modern browsers
      if(window.XMLHttpRequest)
      { 
        ajaxRequest = new XMLHttpRequest();  // Creates a new XMLHttpRequest object
      }

      // Code to be uesd for old IE browsers
      else
      { 
        ajaxRequest = new ActiveXObject("Microsoft.XMLHTTP"); 
      }

      function ajaxLoad(ajaxURL) 
      {
        if(!ajaxRequest) 
        {
           alert("AJAX is not supported."); return; 
        }

        /*
          Notes about Open() function
          
          What does it do : Specifies the request

          Syntax : open(method, url, async, user, psw)

          method: the request type GET or POST
          url: the file location
          async: true (asynchronous) or false (synchronous)
          user: optional user name
          psw: optional password
        */

        ajaxRequest.open("GET", ajaxURL, true);

        /*
          Notes about onreadystatechange

          What does it do : Defines a function to be called when the readyState property changes
        */
        ajaxRequest.onreadystatechange = function() 
        {
          /*
            Notes about readyState
            
              What does it do : Holds status of XMLHttpRequest

              0 : request not initialized
              1 : server connection established
              2 : request received
              3 : processing request
              4 : request finished and response is ready

            Notes about status

            	Returns the status-number of a request
              200: "OK"
              403: "Forbidden"
              404: "Not Found"
              For a complete list go to the Http Messages Reference
          */
          if(ajaxRequest.readyState == 4 && ajaxRequest.status == 200) 
          {
            // Returns the response data as a string
            var ajaxResult = ajaxRequest.responseText;

            // Split string into array of substrings
            tmpArray = ajaxResult.split(":");

            if(tmpArray[0] === "0") 
            {
              /*
                Notes about getElementById()

                  Most commonly used methods
                  Used when you want to manipulate/get info from anelement in your document
                  Returns NULL ifno elements with specified IDexists
                  ID should be unique 
                    If more than one element has the same ID, getElementById() returns the first element 
              */
              // The document object is reffering to the HTML stuff towards the bottom (The radio buttons)
              
              // Get element with id="but03" and change the 'value' to ON
              document.getElementById("butO3").value = "ON";                  

              document.getElementById("butO3").style.backgroundColor = "#66ff33";
              
              // Change contents of HTML element
              document.getElementById("f4c1").innerHTML = "LOW"; 
            }

            else 
            {
              document.getElementById("butO3").value = "OFF";
              document.getElementById("butO3").style.backgroundColor = "#ff3300";
              document.getElementById("f4c1").innerHTML = "HIGH";
            }

            if(tmpArray[1] === "0") 
            {
              document.getElementById("butO2").value = "ON";
              document.getElementById("butO2").style.backgroundColor = "#66ff33";
              document.getElementById("f3c1").innerHTML = "LOW";
            }

            else 
            {
              document.getElementById("butO2").value = "OFF";
              document.getElementById("butO2").style.backgroundColor = "#ff3300";
              document.getElementById("f3c1").innerHTML = "HIGH";
            }

            if(tmpArray[2] === "0") 
            {
              document.getElementById("butO1").value = "ON";
              document.getElementById("butO1").style.backgroundColor = "#66ff33";
              document.getElementById("f2c1").innerHTML = "LOW";
            }

            else 
            {
              document.getElementById("butO1").value = "OFF";
              document.getElementById("butO1").style.backgroundColor = "#ff3300";
              document.getElementById("f2c1").innerHTML = "HIGH";
            }

            if(tmpArray[3] === "0") 
            {
              document.getElementById("butO0").value = "ON";
              document.getElementById("butO0").style.backgroundColor = "#66ff33";
              document.getElementById("f1c1").innerHTML = "LOW";
            }

            else 
            {
              document.getElementById("butO0").value = "OFF";
              document.getElementById("butO0").style.backgroundColor = "#ff3300";
              document.getElementById("f1c1").innerHTML = "HIGH";
            }

            document.getElementById("reply").innerHTML = "LAST COMMAND: " + ajaxResult;
          }
        }
        // Sends the request to the server (used for GET)
        ajaxRequest.send();
      }
      
      //<!-- update status every 10 seconds -->
      //<!--setInterval("readSTATE()", 10000); -->
    </script>

    <!-- Execute a JavaScript immediately after a page has been loaded: -->
<body onload="readSTATE()">
  <h1><center>ESP8266 AJAX Control Outputs</center></h1>

  <table>
    <tr>
      <th>PIN/GPIO</th>
      <th>Current State</th>
      <th>Command</th>
    </tr>
    <tr>
      <td>D0/16</td>
      <td id="f1c1">LOW</td>
      <td><input type="button" id="butO0" onclick="switchO_0()" value="" /></td>
    </tr>
    <tr>
      <td>D1/05</td>
      <td id="f2c1">LOW</td>
      <td><input type="button" id="butO1" onclick="switchO_1()" value="" /></td>
    </tr>
    <tr>
      <td>D2/04</td>
      <td id="f3c1">LOW</td>
      <td><input type="button" id="butO2" onclick="switchO_2()" value="" /></td>
    </tr>
    <tr>
      <td>D3/00</td>
      <td id="f4c1">LOW</td>
      <td><input type="button" id="butO3" onclick="switchO_3()" value="" /></td>
    </tr>
</table>
<div class="">
  <p></p>
  <center><input type="button" id="butREAD" onclick="readSTATE()" value="UPDATE" /></center>
  <p></p>
    <p id="reply" style="text-align:center; font-size: 14px; font-family: sans-serif;"></p>
</div>
</body>

</head>

</html>
)=====";
