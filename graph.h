/*-------------------------------------------------------------------------------------------
	_   __             _   __
   | | / /            | | / /
   | |/ /  ___ _ __   | |/ /  ___ _ __
   |    \ / _ \ '_ \  |    \ / _ \ '_ \
   | |\  \  __/ | | | | |\  \  __/ | | |
   \_| \_/\___|_| |_| \_| \_/\___|_| |_| R U S H 				(c) rodolfo gonzalez
		                                        
	Libreria de Dise#o
	
	Este header contiene las funciones requeridas por el juego para la representacion 
	grafica del KenKen. Se divide en dos partes: 
	
	La primera contiene las funciones que centran los simbolos, para conseguir este
	proposito, hay tres funciones importantes: ln, tb y sp; que se explican mas adelante,
	asi como una funcion que estandariza los usos de estos espacios (dsn).
	
	La segunda parte contiene el arte ASCII, es decir, los simbolos que conforman el
	tablero y los caracteres. Las funciones de la primera parte hacen un uso importante
	de estas.
	
	Algunos de estos metodos dependen mucho en los espacios, pero funcionan correctamente.
	La primera regla del diseño grafico, despues de todo, es: Si se ve bien, esta bien.

-----------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Prototipos de pantallas de juego, 30 lineas cada uno
	void tt();//TiTulo
	void csr();//ChooSe Rows
	void pp(int rows, int m[6][6], int u[6][6]); //Player Pantalla
	void game(int g, int r, int m[6][6],int u[6][6], int a[6][6]); //Juego Terminado

//Prototipos de funciones para imprimir tableros
	void tres(int[6][6],int[6][6]);
	void cuatro(int[6][6],int[6][6]);
	void cinco(int[6][6],int[6][6]);
	void seis(int[6][6],int[6][6]);

//Prototipos de funciones para centrar graficos
	void dsn(int); //Funcion estandar de acomodo
	void cls(); //CLear Screen
	void sp(int); //Imprimir eSPacio
	void ln(int); //salto de LiNea
	void tb(int); //TaBulacion
	void dsp(int d); //Digito eSPacio
	char ps(int m[6][6], int a, int b); //Poner eSpacio

//Prototipos de funciones arte ASCII
	void logo();
	void kkd(); //KenKen Display
	void won();
	void lose();
	void asciitres(int r, int[6][6],int[6][6]);
	void asciicuatro(int r, int[6][6],int[6][6]);
	void asciicinco(int r, int[6][6],int[6][6]);
	void asciiseis(int r, int[6][6],int[6][6]);



void logo(){ //Logotipo del juego, impreso en lineas separadas. El dsn se utiliza para centrar el logo.
	dsn(2);printf(" _   __             _   __           \n");
	dsn(2);printf("| | / /            | | / /           \n");
	dsn(2);printf("| |/ /  ___ _ __   | |/ /  ___ _ __  \n");
	dsn(2);printf("|    \\ / _ \\ '_ \\  |    \\ / _ \\ '_ \\ \n");
	dsn(2);printf("| |\\  \\  __/ | | | | |\\  \\  __/ | | |\n");
	dsn(2);printf("\\_| \\_/\\___|_| |_| \\_| \\_/\\___|_| |_|\n");
	dsn(3);printf("R   U   S   H\n");	
}

void won(){ //Arte ASCII, mostrado cuando se gana el juego
	dsn(4);printf("______   _ _      _     _           _            \n");
	dsn(4);printf("|  ___| | (_)    (_)   | |         | |           \n");
	dsn(4);printf("| |_ ___| |_  ___ _  __| | __ _  __| | ___  ___  \n");
	dsn(4);printf("|  _/ _ \\ | |/ __| |/ _` |/ _` |/ _` |/ _ \\/ __| \n");
	dsn(4);printf("| ||  __/ | | (__| | (_| | (_| | (_| |  __/\\__ \\ \n");
	dsn(4);printf("\\_| \\___|_|_|\\___|_|\\__,_|\\__,_|\\__,_|\\___||___/\n");

}
void lose(){ //Arte ASCII, mostrado cuando se pierde el juego
	dsn(11);printf("  _    _             _____             _ _     _            \n");
	dsn(11);printf(" | |  | |           |  __ \\           | (_)   | |           \n");
	dsn(11);printf(" | |__| | __ _ ___  | |__) |__ _ __ __| |_  __| | ___       \n");
	dsn(11);printf(" |  __  |/ _` / __| |  ___/ _ \\ '__/ _` | |/ _` |/ _ \\      \n");
	dsn(11);printf(" | |  | | (_| \\__ \\ | |  |  __/ | | (_| | | (_| | (_) | _ _ \n");
	dsn(11);printf(" |_|  |_|\\__,_|___/ |_|   \\___|_|  \\__,_|_|\\__,_|\\___(_|_|_)\n");                                
}

void tt(){ //Imprime la pantalla principal
	dsn(1);
	logo();
	dsn(1);
	kkd();
	dsn(1);
	dsn(5);printf("PRESIONA CUALQUIER TECLA PARA JUGAR\n");
	dsn(6);
	printf("(C)2016 Todos Los Derechos Reservados. Benjamin Gonzalez, Rodolfo Gonzalez, Cristina Gonzalez, Alex Calderon.\n");
}


void csr(){ //Pantalla para escoger el numero de filas del KenKen
	system("color e");
	dsn(1);
	logo();
	dsn(1);
	kkd();
	ln(8);
	dsn(5);printf("De cuantas filas quieres tu KenKen?");
	ln(1);
}

void pp(int rows, int m[6][6], int u[6][6]){ //Pantalla de juego, recibe el numero de filas del kenken y las matrices de muestra y usuario.
	switch (rows){ //De este modo, solo imprime el tablero que va de acuerdo al numero de filas (rows) del KenKen.
		case 3:
			system("color b"); //Pinta el texto de un lindo color aqua
			ln(2); //Espacio entre el logo y el tablero
			tres(m,u);
			ln(9);
			break;
		case 4:
			system("color f"); //Pinta el texto de un lindo color blanco
			ln(3); //Espacio entre el logo y el tablero
			cuatro(m,u);
			ln(5);
			break;
		case 5:
			system("color e"); //Pinta el texto de un lindo color amarillo
			ln(1);
			cinco(m,u);
			ln(4);
			break;
		case 6:
			system("color d"); //Pinta el texto de un lindo color morado
			ln(1);
			seis(m,u);
			ln(1);
			break;
	}	
}

void ln(int l){ //Imprime un salto de linea
	for (int n=1;n<=l;n++)
		printf("\n");
}

void tb(int t){ //Imprime una tabulacion
	for (int b=1;b<=t;b++)
			printf("\t");
}

void sp(int s){ //Imprime un espacio
	for (int p=1;p<=s;p++)
		printf(" ");
}

void dsn(int n){ //Maneja el espaciado referenciando las funciones ln, tb y sp. Se utiliza para que todo el texto este parejo
	switch (n) {
		case 1:
			ln(2);
			break;
		case 2:
			tb(5);sp(1);
			break;
		case 3:
			tb(6);sp(5);
			break;
		case 4:
			tb(4);sp(5);
			break;
		case 5:
			tb(5);sp(3);
			break;
		case 6:
			ln(6);
			break;
		case 7: //Espacio para el tablero de 3
			tb(6);
			break;
		case 8: //Espacio para el tablero de 4
			tb(5);sp(5);
			break;
		case 9: //Espacio para el tablero de 5
			tb(5);sp(2);
			break;
		case 10: //Espacio para el tablero de 6     
			tb(4);sp(6);
			break;
		case 11:
			tb(4);
			break;
	}
}

void cls(){ //CLear Screen; Limpia la pantalla
    for (int i=0; i<10; i++)
      printf("\n\n\n\n\n\n\n\n\n\n");
}

void dsp(int d,int b){ //Digit Space; Imprime un pipe al final del tablero y antes del salto de linea. 
	if (d <= 9)
		printf(" ");
	if (b == 1)
		printf("|");
}

char ps(int m[6][6], int a, int b){ //Poner eSpacio
	if (m[a][b] != 0)
		return m[a][b]+'0';
		/* Regresa el entero menor a nueve que se encuentra en la matriz "usuario",
		   NO como entero SINO como tipo caracter. De este modo, si no se ha ingresado ningun valor
		   (cuando el valor es 0), regresara un espacio, y si es diferente de 0, regresara el valor correspondiente.
		   Es un capricho estetico. */
	else
		return 32; //32 es " " en ASCII
}


