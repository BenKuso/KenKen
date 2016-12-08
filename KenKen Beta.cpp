#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rodo.h"
//Prototipos.
void ceros(int matriz[6][6], int muestra[6][6], int usuarios[6][6], int n); //Función que llena en ceros las matrices usadas.
void respuesta(int matriz[6][6], int n);									//Función que genera un cuadrado Latino (CL).
void calculos(int muestra[6][6], int matriz[6][6], int n);					//Función que dado el CL asocia casillas y genera los calculos a realizar.
void user(int muestra[6][6], int usuario[6][6], int n);						//Función que permite al usuario llenar un arreglo
void resultado(int matriz[6][6],int usuario[6][6], int muestra[6][6],int n);
//Bloque Principal.
int main(){
	int n, matriz[6][6], muestra[6][6], usuario[6][6];  //Declaración de variables requeridas.
	system("cls");
	system("color 0b");
	title();
	cls();
	system("color 07");
	for(int i=0; i<30; i++){
		printf("\n");
	}
	sp(3);printf("Ingrese el orden de la matriz \n");			//Imprime mensaje que solicite el orden de la Matriz.
	scanf("%d",&n);
	ceros(matriz,muestra, usuario, n);							//Llama a la función ceros.
	pp(n, matriz, usuario);
	if(n>=3 && n<=6){	 								//Lee el orden de la matriz.
		ceros(matriz,muestra, usuario, n);				//Llama a la función ceros.
		respuesta(matriz, n);							//Llama a la función respuesta.
		calculos(muestra, matriz, n);					//Llama a la función calculo.
		user(muestra, usuario, n);						//Llama a la función user.
		resultado(matriz, usuario,muestra, n);			//Llama a la función resultado.
		system("pause");
	}else{
		system("color d");
		sp(5);printf("Este juego no est\240 dise\244ado para n\243meros mayores que 6 ni menores que 2\n");  //If que controla no salirse del rango e imprima mensaje si sucede.
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
			respaldo[i][j]=z;
			z++;
		}
		z=original;
	}
	for(int i=0; i<n; i++){								//ceros.
		vector[i]=0;
	}
	while(vector[n-1]==0){
		do{
			x=1+rand()%n;
			for(int i=0; i<n; i++){
				if(x==vector[i]){
					bandera=1;
					break;
				}else{
					bandera=0;
				}
			}
		}while(bandera==1);
		vector[k]=x;
		k++;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matriz[i][j]=respaldo[i][vector[j]-1];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			respaldo[i][j]=matriz[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
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
		printf("fila de la casilla que desea llenar \n");	//Muestra un mensaje pidiendo la fila de la casilla.
		scanf("%d",&fil);									//Lee la fila.
		printf("columna de la casilla que desea llenar \n");//Muestra un mensaje pidiendo la columna de la casilla.
		scanf("%d",&col);									//Lee la columna.
		printf("valor con que desea llenar \n");			//Pide el valor que se pondrá en la casilla indicada.
		scanf("%d",&valor);									//lee dicho valor.
		usuario[fil][col]=valor;							//Llena el valor dado en la casilla indicada. 
		cls();												//De nuevo hace un Clear Screen.
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
		printf("desea llenar otra casilla? SI=1 NO=0 \n");//pregunta si desea llenar otra casilla, al resonder si, se repetirá el ciclo.
		scanf("%d",&pregunta);							  //recibe la respuesta
	}while(pregunta==1);								  //Compara la respuesta dada y determina si se repite o no el ciclo.	
}		
					//resultado.
void resultado(int matriz[6][6],int usuario[6][6], int muestra[6][6], int n){
	int iguales=0;										//Declara la variable tipo contador usada para determinar la victoria o derrota.
		for(int i=0; i<n; i++){							//Doble ciclo que comparará valor por valor la matriz original y la que lleno el usuario.
			for(int j=0; j<n; j++){
				if(matriz[i][j]==usuario[i][j]){
					iguales++;							//En caso de que dos valores sean iguales, se añaden al contador.
				}
			}
		}
		if(iguales==(n*n)){								//Si el contador es igual a n^2 entonces ambas matrices son identicas, lo que significa que el usuario ha ganado.
			system("color a");							//Cambio de color a Verde.
			won();										//Imprime mensaje de Victoria.
		}else{											//Caso contrario el usuario ha perdido.
			system("color c");							//cambio de color a rojo.
			lose();									 	//Mensaje de Derrota.
			switch(n){									//se le da el resultado correcto.
				case 3:
					tres(muestra, matriz);
					break;
				case 4:
					cuatro(muestra, matriz);
					break;
				case 5: 
					cinco(muestra, matriz);
					break;
				case 6:
					seis(muestra, matriz);
					break;
			}
		}
}
