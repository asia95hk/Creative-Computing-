
//the basis of this code comes from the arduino projects book pg43)

const int sensorPin = A0;
const float baselineTemp = -19.25;
int green = 4;
int yellow = 6;
int red = 8;

void setup(){
  Serial.begin(9600); 

  for (int pinNumber = 4; pinNumber<=8; pinNumber+=2) {
    pinMode (pinNumber,OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
 //converting ADC reading to voltage
 float voltage = (sensorVal/1024.0) * 5.0;
 Serial.print(" , Volts: ");
 Serial.print(voltage);
 Serial.print(", degrees C: ");
 float temperature = (voltage - .5) * 100;
 Serial.println(temperature);

 if(temperature < baselineTemp){
        digitalWrite(green, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(red, LOW);   }

 else if(temperature >= baselineTemp+1 && temperature < baselineTemp+4) {
        digitalWrite(green,HIGH);
        digitalWrite(yellow,LOW);
        digitalWrite(red,LOW);    }

else if(temperature >= baselineTemp+4 && temperature < baselineTemp+10) {
        digitalWrite(green,HIGH);
        digitalWrite(yellow,HIGH);
        digitalWrite(red,HIGH);    }

else if(temperature >= baselineTemp+10){
        digitalWrite(green,HIGH);
        digitalWrite(yellow,HIGH);
        digitalWrite(red,HIGH);    }

   delay(1);
}
 