void tres(int m[6][6], int u[6][6]){ //Esta y las siguientes tres funciones imprimen los tableros de acuerdo al
	for (int r = 0; r<=9; r++) {    //numero de digitos que posee la matriz de juego (que puede ir desde 0 hasta 99)
		dsn(7);
		asciitres(r,m,u);
		printf("\n");
	}
}

void cuatro(int m[6][6], int u[6][6]){
	for (int r = 0; r<=12; r++) {
		dsn(8);
		asciicuatro(r,m,u);
		printf("\n");
	}
}

void cinco(int m[6][6], int u[6][6]){
	for (int r = 0; r<=15; r++) {
		dsn(9);
		asciicinco(r,m,u);
		printf("\n");
	}
}

void seis(int m[6][6], int u[6][6]){
	for (int r = 0; r<=18; r++) {
		dsn(10);
		asciiseis(r,m,u);
		printf("\n");
	}
}

void kkd(){ //KenKenDesign, imprime un tablero vacío para las pantallas de título y ayuda.
	dsn(7);printf("+------+------+------+\n");
	dsn(7);printf("|      |             |\n");
	dsn(7);printf("|      |             |\n");
	dsn(7);printf("+      +------+------+\n");
	dsn(7);printf("|      |             |\n");
	dsn(7);printf("|      |             |\n");
	dsn(7);printf("+------+------+------+\n");
	dsn(7);printf("|             |      |\n");
	dsn(7);printf("|             |      |\n");
	dsn(7);printf("+------+------+------+\n");
}

