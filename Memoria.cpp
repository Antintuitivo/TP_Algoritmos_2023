#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>
#include "func_aux.h"
using namespace std;

//Funciones

char memoria(string []);
void tituloMemoria();
void mostrarPalabrasMemoria(string []);
void salir(char opcion='x');
void menuJuegos();
int calcularPuntajeLetraRepetida(string [],char[]);
int calcularPuntajeCantVocales(string [],char []);
int calcularPuntajePalabraLarga(string [],char []);
bool esVocal(char);
int pot(int,int);
void cargarCincoPalabras(string palabrasElegidas[], string const palabras[]);

//Funciones

char memoria(string palabras[]){
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string palabrasElegidas[5];
	cargarCincoPalabras(palabrasElegidas,palabras);
	tituloMemoria();//Mostramos el titulo del juego 
	mostrarPalabrasMemoria(palabrasElegidas);//Mostramos las 5 palabras por 2 segundos
	system("cls");
	tituloMemoria();
	char letraMasVeces[10],vocales[50],palabraMasLarga[200];
	do{
		cout<<"Cual es la letra que se repite mas veces? :";
		gets(letraMasVeces);
		if(strlen(letraMasVeces)>1 or !(isalpha(letraMasVeces[0]))){//Verifica que la cadena de caracteres ingresada contenga solo 1 caracter y sea una letra
			system("cls");
			tituloMemoria();
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	} while(strlen(letraMasVeces)>1 or !(isalpha(letraMasVeces[0])));
	letraMasVeces[0]=tolower(letraMasVeces[0]);//Verificado el paso anterior, nos aseguramos que la letra ingresada este en minusculas
	int contadorRepet=0;
	bool todosNum=true;
	do{
		todosNum=true;
		if(contadorRepet==0){//Si es la primera iteracion del bucle, limpia la consola para no arrastrar posibles mensajes de error
			system("cls");
			tituloMemoria();
			cout<<"Cual es la letra que se repite mas veces? :";puts(letraMasVeces);
		}
		cout<<"Cuantas vocales hay en total?: ";
		gets(vocales);
		int largoVocales=strlen(vocales);
		for(int i=0;i<largoVocales;i++) { //Verifica que cada digito ingresado en la cadena sea un numero
			if(!(isdigit(vocales[i])))todosNum=false;
		}
		if(!todosNum){
			system("cls");
			tituloMemoria();
			cout<<"Cual es la letra que se repite mas veces? :";puts(letraMasVeces);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
			contadorRepet++;
		}
	} while(!todosNum);
	contadorRepet=0;
	bool todosLet=true;
	do{
		todosLet=true;
		if(contadorRepet==0){//Si es la primera iteracion del bucle, limpia la consola para no arrastrar posibles mensajes de error
			system("cls");
			tituloMemoria();
			cout<<"Cual es la letra que se repite mas veces? :";puts(letraMasVeces);
			cout<<"Cuantas vocales hay en total?: ";puts(vocales);
		}
		cout<<"Cual es la palabra mas larga?: ";
		gets(palabraMasLarga);
		int largoPalabra=strlen(palabraMasLarga);
		for(int i=0;i<largoPalabra;i++) { 
			if(!(isalpha(palabraMasLarga[i])))todosLet=false;//Verifica que cada caracter de la cadena sea una letra
		}
		if(!todosLet){
			system("cls");
			tituloMemoria();
			cout<<"Cual es la letra que se repite mas veces? :";puts(letraMasVeces);
			cout<<"Cuantas vocales hay en total?: ";puts(vocales);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
			contadorRepet++;
		}
	} while(!todosLet);
	if(contadorRepet>0){//Si arrastra un error del menu anterior, limpia la consola para borrar esos mensajes, y muestra todo limpio
		system("cls");
		tituloMemoria();
		cout<<"Cual es la letra que se repite mas veces? :";puts(letraMasVeces);
		cout<<"Cuantas vocales hay en total?: ";puts(vocales);
		cout<<"Cual es la palabra mas larga?: ";puts(palabraMasLarga);
	}
	int puntajeLetra=calcularPuntajeLetraRepetida(palabrasElegidas,letraMasVeces);
	int puntajeVocal=calcularPuntajeCantVocales(palabrasElegidas,vocales);
	int puntajePalabra=calcularPuntajePalabraLarga(palabrasElegidas,palabraMasLarga);
	cout<<endl;
	cout<<"Tu puntaje total es: "<<puntajeLetra+puntajePalabra+puntajeVocal<<endl<<endl;
	cout<<"Las palabras eran: "<<endl;
	for(int i=0;i<5;i++) { 
		cout<<palabrasElegidas[i]<<endl;
	}
	cout<<endl<<endl;
	char eleccion[200],salida;
	do{//Menu de accion al terminar el juego
		cout<<endl;
		cout<<"Desea volver a jugar o volver al menu anterior? (1/X): ";
		fflush(stdin);
		for(int i=0;i<(int)strlen(eleccion);i++) cout<<" ";
		for(int i=0;i<(int)strlen(eleccion);i++) cout<<'\b';
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion))){
			gotoxy(0,30);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion)));
	salida=eleccion[0];
	return salida;
}

