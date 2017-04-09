char NAME[10] = "LAMPY";
char BPS      = '4';
char PASS[10] = "0000";
 
 
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  digitalWrite(13, HIGH);
  delay(10000);
  digitalWrite(13, LOW);
  
  Serial.print("AT");
  delay(1000);

  Serial.print("AT+NAME");
  Serial.print(NAME);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.print(BPS);
  delay(1000);

  Serial.print("AT+PIN");
  Serial.print(PASS);
  delay(1000);
  
}
 
void loop() {
  digitalWrite(13, !digitalRead(13));
  delay(500);
}
