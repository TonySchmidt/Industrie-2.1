#include <FtduinoSimple.h>
#include "RICv2.h"

RobotikInterConnect *ric;
int fach = 0;
/*

M1 
M2 Schiene (x-achse)
M3 hoch runter
M4 vor zurück


I1 Schiene Stopp Annahme und Regal 1
I2 Schiene Stopp Regal 2
I3 Schiene Stopp Ausgabe und Regal 3
I4 regal unten
I5 regal mitte
I6 Arm hinten stopp
I7  regal unten
I8 Arm vorne stopp
*/

void setup() {
Serial.begin(9600);
ric = new RobotikInterConnect(10);
ric->send(0,"Connected to Interconnect");
ric->send(0,"Setup");
Serial.println("Connected to Interconnect");
Serial.println("SETUP");
armsetup();
ric->send(0,"Setup completed");
}
void loop() {
  armsetup();
  ric->send(0,"READY");
  Serial.println("READY");
  if(ric-> can_recv()){ //wait for command
   String msg = ric->recv();

   if(msg == einlagern){
    
    einlagern();
   }

   else if (msg == order){
      auslagern();
    }
  }
}//loop


// auslager funktion
void auslagern(){
  ric->send(0,"fach");
  fach = ric->recv();
  
  switch case(fach)
    //auslagern
    case 00:
      
           
        //auslagern
        fach0_auslagern();
        ausgeben(); 
        ric->send(0,"Order geliefert");


      
   case 01:
      
           
        //auslagern
        fach1_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      
    case 02:
      
           
        //auslagern
        fach2_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      
    case 03:
      
           
        //auslagern
        fach3_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      
    case 04:
        
        //auslagern
        fach4_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      
    case 05:
       
        //auslagern
        fach5_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      
    case 06:
         
        //auslagern
        fach6_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      
    case 07:
        
        //auslagern
        fach7_auslagern();
        ausgeben();  
        ric->send(0,"Order geliefert");
      

    
  }
 }




//einlager funktion
void einlagern(){
    ric->send(0,"fach");
    fach = ric->recv();
    
    switch case(fach){
      
      case 00:
        fach0_einlagern();
        annehmen();      
        ric->send(0,"eingelagert");
    case 01:         
        fach1_einlagern();     
        annehmen();
        ric->send(0,"eingelagert");
    case 02:
      //einlagern
      fach2_einlagern();          
      annehmen(); 
      ric->send(0,"eingelagert"); 
    case 03:      
      //einlagern
      fach3_einlagern();          
      annehmen();         
      ric->send(0,"eingelagert"); 
    case 04:
      fach4_einlagern();          
      annehmen();        
      ric->send(0,"eingelagert"); 
    case 05:      
      //einlagern
      fach5_einlagern();         
      annehmen();         
      ric->send(0,"eingelagert");  
    case 06:      
      //einlagern
      fach6_einlagern();          
      annehmen();         
      ric->send(0,"eingelagert");
    case 07:      
      //einlagern
      fach7_einlagern();          
      annehmen();         
      ric->send(0,"eingelagert");

    }
    
}

//auslager funktionen
void fach7_auslagern(){
  while(!ftduino.input_get(Ftduino::I3)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur seite
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I7)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  hoch
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  hoch
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
}
void fach6_auslagern(){

  while(!ftduino.input_get(Ftduino::I3)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur seite
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I5)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  hoch
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach5_auslagern(){
  while(!ftduino.input_get(Ftduino::I3)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur seite
  }
  
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
 Serial.println(2);
  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  Serial.println(3);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach4_auslagern(){
  while(!ftduino.input_get(Ftduino::I2)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur mitte
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I7)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  hoch
  }

  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm  hoch
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }

  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas hoch(auslagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach3_auslagern(){
  while(!ftduino.input_get(Ftduino::I2)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur mitte
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I5)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  hoch zur mitte
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach2_auslagern(){
  while(!ftduino.input_get(Ftduino::I2)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur mitte
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm hoch
  delay(3000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach1_auslagern(){
  while(!ftduino.input_get(Ftduino::I7)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm hoch
  
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm hoch
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(1500);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach0_auslagern(){
  while(!ftduino.input_get(Ftduino::I5)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm hoch
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas hoch(auslagern)
  delay(1500);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm vorne hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
//einlager funktionen
void fach0_einlagern(){
  while(!ftduino.input_get(Ftduino::I5)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm hoch
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm höher
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas runter(einlagern)
  delay(1500);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm vorne hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach1_einlagern(){
  while(!ftduino.input_get(Ftduino::I7)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm runter
  
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas runter(einlagern)
  delay(1500);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach2_einlagern(){
  while(!ftduino.input_get(Ftduino::I2)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur mitte
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm etwas hoch
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  while(!ftduino.input_get(Ftduino::I4)){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas runter(einlagern)
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach3_einlagern(){
  while(!ftduino.input_get(Ftduino::I2)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur mitte
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I5)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  runter zur mitte
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas runter(einlagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach4_einlagern(){
  while(!ftduino.input_get(Ftduino::I2)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur mitte
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I7)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  hoch
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm etwas runter
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }

  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas runter(einlagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach5_einlagern(){
  while(!ftduino.input_get(Ftduino::I3)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur seite
  }
  
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
 Serial.println(2);
  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  Serial.println(3);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas runter(einlagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach6_einlagern(){
  while(!ftduino.input_get(Ftduino::I3)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur seite
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I5)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  runter
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);// arm etwas runter(einlagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  //eingelagert senden
}
void fach7_einlagern(){
  while(!ftduino.input_get(Ftduino::I3)){
  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm  zur seite
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I7)){
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  runter
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm  runter
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I8)){
  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);// arm etwas runter(einlagern)
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I6)){
  ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm  hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  //eingelagert senden
}
void ausgeben(){
  while(!ftduino.input_get(Ftduino::I3)){
    ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);//arm zur seite
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
  while(!ftduino.input_get(Ftduino::I7)){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm runter
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm etwas hoch
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  //arm raus
  while(!ftduino.input_get(Ftduino::I7)){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm runter
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  armsetup();
}
void annehmen(){
  armsetup();
  while(!ftduino.input_get(Ftduino::I8)){
    ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);//arm vorne
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);//arm hoch
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  while(!ftduino.input_get(Ftduino::I6)){
    ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm hinten
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  while(!ftduino.input_get(Ftduino::I4)){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm runter
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF); 
}

void armsetup(){
  while(!ftduino.input_get(Ftduino::I6)){
    ftduino.motor_set(Ftduino::M4, Ftduino::RIGHT);//arm hinten
    }
    ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  while(!ftduino.input_get(Ftduino::I4)){
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);//arm runter
    }
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
    
  while(!ftduino.input_get(Ftduino::I1)){
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);//arm anfang
    }
    ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}


