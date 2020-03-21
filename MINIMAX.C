#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>

#include "lib_cron.h"

#define SIMBOL WHITE
#define TABLERO CYAN

/*-------------------------------------------------------------------------*/
/*                       CABECERAS DE FUNCIONES                            */
/*-------------------------------------------------------------------------*/

void Hombre (int *tablero, int *mejorm, int *valor);
void Computadora (int *tablero, int *mejorm, int *valor);
int TableroLleno (int *array);
int Vacio (int *array, int cual);
void Coloca (int *array, int cual, int simbolo);
void DesColoca (int *array, int cual);
int CGanaUno (int *array, int *jugada);
int HGanaUno (int *array, int *jugada);
void PintaTablero (void);
void EscribeTablero (int *array);
void graf_on (void);  /*Inicializa los gr ficos*/
void graf_off (void); /*Cierra los gr ficos*/

/*-------------------------------------------------------------------------*/
/*                           PROGRAMA PRINCIPAL                            */
/*-------------------------------------------------------------------------*/

int main (void){
	int array [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int mejorm;
	int valor, i;
	struct  time t1, t2;
	ldiv_t segundo;
	double segundo2;
	unsigned long int centesimas;


	valor = 1;
	graf_on ();
	PintaTablero ();

	cronostart (&t1);
/*for (i=0; i<3; i++){*/
	Hombre (array, &mejorm, &valor);
	array[mejorm] = 1;

//	EscribeTablero (array);

	Computadora (array, &mejorm, &valor);
	array[mejorm] = 2;

//	EscribeTablero (array);

	Hombre (array, &mejorm, &valor);
	array[mejorm] = 1;

//	EscribeTablero (array);

	Computadora (array, &mejorm, &valor);
	array[mejorm] = 2;

//	EscribeTablero (array);

	Hombre (array, &mejorm, &valor);
	array[mejorm] = 1;

//	EscribeTablero (array);


	Computadora (array, &mejorm, &valor);
	array[mejorm] = 2;

//	EscribeTablero (array);

	Hombre (array, &mejorm, &valor);
	array[mejorm] = 1;

//	EscribeTablero (array);

	Computadora (array, &mejorm, &valor);
	array[mejorm] = 2;

//	EscribeTablero (array);

	Hombre (array, &mejorm, &valor);
	array[mejorm] = 1;


	EscribeTablero (array);
/*}*/
	cronostop (&t2);
	centesimas = cronodifcent (&t1, &t2);
	segundo = ldiv (centesimas, 100L);
	printf ("\n\nEl n£mero de cent‚simas es: %lu", centesimas);
	segundo2 = segundo.quot+segundo.rem*0.01;
	printf ("\nEl n£mero de segundos es: %.2lf", segundo2);

	getch ();
	graf_off ();
	return (0);
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-    CUERPOS DE FUNCIONES   -=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

void Hombre (int *tablero, int *mejorm, int *valor){

	int nosirve, i, valorR, x;

	if (TableroLleno (tablero)){
		*valor = 0; /* Empate = 0 */

	}
	else{
		if (HGanaUno (tablero, mejorm)){
			*valor = -1; /* Pierde = -1 */

		}
		else{
			*valor = 1; /* Gana = 1 */
			randomize ();
			x = random (9);
			for (i=0; i<9; i++){
				x = (7*x+5)%9;
				if (Vacio (tablero, x)){
					Coloca (tablero, x, 1); /* 1 es O */
					Computadora (tablero, &nosirve, &valorR);
					DesColoca (tablero, x);
					if (valorR<*valor){
						*valor = valorR;
						*mejorm = x;
					}
				}
			}

		}
	}
}

/*-------------------------------------------------------------------------*/

void Computadora (int *tablero, int *mejorm, int *valor){

	int nosirve, i, valorR, x;

	if (TableroLleno (tablero)){
		*valor = 0; /* Empate = 0 */

	}
	else{
		if (CGanaUno (tablero, mejorm)){
			 *valor = 1; /* Gana = 1 */
		}
		else {
			*valor = -1; /* Pierde = -1 */
			randomize ();
			x = random (9);
			for (i=0; i<9; i++){
				x = (7*x+5)%9;
				if (Vacio (tablero, x)){
					Coloca (tablero, x, 2); /* 2 es X */
					Hombre (tablero, &nosirve, &valorR);
					DesColoca (tablero, x);
					if (valorR>*valor){
						*valor = valorR;
						*mejorm = x;
					}
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------*/

int TableroLleno (int *array){

	int i;

	for (i=0; i<9; i++) {
			if (array[i] == 0) return (0);
	}

	return (1);
}

/*-------------------------------------------------------------------------*/

int Vacio (int *array, int cual){
	return (array[cual] == 0);
}

/*-------------------------------------------------------------------------*/

void Coloca (int *array, int cual, int simbolo){
	array[cual] = simbolo;
}

/*-------------------------------------------------------------------------*/

void DesColoca (int *array, int cual){
	array[cual] = 0;
}

/*-------------------------------------------------------------------------*/

int CGanaUno (int *array, int *jugada){

	int i;

	for (i=0; i<9; i++){
		*jugada = i;
		if (array[i] == 0)
			switch (i){
				case 0: if (array[1]==2 && array[2]==2) return (1);
								else if (array[3]==2 && array[6]==2) return (1);
								else if (array[4]==2 && array[8]==2) return (1);
								break;
				case 1: if (array[0]==2 && array[2]==2) return (1);
								else if (array[4]==2 && array[7]==2) return (1);
								break;
				case 2: if (array[0]==2 && array[1]==2) return (1);
								else if (array[5]==2 && array[8]==2) return (1);
								else if (array[4]==2 && array[6]==2) return (1);
								break;
				case 3: if (array[4]==2 && array[5]==2) return (1);
								else if (array[0]==2 && array[6]==2) return (1);
								break;
				case 4: if (array[3]==2 && array[5]==2) return (1);
								else if (array[1]==2 && array[7]==2) return (1);
								else if (array[0]==2 && array[8]==2) return (1);
								else if (array[2]==2 && array[6]==2) return (1);
								break;
				case 5: if (array[3]==2 && array[4]==2) return (1);
								else if (array[2]==2 && array[8]==2) return (1);
								break;
				case 6: if (array[7]==2 && array[8]==2) return (1);
								else if (array[0]==2 && array[3]==2) return (1);
								else if (array[2]==2 && array[4]==2) return (1);
								break;
				case 7: if (array[6]==2 && array[8]==2) return (1);
								else if (array[1]==2 && array[4]==2) return (1);
								break;
				case 8: if (array[6]==2 && array[7]==2) return (1);
								else if (array[2]==2 && array[5]==2) return (1);
								else if (array[0]==2 && array[4]==2) return (1);
								break;
			}
	}
	return (0);
}

/*-------------------------------------------------------------------------*/

int HGanaUno (int *array, int *jugada){

	int i;

	for (i=0; i<9; i++){
		*jugada = i;
		if (array[i] == 0)
			switch (i){
				case 0: if (array[1]==1 && array[2]==1) return (1);
								else if (array[3]==1 && array[6]==1) return (1);
								else if (array[4]==1 && array[8]==1) return (1);
								break;
				case 1: if (array[0]==1 && array[2]==1) return (1);
								else if (array[4]==1 && array[7]==1) return (1);
								break;
				case 2: if (array[0]==1 && array[1]==1) return (1);
								else if (array[5]==1 && array[8]==1) return (1);
								else if (array[4]==1 && array[6]==1) return (1);
								break;
				case 3: if (array[4]==1 && array[5]==1) return (1);
								else if (array[0]==1 && array[6]==1) return (1);
								break;
				case 4: if (array[3]==1 && array[5]==1) return (1);
								else if (array[1]==1 && array[7]==1) return (1);
								else if (array[0]==1 && array[8]==1) return (1);
								else if (array[2]==1 && array[6]==1) return (1);
								break;
				case 5: if (array[3]==1 && array[4]==1) return (1);
								else if (array[2]==1 && array[8]==1) return (1);
								break;
				case 6: if (array[7]==1 && array[8]==1) return (1);
								else if (array[0]==1 && array[3]==1) return (1);
								else if (array[2]==1 && array[4]==1) return (1);
								break;
				case 7: if (array[6]==1 && array[8]==1) return (1);
								else if (array[1]==1 && array[4]==1) return (1);
								break;
				case 8: if (array[6]==1 && array[7]==1) return (1);
								else if (array[2]==1 && array[5]==1) return (1);
								else if (array[0]==1 && array[4]==1) return (1);
								break;
			}
	}
	return (0);
}

/*-------------------------------------------------------------------------*/

void PintaTablero (void){
	 int x, y, x3, y3;
	 cleardevice ();
	 x = getmaxx ();
	 y = getmaxy ();
	 x3 = x/3;
	 y3 = y/3;
	 setcolor (TABLERO);
	 setlinestyle (0, 0, 3);
	 line (1, y3, x, y3);
	 line (1, 2*y3, x, 2*y3);
	 line (x3, 1, x3, y);
	 line (2*x3, 1, 2*x3, y);
}

/*-------------------------------------------------------------------------*/

void EscribeTablero (int *array){

	int i, x, y, x2, y2;

	x = getmaxx()/3;
	y = getmaxy()/3;
	x2 = x/2;
	y2 = y/2;
	setcolor (SIMBOL);
	for (i=0; i<9; i++){
			if (array[i] == 1){
			switch (i){
				case 0: circle (x2, y2, x2-50);
								circle (x2, y2, x2-48);
								break;
				case 1: circle (x+x2, y2, x2-50);
								circle (x+x2, y2, x2-48);
								break;
				case 2: circle (2*x+x2, y2, x2-50);
								circle (2*x+x2, y2, x2-48);
								break;
				case 3: circle (x2, y+y2, x2-50);
								circle (x2, y+y2, x2-48);
								break;
				case 4: circle (x+x2, y+y2, x2-50);
								circle (x+x2, y+y2, x2-48);
								break;
				case 5: circle (2*x+x2, y+y2, x2-50);
								circle (2*x+x2, y+y2, x2-48);
								break;
				case 6: circle (x2, 2*y+y2, x2-50);
								circle (x2, 2*y+y2, x2-48);
								break;
				case 7: circle (x+x2, 2*y+y2, x2-50);
								circle (x+x2, 2*y+y2, x2-48);
								break;
				case 8: circle (2*x+x2, 2*y+y2, x2-50);
								circle (2*x+x2, 2*y+y2, x2-48);
								break;
			}
		}
		else if (array[i] == 2){
			switch (i){
				case 0: line (50, 35, x-50, y-35);
								line (x-50, 35, 50, y-35);
								break;
				case 1: line (x+50, 35, 2*x-50, y-35);
								line (2*x-50, 35, x+50, y-35);
								break;
				case 2: line (2*x+50, 35, 3*x-50, y-35);
								line (3*x-50, 35, 2*x+50, y-35);
								break;
				case 3: line (50, y+35, x-50, 2*y-35);
								line (50, 2*y-35, x-50, y+35);
								break;
				case 4: line (x+50, y+35, 2*x-50, 2*y-35);
								line (x+50, 2*y-35, 2*x-50, y+35);
								break;
				case 5: line (2*x+50, y+35, 3*x-50, 2*y-35);
								line (2*x+50, 2*y-35, 3*x-50, y+35);
								break;
				case 6: line (50, 2*y+35, x-50, 3*y-35);
								line (50, 3*y-35, x-50, 2*y+35);
								break;
				case 7: line (x+50, 2*y+35, 2*x-50, 3*y-35);
								line (x+50, 3*y-35, 2*x-50, 2*y+35);
								break;
				case 8: line (2*x+50, 2*y+35, 3*x-50, 3*y-35);
								line (2*x+50, 3*y-35, 3*x-50, 2*y+35);
								break;
			} /* DEL SWITCH */
		} /* DEL IF-ELSE */
	} /* DEL FOR */
} /* DE LA FUNCIàN */

/*-------------------------------------------------------------------------*/

void graf_on (void){

	int gdriver = DETECT;
	int gmode = DETECT;
	int errorcode;

	initgraph (&gdriver, &gmode, "c:\\borlandc\\bgi");

	errorcode = graphresult ();
	if (errorcode != grOk)
	{
		clrscr ();
		printf("\nError en gr ficos: %s\n", grapherrormsg (errorcode));
		exit (1);
	}
}

/*-------------------------------------------------------------------------*/

void graf_off (void){
	closegraph ();
}