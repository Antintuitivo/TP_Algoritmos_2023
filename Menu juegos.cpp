#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <stdio.h>
#include <iomanip>
#include "archivo.h"
#include "func_aux.h"

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
void menuAbecedarios();
char menuJuegos();
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
void ahorcado(string []);
bool descubrir(bool v[],int top);
void tituloAhorcado();
void mostrarLetrasIngresadas(const char escritas[],const int k);
void numeroOtroIdioma();
void extraerPalabrasDeArchivo(string []);
void palabraCifrada(string []);
void numerosOtroIdioma();
void memoria(string []);

//Funciones

char menuJuegos(){//Menu para elegir el juego
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	system("cls");//Limpia la consola
	string encabezado="Menu Juegos";
	int largoEncabezado=(((encabezado.length()/2)-50)*(-1));//Usado para centrar el titulo
	cout<<endl;
	for(int i=0;i<largoEncabezado;i++)cout<<" ";
	cout<<encabezado<<endl;
	for(int i=0;i<100;i++) cout<<"=";//Linea separadora del titulo
	string opciones[5]={
		{"1.- Ahorcado"},
	{"2.- Palabra cifrada"},
		{"3.- Nros en otro idioma"},
	{"4.- Memoria"},
		{"X.- Volver al menu pricipal"}};
	for(int i=0;i<5;i++) cout<<opciones[i]<<endl;//Muestra las opciones
	cout<<endl;
	char eleccion[20],salida;
	do{//Pide y valida que se ingrese una de las opciones validas
		cout<<"Ingrese una opci"<<(char)162<<"n: ";
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if(!((eleccion[0]>='1' and eleccion[0]<='4') or eleccion[0]=='X') or !(esUnDigito(eleccion))){
			system("cls");
			cout<<endl;
			for(int i=0;i<largoEncabezado;i++)cout<<" ";
			cout<<encabezado<<endl;
			for(int i=0;i<100;i++) cout<<"=";
			for(int i=0;i<5;i++) cout<<opciones[i]<<endl;
			cout<<endl;
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(!((eleccion[0]>='1' and eleccion[0]<='4') or eleccion[0]=='X') or !(esUnDigito(eleccion)));
	salida=eleccion[0];
	return salida;
}

