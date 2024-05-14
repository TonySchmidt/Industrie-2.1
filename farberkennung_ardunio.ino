#include <FtduinoSimple.h>

/*
I1 Lichtschranke innen
I2 Lichtschranke oben
I3 Lichtschranke unten
I4 Octo1(Ft.M1)
I5 Octo2(Ft.M2)


M1 send octo3 (FT.I1)
M2 Förderband unten
M3 Förderband Oben
07 Lochtschranke oben förderband und unten
08 Lichtschranke innen
*/


int farbe = 0;//rot = 1; blau = 2; grün = 3;




void setup() {
  // put your setup code here, to run once:
  //connected
  //setup
  Serial.begin(9600);
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//check belts
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
  delay(2000);
  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
  delay(2000);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  //Setup complete
  Serial.println("c1");

}

void loop() {
  //Ready
// String msg = ric->recv();
  String msg = "GO";
  if(msg == "GO"){
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    ftduino.output_set(Ftduino::O7, Ftduino::HI);
    delay(2000);
    while (!ftduino.input_get(Ftduino::I3)){//Lichtschranke unten
      //nichts
    }
    Serial.println("c2");
    ftduino.output_set(Ftduino::O7, Ftduino::LO);
    ftduino.output_set(Ftduino::O8, Ftduino::HI);
    delay(3000);
    Serial.println("c3");
    ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
    while (!ftduino.input_get(Ftduino::I1)){//Lichtschranke Oben
      ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
    }
    Serial.println("c4");
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);//farbe in Dunkelraum
    delay(500);
    ftduino.output_set(Ftduino::O8, Ftduino::LO);
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);//TXT START BEFEHL
    delay(1000);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
    while(!ftduino.input_get(Ftduino::I1)){//warten auf signal
    //nichts
    }
    delay(1000);
    checkcolor();
    ftduino.output_set(Ftduino::O7, Ftduino::HI);//schranke an
    ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
    while(!ftduino.input_get(Ftduino::I2)){//warten auf signal
    //nichts
    }
    delay(3000);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
    ftduino.output_set(Ftduino::O7, Ftduino::LO);//schranke an
  }


}

void checkcolor(){
  if(ftduino.input_get(Ftduino::I4)){//ftm1 grün oder rot
    if(ftduino.input_get(Ftduino::I5)){// rot
      farbe = 1;
      Serial.println("1");
      //send rot(1)
    } else{//grün
      farbe = 2;
      Serial.println("2");
      //send Grün(3)
    }
  } else if(ftduino.input_get(Ftduino::I5)){//ftm2 rot oder blau
    if(ftduino.input_get(Ftduino::I4)){//rot
      farbe = 1;
      //send rot (1)
      Serial.println("1");
    } else{//blau
      farbe = 3;
      //send blau (3)
      Serial.println("3");
    }
  }
}
