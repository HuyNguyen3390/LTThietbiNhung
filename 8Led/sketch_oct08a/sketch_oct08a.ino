#define _latch 6
#define _clock 7
#define _data 5

void setup()
{
  pinMode(_latch, OUTPUT);
  pinMode(_clock, OUTPUT);
  pinMode(_data, OUTPUT);
}

void loop()
{
  // Chốt IC
  digitalWrite(_latch, LOW);
  // Đẩy dữ liệu ra IC
  int solieu = 255; // B11111111 hoặc 0x18
  shiftOut(_data,  _clock, LSBFIRST, solieu);
  // Mở chốt đẻ IC out dữ liệu ra
  digitalWrite(_latch, HIGH);
}