void asciitres(int r, int m[6][6], int u[6][6]){ //Esta y las siguientes tres funciones son el corazon del arte para los tableros.
	switch(r){ //Se utiliza un switch para separar las lineas
		default :
			printf("+------+------+------+"); //Debido a que este patron de simbolos se repite varias veces, sera el default para ahorrar codigo y memoria
			break;
		case 1:		
			printf("| %i%c  ",m[0][0],m[1][0]);  dsp(m[0][0],0);
			printf("| %i%c         ",m[0][1],m[0][2]);  dsp(m[0][1],1);
			break;
		case 2:	
			printf("| [%c]  | [%c]    [%c]  |",ps(u,0,0),ps(u,0,1),ps(u,0,2));
			break;
		case 3:
			printf("+      +------+------+");
			break;
		case 4:
			printf("|      | %i%c         ",m[1][1],m[1][2]);  dsp(m[1][1],1); 
			break;
		case 5:
			printf("| [%c]  | [%c]    [%c]  |",ps(u,1,0),ps(u,1,1),ps(u,1,2));
			break;
		case 7:
			printf("| %i%c         ",m[2][0],m[2][1]);  dsp(m[2][0],0);
			printf("| %i   ",m[2][2]);  dsp(m[2][0],1);
			break;
		case 8:
			printf("| [%c]    [%c]  | [%c]  |",ps(u,2,0),ps(u,2,1),ps(u,2,2)); 
			break;
	}
}
    
