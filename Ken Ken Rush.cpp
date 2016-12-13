#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "graph.h"
//Prototipos.
void ceros(int matriz[6][6], int muestra[6][6], int usuarios[6][6], int n); //Función que llena en ceros las matrices usadas.
void respuesta(int matriz[6][6], int n);									//Función que genera un cuadrado Latino (CL).
void calculos(int muestra[6][6], int matriz[6][6], int n);					//Función que dado el CL asocia casillas y genera los calculos a realizar.
void user(int muestra[6][6], int usuario[6][6], int n);						//Función que permite al usuario llenar un arreglo.
void resultado(int matriz[6][6],int usuario[6][6], int muestra[6][6],int n);//Función que determina si el usuario ganó o perdió.
void sound();																//Función que reproduce la musica.
void again(char r);															//Función que permite al usuario jugar de nuevo sin cerrar el programa.
//Bloque Principal.
int main(){
	int n, matriz[6][6], muestra[6][6], usuario[6][6];  //Declaración de variables requeridas.
	char r;												//declaración de la variable que se enviará a la función "again"
	system("mode con lines=35");						//Establece un largo de 35 lineas para la ventana del programa.
	system("mode con cols=110");						//Establece un ancho de 110 columnas para la ventana del programa.
	sound();											//Llama a la función del sonido.
	cls();												//limpia la pantalla.
	system("color 0b");									//Color aqua.
	printf("KenKen Rush v.0.0.1 Beta");					//Mensaje con la Versión.
	tt();												//Llama a la función del título.
	system("pause");									//Espera...
	cls();												//Limpia Pantalla.
	csr();												//Llama a la función con la pantalla que pide el orden de la Matriz.
	dsn(5);scanf("%d",&n);								//Lee el orden de la Matriz.
	if(n>=3 && n<=6){	 								//Si el numero cumple con los requisitos...
		ceros(matriz,muestra, usuario, n);				//Llama a la función ceros.
		pp(n,muestra,usuario);							//Llama esta función que asignará colores por tableros y los centrará.
		respuesta(matriz, n);							//Llama a la función respuesta.
		calculos(muestra, matriz, n);					//Llama a la función calculo.
		user(muestra, usuario, n);						//Llama a la función user.
		resultado(matriz, usuario,muestra, n);			//Llama a la función resultado.
	}else{												//Si sale de Rango del Juego...
		cls();											//Limpia Pantalla.
		system("color d");								//Color Morado.
		dsn(1);											//Llama todas las funciones que componen el Título.
		logo();
		dsn(1);
		kkd();
		dsn(1);
		dsn(5);printf("Este juego no est\240 dise\244ado para n\243meros mayores que 6 \n");  //Mensaje que avisa que se salió de rango.
		dsn(5);printf("ni menores que 2\n");
		system("pause");								//Esperar...
		cls();											//Limpia Pantalla...
		dsn(1);											//LLama de nuevo todas las funciones del TITULO. (No llamamos al titulo, porque necesitamos mensajes diferentes del de inicio).
		logo();	
		dsn(1);
		kkd();
		dsn(1);
		dsn(5);printf("Desea jugar otra vez?\n");		//Preguntamos si desea jugar de nuevo.
		dsn(5);printf("Si[S]  /  No[N]\n");				
		dsn(5);scanf("%s",&r);							//recibe la respuesta que se mandará a la funcion "again".
		again(r);										//Llama a la función "again" y le manda la respuesta.
	}
}
//Implemmentaciones
						//ceros.
void ceros(int matriz[6][6], int muestra[6][6], int usuario[6][6], int n){
	for(int i=0; i<n; i++){ 							//ciclo que permite llenar las matrices en ceros.
		for(int j=0; j<n; j++){
			matriz[i][j]=0;
			muestra[i][j]=0;
			usuario[i][j]=0;
		}
	}	
}
						//respuesta.
