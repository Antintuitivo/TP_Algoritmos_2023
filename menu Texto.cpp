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

char menuProcesadorTexto(){//Menu principal de la app
	system("cls");//Limpia la consola
	system("mode con: cols=100 lines=40");//Definimos el tamanio de la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	cout<<endl;
	string encabezado="Procesador de Textos";
	int centrar=(50-(encabezado.length()/2));//Usado para centrar el titulo
	for(int i=0;i<centrar;i++)cout<<" ";
	cout<<encabezado<<endl;
	for(int i=0;i<100;i++) cout<<"=";//Linea separadora del titulo
	cout<<endl;
	string opciones[3]={
		{"1.- Estadisticas a nivel caracteres."},
		{"2.- Estadisticas a nivel palabras."},
		{"X.- Volver al menu principal."}};
	for(int i=0;i<3;i++) cout<<opciones[i]<<endl;//Muestra las opciones
	cout<<endl;
	char elegido[20],salida;
	do{//Pide y valida que se ingrese una de las opciones validas
		cout<<"Ingrese una opci"<<(char)162<<"n: ";
		gets(elegido);
		if(esUnDigito(elegido))elegido[0]=toupper(elegido[0]);
		if((elegido[0]!='1' and elegido[0]!='2' and elegido[0]!='X') or !esUnDigito(elegido)){
			system("cls");
			cout<<endl;
			for(int i=0;i<centrar;i++)cout<<" ";
			cout<<encabezado<<endl;
			for(int i=0;i<100;i++) cout<<"=";
			for(int i=0;i<3;i++) cout<<opciones[i]<<endl;
			cout<<endl;
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	} while((elegido[0]!='1' and elegido[0]!='2' and elegido[0]!='X') or !esUnDigito(elegido));
	salida=elegido[0];
	return salida;
}
	
	
