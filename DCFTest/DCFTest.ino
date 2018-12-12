
#define LEDPIN 4
#define DCFPIN 9

void setup() {
  Serial.begin(9600);
  Serial.println("DCF77 test sketch by 'jurs'");
  pinMode(LEDPIN, OUTPUT);
  pinMode(DCFPIN, INPUT_PULLUP);
}

boolean lastState;
unsigned long lastChangeTime;
unsigned int hitime, lotime, pulsetime;

void loop() {
  boolean state= digitalRead(DCFPIN);
  if (state!=lastState)
  {
//    digitalWrite(LEDPIN,state); // mit dieser Zeile ==> schlechte Daten
    long changeTime=millis();
    if (lastState)
    {
      Serial.print("H ");
      hitime=changeTime-lastChangeTime;
      Serial.print(hitime);
      Serial.print('\t');
    }
    else 
    {
      Serial.print("L ");
      lotime=changeTime-lastChangeTime;
      Serial.print(lotime);
      Serial.print('\t');
      pulsetime=hitime+lotime;
      Serial.print("= ");
      Serial.print(pulsetime);
      if (pulsetime>=960 && pulsetime<=1040)
      {
        Serial.print("\tOK  ");
        if (hitime<150) Serial.println('0'); else Serial.println('1');
      }
      else if (pulsetime>=1960 && pulsetime<=2040) Serial.println("\tMinute Marker");
      else Serial.println();
    }
    lastState=state;
    lastChangeTime=changeTime;
  }
}
