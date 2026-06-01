
// Variables globales de inicialización:

//Cambiar según el conexionado con los pines de Arduino:
int A=11;  int B=7;  int C=4;
int D=2;  int E=13;  int F=10;
int G=5;  int DP=3;  int D1=12;
int D2=9;  int D3=8;  int D4=6;
int k;

  int cuenta[]= {0,0,0,0};
  int t_numero = 0.01 * 1000; //Segundos que permanece encendido cada número (ojo con el formato)
  int t_cambio_digito = 5;  // ms que tarda en cambiar de dígito

void setup() {
  // Activar todos los pines como salidas digitales:
  for(k=2; k<=13; k++){
    pinMode(k, OUTPUT);
  }
}

void loop() {
  unsigned long comienzo = millis(); // Millis da los ms desde el arranque

  while(millis()- comienzo < t_numero){

    MuestraNumero(D1,cuenta[0]);
    delay(t_cambio_digito);
    MuestraNumero(D2,cuenta[1]);
    delay(t_cambio_digito);
    MuestraNumero(D3,cuenta[2]);
    delay(t_cambio_digito);
    MuestraNumero(D4,cuenta[3]);
    delay(t_cambio_digito);
    //t_transicion = t_transicion + t_cambio_digito*4;
  }

  // Aumentamos el número
  cuenta[3]++;
  if(cuenta[3]==10){
    cuenta[3]=0;
    cuenta[2]++;
  }
  if(cuenta[2]==10){
    cuenta[2]=0;
    cuenta[1]++;
  }
  if(cuenta[1]==10){
    cuenta[1]=0;
    cuenta[0]++;
  }
  if(cuenta[0]==10){
    cuenta[0] = 0;
    cuenta[1] = 0;
    cuenta[2] = 0;
    cuenta[3] = 0;
  }
}

void MuestraNumero(int digito, int numero){
  //Seleccionar dígito:
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(digito, HIGH);

  /* AHORA ES LÓGICA INVERSA:
    0/LOW = segmento ON
    1/HIGH = segmento OFF*/
  digitalWrite(D, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(E, HIGH);

  //Empezamos a hacer casos
  switch(numero){
    case 0:
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      digitalWrite(F, LOW);
      digitalWrite(A, LOW);
      digitalWrite(E, LOW);
      break;
    case 1:
      digitalWrite(C, LOW);
      digitalWrite(B, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(G, LOW);
      break;
    case 3:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(G, LOW);
      break;
    case 4:
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 5:
      digitalWrite(A, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 6:
      digitalWrite(D, LOW);
      digitalWrite(C, LOW);
      digitalWrite(G, LOW);
      digitalWrite(F, LOW);
      digitalWrite(A, LOW);
      digitalWrite(E, LOW);
      break;
    case 7:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      break;
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 9:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    default:
      break;
    }
  return;
  }