void asciicuatro(int r, int m[6][6], int u[6][6]){
	switch(r) {   
		default:	
			printf("+------+------+------+------+");
			break;
		case 1:
			printf("| %i%c  ",m[0][0],m[1][0]);  dsp(m[0][0],0);
			printf("| %i%c         ",m[0][1],m[0][2]); dsp(m[0][1],0);
			printf("| %i   ",m[0][3]); dsp(m[0][3],1);
			break;
		case 2:
			printf("| [%c]  | [%c]    [%c]  | [%c]  |",ps(u,0,0),ps(u,0,1),ps(u,0,2),ps(u,0,3));
			break;
		case 3:
			printf("+      +------+------+------+");
			break;
		case 4:
			printf("|      | %i   ",m[1][1]); dsp(m[1][1],0);
			printf("| %i%c  ",m[1][2],m[2][2]); dsp(m[1][2],0);
			printf("| %i%c  ",m[1][3],m[2][3]); dsp(m[1][3],1);
			break;
		case 5:	
			printf("| [%c]  | [%c]  | [%c]  | [%c]  |",ps(u,1,0),ps(u,1,1),ps(u,1,2),ps(u,1,3));
			break;
		case 6:
			printf("+------+------+      +      +");
			break;
		case 7:
			printf("| %i%c  ",m[2][0],m[3][0]); dsp(m[2][0],0);
			printf("| %i%c  ",m[2][1],m[3][1]); dsp(m[2][1],0);
			printf("|      |      |");
			break;
		case 8:
			printf("| [%c]  | [%c]  | [%c]  | [%c]  |",ps(u,2,0),ps(u,2,1),ps(u,2,2),ps(u,2,3));
			break;
		case 9:
			printf("+      +      +------+------+");
			break;
		case 10:
			printf("|      |      | %i%c         ",m[3][2],m[3][3]); dsp(m[3][2],1);
			break;
		case 11:
			printf("| [%c]  | [%c]  | [%c]    [%c]  |",ps(u,3,0),ps(u,3,1),ps(u,3,2),ps(u,3,3));
			break;
	}
}

void asciicinco(int r, int m[6][6], int u[6][6]){ //15 lineas
	switch(r) {
		default:
			printf("+------+------+------+------+------+");
			break;
		case 1:
			printf("| %i%c         ",m[0][0],m[0][1]); dsp(m[0][0],0);
			printf("| %i%c         ",m[0][2],m[0][3]); dsp(m[0][2],0);
			printf("| %i%c  ",m[0][4],m[1][3]); dsp(m[0][4],1);
			break;
		case 2:
			printf("| [%c]    [%c]  | [%c]    [%c]  | [%c]  |",ps(u,0,0),ps(u,0,1),ps(u,0,2),ps(u,0,3),ps(u,0,4));
			break;
		case 3:
			printf("+------+------+------+------+      +");
			break;
		case 4:
			printf("| %i   ",m[1][0]); dsp(m[1][0],0);
			printf("| %i%c         ",m[1][1],m[1][2]); dsp(m[1][1],0);
			printf("|             |");
			break;
		case 5:
			printf("| [%c]  | [%c]    [%c]  | [%c]    [%c]  |",ps(u,1,0),ps(u,1,1),ps(u,1,2),ps(u,1,3),ps(u,1,4));
			break;
		case 7:
			printf("| %i%c  ",m[2][0],m[3][0]); dsp(m[2][0],0);
			printf("| %i%c  ",m[2][1],m[3][1]); dsp(m[2][1],0);
			printf("| %i%c         ",m[2][2],m[3][3]); dsp(m[2][2],0);
			printf("| %i%c   |",m[2][4],m[3][4]); dsp(m[2][4],0);
			break;
		case 8:
			printf("| [%c]  | [%c]  | [%c]    [%c]  | [%c]  |",ps(u,2,0),ps(u,2,1),ps(u,2,2),ps(u,2,3),ps(u,2,4));
			break;
		case 9:
			printf("+      +      +------+      +      +");
			break;
		case 10:
			printf("|      |      | %i%c  ",m[3][2],m[3][3]); dsp(m[3][2],0);
			printf("|      |      |");
			break;
		case 11:
			printf("| [%c]  | [%c]  | [%c]  | [%c]  | [%c]  |",ps(u,3,0),ps(u,3,1),ps(u,3,2),ps(u,3,3),ps(u,3,4));
			break;
		case 12:
			printf("+------+------+      +------+------+");
			break;
		case 13:
			printf("| %i%c         ",m[4][0],m[4][1]); dsp(m[4][0],0);
			printf("|             ");
			printf("| %i   ",m[4][4]); dsp(m[4][4],1);
			break;
		case 14:
			printf("| [%c]    [%c]  | [%c]    [%c]  | [%c]  |",ps(u,4,0),ps(u,4,1),ps(u,4,2),ps(u,4,3),ps(u,4,4));
			break;
	}
}