void respuesta(int matriz[6][6], int n){
	int respaldo[6][6],z, original,x,vector[6],bandera,k=0;		//Declaración de variables.
	srand(time(NULL));									//Semilla.
	z=1+rand()%n;										//asigna a z un numero aleatorio de 1 a n.
	original=z;											//Guarda el número generado.								
	for(int i=0; i<n; i++){								//Ciclos para permutar valores.
		z=z+i;											//Al número generado le suma i.
		for(int j=0; j<n; j++){							
			if(z>n){									//condicional que impide que el numero pase de n.
				z=(z-n);						
			}
			matriz[i][j]=z;								//Asigna el número a la posición correspondiente en la matriz.
			respaldo[i][j]=z;							//generamos un respaldo de la matriz.
			z++;										//Aumenta el valor de z.
		}
		z=original;										//devuelve z a su valor original.
	}
	for(int i=0; i<n; i++){								//Llena el vector en ceros.
		vector[i]=0;
	}
	while(vector[n-1]==0){								//ciclo while que se repetirá mientras que no se generen todos los números hasta n.
		do{												//ciclo do while que se repetirá mientras que el número generado esté repetido en el vector.
			x=1+rand()%n;								//Se le asigna un número aleatorio a una variable x.
			for(int i=0; i<n; i++){						//Ciclo for que buscará el número generado en el vector.
				if(x==vector[i]){
					bandera=1;
					break;
				}else{
					bandera=0;
				}
			}
		}while(bandera==1);								
		vector[k]=x;									//Una vez generado un número que no se encuentre antes en el vector lo guarda en el mismo.
		k++;											//aumenta la variable k que permitirá guardar los números en distintas posiciones del vector.
	}
	for(int i=0; i<n; i++){								//ciclo que permite intercambiar los valores de la matriz de manera horizontal en función con los números generados.
		for(int j=0; j<n; j++){
			matriz[i][j]=respaldo[i][vector[j]-1];
		}
	}
	for(int i=0; i<n; i++){								//ciclo que actualiza el respaldo con los cambios realizados.
		for(int j=0; j<n; j++){
			respaldo[i][j]=matriz[i][j];
		}
	}
	for(int i=0; i<n; i++){								//ciclo que permite intercambiar los valores de la matriz de manera vertical en función con los números generados.
		for(int j=0; j<n; j++){
			matriz[j][i]=respaldo[vector[j]-1][i];
		}
	}
}	
					//calculos.
