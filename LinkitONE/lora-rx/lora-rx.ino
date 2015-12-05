String str;
void setup() {
  Serial.begin(115200);
  while (!Serial);


  Serial.println("Lora RX Test");
  Serial1.begin(57600);
  while (!Serial1);

  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  Serial1.setTimeout(2000);
  str = Serial1.readStringUntil('\n');
  Serial1.println("radio set wdt 105000");
  Serial.println("radio set wdt 105000");

  str = Serial1.readStringUntil('\n');
  Serial.println(str);
  Serial1.println("mac pause");
  Serial.println("mac pause");

  str = Serial1.readStringUntil('\n');
  Serial.println(str);
  digitalWrite(3, LOW);
}
void loop() {
  // switch recieve mode
  Serial1.println("radio rx 0");
  Serial.println("radio rx 0");
  str = Serial1.readStringUntil('\n');
   Serial.println(str);
  if ( str.indexOf("ok") == 0 ) {
    int ok = 0;
    while ( ok == 0 ) {
      str = Serial1.readStringUntil('\n');
      if ( str.length() > 1 ) {

        Serial.println("Received something");
        Serial.println(str);

        if ( str.indexOf("radio_rx") >= 0 ) {
          if ( str.indexOf("0123456789AB") >= 0 ) {
            int j;
            for ( j = 0 ; j < 10 ; j++) {
              digitalWrite(3, HIGH);
              delay(100);
              digitalWrite(3, LOW);
              delay(100);
            }
          }
          ok = 1;
        }
      }
    }
  }
}
