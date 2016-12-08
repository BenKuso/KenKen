#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int generals(int);
int title();
int sp(int);
void cls();
int pp(int rows, int m[6][6], int u[6][6]);
int tres(int[6][6],int[6][6]);
int cuatro(int[6][6],int[6][6]);
int cinco(int[6][6],int[6][6]);
int seis(int[6][6],int[6][6]);
int logo();
void won();
void lose();


int logo(){
	sp(1);
	sp(2);printf(" _   __             _   __           \n");
	sp(2);printf("| | / /            | | / /           \n");
	sp(2);printf("| |/ /  ___ _ __   | |/ /  ___ _ __  \n");
	sp(2);printf("|    \\ / _ \\ '_ \\  |    \\ / _ \\ '_ \\ \n");
	sp(2);printf("| |\\  \\  __/ | | | | |\\  \\  __/ | | |\n");
	sp(2);printf("\\_| \\_/\\___|_| |_| \\_| \\_/\\___|_| |_|\n");
	sp(3);printf("R   U   S   H\n");
	sp(4);	
}

int title(){ //Imprime la pantalla principal
	logo();
	sp(5);printf("+------+------+------+\n");
	sp(5);printf("|      |             |\n");
	sp(5);printf("|      |             |\n");
	sp(5);printf("+      +------+------+\n");
	sp(5);printf("|      |             |\n");
	sp(5);printf("|      |             |\n");
	sp(5);printf("+------+------+------+\n");
	sp(5);printf("|             |      |\n");
	sp(5);printf("|             |      |\n");
	sp(5);printf("+------+------+------+\n");
	sp(1);
	sp(6);printf("PRESIONA CUALQUIER TECLA PARA JUGAR\n");
	sp(7);
	printf("(C)2016 Todos Los Derechos Reservados. Benjamin Gonzalez, Rodolfo Gonzalez, Cristina Gonzalez, Alex Calderon.\n");
	getch();

}

int pp(int rows, int m[6][6], int u[6][6]){ //Pantalla de juego, recibe el numero de filas del kenken y las matrices de muestra y usuario.
	logo();
	switch (rows){ //De este modo, solo imprime el tablero que va de acuerdo al numero de filas (rows) del KenKen.
		case 3:
			tres(m,u);break;
		case 4:
			cuatro(m,u);break;
		case 5:
			cinco(m,u);break;
		case 6:
			seis(m,u);break;
	}
	sp(1);
	sp(6);
	sp(7);
	printf("Ingresa la fila, columna y valor, entre cada dato presiona ENTER.\n");
	getch();
}

int sp(int n){ //Maneja el espaciado de la función title
	switch (n) {
		case 1:
			printf("\n\n");
			break;
		case 2:
			printf("\t\t\t\t\t ");
			break;
		case 3:
			printf("\t\t\t\t\t\t     ");
			break;
		case 4:
			printf("\n\n");
			break;
		case 5:
			printf("\t\t\t\t\t\t");
			break;
		case 6:
			printf("\t\t\t\t\t   ");
			break;
		case 7:
			printf("\n\n\n\n\n\n");
			break;
	}
}

void cls(){
    system("cls");
}
    
int tres(int m[6][6], int u[6][6]){
	sp(5);printf("+------+------+------+\n");	
	sp(5);printf("| %i%c   | %i%c          |\n",m[0][0],m[1][0],m[0][1],m[0][2]);
	sp(5);printf("| [%i]  | [%i]    [%i]  |\n",u[0][0],u[0][1],u[0][2]);
	sp(5);printf("+      +------+------+\n");
	sp(5);printf("|      | %i%c          |\n",m[1][1],m[1][2]);
	sp(5);printf("| [%i]  | [%i]    [%i]  |\n",u[1][0],u[1][1],u[1][2]);
	sp(5);printf("+------+------+------+\n");
	sp(5);printf("| %i%c          | %i    |\n",m[2][0],m[2][1],m[2][2]);
	sp(5);printf("| [%i]   [%i]   | [%i]  |\n",u[2][0],u[2][1],u[2][2]);
	sp(5);printf("+------+------+------+\n");
}
    
int cuatro(int m[6][6], int u[6][6]){   
	printf("+------+------+------+------+\n");
	printf("| %i%c  | %i%c          | %i    |\n",m[0][0],m[1][0],m[0][1],m[0][2],m[0][3]);
	printf("| [%i]  | [%i]    [%i]  | [%i]  |\n",u[0][0],u[0][1],u[0][2],u[0][3]);
	printf("+      +------+------+------+\n");
	printf("|      | %i    | %i%c   | %i%c   |\n",m[1][1],m[1][2],m[2][2],m[1][3],m[2][3]);
	printf("| [%i]  | [%i]  | [%i]  | [%i]  |\n",u[1][0],u[1][1],u[1][2],u[1][3]);
	printf("+------+------+      +      +\n");
	printf("| %i%c   | %i%c   |      |      |\n",m[2][0],m[3][0],m[2][1],m[3][1]);
	printf("| [%i]  | [%i]  | [%i]  | [%i]  |\n",u[2][0],u[2][1],u[2][2],u[2][3]);
	printf("+      +      +------+------+\n");
	printf("|      |      | %i%c          |\n",m[3][2],m[3][3]);
	printf("| [%i]  | [%i]  | [%i]    [%i]  |\n",u[3][0],u[3][1],u[3][2],u[3][3]);
	printf("+------+------+------+------+\n");
}


