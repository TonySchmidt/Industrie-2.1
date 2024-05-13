#include <FtduinoSimple.h>
/*
M1 Aufzug
M2 Förderband
M3 Licht-Lichtschranke
I1 Lichtschranke 
I2 Stop unten
I3 Stop oben
*/
RobotikInterConnect *ric;

void setup() {
ric->send(0,"Connected to Interconnect");
ric->send(0,"Setup");
go_down();
ric->send(0,"Setup completed");
}
void loop() {
  ric->send(0,"READY");
  String msg = ric->recv();
  if(msg == GO){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
    delay(1000);
    while (!ftduino.input_get(Ftduino::I1)){
      ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    }
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
    go_up();
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
    delay(5000);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
    go_down();
  }

}

void go_down(){
  while (!ftduino.input_get(Ftduino::I2)){
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void go_up(){
  while (!ftduino.input_get(Ftduino::I3)){
    ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

