#include <CapacitiveSensor.h>

// capacitive sensor initialization
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); // 2 is sensor pin 
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);
CapacitiveSensor   cs_4_9 = CapacitiveSensor(4,9);
CapacitiveSensor   cs_4_10 = CapacitiveSensor(4,10);
CapacitiveSensor   cs_4_11 = CapacitiveSensor(4,11);
CapacitiveSensor   cs_4_12 = CapacitiveSensor(4,12);
CapacitiveSensor   cs_4_13 = CapacitiveSensor(4,13);
CapacitiveSensor   cs_4_14 = CapacitiveSensor(4,14);
CapacitiveSensor   cs_4_15 = CapacitiveSensor(4,15);
CapacitiveSensor   cs_4_16 = CapacitiveSensor(4,16);
CapacitiveSensor   cs_4_17 = CapacitiveSensor(4,17);
CapacitiveSensor   cs_4_18 = CapacitiveSensor(4,18);

//boolean values showing if a sensor has been touched
bool cs_4_2_touched;
bool cs_4_3_touched;
bool cs_4_5_touched;
bool cs_4_6_touched;
bool cs_4_7_touched;
bool cs_4_8_touched;
bool cs_4_9_touched;
bool cs_4_10_touched; 
bool cs_4_11_touched;
bool cs_4_12_touched;
bool cs_4_13_touched;
bool cs_4_14_touched;
bool cs_4_15_touched;
bool cs_4_16_touched;
bool cs_4_17_touched;
bool cs_4_18_touched;

void setup() 
{
//   set up serial communication and calibrate sensors
  Serial.begin(19200);
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF);  
   cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_4_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_10.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_4_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_12.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_4_13.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_14.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_4_15.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_16.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_4_17.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_18.set_CS_AutocaL_Millis(0xFFFFFFFF); 

//  initialize sensor touched flags as false
    cs_4_2_touched = false;
    cs_4_3_touched = false;
    cs_4_5_touched = false;
    cs_4_6_touched = false;
    cs_4_7_touched = false;
    cs_4_8_touched = false;
    cs_4_9_touched = false;
    cs_4_10_touched = false; 
    cs_4_11_touched = false;
    cs_4_12_touched = false;
    cs_4_13_touched = false;
    cs_4_14_touched = false;
    cs_4_15_touched = false;
    cs_4_16_touched = false;
    cs_4_17_touched = false;
    cs_4_18_touched = false;
}

void loop() {
  if(Serial.available() >= 0) 
  {
//     Measure the sensors
    long total_2 = cs_4_2.capacitiveSensor(30);
    long total_3 = cs_4_3.capacitiveSensor(30);
    long total_5 = cs_4_5.capacitiveSensor(30);
    long total_6 = cs_4_6.capacitiveSensor(30);
    long total_7 = cs_4_7.capacitiveSensor(30);
    long total_8 = cs_4_8.capacitiveSensor(30);
    long total_9 = cs_4_9.capacitiveSensor(30);
    long total_10 = cs_4_10.capacitiveSensor(30);
    long total_11 = cs_4_11.capacitiveSensor(30);
    long total_12 = cs_4_12.capacitiveSensor(30);
    long total_13 = cs_4_13.capacitiveSensor(30);
    long total_14 = cs_4_14.capacitiveSensor(30);
    long total_15 = cs_4_15.capacitiveSensor(30);
    long total_16 = cs_4_16.capacitiveSensor(30);
    long total_17 = cs_4_17.capacitiveSensor(30);
    long total_18 = cs_4_18.capacitiveSensor(30);
  
  
//  check if a sensor has been touched and send the corresponding index through serial to the .py script
//  no additional signals are sent as long as the sensor is touched

  if (total_2 > 500 && cs_4_2_touched == false){Serial.println(0); cs_4_2_touched = true;}
  else if (total_2 < 500 && cs_4_2_touched == true){cs_4_2_touched = false;}
  if (total_3 > 500 && cs_4_3_touched == false){Serial.println(1); cs_4_3_touched = true;}
  else if (total_3 < 500 && cs_4_3_touched == true){cs_4_3_touched = false;}
  if (total_5 > 500 && cs_4_5_touched == false){Serial.println(1); cs_4_5_touched = true;}
  else if (total_5 < 500 && cs_4_5_touched == true){cs_4_5_touched = false;}
  if (total_6 > 500 && cs_4_6_touched == false){Serial.println(1); cs_4_6_touched = true;}
  else if (total_6 < 500 && cs_4_6_touched == true){cs_4_6_touched = false;}
  if (total_7 > 500 && cs_4_7_touched == false){Serial.println(1); cs_4_7_touched = true;}
  else if (total_7 < 500 && cs_4_7_touched == true){cs_4_7_touched = false;}
  if (total_8 > 500 && cs_4_8_touched == false){Serial.println(1); cs_4_8_touched = true;}
  else if (total_8 < 500 && cs_4_8_touched == true){cs_4_8_touched = false;}
  if (total_9 > 500 && cs_4_9_touched == false){Serial.println(1); cs_4_9_touched = true;}
  else if (total_9 < 500 && cs_4_9_touched == true){cs_4_9_touched = false;}
  if (total_10 > 500 && cs_4_10_touched == false){Serial.println(1); cs_4_10_touched = true;}
  else if (total_10 < 500 && cs_4_10_touched == true){cs_4_10_touched = false;}
  if (total_11 > 500 && cs_4_11_touched == false){Serial.println(1); cs_4_11_touched = true;}
  else if (total_11 < 500 && cs_4_11_touched == true){cs_4_11_touched = false;}
  if (total_12 > 500 && cs_4_12_touched == false){Serial.println(1); cs_4_12_touched = true;}
  else if (total_12 < 500 && cs_4_12_touched == true){cs_4_12_touched = false;}
  if (total_13 > 500 && cs_4_13_touched == false){Serial.println(1); cs_4_13_touched = true;}
  else if (total_13 < 500 && cs_4_13_touched == true){cs_4_13_touched = false;}
  if (total_14 > 500 && cs_4_14_touched == false){Serial.println(1); cs_4_14_touched = true;}
  else if (total_14 < 500 && cs_4_14_touched == true){cs_4_14_touched = false;}
  if (total_15 > 500 && cs_4_15_touched == false){Serial.println(1); cs_4_15_touched = true;}
  else if (total_15 < 500 && cs_4_15_touched == true){cs_4_15_touched = false;}
  if (total_16 > 500 && cs_4_16_touched == false){Serial.println(1); cs_4_16_touched = true;}
  else if (total_16 < 500 && cs_4_16_touched == true){cs_4_16_touched = false;}
  if (total_17 > 500 && cs_4_17_touched == false){Serial.println(1); cs_4_17_touched = true;}
  else if (total_17 < 500 && cs_4_17_touched == true){cs_4_17_touched = false;}
  if (total_18 > 500 && cs_4_18_touched == false){Serial.println(1); cs_4_18_touched = true;}
  else if (total_18 < 500 && cs_4_18_touched == true){cs_4_18_touched = false;}
  }
}
