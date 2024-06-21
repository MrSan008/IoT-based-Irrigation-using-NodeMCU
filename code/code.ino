//Include the library files
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3nlnGcjEU"
#define BLYNK_TEMPLATE_NAME "planting watering sytem"
#include <ESP8266WiFi.h>
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);
//#define BLYNK_AUTH_TOKEN "BSgwYfIBNJAApVH4gB-Aig9Lhj63APQ4"
char auth[] = "BSgwYfIBNJAApVH4gB-Aig9Lhj63APQ4";//Enter your Auth token
char ssid[] = "SAI DHANUSH R N";//Enter your WIFI name
char pass[] = "8971911818";//Enter your WIFI password

BlynkTimer timer;
bool Relay = 0;

//Define component pins
#define sensor A0
#define waterPump D3

void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, HIGH);
  lcd.init();
  lcd.backlight();

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  lcd.setCursor(1, 0);
  lcd.print("System Loading");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();

  //Call the function
  timer.setInterval(100L, soilMoistureSensor);
}

//Get the button value
BLYNK_WRITE(V1) {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(waterPump, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  } else {
    digitalWrite(waterPump, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF");
  }
}

//Get the soil moisture values
void soilMoistureSensor() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V0, value);
  lcd.setCursor(0, 0);
  lcd.print("Moisture :");
  lcd.print(value);
  lcd.print(" ");

}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}