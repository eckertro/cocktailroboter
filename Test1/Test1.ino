const int relay1 = 4; 
const int relay2 = 5; 
const int relay3 = 6; 
const int relay4 = 7; 
const int relay5 = 8; 
const int relay6 = 9; 
const int relay7 = 10; 
const int relay8 = 11; 
const int button1 = 12;
bool schalter = 0;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(button1, INPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);
  //digitalWrite(button1, HIGH);
}
void loop()
{
  Serial.print(button1);
 // int counter = 0;
 // schalter = digitalRead(button1);
// if(digitalRead(button1) == HIGH){
 //      rezept1();
//     }
 /*while (digitalRead(button1) == HIGH)
    {
      counter ++;
    
      if(counter == 1000){
       rezept1();
    }
    */
}

void relaySchalten(int relayNr, int dauer){
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
  
}
