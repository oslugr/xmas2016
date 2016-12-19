/* Parpadeo de tres tiras de led de color rojo, verde y azul, a las que se les pasa un número de 6 cifras, siendo las dos primeras las que determinan la velocidad
 * de parpadeo del led rojo, las dos siguientes al led verde y las dos últimas a la tira azul.
 *  
 * Con la inestimable colaboración de Renato y Pablo, sin ellos no sería posible.
 */


// Declaramos los pines donde estan conectados los RGB
int rojo = 13;
int verde = 12;
int azul = 11;

//Declaramos el intervalo de tiempo del parpadeo de cada led

int intervalr = 1000; //rojo
int intervalg = 1000; //verde
int intervalb = 1000;//blue

//Declaramos la velocidad que determina la iluminación de los leds

int kvelocidad = 10;

//Iniciamos el led rojo como apagado 

int ledStater = LOW;             

//Variable en la que se guarda el ultimo tiempo desde que se actualizo el estado del led

long previousMillisr = 0;        

//Iniciamos el led verde como apagado

int ledStateg = LOW;             

//Variable en la que se guarda el ultimo tiempo desde que se actualizo el estado del led

long previousMillisg = 0;        

//Iniciamos el led azul como apagado

int ledStateb = LOW;             

//Variable en la que se guarda el ultimo tiempo desde que se actualizo el estado del led

long previousMillisb = 0;        

void setup() {
  
  //Iniciamos comunicación con el puerto serie, velocidad 9600 baudios
  
  Serial.begin(9600);
  
  // Usamos el metodo setTimeout para poder tener un tiempo para que reconozca los seis números
  
  Serial.setTimeout(100);

  //Declaramos los pines como salida a los que conectamos cada una de las tiras
  
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT); 
  pinMode(azul, OUTPUT); 
  
}

void loop() {
  
  //Si existen datos disponibles a través del puerto serie los leemos
  
  if (Serial.available() > 0) {

  //Guardamos en una cadena los 6 números pasados por el puerto serie
 
    String entrada = Serial.readString();

  //Seleccionamos los dos primeros números para la tira rojo, los dos siguientes para la verde  y los dos últimos para la azul
  //Cada par de números determinara la velocidad de parpadeo
      
    int velocidadr = entrada.substring(0,2).toInt();
    int velocidadg = entrada.substring(2,4).toInt();
    int velocidadb = entrada.substring(4,6).toInt(); 

  //Guardamos en una variable para cada led su intervalo de tiempo, mediante multiplicación de su velocidad por la constante
  //Multiplicamos la constante por el par de números recogidos para cada led
  
    intervalr = velocidadr * kvelocidad;
    intervalg = velocidadg * kvelocidad;
    intervalb = velocidadb * kvelocidad;
    
    //Se imprime el número que se recibe
    
    Serial.println(intervalr);
    Serial.println(intervalg);
    Serial.println(intervalb);

  }

  // Creamos una variable que va almacenando el tiempo que va transcurriendo desde que iniciamos, es decir, el tiempo actual
  
  unsigned long currentMillis = millis();

 // Imprimimos su valor para ver que esta funcionando

    Serial.println(currentMillis);

 //  Comprobamos que el tiempo actual menos el último tiempo en que se actualizo el estado del led es menor que el intervalo de tiempo definido

 if(currentMillis - previousMillisr > intervalr) {

  // Si se cumple la condición, almacenamos el nuevo tiempo desde que se actualizo el led
    
    previousMillisr = currentMillis;   

  // Si el led esta apagado, se procede a encenderlo, si esta encendido se apaga
  
    if (ledStater == LOW)
      ledStater = HIGH;
    else
      ledStater = LOW;

  // Se pasa al led rojo el estado en el que tiene que estar

    digitalWrite(rojo, ledStater);

  //  Comprobamos que el tiempo actual menos el último tiempo en que se actualizo el estado del led es menor que el intervalo de tiempo definido
     
     if(currentMillis - previousMillisg > intervalg) {

  // Si se cumple la condición, almacenamos el nuevo tiempo desde que se actualizo el led

    previousMillisg = currentMillis;   

   // Si el led esta apagado, se procede a encenderlo, si esta encendido se apaga

    if (ledStateg == LOW)
      ledStateg = HIGH;
    else
      ledStateg = LOW;

  // Se pasa al led verde el estado en el que tiene que estar

    digitalWrite(verde, ledStateg);

  //  Comprobamos que el tiempo actual menos el último tiempo en que se actualizo el estado del led es menor que el intervalo de tiempo definido

     if(currentMillis - previousMillisb > intervalb) {

  // Si se cumple la condición, almacenamos el nuevo tiempo desde que se actualizo el led
      
    previousMillisb = currentMillis;   

  // Si el led esta apagado, se procede a encenderlo, si esta encendido se apaga

    if (ledStateb == LOW)
      ledStateb = HIGH;
    else
      ledStateb = LOW;

  // Se pasa al led azul el estado en el que tiene que estar

    digitalWrite(azul, ledStateb);
    
    
        }

      }
    }
 }