void calculos(int muestra[6][6], int matriz[6][6], int n){
	int calculo, operacion;								//Declaración de variables requeridas.
	switch(n){											//Switch que asocia casillas según el orden.
		case 3:								
			operacion=rand()%4;							//genera un valor aleatorio que representan una operación aritmética.
			if(operacion==0){							//0=+ 1=- 2=* 3=/.
				calculo=matriz[0][0]+matriz[1][0];		//Se realiza el calculo requerido contemplando evitar números negativos.
				operacion=43;							//Se asigna el valor en ASCII para el símbolo de la operación:
			}											//43=+ 45=-  42=* 47=/.
			if(operacion==1){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]-matriz[1][0];
					operacion=45;
				}else{
					calculo=matriz[1][0]-matriz[0][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][0]*matriz[1][0];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]/matriz[1][0];
					operacion=47;
					
				}else{
					calculo=matriz[1][0]/matriz[0][0];
					operacion=47;
				}
			}
			muestra[0][0]=calculo;						//de las casillas asociadas a la primera se le asigna el valor de la operación efectuada
			muestra[1][0]=operacion;					//a la última el valor en ASCII.
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][1]+matriz[0][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]-matriz[0][2];
					operacion=45;
				}else{
					calculo=matriz[0][2]-matriz[0][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][1]*matriz[0][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]/matriz[0][2];
					operacion=47;
				}else{
					calculo=matriz[0][2]/matriz[0][1];
					operacion=47;
				}
			}
			muestra[0][1]=calculo;
			muestra[0][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][1]+matriz[1][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]-matriz[1][2];
					operacion=45;
				}else{
					calculo=matriz[1][2]-matriz[1][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][1]*matriz[1][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]/matriz[1][2];
					operacion=47;
				}else{
					calculo=matriz[1][2]/matriz[1][1];
					operacion=47;
				}
			}
			muestra[1][1]=calculo;
			muestra[1][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[2][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[2][1]){
					calculo=matriz[2][0]-matriz[2][1];
					operacion=45;
				}else{
					calculo=matriz[2][1]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[2][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[2][1]){
					calculo=matriz[2][0]/matriz[2][1];
					operacion=47;
				}else{
					calculo=matriz[2][1]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[2][1]=operacion;
			muestra[2][2]=matriz[2][2];
			break;
		case 4:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][0]+matriz[1][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]-matriz[1][0];
					operacion=45;
				}else{
					calculo=matriz[1][0]-matriz[0][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][0]*matriz[1][0];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]/matriz[1][0];
					operacion=47;
				}else{
					calculo=matriz[1][0]/matriz[0][0];
					operacion=47;
				}
			}
			muestra[0][0]=calculo;
			muestra[1][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][1]+matriz[0][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]-matriz[0][2];
					operacion=45;
				}else{
					calculo=matriz[0][2]-matriz[0][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][1]*matriz[0][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]/matriz[0][2];
					operacion=47;
				}else{
					calculo=matriz[0][2]/matriz[0][1];
					operacion=47;
				}
			}
			muestra[0][1]=calculo;
			muestra[0][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[3][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]-matriz[3][0];
					operacion=45;
				}else{
					calculo=matriz[3][0]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[3][0];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]/matriz[3][0];
					operacion=47;
				}else{
					calculo=matriz[3][0]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[3][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][1]+matriz[3][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][1]>matriz[3][0]){
					calculo=matriz[2][1]-matriz[3][1];
					operacion=45;
				}else{
					calculo=matriz[3][1]-matriz[2][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][1]*matriz[3][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]/matriz[3][1];
					operacion=47;
				}else{
					calculo=matriz[3][1]/matriz[2][1];
					operacion=47;
				}
			}
			muestra[2][1]=calculo;
			muestra[3][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
					calculo=matriz[1][2]+matriz[2][2];
					operacion=43;
			}
			if(operacion==1){
				if(matriz[1][2]>matriz[2][2]){
					calculo=matriz[1][2]-matriz[2][2];
					operacion=45;
				}else{
					calculo=matriz[2][2]+matriz[1][2];
					operacion=45;
				}
			}
			if(operacion==2){
					calculo=matriz[1][2]*matriz[2][2];
					operacion=42;
			}
			if(operacion==3){
				if(matriz[1][2]>matriz[2][2]){
					calculo=matriz[1][2]/matriz[2][2];
					operacion=47;
				}else{
					calculo=matriz[2][2]/matriz[1][2];
					operacion=47;
				}
			}
			muestra[1][2]=calculo;
			muestra[2][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[3][2]+matriz[3][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[3][2]>matriz[3][3]){
					calculo=matriz[3][2]-matriz[3][3];
					operacion=45;
				}else{
					calculo=matriz[3][3]-matriz[3][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[3][2]*matriz[3][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[3][2]>matriz[3][3]){
					calculo=matriz[3][2]/matriz[3][3];
					operacion=47;
				}else{
					calculo=matriz[3][3]/matriz[3][2];
					operacion=47;
				}
			}
			muestra[3][2]=calculo;
			muestra[3][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][3]+matriz[2][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][3]>matriz[2][3]){
					calculo=matriz[1][3]-matriz[2][3];
					operacion=45;
				}else{
					calculo=matriz[2][3]-matriz[1][3];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][3]*matriz[2][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[1][3]>matriz[2][3]){
					calculo=matriz[1][3]/matriz[2][3];
					operacion=47;
				}else{
					calculo=matriz[2][3]/matriz[1][3];
					operacion=47;
				}
			}
			muestra[1][3]=calculo;
			muestra[2][3]=operacion;
			muestra[1][1]=matriz[1][1];
			muestra[0][3]=matriz[0][3];
			break;
		case 5:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][0]+matriz[0][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][0]>matriz[0][1]){
					calculo=matriz[0][0]-matriz[0][1];
					operacion=45;
				}else{
					calculo=matriz[0][1]-matriz[0][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][0]*matriz[0][1];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[0][0]>matriz[0][1]){
					calculo=matriz[0][0]/matriz[0][1];
					operacion=47;
				}else{
					calculo=matriz[0][1]/matriz[0][0];
					operacion=47;
				}
			}
			muestra[0][0]=calculo;
			muestra[0][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][2]+matriz[0][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][2]>matriz[0][3]){
					calculo=matriz[0][2]-matriz[0][3];
					operacion=45;
				}else{
					calculo=matriz[0][3]-matriz[0][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][2]*matriz[0][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][2]>matriz[0][3]){
					calculo=matriz[0][2]/matriz[0][3];
					operacion=47;
				}else{
					calculo=matriz[0][3]/matriz[0][2];
					operacion=47;
				}
			}
			muestra[0][2]=calculo;
			muestra[0][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[3][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]-matriz[3][0];
					operacion=45;
				}else{
					calculo=matriz[3][0]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[3][0];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]/matriz[3][0];
					operacion=47;
				}else{
					calculo=matriz[3][0]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[3][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][1]+matriz[3][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][1]>matriz[3][0]){
					calculo=matriz[2][1]-matriz[3][1];
					operacion=45;
				}else{
					calculo=matriz[3][1]-matriz[2][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][1]*matriz[3][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]/matriz[3][1];
					operacion=47;
				}else{
					calculo=matriz[3][1]/matriz[2][1];
					operacion=47;
				}
			}
			muestra[2][1]=calculo;
			muestra[3][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
					calculo=matriz[1][1]+matriz[1][2];
					operacion=43;
			}
			if(operacion==1){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]-matriz[1][2];
					operacion=45;
				}else{
					calculo=matriz[1][2]-matriz[1][1];
					operacion=45;
				}
			}
			if(operacion==2){
					calculo=matriz[1][1]*matriz[1][2];
					operacion=42;
			}
			if(operacion==3){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]/matriz[1][2];
					operacion=47;
				}else{
					calculo=matriz[1][2]+matriz[1][1];
					operacion=47;
				}
			}
			muestra[1][1]=calculo;
			muestra[1][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[4][0]+matriz[4][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[4][0]>matriz[4][1]){
					calculo=matriz[4][0]-matriz[4][1];
					operacion=45;
				}else{
					calculo=matriz[4][1]-matriz[4][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[4][0]*matriz[4][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[4][0]>matriz[4][1]){
					calculo=matriz[4][0]-matriz[4][1];
					operacion=47;
				}else{
					calculo=matriz[4][1]/matriz[4][0];
					operacion=47;
				}
			}
			muestra[4][0]=calculo;
			muestra[4][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][4]+matriz[3][4];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][4]>matriz[3][4]){
					calculo=matriz[2][4]-matriz[3][4];
					operacion=45;
				}else{
					calculo=matriz[3][4]-matriz[2][4];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][4]*matriz[3][4];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][4]>matriz[3][4]){
					calculo=matriz[2][4]/matriz[3][4];
					operacion=47;
				}else{
					calculo=matriz[3][4]-matriz[2][4];
					operacion=47;
				}
			}
			muestra[2][4]=calculo;
			muestra[3][4]=operacion;
			operacion=rand()%2;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[0][4]+matriz[1][3]+matriz[1][4];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[0][4]*matriz[1][3]*matriz[1][4];
				operacion=42;
			}
			muestra[0][4]=calculo;
			muestra[1][3]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[2][2]+matriz[2][3]+matriz[3][3];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[2][2]*matriz[2][3]*matriz[3][3];
				operacion=42;
			}
			muestra[2][2]=calculo;
			muestra[3][3]=operacion;
			if(operacion==0){
				calculo=matriz[3][2]+matriz[4][2]+matriz[4][3];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[3][2]*matriz[4][2]*matriz[4][3];
				operacion=42;
			}
			muestra[3][2]=calculo;
			muestra[4][3]=operacion;
			muestra[1][0]=matriz[1][0];
			muestra[4][4]=matriz[4][4];
			break;
		case 6:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][1]+matriz[1][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][2]-matriz[1][2];
					operacion=45;
				}else{
					calculo=matriz[1][2]-matriz[1][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][1]*matriz[1][2];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]/matriz[1][2];
					operacion=47;
				}else{
					calculo=matriz[1][2]/matriz[1][1];
					operacion=47;
				}
			}
			muestra[1][1]=calculo;
			muestra[1][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][3]+matriz[1][4];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][3]>matriz[1][4]){
					calculo=matriz[1][3]-matriz[1][4];
					operacion=45;
				}else{
					calculo=matriz[1][4]-matriz[1][3];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][3]*matriz[1][4];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[1][3]>matriz[1][4]){
					calculo=matriz[1][3]/matriz[1][4];
					operacion=47;
				}else{
					calculo=matriz[1][4]/matriz[1][3];
					operacion=47;
				}
			}
			muestra[1][3]=calculo;
			muestra[1][4]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][5]+matriz[1][5];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][5]>matriz[1][5]){
					calculo=matriz[0][5]-matriz[1][5];
					operacion=45;
				}else{
					calculo=matriz[1][5]-matriz[0][5];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][5]*matriz[1][5];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][5]>matriz[1][5]){
					calculo=matriz[0][5]/matriz[1][5];
					operacion=47;
				}else{
					calculo=matriz[1][5]/matriz[0][5];
					operacion=47;
				}
			}
			muestra[0][5]=calculo;
			muestra[1][5]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[3][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]-matriz[3][0];
					operacion=45;
				}else{
					calculo=matriz[3][0]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[3][0];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]/matriz[3][0];
					operacion=47;
				}else{
					calculo=matriz[3][0]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[3][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][1]+matriz[3][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]-matriz[3][1];
					operacion=45;
				}else{
					calculo=matriz[3][1]-matriz[2][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][1]*matriz[3][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]/matriz[3][1];
					operacion=47;
				}else{
					calculo=matriz[3][1]/matriz[2][1];
					operacion=47;
				}
			}
			muestra[2][1]=calculo;
			muestra[3][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][2]+matriz[2][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][2]>matriz[2][3]){
					calculo=matriz[2][2]-matriz[2][3];
					operacion=45;
				}else{
					calculo=matriz[2][3]-matriz[2][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][2]*matriz[2][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[2][3]){
					calculo=matriz[2][2]-matriz[2][3];
					operacion=47;
				}else{
					calculo=matriz[2][3]/matriz[2][2];
					operacion=47;
				}
			}
			muestra[2][2]=calculo;
			muestra[2][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[3][2]+matriz[3][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[3][2]>matriz[3][3]){
					calculo=matriz[3][2]-matriz[3][3];
					operacion=45;
				}else{
					calculo=matriz[3][3]-matriz[3][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[3][2]*matriz[3][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[3][3]){
					calculo=matriz[3][2]-matriz[3][3];
					operacion=47;
				}else{
					calculo=matriz[3][3]/matriz[3][2];
					operacion=47;
				}
			}
			muestra[3][2]=calculo;
			muestra[3][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[4][3]+matriz[4][4];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[4][3]>matriz[4][4]){
					calculo=matriz[4][3]-matriz[4][4];
					operacion=45;
				}else{
					calculo=matriz[4][4]-matriz[4][3];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[4][3]*matriz[4][4];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[4][3]>matriz[4][4]){
					calculo=matriz[4][3]-matriz[4][4];
					operacion=47;
				}else{
					calculo=matriz[4][4]/matriz[4][3];
					operacion=47;
				}
			}
			muestra[4][3]=calculo;
			muestra[4][4]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[5][4]+matriz[5][5];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[5][4]>matriz[5][5]){
					calculo=matriz[5][4]-matriz[5][5];
					operacion=45;
				}else{
					calculo=matriz[5][5]-matriz[5][4];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[5][4]*matriz[5][5];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[5][5]){
					calculo=matriz[5][4]-matriz[5][5];
					operacion=47;
				}else{
					calculo=matriz[5][5]/matriz[5][4];
					operacion=47;
				}
			}
			muestra[5][4]=calculo;
			muestra[5][5]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][4]+matriz[2][5];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][4]>matriz[2][5]){
					calculo=matriz[2][4]-matriz[2][5];
					operacion=45;
				}else{
					calculo=matriz[2][5]-matriz[2][4];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][4]*matriz[2][5];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[2][5]){
					calculo=matriz[2][4]-matriz[2][5];
					operacion=47;
				}else{
					calculo=matriz[2][5]/matriz[2][4];
					operacion=47;
				}
			}
			muestra[2][4]=calculo;
			muestra[2][5]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[4][1]+matriz[4][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[4][1]>matriz[4][2]){
					calculo=matriz[4][1]-matriz[4][2];
					operacion=45;
				}else{
					calculo=matriz[4][2]-matriz[4][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[4][1]*matriz[4][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[4][2]){
					calculo=matriz[4][1]-matriz[4][2];
					operacion=47;
				}else{
					calculo=matriz[4][2]/matriz[4][1];
					operacion=47;
				}
			}
			muestra[4][1]=calculo;
			muestra[4][2]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[0][1]+matriz[0][0]+matriz[1][0];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[1][0]*matriz[0][0]*matriz[1][0];
				operacion=42;
			}
			muestra[0][1]=calculo;
			muestra[1][0]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[0][2]+matriz[0][3]+matriz[0][4];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[0][2]*matriz[0][3]*matriz[0][4];
				operacion=42;
			}
			muestra[0][2]=calculo;
			muestra[0][4]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[3][4]+matriz[3][5]+matriz[4][5];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[3][4]*matriz[3][5]*matriz[4][5];
				operacion=42;
			}
			muestra[3][4]=calculo;
			muestra[4][5]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[5][0]+matriz[5][1]+matriz[5][2];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[5][0]*matriz[5][1]*matriz[5][2];
				operacion=42;
			}
			muestra[5][0]=calculo;
			muestra[5][2]=operacion;
			muestra[4][0]=matriz[4][0];
			muestra[5][3]=matriz[5][3];
			break;
	}
}	
					//Usuario.