void asciiseis(int r, int m[6][6], int u[6][6]){
	switch(r) {
		default:	
			printf("+------+------+------+------+------+------+");
			break;
		case 1:
			printf("| %i%c         ",m[0][1],m[1][0]); dsp(m[0][1],0);
			printf("| %i%c                ",m[0][2],m[0][4]); dsp(m[0][2],0);
			printf("| %i%c  ",m[0][5],m[1][5]); dsp(m[0][5],1);
			break;
		case 2:
			printf("| [%c]    [%c]  | [%c]    [%c]    [%c]  | [%c]  |",ps(u,0,0),ps(u,0,1),ps(u,0,2),ps(u,0,3),ps(u,0,4),ps(u,0,5));
			break;
		case 3:
			printf("+      +------+------+------+------+      +");
			break;
		case 4:
			printf("|      | %i%c         ",m[1][1],m[1][2]); dsp(m[1][1],0);
			printf("| %i%c         ",m[1][3],m[1][4]); dsp(m[1][3],0);
			printf("|      |");
			break;
		case 5:
			printf("| [%c]  | [%c]    [%c]  | [%c]    [%c]  | [%c]  |",ps(u,1,0),ps(u,1,1),ps(u,1,2),ps(u,1,3),ps(u,1,4),ps(u,1,5));
			break;
		case 7:
			printf("| %i%c  ",m[2][0],m[3][0]); dsp(m[2][0],0);
			printf("| %i%c  ",m[2][1],m[3][1]); dsp(m[2][1],0);
			printf("| %i%c         ",m[2][2],m[2][3]); dsp(m[2][2],0);
			printf("| %i%c         ",m[2][4],m[2][5]); dsp(m[2][4],1);
			break;
		case 8:
			printf("| [%c]  | [%c]  | [%c]    [%c]  | [%c]    [%c]  |",ps(u,2,0),ps(u,2,1),ps(u,2,2),ps(u,2,3),ps(u,2,4),ps(u,2,5));
			break;
		case 9:
			printf("+      +      +------+------+------+------+");
			break;
		case 10:
			printf("|      |      | %i%c         ",m[3][2],m[3][3]); dsp(m[3][2],0);
			printf("| %i%c         ",m[3][4],m[4][4]); dsp(m[3][4],1);
			break;
		case 11:
			printf("| [%c]  | [%c]  | [%c]    [%c]  | [%c]    [%c]  |",ps(u,3,0),ps(u,3,1),ps(u,3,2),ps(u,3,3),ps(u,3,4),ps(u,3,5));
			break;
		case 12:
			printf("+------+------+------+------+------+      +");
			break;
		case 13:
			printf("| %i   ",m[4][0]); dsp(m[4][0],0);
			printf("| %i%c         ",m[4][1],m[4][2]); dsp(m[4][1],0);
			printf("| %i%c         ",m[4][3],m[4][4]); dsp(m[4][3],0);
			printf("|      |");
			break;
		case 14:
			printf("| [%c]  | [%c]    [%c]  | [%c]    [%c]  | [%c]  |",ps(u,4,0),ps(u,4,1),ps(u,4,2),ps(u,4,3),ps(u,4,4),ps(u,4,5));
			break;
		case 16:
			printf("| %i%c                ",m[5][0],m[5][2]); dsp(m[5][0],0);
			printf("| %i   ",m[5][3]); dsp(m[5][3],0);
			printf("| %i%c         ",m[5][4],m[5][5]); dsp(m[5][4],1);
			break;
		case 17:
			printf("| [%c]    [%c]    [%c]  | [%c]  | [%c]    [%c]  |",ps(u,5,0),ps(u,5,1),ps(u,5,2),ps(u,5,3),ps(u,5,4),ps(u,5,5));
			break;
	}
}

