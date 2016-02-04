//Przesylana wiadomosc
String tekst;
//Okresla, do ktorego robota ma trafic wiadomosc
//robot = 1 - do robota nr 1
//robot = 2 - do robota nr 2
int robot = 0;

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
  //przeslij ja do robota, ktory nawiazal polaczenie
  if(Serial1.available())
  {
    tekst = Serial1.readStringUntil('\r');
    Serial.println("Keyence: " + tekst);
    if(robot == 1) Serial2.println(tekst);
    else if(robot == 2) Serial3.println(tekst);
    robot = 0;
  }

  //Jezeli przyszla wiadomosc od robota nr 1,
  //przeslij ja do sterownika Keyence
  if(Serial2.available())
  {
    robot = 1;
    tekst = Serial2.readStringUntil('\r');
    Serial.println("Robot nr 1: " + tekst);
    Serial1.println(tekst);
  }

  //Jezeli przyszla wiadomosc od robota nr 2,
  //przeslij ja do sterownika Keyence
  if(Serial3.available())
  {
    robot = 2;
    tekst = Serial3.readStringUntil('\r');
    Serial.println("Robot nr 2: " + tekst);
    Serial1.println(tekst);
  }
}
