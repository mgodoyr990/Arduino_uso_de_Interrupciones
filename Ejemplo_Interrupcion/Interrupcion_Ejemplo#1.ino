int luz_verde=26;
int luz_amarilla=27;
int luz_roja=25;
int pulsador=32;

void IRAM_ATTR encenderTodas(){ //El comando IRAM_ATTAR direcciona la funcion a la memoria RAM en vez de la memoria flash
digitalWrite(luz_verde,HIGH);
digitalWrite(luz_amarilla,HIGH);
digitalWrite(luz_roja,HIGH);
}

void setup() {
pinMode(luz_amarilla,OUTPUT);
pinMode(luz_roja,OUTPUT);
pinMode(luz_verde,OUTPUT);
pinMode(pulsador,OUTPUT);
attachInterrupt(digitalPinToInterrupt(pulsador), encenderTodas, RISING);//El modod RISING activara nuestro codigo cuando pase de estado bajo a estado alto
}

void loop() {
digitalWrite(luz_amarilla,LOW);
digitalWrite(luz_roja,LOW);
digitalWrite(luz_verde,HIGH);
delay(2000);
digitalWrite(luz_verde,LOW);
digitalWrite(luz_roja,LOW);
digitalWrite(luz_amarilla,HIGH);
delay(2000);
digitalWrite(luz_amarilla,LOW);
digitalWrite(luz_verde,LOW);
digitalWrite(luz_roja,HIGH);
delay(2000);

int estadoPulsador=digitalRead(pulsador);
if(estadoPulsador==LOW){
  encenderTodas();
}
}