/* GAME, funcion que imprime el resultado del juego. Recibe 4 variables:
	int g: (Game)	'0': Ha PERDIDO el juego; '1': Ha GANADO el juego
	int r: (Row)	Numero de filas del KenKen
	int m[6][6]: (Default)	Es la MATRIZ que el jugador DEBIO TENER para GANAR el juego.
	int u[6][6]: (User)		Es la MATRIZ DEL JUGADOR, aquella que construyo durante el juego.
*/
void game(int g, int r, int m[6][6],int u[6][6], int a[6][6]){
	char respuesta;
	if (g == 0) {
		cls();
		system("color c"); //Color rojo
		lose();
		switch (r) {
		case 3:		
			ln(1);
			tb(3);sp(2);printf("Debi\242 tener algo como esto :\n");
			for (int r = 0; r<=9; r++) {
				tb(3);sp(5);
				asciitres(r,m,a);
				tb(3);
				asciitres(r,m,u);
				printf("\n");
			}
			ln(2);
			tb(6);sp(2);printf("Desea jugar otra vez?\n");
			tb(6);sp(6);printf("Si[S]  /  No[N]");
			ln(5);
			break;
		case 4:
			ln(2);
			tb(2);sp(6);printf("Debi\242 tener algo como esto:\n");
			for (int r = 0; r<=12; r++) {
				tb(2);sp(5);
				asciicuatro(r,m,a);
				tb(3);
				asciicuatro(r,m,u);
				printf("\n");
			}
			tb(6);sp(2);printf("Desea jugar otra vez?\n");
			tb(6);sp(6);printf("Si[S]  /  No[N]");
			ln(6);
			break;
		case 5:
			ln(2);
			tb(2);printf("Debi\242 tener algo como esto:");
			ln(1);
			for (int r = 0; r<=15; r++) {
				tb(1);sp(4);
				asciicinco(r,m,a);
				tb(3);
				asciicinco(r,m,u);
				printf("\n");
			}
			tb(6);printf("Desea jugar otra vez?\n");
			tb(6);sp(4);printf("Si[S]  /  No[N]");
			ln(2);
			break;
		case 6:
			ln(1);
			tb(1);sp(5);printf("Debi\242 tener algo como esto :");
			ln(1);
			for (int r = 0; r<=18; r++) {
				sp(5);
				asciiseis(r,m,a);
				tb(2);
				asciiseis(r,m,u);
				printf("\n");
			}
			tb(6);printf("Desea jugar otra vez?\n");
			tb(6);sp(4);printf("Si[S]  /  No[N]");
			ln(1);
			break;
		}
	}
	else if (g == 1) {
		cls();
		won();
		pp(r,m,u);
		system("color a"); //Color verde
		tb(6);printf("Desea jugar otra vez?\n");
		tb(6);sp(4);printf("Si[S]  /  No[N]");
		ln(1);
	}
	else
		printf("Error. Parametro g no valido.");
	
}
