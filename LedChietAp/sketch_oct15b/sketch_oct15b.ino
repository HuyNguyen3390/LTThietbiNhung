int X=0;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  //đọc giá trị từ biến
  X= analogRead(A0);
  //Qui đổi sang độ sáng  
  int brightness= map(X,0,1023,0,255); 
  //sáng led brightness  
  analogWrite(9,brightness);
}
