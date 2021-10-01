int sensorPin = 0;
#define led 10
float temperature = 38.5;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(0,INPUT);
}
void loop() {
int reading = analogRead(sensorPin);
float volts = (reading * 5.0);
volts /= 1024.0;
temperature = volts * 100.0;
if (temperature>37){digitalWrite(led, HIGH);}
else{digitalWrite(led, LOW);}
}
