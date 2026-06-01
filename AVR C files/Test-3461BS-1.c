#define F_CPU 16000000UL //definimos la frecuencia del procesador (16MHz) en formato unsigned y long. Es necesario definir F_CPU porque la función _delay_ms() internamente usa esta variable. 

#include <avr/io.h> //Carga todas las definiciones variables del hardware de la familia de microcontroladores AVR: define DDRB, PORTB etc.
#include <util/delay.h> //Carga las funciones de espera que usaremos _delay_ms()
#include <stdbool.h> // Para poder usar variable booleanas

//Declaración de funciones
int digitalWrite_mia(int pin, bool bit); // Ahora nosotros vamos a hacer esta función
void MuestraNumero(int digito, int numero); //Será idéntica si creamos el digitalWrite nosotros

// Variables globales de inicialización:
//Cambiar según el conexionado con los pines de Arduino:
int A=11;  int B=7;  int C=4;
int D=2;  int E=13;  int F=10;
int G=5;  int DP=3;  int D1=12;
int D2=9;  int D3=8;  int D4=6;
int k;

int main(int argc, char  *argv[]){
	//Inicialización de variables
	// Definir todos los pines digitales D0–D13 como salidas:
	// Puerto D → D2 a D7 (el 0 y el 1 son RX y TX, no los usamos).
	DDRD |= (1 << PD2);
	DDRD |= (1 << PD3);
	DDRD |= (1 << PD4);
	DDRD |= (1 << PD5);
	DDRD |= (1 << PD6);
	DDRD |= (1 << PD7);
	// Puerto B → D8 a D13
	DDRB |= (1 << PB0);
	DDRB |= (1 << PB1);
	DDRB |= (1 << PB2);
	DDRB |= (1 << PB3);
	DDRB |= (1 << PB4);
	DDRB |= (1 << PB5);
	
	
	// Escribir un HIGH ("1"):
	/*
	// Puerto D → D0 a D7
	PORTD |= (1 << PD0);  //Pin0
	PORTD |= (1 << PD1);  //Pin1
	PORTD |= (1 << PD2);  //Pin2
	PORTD |= (1 << PD3);  //Pin3
	PORTD |= (1 << PD4);  //Pin4
	PORTD |= (1 << PD5);  //Pin5
	PORTD |= (1 << PD6);  //Pin6
	PORTD |= (1 << PD7);  //Pin7
	
	// Puerto B → D8 a D13
	PORTB |= (1 << PB0);  //Pin8
	PORTB |= (1 << PB1);  //Pin9
	PORTB |= (1 << PB2);  //Pin10
	PORTB |= (1 << PB3);  //Pin11
	PORTB |= (1 << PB4);  //Pin12
	PORTB |= (1 << PB5);  //Pin13
	*/
	
	// Poner todos en LOW:
	// Poner D0–D7 en LOW
	PORTD = 0b00000000;
	// Poner D8–D13 en LOW
	PORTB = 0b00000000;
	
	int flag = 0;
	//int flag = digitalWrite_mia();
	if(flag != 0){
		return flag;
	}
	
	while(1){//Rutina de ejecución
		PORTB |= (1 << PB4);  //Pin12 a 1
		_delay_ms(1000);
		PORTB &= ~(1 << PB4); //Pin12 a 0
		_delay_ms(1000);
	}
return 0;}


int digitalWrite_mia(int pin, bool bit){
	return 0;
	}



void MuestraNumero(int digito, int numero){
  //Seleccionar dígito:
  digitalWrite_mia(D4, 0);
  digitalWrite_mia(D3, 0);
  digitalWrite_mia(D2, 0);
  digitalWrite_mia(D1, 0);
  digitalWrite_mia(digito, 1);

  /* AHORA ES LÓGICA INVERSA:
    0/0 = segmento ON
    1/1 = segmento OFF*/
  digitalWrite_mia(D, 1);
  digitalWrite_mia(DP, 1);
  digitalWrite_mia(C, 1);
  digitalWrite_mia(G, 1);
  digitalWrite_mia(B, 1);
  digitalWrite_mia(F, 1);
  digitalWrite_mia(A, 1);
  digitalWrite_mia(E, 1);

  //Empezamos a hacer casos
  switch(numero){
    case 0:
      digitalWrite_mia(D, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(B, 0);
      digitalWrite_mia(F, 0);
      digitalWrite_mia(A, 0);
      digitalWrite_mia(E, 0);
      break;
    case 1:
      digitalWrite_mia(C, 0);
      digitalWrite_mia(B, 0);
      break;
    case 2:
      digitalWrite_mia(A, 0);
      digitalWrite_mia(B, 0);
      digitalWrite_mia(D, 0);
      digitalWrite_mia(E, 0);
      digitalWrite_mia(G, 0);
      break;
    case 3:
      digitalWrite_mia(A, 0);
      digitalWrite_mia(B, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(D, 0);
      digitalWrite_mia(G, 0);
      break;
    case 4:
      digitalWrite_mia(B, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(F, 0);
      digitalWrite_mia(G, 0);
      break;
    case 5:
      digitalWrite_mia(A, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(D, 0);
      digitalWrite_mia(F, 0);
      digitalWrite_mia(G, 0);
      break;
    case 6:
      digitalWrite_mia(D, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(G, 0);
      digitalWrite_mia(F, 0);
      digitalWrite_mia(A, 0);
      digitalWrite_mia(E, 0);
      break;
    case 7:
      digitalWrite_mia(A, 0);
      digitalWrite_mia(B, 0);
      digitalWrite_mia(C, 0);
      break;
    case 8:
      digitalWrite_mia(A, 0);
      digitalWrite_mia(B, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(D, 0);
      digitalWrite_mia(E, 0);
      digitalWrite_mia(F, 0);
      digitalWrite_mia(G, 0);
      break;
    case 9:
      digitalWrite_mia(A, 0);
      digitalWrite_mia(B, 0);
      digitalWrite_mia(C, 0);
      digitalWrite_mia(F, 0);
      digitalWrite_mia(G, 0);
      break;
    default:
      break;
    }
  return;
  }