void user(int muestra[6][6], int usuario[6][6], int n){
	int fil, col, valor, pregunta; 							//Declaración de variables usadas.
	do{														//ciclo do wuile que permita repetir siempre que el usuario así lo desee.
		cls();
		logo();
		switch(n){											//Switch para llamar a la funcion que corresponda según el orden de la matriz.
			case 3:
				tres(muestra, usuario);
				break;
			case 4:
				cuatro(muestra, usuario);
				break;
			case 5: 
				cinco(muestra, usuario);
				break;
			case 6:
				seis(muestra, usuario);
				break;
		}
		dsn(5);printf("fila de la casilla que desea llenar \n");	//Muestra un mensaje pidiendo la fila de la casilla.
		dsn(5);scanf("%d",&fil);											//Lee la fila.
		dsn(5);printf("columna de la casilla que desea llenar \n");//Muestra un mensaje pidiendo la columna de la casilla.
		dsn(5);scanf("%d",&col);											//Lee la columna.
		dsn(5);	printf("valor con que desea llenar \n");		//Pide el valor que se pondrá en la casilla indicada.
		dsn(5);scanf("%d",&valor);										//lee dicho valor.
		if(valor>n || valor<0){											//Condicional que controla que los números ingresados entén en el dominio del Ken Ken.
			dsn(5);printf("Debes Colocar un Valor entre 1 y %d\n",n);
			pregunta==1;
		}else{
			usuario[fil][col]=valor;							//Llena el valor dado en la casilla indicada. 
			cls();												//De nuevo hace un Clear Screen.
			logo();
			switch(n){											//Switch para llamar a la funcion que corresponda según el orden de la matriz.
				case 3:
					tres(muestra, usuario);
					break;
				case 4:
					cuatro(muestra, usuario);
					break;
				case 5: 
					cinco(muestra, usuario);
					break;
				case 6:
					seis(muestra, usuario);
					break;
			}
		}
		dsn(5);printf("desea llenar otra casilla? SI=1 NO=0 \n");//pregunta si desea llenar otra casilla, al resonder si, se repetirá el ciclo.
		dsn(5);scanf("%d",&pregunta);					  //recibe la respuesta
	}while(pregunta==1);								  //Compara la respuesta dada y determina si se repite o no el ciclo.	
}		
					//resultado.
