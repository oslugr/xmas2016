// Declaramos los pines donde estan conectados los RGB
int rojo = 13;
int verde = 7;
int azul = 8;

int intervalr = 1000;
int intervalv = 1000;
int intervala = 1000;

int kvelocidad = 10;

int ledStater = LOW;             // ledState used to set the LED

long previousMillisr = 0;        // will store last time LED was updated


int ledStatev = LOW;             // ledState used to set the LED

long previousMillisv = 0;        // will store last time LED was updated


int ledStatea = LOW;             // ledState used to set the LED

long previousMillisa = 0;        // will store last time LED was updated


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
 
    String entrada = Serial.readString();
    
   int velocidadr = entrada.substring(0,2).toInt();
    int velocidadg = entrada.substring(2,4).toInt();
    int velocidadb = entrada.substring(4,6).toInt(); 
  
    intervalr = velocidadr * kvelocidad;
    intervalg = velocidadg * kvelocidad;
    intervalb = velocidadb * kvelocidad;
    
    
    //Se imprime el número que se recibe
    Serial.println(intervalr);
    Serial.println(intervalg);
    Serial.println(intervalb);

  }
  unsigned long currentMillis = millis();


    Serial.println(currentMillis);


 if(currentMillis - previousMillisr > intervalr) {
    // save the last time you blinked the LED 
    previousMillisr = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStater == LOW)
      ledStater = HIGH;
    else
      ledStater = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(rojo, ledStater);
    
    
     if(currentMillis - previousMillisv > intervalv) {
    // save the last time you blinked the LED 
    previousMillisv = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStatev == LOW)
      ledStatev = HIGH;
    else
      ledStatev = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(verde, ledStater);
    
     if(currentMillis - previousMillisa > intervala) {
    // save the last time you blinked the LED 
    previousMillisa = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStatea == LOW)
      ledStatea = HIGH;
    else
      ledStatea = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(azul, ledStatera);
    
    
    
  }




















    //Se imprime el número que se recibe
//  Serial.println(entrada);
   /*
    
      if(num=="0") {
      digitalWrite(rojo, LOW);
      Serial.println("OFF");
    }
    else if(num=="1") {
      digitalWrite(rojo, HIGH);
      Serial.println("ON");
    }
    
      if(num=="3") {
      digitalWrite(verde, LOW);
      Serial.println("OFF");
    }
    else if(num=="4") {
      
      for (int i = 0; i<=4; i++)
    {
      digitalWrite(verde, HIGH);
      delay(1000);
      digitalWrite(verde, LOW);
      delay(1000);
      Serial.println("ON");

    }
    }
   
 */ 
  
}
