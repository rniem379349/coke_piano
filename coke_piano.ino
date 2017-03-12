#include <CapacitiveSensor.h>

// capacitive sensor initialization
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); // 2 is sensor pin 
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);
//CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);
//CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);
//CapacitiveSensor   cs_4_9 = CapacitiveSensor(4,9);
//CapacitiveSensor   cs_4_10 = CapacitiveSensor(4,10);
//CapacitiveSensor   cs_4_11 = CapacitiveSensor(4,11);
//CapacitiveSensor   cs_4_12 = CapacitiveSensor(4,12);
//CapacitiveSensor   cs_4_13 = CapacitiveSensor(4,13);
//CapacitiveSensor   cs_4_14 = CapacitiveSensor(4,14);
//CapacitiveSensor   cs_4_15 = CapacitiveSensor(4,15);
//CapacitiveSensor   cs_4_16 = CapacitiveSensor(4,16);
//CapacitiveSensor   cs_4_17 = CapacitiveSensor(4,17);
//CapacitiveSensor   cs_4_18 = CapacitiveSensor(4,18);

int data_tab[16];
unsigned long time;
unsigned long timedelta;
int first = 0;
int last = -1;
int amount = 0;


void setup() 
{
	time = millis();
	timedelta = 50;
  // set up serial communication and calibrate sensors
  Serial.begin(19200);
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF);  
//   cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF); 
//   cs_4_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_10.set_CS_AutocaL_Millis(0xFFFFFFFF); 
//   cs_4_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_12.set_CS_AutocaL_Millis(0xFFFFFFFF); 
//   cs_4_13.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_14.set_CS_AutocaL_Millis(0xFFFFFFFF); 
//   cs_4_15.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_16.set_CS_AutocaL_Millis(0xFFFFFFFF); 
//   cs_4_17.set_CS_AutocaL_Millis(0xFFFFFFFF);
//   cs_4_18.set_CS_AutocaL_Millis(0xFFFFFFFF); 
}

void loop() {

  if(Serial.available() >= 0) 
  {
    // Measure the sensors
    long total_2 = cs_4_2.capacitiveSensor(30);
//    Serial.println(total_2);
    
    long total_3 = cs_4_3.capacitiveSensor(30);
//    Serial.println(total_3);
//    delay(100);
//    long total_5 = cs_4_5.capacitiveSensor(30);
//    long total_6 = cs_4_6.capacitiveSensor(30);
//    long total_7 = cs_4_7.capacitiveSensor(30);
//    long total_8 = cs_4_8.capacitiveSensor(30);
//    long total_9 = cs_4_9.capacitiveSensor(30);
//    long total_10 = cs_4_10.capacitiveSensor(30);
//    long total_11 = cs_4_11.capacitiveSensor(30);
//    long total_12 = cs_4_12.capacitiveSensor(30);
//    long total_13 = cs_4_13.capacitiveSensor(30);
//    long total_14 = cs_4_14.capacitiveSensor(30);
//    long total_15 = cs_4_15.capacitiveSensor(30);
//    long total_16 = cs_4_16.capacitiveSensor(30);
//    long total_17 = cs_4_17.capacitiveSensor(30);
//    long total_18 = cs_4_18.capacitiveSensor(30);
  
  
  //check if a sensor has been touched and send the corresponding index through serial to the .py script

  if (total_2 > 500){push(0);}
  if (total_3 > 500){push(1);} // and so on...  
//  if (total_5 > 60){Serial.write(2); delay(10);}
//  if (total_6 > 60){Serial.write(3); delay(10);}
//  if (total_7 > 60){Serial.write(4); delay(10);}
//  if (total_8 > 60){Serial.write(5); delay(10);}
//  if (total_9 > 60){Serial.write(6); delay(10);}
//  if (total_10 > 60){Serial.write(7); delay(10);}
//  if (total_11 > 60){Serial.write(8); delay(10);}
//  if (total_12 > 60){Serial.write(9); delay(10);}
//  if (total_13 > 60){Serial.write(10); delay(10);}
//  if (total_14 > 60){Serial.write(11); delay(10);}
//  if (total_15 > 60){Serial.write(12); delay(10);}
//  if (total_16 > 60){Serial.write(13); delay(10);}
//  if (total_17 > 60){Serial.write(14); delay(10);}
//  if (total_18 > 60){Serial.write(15); delay(10);}
	send();
  }
}

void send() {
	if (millis()>time+timedelta && amount>0){
		Serial.println(pop());
		first = count_pos(first);
		time = millis();
	}
}

int count_pos(int current) {
	return (current++)%10;
}

void push(int data) {
	last = count_pos(last);
	data_tab[last] = data;
	amount++;
}

int pop() {
	amount--;
	return data_tab[first];
}
