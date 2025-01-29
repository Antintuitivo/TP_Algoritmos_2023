#include <iostream>
#include <string>
#include <windows.h>
#define fil 3
#define col 65
#include <cctype>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <ctime>
#include "Pcifrada.h"
#include "func_aux.h"
#include <cstdio>
//Funciones

void menuJuegos();
void salir(char opcion='x');
bool esRepetido(char [], char ,int );

//Funciones
using namespace std;

char palabraCifrada(string palabras[]){
	srand(time(NULL));
	int selectorPalabra=rand()%100;
	string palabra=palabras[selectorPalabra];//seleccionada del archivo
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int tam=palabra.length(), errores=0, puntos=100;
	string palabra_cod= cifrar(palabra, tam);
	char matrizRespuesta[fil][col], matrizCifrada[fil][col];
	
	//generar matrices
	crearMatrices(matrizRespuesta, tam);
	crearMatrices(matrizCifrada, tam);
	int tl=tam*4+1; //tamanio final del grafico de la matriz
	cargarPalabraCodificada(matrizCifrada, palabra_cod, tam);
	
	int cantIntentos=tam+7, k=0;//k es la cantidad de intentos acumulados
	bool correctas[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, gano=false;
	char letra[20], letrasIngresadas[20];
	vectorDeIntentos(letrasIngresadas, 20);
	
	do{//bucle donde ocurre el juego
		system("cls");
		tituloPalabraCifrada(matrizCifrada,tl);
		mostrarLetrasIngresadas(letrasIngresadas,k,cantIntentos);
		mostrar(matrizRespuesta, tl);
		alertaDeError(letra, letrasIngresadas, k,13);
		int busqueda=-1;
		busqueda=palabra.find(letra);
		if(busqueda==-1){//si la letra ingresada no forma parte de la palabra
			if(cantIntentos>k)noAdivino(errores);
		}else{//si la letra ingresada sí forma parte de la palabra
			adivino(palabra, matrizRespuesta, letra,tam, correctas, gano);//altera la cant de letras adivinadas
		}
		letrasIngresadas[k]=letra[0];
		k++;
		if(cantIntentos==k){
			system("cls");
			tituloPalabraCifrada(matrizCifrada,tl);
			mostrarLetrasIngresadas(letrasIngresadas,k,cantIntentos);
			mostrar(matrizRespuesta, tl);
		}
	} while(cantIntentos>k and !gano);//mientras no se hayan agotado los intentos ni haya ganado
	
	if(gano){//finaliza la partida con texto de victoria
		system("cls");
		tituloPalabraCifrada(matrizCifrada,tl);
		mostrarLetrasIngresadas(letrasIngresadas,k,cantIntentos);
		mostrar(matrizRespuesta, tl);
		puntos-=(errores*5);
		cout<<"FELICIDADES! Usted gano!"<<endl;
		cout<<"Tus puntos fueron: "<<puntos<<endl<<endl;
	}
	else cout<<endl<<"Te quedaste sin intentos, mejor suerte la proxima :("<<endl<<"La palabra codificada era: "<<palabra<<endl;//finaliza la partida con una derrota
	char eleccion[200],salida;
	do{//opciones de salir o volver
		cout<<endl;
		cout<<"Desea volver a jugar o volver al menu anterior? (1/X): ";
		fflush(stdin);
		for(int i=0;i<(int)strlen(eleccion);i++) cout<<" ";
		for(int i=0;i<(int)strlen(eleccion);i++) cout<<'\b';
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion))){
			gotoxy(0,17);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. ";
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion)));
	salida=eleccion[0];
	return salida;
}

