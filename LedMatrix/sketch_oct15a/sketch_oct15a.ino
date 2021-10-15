int ST_CP = 0; // khai báo các chân kết nối thanh ghi dịch
int SH_CP = 2;
int DS = 13;
int pins [8] = {3, 4, 5, 6, 7, 8, 9, 10};
byte H[8] = { 0x66,0x66,0x66,0x7E,0x7E,0x66,0x66,0x66 };
byte U[8] = { 0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x3C };
byte Y[8] = { 0x66,0x66,0x66,0x7E,0x3C,0x18,0x18,0x18 };
void setup() {
  Serial.begin(9600); // dữ liệu code đã lập trình từ máy tính nạp vào Arduino với tốc độ 9600 baud rate
  pinMode(ST_CP, OUTPUT); // cấu hình các chân là ngõ ra
  pinMode(SH_CP, OUTPUT);
  pinMode(DS, OUTPUT);
  for (int i = 0; i < 8; i++) { // vòng lặp để cấu hình các chân cathode chung
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
}
void loop() {
  for (int k = 0; k < 500; k++) { // hiển thị mỗi ký tự A là ký tự đã lập trình ở trên trong 1 giây
    display_char(H);
  }
  for (int k = 0; k < 500; k++) {
    display_char(U);
  }
  for (int k = 0; k < 500; k++) {
    display_char(Y);
  }
}
void display_char(byte ch[8]) { // phương pháp ghép kênh
  for (int j = 0; j < 8; j++) {
    digitalWrite(ST_CP, LOW);
    digitalWrite(pins[j], LOW);
    shiftOut(DS, SH_CP, LSBFIRST, ch[j]);
    digitalWrite(ST_CP, HIGH);
    //delay(1);
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, LSBFIRST, 0x00); //tắt hết led trước khi hiển thị ký tự tiếp theo
    digitalWrite(ST_CP, HIGH);
    digitalWrite(pins[j], HIGH);
  }
}
