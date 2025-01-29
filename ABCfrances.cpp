#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include "func_aux.h"
using namespace std;

//Funciones

void menuPrincipal();
void salir(char opcion='x');
void menuAbecedarios();
void show(char[], int,int,int [],int);
void mayusculas (char[], int);
void minusculas (char[], int);
void showABC (char[], int);

//Funciones


bool ABCfrances(){
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Las usamos para operar los colores de la consola en una linea especifica
	char abc[26];//Definimos el abecedario
	for(int i=97, j=0;i<123;i++, j++) abc[j]=(char)i;
	int vocales[]={145,198,133,131,130,138,136,137,140,139,147,151,150,129,135,152};//Definimos el abecedario y las letras acentuadas
	int tam=26, tl=16;	//Definimos el tamanio del abecedario

	show(abc, tam,5,vocales,tl);//Llamamos la funcion show para mostrar todo
	cout<<"Caracter no disponible en la tabla ASCII: oe"<<endl<<endl;
	
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
			show(abc,tam,5,vocales,tl);//vuelve a mostrar toda la funcion para volver a elegir la opcion
			cout<<"Caracter no disponible en la tabla ASCII: oe"<<endl<<endl;
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}

