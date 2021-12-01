#define Hall_Sensor A0          //A0 used with analog output, D2 with digital output
#define Hall_Sensor_D 2
#define ON 0
#define OFF 1

//define values for hall effect sensor, set to 0
int Val1=0,Val2=0;             //Here you can store both values, the Val2 can be boolean

//the relays connect to
int IN1 = 5, IN2=6, IN3=9, IN4=10;
String command = "";

unsigned long previousMillis = 0; // will store last time motor ran
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup()
{
 relay_init();//initialize the relay

 //setup for hall sensor
 Serial.begin(9600);
 pinMode(Hall_Sensor_D,INPUT);
 
 Serial.println("Enter 'powder', 'gas', or 'off'"); //Prompt User for Input
 
 
}
void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval || Val1<500 || Val1>530){
    previousMillis = currentMillis;
    relay_SetStatus(OFF, OFF, OFF, OFF); //if it has been X seconds *or* magnet was detected, turn off the motor
  }

   //We read both values and display them raw on the serial monitor
   Val1=analogRead(Hall_Sensor);            
   Serial.print(Val1);
   Val2=digitalRead(Hall_Sensor_D);
   Serial.print("\t");
   Serial.println(Val2);
   Serial.println(Val1,Val2);
  
   if (Val1 > 514 || Val1 < 510){
    //relay_SetStatus(ON,ON,ON,ON);
   }
   else{
    relay_SetStatus(OFF, OFF, OFF, OFF);
   }

   /*
   relay_SetStatus(OFF, ON, ON, OFF);//turn forward
   delay(20);//delay 2s
   relay_SetStatus(OFF, OFF, OFF, OFF); //turn off all the relay
   delay(2000);
   relay_SetStatus(ON, OFF, OFF, ON);//turn backward
   delay(20);//delay 2s
   relay_SetStatus(OFF, OFF, OFF, OFF); //turn off all the relay
   delay(2000);
   */
   
}



void relay_init(void)//initialize the relay
{
 //set all the relays as OUTPUT
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 relay_SetStatus(OFF, OFF, OFF, OFF); //turn off all the relay
}
//set the status of relays
void relay_SetStatus( unsigned char status_1, unsigned char status_2, unsigned char status_3, unsigned char status_4)
{
 digitalWrite(IN1, status_1);
 digitalWrite(IN2, status_2);
 digitalWrite(IN3, status_3);
 digitalWrite(IN4, status_4);
}