int cinco(int m[6][6], int u[6][6]){
	printf("+------+------+------+------+------+\n");
	printf("| %i%c          | %i%c          | %i%c   |\n",m[0][0],m[0][1],m[0][2],m[0][3],m[0][4],m[1][3]);
	printf("| [%i]         | [%i]         | [%i]  |\n",u[0][0],u[0][1],u[0][2],u[0][3],u[0][4]);
	printf("+------+------+------+------+      +\n");
	printf("| %i    | %i%c          |             |\n",m[1][0],m[1][1],m[1][2]);
	printf("| [%i]  | [%i]    [%i]  | [%i]    [%i]  |\n",u[1][0],u[1][1],u[1][2],u[1][3],u[1][4]);
	printf("+------+------+------+------+------+\n");
	printf("| %i%c   | %i%c   | %i%c          | %i%c   |\n",m[2][0],m[3][0],m[2][1],m[3][1],m[2][2],m[3][3],m[2][4],m[3][4]);
	printf("| [%i]  | [%i]  | [%i]    [%i]  | [%i]  |\n",u[2][0],u[2][1],u[2][2],u[2][3],u[2][4]);
	printf("+      +      +------+      +      +\n");
	printf("|      |      | %i%c   |      |      |\n",m[3][2],m[3][3]);
	printf("| [%i]  | [%i]  | [%i]  | [%i]  | [%i]  |\n",u[3][0],u[3][1],u[3][2],u[3][3],u[3][4]);
	printf("+------+------+      +------+------+\n");
	printf("| %i%c          |             | %i    |\n",m[4][0],m[4][1],m[4][4]);
	printf("| [%i]    [%i]  | [%i]    [%i]  | [%i]  |\n",u[4][0],u[4][1],u[4][2],u[4][3],u[4][4]);
	printf("+------+------+------+------+------+\n");
}


int seis(int m[6][6], int u[6][6]){
	printf("+------+------+------+------+------+------+\n");
	printf("| %i%c          | %i%c                 | %i%c   |\n");
	printf("| [%i]    [%i]  | [%i]    [%i]    [%i]  | [%i]  |\n");
	printf("+      +------+------+------+------+      +\n");
	printf("|      | %i%c          | %i%c          |      |\n");
	printf("| [%i]  | [%i]    [%i]  | [%i]    [%i]  | [%i]  |\n");
	printf("+------+------+------+------+------+------+\n");
	printf("| %i%c   | %i%c   | %i%c          | %i%c          |\n");
	printf("| [%i]  | [%i]  | [%i]    [%i]  | [%i]    [%i]  |\n");
	printf("+      +      +------+------+------+------+\n");
	printf("|      |      | %i%c          | %i%c          |\n");
	printf("| [%i]  | [%i]  | [%i]    [%i]  | [%i]    [%i]  |\n");
	printf("+------+------+------+------+------+      +\n");
	printf("| %i    | %i%c          | %i%c          |      |\n");
	printf("| [%i]  | [%i]    [%i]  | [%i]    [%i]  | [%i]  |\n");
	printf("+------+------+------+------+------+------+\n");
	printf("| %i%c                 | %i    | %i%c          |\n");
	printf("| [%i]    [%i]    [%i]  | [%i]  | [%i]    [%i]  |\n");
	printf("+------+------+------+------+------+------+\n");
}
void won(){
	cls();
	printf("______   _ _      _     _           _            \n"); 
	printf("|  ___| | (_)    (_)   | |         | |           \n"); 
	printf("| |_ ___| |_  ___ _  __| | __ _  __| | ___  ___  \n"); 
	printf("|  _/ _ \\ | |/ __| |/ _` |/ _` |/ _` |/ _ \\/ __| \n"); 
	printf("| ||  __/ | | (__| | (_| | (_| | (_| |  __/\\__ \\ \n"); 
	printf("\\_| \\___|_|_|\\___|_|\\__,_|\\__,_|\\__,_|\\___||___/ \n"); 
}
void lose(){
	printf("______                              \n"); 
	printf("|  ___|                             \n"); 
	printf("| |_ _ __ __ _  ___ __  _ ___   ___   \n"); 
	printf("|  _| '__/ _` |/ __/ _ ` / __| / _ \\  \n"); 
	printf("| | | | | (_| | (_| (_|  \\__ \\| (_) | \n"); 
	printf("\\_| |_|  \\__,_|\\___\\__, _|___/ \\___/  \n"); 
	printf("Debi\242 tener algo como esto: \n");                                  
}