void resultado(int matriz[6][6],int usuario[6][6], int muestra[6][6], int n){
	int iguales=0;										//Declara la variable tipo contador usada para determinar la victoria o derrota.
	char r;	
		for(int i=0; i<n; i++){							//Doble ciclo que comparará valor por valor la matriz original y la que lleno el usuario.
			for(int j=0; j<n; j++){
				if(matriz[i][j]==usuario[i][j]){
					iguales++;							//En caso de que dos valores sean iguales, se añaden al contador.
				}
			}
		}
		if(iguales==(n*n)){								//Si el contador es igual a n^2 entonces ambas matrices son identicas, lo que significa que el usuario ha ganado.
			game(1,n,muestra,usuario,matriz);			//Envía el resultdo a la función que mostrará el mensaje de victoria.					
			tb(6);sp(6);scanf("%s",&r);					//Recibe la respuesta para la función "again" (No hacemos la pregunta porque la función llamada arriba lo hace).
			again(r);									//Llama a la función "again".
		}else{											//Caso contrario el usuario ha perdido.
			game(0,n,muestra,usuario,matriz);			//Envía el resultdo a la función que mostrará el mensaje de derrota.	
			tb(6);sp(6);scanf("%s",&r);					//Recibe la respuesta para la función "again" 
			again(r);									//Llama a la función "again".
		}
}	
		//Sound.
void sound(){											
	char soundfile[] = "8 bits.wav" ;					//declara la variable con el nombre del archivo de audio a reproducir.
	PlaySound((LPCSTR)soundfile, NULL, SND_LOOP | SND_ASYNC );//Función que reproduce el audio de manera repetitiva.
}
		//Again.	
void again(char r){										
	cls();												//Limpia la pantalla.
	if(r=='S' || r=='s'){								//Si respondió si llama a la función main haciendo que todo vuelva a empezar(No importa si el usuario ingresa mayúsculas o minúsculas, si es "S" lo hará).
		main();
	}
}							
