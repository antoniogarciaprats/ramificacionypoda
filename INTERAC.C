#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>


#define SIMBOL LIGHTGREEN
#define TABLERO MAGENTA
#define RAYA LIGHTRED
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=   CABECERAS DE FUNCIONES   -=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

void Hombre (int *tablero, int *mejorm, int *valor, int alfa, int beta);
void Computadora (int *tablero, int *mejorm, int *valor, int alfa, int beta);
int TableroLleno (int *array);
int Vacio (int *array, int cual);
void Coloca (int *array, int cual, int simbolo);
void DesColoca (int *array, int cual);

int CGanaUno (int *array, int *jugada);
int HGanaUno (int *array, int *jugada);
void PintaTablero(void);
void EscribeTablero (int *array);
int gana (int *array, int simbolo);
int movi (int cod);
void graf_on (void);  /*Inicializa los gr ficos*/
void graf_off (void); /*Cierra los gr ficos*/

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-=-=-   FUNCION PRINCIPAL   -=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

int main (void) {
	int array [9]={0,0,0,0,0,0,0,0,0};
	int mejorm, cod;
	int valor, alfa, beta,j, sigue;

	randomize();
	valor = 1;
	graf_on();
	sigue = 1;
	printf ("¨Qu‚ bando eliges? [X-O]");
	cod = getch();
	if ((cod == 120)||(cod == 88)) {
		while (sigue){

			cleardevice();
			for (j=0; j<9; j++)
			array[j]=0;
			PintaTablero();

			alfa=-1;
			beta=1;

			mejorm = 1;
			Hombre (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=1;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin;

			lee:
			mejorm = movi (getch());
			if (array [mejorm]==0) array [mejorm] = 2;
			else goto lee;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin;

			mejorm = 1;
			Hombre (array, &mejorm, &valor, alfa, beta);
			if (array [mejorm]==0) 	array[mejorm]=1;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin;

			lee2:
			mejorm = movi (getch());
			if (array [mejorm]==0) 	array [mejorm] = 2;
			else goto lee2;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin;

			mejorm = 1;
			Hombre (array, &mejorm, &valor, alfa, beta);
			if (array [mejorm]==0) 	array[mejorm]=1;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin;

			lee3:
			mejorm = movi (getch());
			if (array [mejorm]==0) 	array [mejorm] = 2;
			else goto lee3;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin;

			mejorm = 1;
			Hombre (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=1;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin;

			lee4:
			mejorm = movi (getch());
			if (array [mejorm]==0) 	array [mejorm] = 2;
			else goto lee4;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin;

			mejorm = 1;
			Hombre (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=1;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin;


			fin:
			delay (1000);
			cleardevice();
			gotoxy (2, 2);
			printf ("¨Seguro que TRAS ESTA HUMILLANTE DERROTA quieres seguir? [s/n]");
			cod = getch();
			if ((cod==110)||(cod==78)) sigue = 0;
		}
	}else{
		while (sigue){

			cleardevice();
			for (j=0; j<9; j++)
			array[j]=0;
			PintaTablero();

			alfa=-1;
			beta=1;

			lee5:
			mejorm = movi (getch());
			if (array [mejorm]==0) array [mejorm] = 1;
			else goto lee5;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin2;

			mejorm = 1;
			Computadora (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=2;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin2;

			lee6:
			mejorm = movi (getch());
			if (array [mejorm]==0) array [mejorm] = 1;
			else goto lee6;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin2;

			mejorm = 1;
			Computadora (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=2;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin2;


			lee7:
			mejorm = movi (getch());
			if (array [mejorm]==0) array [mejorm] = 1;
			else goto lee7;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin2;

			mejorm = 1;
			Computadora (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=2;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin2;


			lee8:
			mejorm = movi (getch());
			if (array [mejorm]==0) array [mejorm] = 1;
			else goto lee8;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin2;

			mejorm = 1;
			Computadora (array, &mejorm, &valor, alfa, beta);
			array[mejorm]=2;
			EscribeTablero (array);
			if (gana(array, 2)) goto fin2;


			lee9:
			mejorm = movi (getch());
			if (array [mejorm]==0) array [mejorm] = 1;
			else goto lee9;
			EscribeTablero (array);
			if (gana(array, 1)) goto fin2;


			fin2:
			delay (1000);
			cleardevice();
			gotoxy (2, 2);
			printf ("¨Seguro que TRAS ESTA HUMILLANTE DERROTA quieres seguir? [s/n]");
			cod = getch();
			if ((cod==110)||(cod==78)) sigue = 0;
		}

	}
	graf_off();
	printf ("\nLa pr¢xima vez seguro que me ganas... So¤ar es gratis :-)\n\n");
	return (0);
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-    CUERPOS DE FUNCIONES   -=-=-=-=-=-=-=-=-=-=-=-=*/
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

void Hombre (int *tablero, int *mejorm, int *valor,int alfa,int beta) {

	int nosirve, i, valorR, x;

	if (TableroLleno(tablero)) {
		*valor = 0; /* Empate = 0 */

	}
	else {
		if (HGanaUno (tablero, mejorm)) {
			*valor = -1; /* Pierde = -1 */
		}
		else {
			*valor = beta;
			i=0;
			x=random(9);
			while ((i<9)&&(*valor>alfa)) {
				x=(7*x+5)%9;
				if (Vacio (tablero, x)) {
					Coloca (tablero, x, 1); /* 1 es O */
					Computadora (tablero, &nosirve, &valorR,alfa,*valor);
					DesColoca (tablero, x);
					if (valorR<*valor) {
						*valor = valorR;
						*mejorm = x;
					}
				}
				i++;
			}

		}
	}
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void Computadora (int *tablero, int *mejorm, int *valor,int alfa,int beta) {

	int nosirve, i, valorR,x;

	if (TableroLleno (tablero)) {
		*valor = 0; /* Empate = 0 */

	}
	else {
		if (CGanaUno (tablero, mejorm)) {
			 *valor = 1; /* Gana = 1 */

		}
		else {
			*valor = alfa;
			i=0;
			x=random(9);
			while ((i<9) && (*valor<beta)){
				x=(7*x+5)%9;
				if (Vacio (tablero, x)) {
					Coloca (tablero, x, 2); /* 2 es X */
					Hombre (tablero, &nosirve, &valorR,*valor,beta);
					DesColoca (tablero, x);
					if (valorR>*valor) {
						*valor = valorR;
						*mejorm = x;
					}
				}
				i++;
			}
		}
	}
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

int TableroLleno (int *array){
	int i;

	for (i=0; i<9; i++) {

		if (array[i]==0) return (0);
	}

	return (1);
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
int Vacio (int *array, int cual) {
	return (array[cual]==0);
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void Coloca (int *array, int cual, int simbolo) {
	array[cual]=simbolo;
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void DesColoca (int *array, int cual) {
	array[cual]=0;
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
int CGanaUno (int *array, int *jugada) {

	int i;

	for (i=0;i<9;i++) {
		*jugada=i;
		if (array[i]==0)
			switch(i) {
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
	return(0);
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
int HGanaUno (int *array, int *jugada) {

	int i;

	for (i=0;i<9;i++) {
		*jugada=i;
		if (array[i]==0)
			switch(i) {
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
	return(0);}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void PintaTablero(void) {
	 int x, y, x3, y3;
	 cleardevice();
	 x = getmaxx();
	 y = getmaxy();
	 x3 = x/3;
	 y3 = y/3;
	 setcolor (TABLERO);
	 setlinestyle (0, 0, 3);
	 line (1, y3, x, y3);
	 line (1, 2*y3, x, 2*y3);
	 line (x3, 1, x3, y);
	 line (2*x3, 1, 2*x3, y);
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void EscribeTablero (int *array) {

	int i, x, y, x2, y2;

	x = getmaxx()/3;
	y = getmaxy()/3;
	x2 = x/2;
	y2 = y/2;
	setcolor (SIMBOL);
	for (i=0; i<9; i++) {
		if (array[i]==1) {
			sound (random(2000));
			delay (200);
			nosound();
			switch (i) {
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
		else if (array[i]==2) {
			sound (random(3000));
			delay (200);
			nosound();
			switch (i) {
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



/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void graf_on (void) {
	int gdriver = DETECT;
	int gmode = DETECT;
	int errorcode;

	initgraph(&gdriver, &gmode, "d:\\borlandc\\bgi");

	errorcode = graphresult();
	if (errorcode != grOk)
	{
		clrscr ();
		printf("\nError en gr ficos: %s\n", grapherrormsg(errorcode));
		exit(1);
	}
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
void graf_off (void) {
	closegraph();
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
int gana (int *array, int simbolo) {
	int x, y, x2, y2;

	x = getmaxx()/2;
	y = getmaxy()/2;
	x2 = x/3;
	y2 = y/3;

	setcolor (RAYA);
	setlinestyle (0, 0, 3);

	if (array[1]==simbolo && array[2]==simbolo && array[0]==simbolo) {
		line (15,  y2, 2*x-15, y2);
		return (1);
	}
	if (array[3]==simbolo && array[4]==simbolo && array[5]==simbolo) {
		line (15,  y, 2*x-15, y);
		return (1);
	}
	if (array[6]==simbolo && array[7]==simbolo && array[8]==simbolo) {
		line (15,  2*y-y2, 2*x-15, 2*y-y2);
		return (1);
	}
	if (array[0]==simbolo && array[3]==simbolo && array[6]==simbolo) {
		line (x2, 15, x2, 2*y-15);
		return (1);
	}
	if (array[1]==simbolo && array[4]==simbolo && array[7]==simbolo) {
		line (3*x2, 15, 3*x2, 2*y-15);
		return (1);
	}
	if (array[2]==simbolo && array[5]==simbolo && array[8]==simbolo) {
		line (2*x-x2, 15, 2*x-x2, 2*y-15);
		return (1);
	}
	if (array[0]==simbolo && array[4]==simbolo && array[8]==simbolo) {
		line (30, 30, 2*x-30, 2*y-30);
		return (1);
	}
	if (array[2]==simbolo && array[4]==simbolo && array[6]==simbolo) {
		line (2*x-30, 30, 30, 2*y-30);
		return (1);
	}
	setcolor (SIMBOL);
	return(0);
}
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
int movi (int cod) {

	int i;

	switch (cod) {

		case 49: i = 6;
					break;
		case 50: i = 7;
					break;
		case 51: i = 8;
					break;
		case 52: i = 3;
					break;
		case 53: i = 4;
					break;
		case 54: i = 5;
					break;
		case 55: i = 0;
					break;
		case 56: i = 1;
					break;
		case 57: i = 2;
					break;
	}
	return (i);
}