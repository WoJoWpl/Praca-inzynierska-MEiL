String tekst;

void setup() {
  //USB
  Serial.begin(9600);
  //Keyence
  Serial1.begin(9600);
  //Robot nr 1
  Serial2.begin(9600);
  //Robot nr 2
  Serial3.begin(9600);
}

void loop() {
  
  //Jezeli przyszla wiadomosc ze sterownika Keyence,
  //przeslij ja do obydwu robotow
  if(Serial1.available())
  {
    tekst = Serial1.readStringUntil('\r');
    Serial.println("Keyence: " + tekst);
    Serial2.println(tekst);
    Serial3.println(tekst);
  }

  //Jezeli przyszla wiadomosc od robota nr 1,
  //przeslij ja do sterownika Keyence
  if(Serial2.available())
  {
    tekst = Serial2.readStringUntil('\r');
    Serial.println("Robot nr 1: " + tekst);
    Serial1.println(tekst);
  }

  //Jezeli przyszla wiadomosc od robota nr 2,
  //przeslij ja do sterownika Keyence
  if(Serial3.available())
  {
    tekst = Serial3.readStringUntil('\r');
    Serial.println("Robot nr 2: " + tekst);
    Serial1.println(tekst);
  }
}
