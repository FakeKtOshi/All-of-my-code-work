//LingShun Lab



#define Moisture A0 //定义AO 引脚 为 IO-A0

#define DO D7        //定义DO 引脚 为 IO-7



void setup() {

  pinMode(Moisture, INPUT);//定义A0为输入模式
  pinMode(DO, INPUT);
  Serial.begin(9600);
}

void loop() {

  //串口返回测量数据
  Serial.print("Moisture=");
  Serial.print(analogRead(Moisture));//读取AO的数值
  Serial.print("|DO=");
  Serial.println(digitalRead(DO));//读取DO的数值
  delay(1000);
}
