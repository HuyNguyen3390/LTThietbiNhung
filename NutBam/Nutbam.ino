int x=0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // đọc cổng 2, cất vào biến x
  x = digitalRead(2);
  // kiểm tra xem nút có đang nhấn hay không 
  if (x == HIGH) {
    // Bật led
    digitalWrite(13, HIGH);
  } else {
    // Tắt led
    digitalWrite(13, LOW);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}
