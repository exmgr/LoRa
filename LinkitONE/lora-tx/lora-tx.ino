String str;
void setup() {
  Serial.begin(115200);
  while (!Serial);


  Serial.println("Lora TX Test");
  Serial1.begin(57600);
  while (!Serial1);

  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  Serial1.setTimeout(2000);
  str = Serial1.readStringUntil('\n');
  Serial1.println("sys get ver");
  Serial.println("sys get ver");

  str = Serial1.readStringUntil('\n');
  Serial.println(str);
  Serial1.println("mac pause");
  Serial.println("mac pause");

  str = Serial1.readStringUntil('\n');
  Serial.println(str);


  Serial1.println("radio set pwr 14");
  Serial.println("radio set pwr 14");
  str = Serial1.readStringUntil('\n');
  Serial.println(str);


  digitalWrite(3, LOW);
}
void loop() {

  Serial1.println("radio tx 123");
  Serial.println("radio tx 123");
  str = Serial1.readStringUntil('\n');
  Serial.println(str);
  delay(10000);
}
