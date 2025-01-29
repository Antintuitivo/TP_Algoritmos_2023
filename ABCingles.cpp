#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <cstring>
#include "func_aux.h"
using namespace std;

//Funciones

void bienvenida();
bool login();
int digitos(int);
bool validarContra(char [],int);
void invertir(int,char[]);
int primDig(int);
void menuPrincipal();
void salir(char opcion='x');
void menuAbecedarios();
void menuJuegos();
int potencia(int,int);
bool ABCingles();
void show(char[], int,int,int [],int);
void mayusculas (char[], int);
void minusculas (char[], int);
void showABC (char[], int);
bool ABCespaniol();
bool ABCfrances();
bool ABCitaliano();
bool ABCportugues();
bool esRepetido(char revisar[], char letra,int l);
void ahorcado();
bool descubrir(bool v[],int top);
void tituloAhorcado();
void mostrarLetrasIngresadas(const char escritas[],const int k);

//Funciones

bool ABCingles(){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Las usamos para operar los colores de la consola en una linea especifica
	system("cls");//Limpia la consola
	char abc[26];//Definimos el abecedario
	for(int i=97, j=0;i<123;i++, j++) abc[j]=(char)i;
	int tam=26;//Definimos el tamanio del abecedario
	//No hay letras acentuadas
	show(abc, tam,2,0,0);//Llamamos la funcion show para mostrar todo
	
	string input;
	char eleccion[2]={'a','k'};
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		getline(cin,input);
		if(input=="X"||input=="x")
		{
			eleccion[0]='X';
			eleccion[1]='\0';
		}
		
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			show(abc, tam,2,0,0);//vuelve a mostrar toda la funcion para volver a elegir la opcion
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}
