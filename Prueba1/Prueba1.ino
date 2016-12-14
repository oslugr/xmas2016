// Declaramos los pines donde estan conectados los RGB
int rojo = 13;
int verde = 7;
int azul = 8;


void setup() {
  //Iniciamos comunicación con el puerto serie, velocidad 9600 baudios
  Serial.begin(9600);
  // Usamos el metodo setTimeout
  Serial.setTimeout(100);

  
  //Declaramos los pines como salida
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT); 
  pinMode(azul, OUTPUT); 
  
}

void loop() {
  //Si existen datos disponibles los leemos
  if (Serial.available() > 0) {
 
    int num = Serial.readString().toInt();

    //Se imprime el número que se recibe
    Serial.println(num);
    
      if(num==0) {
      digitalWrite(rojo, LOW);
      Serial.println("OFF");
    }
    else if(num==1) {
      digitalWrite(rojo, HIGH);
      Serial.println("ON");
    }
    
      if(num==3) {
      digitalWrite(verde, LOW);
      Serial.println("OFF");
    }
    else if(num==4) {
      
      for (int i = 0; i<=4; i++)
    {
      digitalWrite(verde, HIGH);
      delay(1000);
      digitalWrite(verde, LOW);
      delay(1000);
      Serial.println("ON");

    }
    }
    
  
  }
}
