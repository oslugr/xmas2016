int option;

// Declaramos los pines para el RGB
int rojo = 13;
int verde = 12;
int azul = 11;
 
void setup(){
//Velocidad de transmision
  Serial.begin(9600);
//  
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT); 
  pinMode(azul, OUTPUT); 
}

void loop(){
  //si existe datos disponibles los leemos
  if (Serial.available()>0){
    //leemos la opcion enviada
    option=Serial.read();
    //Programacion para Led Rojo
    if(option=='0') {
      digitalWrite(rojo, LOW);
      Serial.println("OFF");
    }
    else if(option=='1') {
      digitalWrite(rojo, HIGH);
      Serial.println("ON");
    }
    //Programacion para Led Verde
     if(option=='2') {
      digitalWrite(verde, LOW);
      Serial.println("OFF");
    }
    else if(option=='3') {
      digitalWrite(verde, HIGH);
      Serial.println("ON");
    }
    //Programacion para Led Azul
     if(option=='4') {
      digitalWrite(azul, LOW);
      Serial.println("OFF");
    }
    else if(option=='5') {
      digitalWrite(azul, HIGH);
      Serial.println("ON");
    }  
  }
  else{
    }
}

