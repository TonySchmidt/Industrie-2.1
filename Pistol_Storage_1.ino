//Lager 1 Sensor - I1
//Lager 2 Sensor - I2
//Lager 1 Motor - M1
//Lager 2 Motor - M2
//Förderband unten - M3
//Förderband oben - M4
//Start Sensor - I3
#include <FtduinoSimple.h>

void setup() {
  //conneteed
  //setup
  // put your setup code here, to run once:
  //Lager 1 Schieber nach hinten
  while(!ftduino.input_get(Ftduino::I2)){
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
  //Lager 2 Schieber nach hinten
  while(!ftduino.input_get(Ftduino::I1)) {
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);  
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
  //Förderband leeren
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //setup complete
}

void loop() {
  /*//READY
  while(//msg)){
    
  }*/
  while(!ftduino.input_get(Ftduino::I3)){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
  }
  delay(6000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  
  ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT);//schieber 1
  delay(2200);
  while(!ftduino.input_get(Ftduino::I1)){
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);
  delay(2550);
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  delay(6000);
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//schieber 2
  delay(1500);
  while(!ftduino.input_get(Ftduino::I2)){
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);
  delay(3000);
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  delay(6000);
}






