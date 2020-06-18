#include <HX711_ADC.h>
#include <Wire.h>

const int relay1 = 1; 
const int relay2 = 2; 
const int relay3 = 6; 
const int relay4 = 7; 
const int relay5 = 8; 
const int relay6 = 9; 
const int relay7 = 10; 
const int relay8 = 11; 
const int button1 = 12;
bool schalter = 0;
float Startgewicht = 0;
float Zielgewicht = 0;

//Waage
HX711_ADC LoadCell(3, 4); // parameters: dt pin, sck pin<span data-mce-type="bookmark" style="display: inline-block; width: 0px; overflow: hidden; line-height: 0;" class="mce_SELRES_start"></span>

void setup() 
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(button1, INPUT);
  //digitalWrite(button1, High);  //Pullup aktivieren
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);

  LoadCell.begin(); // start connection to HX711
  LoadCell.start(2000); // load cells gets 2000ms of time to stabilize
  LoadCell.setCalFactor(999.0); // calibration factor for load cell => strongly dependent on your individual setup
}

void loop()
{
  //Serial.print("Los gehts!\n");
  //int counter = 0;
 // schalter = digitalRead(button1);
 // if(digitalRead(button1) == HIGH)
 //{
   //rezept1();
     
  /*while (digitalRead(button1) == HIGH)
    {
      counter = counter+1;
      delay(1);
      if(counter == 1000)
      {
        rezept1(); 
      }  
    }*/
    
  LoadCell.update();                          // retrieves data from the load cell
  float g = LoadCell.getData();               // get output value
  //Startgewicht = g;
  //Serial.print("Startgewicht:");
  Serial.println(g);
  Zielgewicht = Startgewicht + 100.0;
  Serial.println(Zielgewicht);
  digitalWrite(relay5, LOW);                   //Pumpe 5 Ein
  while(LoadCell.getData() <= Zielgewicht)
  {
    Serial.println(LoadCell.getData());
    delay(100);
  }
  digitalWrite(relay5, HIGH);                 // Pumpe 5 Aus
  //}
  delay(1000);
}

/*void relaySchalten(int relayNr, int dauer){
  digitalWrite(relayNr,LOW);
  delay (dauer);
  digitalWrite(relayNr,HIGH);
}

void rezept1(){
  relaySchalten(relay1,1000);
  //relaySchalten(relay2,10000);
 // relaySchalten(relay3,10000);
  //relaySchalten(relay4,10000);
  relaySchalten(relay5,1000);  
}*/
