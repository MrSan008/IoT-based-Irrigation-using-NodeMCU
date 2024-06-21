# IoT based Irrigation using NodeMCU
 NodeMCU-powered IoT irrigation system for efficient watering based on real-time weather data and soil moisture levels.

![alt text][def]

Using the circuit diagram above, place the components and connect them accordingly.


WEB DASHBOARD

Now, create the Blynk dashboard on the browser. 
-Follow blynk.io and create a new account. 
-Create a new template by clicking on "Template". Fill the project details accordingly.
-Now, click on “Datastreams” tab and create two data streams using the information below.
    Virtual PIN –> Name – Moisture value / PIN — V0 / MIN — 0 / MAX — 100
    Virtual PIN –> Name – Water pump / PIN — V1 / MIN — 0 / MAX — 1
-Click the “Web dashboard” tab and include the one button and one Gauge widget to the dashboard. And then, arrange these widgets as you like.
-Click on each widgets settings buttons and select the data streams that was created earlier. Click on "Save".
-Click on search icon button and create "New Device". Select the template created earlier.

Connect NodeMCU to the computer and upload the code.

Next, copy nad paste the Blynk auth token from the web dashboard.
Enter your WiFi SSID and password in the code. 
Select Board "ESP8266 Boards" -> NodeMCU 1.0(ESP-12E Module)
Select the appropriate port.

MOBILE DASHBOARD

Create a Dashboard in your Mobile by downloading Blynk App from App/PlayStore.
Sign in with your registered email and click on the template created earlier.
Now, select on "+" icon on the top right hand corner. Add Button & Gauge from the widget box.
Select the datastreams in the dashboard and assign "Moisture value" to Gauge and "Water pump" to Button in "Switch" mode.

Relay connections with water pump and 9V battery to be made.


[def]: circuit.png