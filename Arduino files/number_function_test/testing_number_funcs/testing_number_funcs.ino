
// Variables globales de inicialización:
int t_numero = 2 * 1000; //Segundos que permanece encendido cada número (ojo con el formato)

//Cambiar según el conexionado con los pines de Arduino:
int A=11;  int B=7;  int C=4;
int D=2;  int E=13;  int F=10;
int G=5;  int DP=3;  int D1=12;
int D2=9;  int D3=8;  int D4=6;
int k;

void setup() {
  // Activar todos los pines como salidas digitales:
  for(k=2; k<=13; k++){
    pinMode(k, OUTPUT);
  }
}

void loop() {
  int digits[]={D4, D3, D2, D1};
  /*for(k=0; k<4; k++){
    digitalWrite(digits[k], HIGH);
    delay(500);
    digitalWrite(digits[k], LOW);
    delay(500); //Si no ponemos dos, pasa inmediatamente al estado anterior
    }
    MuestraNumero(D4, 1);
  */
  MuestraNumero(D1,1);
  delay(t_numero);
  MuestraNumero(D2,2);
  delay(t_numero);
  MuestraNumero(D3,3);
  delay(t_numero);
  MuestraNumero(D4,4);
  delay(t_numero);
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