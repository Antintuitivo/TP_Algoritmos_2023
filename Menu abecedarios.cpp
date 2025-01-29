#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include "func_aux.h"

#include <cstdio>
using namespace std;

//Funciones

void bienvenida();
void login();
int digitos(int);
bool validarContra(char [],int);
void invertir(int,char[]);
int primDig(int);
void menuPrincipal();
void salir(char opcion='x');
char menuAbecedarios();
void juegos();
int potencia(int,int);
void ABCingles();
void show(string, int,string,string);
void mayusculas (string &, int);
void minusculas (string &, int);
void showABC (string, int,string);
void ABCespaniol();
void ABCfrances();
void ABCitaliano();
void ABCportugues();
bool esRepetido(char revisar[], char letra,int l);
void ahorcado();
bool descubrir(bool v[],int top);
void tituloAhorcado();
void mostrarLetrasIngresadas(const char escritas[],const int k);
void escribirPalabrasEspeciales (int);
//Funciones

char menuAbecedarios(){//Menu para elegir los abecedarios
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	system("cls");//Limpia la consola
	string encabezado="Menu Abecedarios";
	int largoEncabezado=(50-(encabezado.length()/2));//Usado para centrar el titulo
	cout<<endl;
	for(int i=0;i<largoEncabezado;i++)cout<<" ";
	cout<<encabezado<<endl;
	for(int i=0;i<100;i++) cout<<"=";//Linea separadora del titulo
	for(int i=1;i<6;i++){//Muestra las opciones
		cout<<i<<".- ";
		escribirPalabrasEspeciales(i);
		cout<<endl;
	}
	escribirPalabrasEspeciales(6);
	cout<<endl;
	char eleccion[20],salida;
	do{//Pide y valida que se ingrese una de las opciones validas
		cout<<"Ingrese una opci"<<(char)162<<"n: ";
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if(!((eleccion[0]>='1' and eleccion[0]<='5') or eleccion[0]=='X') or !(esUnDigito(eleccion))){
			system("cls");
			cout<<endl;
			for(int i=0;i<largoEncabezado;i++)cout<<" ";
			cout<<encabezado<<endl;
			for(int i=0;i<100;i++) cout<<"=";
			for(int i=1;i<6;i++){//Muestra las opciones
				cout<<i<<".- ";
				escribirPalabrasEspeciales(i);
				cout<<endl;
			}
			escribirPalabrasEspeciales(6);
			cout<<endl;
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(!((eleccion[0]>='1' and eleccion[0]<='5') or eleccion[0]=='X') or !(esUnDigito(eleccion)));
	salida=eleccion[0];
	return salida;
}
