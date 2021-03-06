#include <Servo.h>

#include <GSM.h>


Servo myservo;
int angle=0;
char inchar;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);

}

void loop() {

  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
  Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"Mobile Number\"\r ");
delay(1000);

      break;

case 'r':
      Serial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(1000);
      
   if(Serial.available()>0)
  {
  inchar=Serial.read();
  if(inchar=='$')
  {
  //delay(100);
  inchar=Serial.read();
  if(inchar=='A')
  {
  delay(100);
  inchar=Serial.read();
  if(inchar=='R')
  {
  Serial.println("servo turning RIGHT\r");
  for(angle=0;angle<=180;angle+=5)
    {
      myservo.write(angle);
      delay(150);
    }
  }
 else if(inchar=='L')
   {
  Serial.println("servo turning LEFT\r");
  for(angle=180;angle>=0;angle-=5)
    {
      myservo.write(angle);
      delay(150);
    }
   }
   delay(2000);
   Serial.println("AT+CMGD=1,4");
   delay(1000);
  }
  }
  
}
break;
}
}
