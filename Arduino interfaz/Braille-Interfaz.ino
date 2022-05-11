// Variables para los botones 
const int boton1 = 2;
const int boton2 = 3;
const int reset = 4;
// Variables para los led 
const int led1 = 8;
const int led2 = 9;
/////////////////////////
// Valores actual
int estadoBoton1 = 0;
int estadoBoton2 = 0;
int estadoReset = 0;
///////////////////
// Valores anteriores 
int estadoAnteriorBoton1 = 0;
int estadoAnteriorBoton2 = 0;

void resetLeds();
void setLeds(int, int);
///////////////////

void setup()
{
  //definicion salidas y entradas 
  //LEDS
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  //BOTONES
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(reset,INPUT);
  resetLeds();
}

void loop()
{
  // Leer estados
  estadoBoton1 = digitalRead(boton1);
  estadoBoton2 = digitalRead(boton2);
  estadoReset = digitalRead(reset);
  
  if(!estadoReset)
    setLeds(estadoBoton1, estadoBoton2);
  else
    resetLeds();
  
  /*
  				Code for check push buttons status
  When the push button 1 or the push button 2 is pressed, the led 1 or led 2 turns on, respectively. If reset button is pressed, both leds turn off.
  
  if(estadoBoton1 == 1)
    digitalWrite(led1,HIGH);
  if(estadoBoton2 != 0)
    digitalWrite(led2,HIGH);
  if(estadoReset)
    resetLeds();
  
  */
}

void resetLeds()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  estadoAnteriorBoton1 = 0;
  estadoAnteriorBoton2 = 0;
}

void setLeds(int stateLed1, int stateLed2)
{
  (stateLed1 != estadoAnteriorBoton1) ? (estadoAnteriorBoton1) ? estadoAnteriorBoton1=estadoAnteriorBoton1 : estadoAnteriorBoton1=stateLed1 : estadoAnteriorBoton1=estadoAnteriorBoton1;
  (stateLed2 != estadoAnteriorBoton2) ? (estadoAnteriorBoton2) ? estadoAnteriorBoton2=estadoAnteriorBoton2 : estadoAnteriorBoton2=stateLed2 : estadoAnteriorBoton2=estadoAnteriorBoton2;
  digitalWrite(led1, estadoAnteriorBoton1);
  digitalWrite(led2, estadoAnteriorBoton2);
}