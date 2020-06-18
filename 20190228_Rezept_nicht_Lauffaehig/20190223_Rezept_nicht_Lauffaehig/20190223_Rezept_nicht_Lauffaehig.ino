#include <HX711_ADC.h>
#include <Wire.h>

double gesamtgewicht = 0;
int maximalgewicht = 100;
const int relay1 = 2; 
const int relay2 = 3; 
const int relay3 = 4; 
const int relay4 = 5; 
const int relay5 = 6; 
const int relay6 = 7; 
const int relay7 = 8; 
const int relay8 = 9; 
const int relay9 = 10;
const int relay10 = 11;
float Startgewicht = 0;
float Zielgewicht = 0;
float h;
float g;

//Empfangen der RasPi-Werte
const int NUMBER_OF_FIELDS = 2;
int fieldIndex = 0;
int values[NUMBER_OF_FIELDS];

//Waage
HX711_ADC LoadCell(0, 1); // parameters: dt pin, sck pin<span data-mce-type="bookmark" style="display: inline-block; width: 0px; overflow: hidden; line-height: 0;" class="mce_SELRES_start"></span>

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
  pinMode(relay9, OUTPUT);
  pinMode(relay10, OUTPUT);
  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);
  digitalWrite(relay9, HIGH);
  digitalWrite(relay10, HIGH);
  
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(2000); // load cells gets 2000ms of time to stabilize
  LoadCell.setCalFactor(999.0); // calibration factor for load cell => strongly dependent on your individual setup
}

void loop()
{    
  if (Serial.available())
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <= '9')
    {
      if (fieldIndex < NUMBER_OF_FIELDS)
      {
        values[fieldIndex] = (values[fieldIndex] * 10) + (ch - '0');
      }
    }
    else if (ch == ',')
    {
      fieldIndex = fieldIndex + 1;
    }
    else
    {
      //Serial.print("Pumpe: ");
      Serial.println(values[0]);
      //Serial.print("; Gewicht: ");
      Serial.println(values[1]);
      LoadCell.start(1000);
      LoadCell.update();                          // retrieves data from the load cell
      g = LoadCell.getData();               // get output value
      
      Startgewicht = g;
      //Serial.print("Startgewicht:");
      //Serial.println(g);
      Zielgewicht = Startgewicht + values[1];
      //Serial.print("Zielgewicht:");
      //Serial.println(Zielgewicht);
      digitalWrite(values[0]+1, LOW);                   //Pumpe Ein
      
      double merker = 0;
      do
      {
        
        digitalWrite(values[0]+1, LOW);
        LoadCell.update();
        h = LoadCell.getData();
        gesamtgewicht += h - merker;
        merker = h;
        Serial.println(h);
        delay(1);
        digitalWrite(values[0]+1, HIGH);
        
      }while(h <= Zielgewicht-0.5 && gesamtgewicht < maximalgewicht);
      //Serial.print("Erreichtes Gewicht: ");
      /*delay(3000);
      LoadCell.update();
      h = LoadCell.getData();
      Serial.println(h);
      delay(1000);*/
      values[0] = 0;
      values[1] = 0;
      fieldIndex = 0;
     // Serial.print("|");
    } 
    
  }
}

//                                \_(ò_Ó)_/
