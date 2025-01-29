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


char menuPrincipal();
void salir(char opcion='x');
void menuAbecedarios();
void menuJuegos();


char menuPrincipal(){//Menu principal de la app
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	cout<<endl;
	string encabezado="Menu Principal";
	int centrar=(((encabezado.length()/2)-50)*(-1));//Usado para centrar el titulo
	for(int i=0;i<centrar;i++)cout<<" ";
	cout<<encabezado<<endl;
	for(int i=0;i<100;i++) cout<<"=";//Linea separadora del titulo
	cout<<endl;
	string opciones[4]={
		{"1.- Abecedarios."},
		{"2.- Juegos."},
		{"3.- Procesador de texto."},
		{"X.- Salir de la aplicacion."}};
	for(int i=0;i<4;i++) cout<<opciones[i]<<endl;//Muestra las opciones
	cout<<endl;
	char elegido[20],salida;
	do{//Pide y valida que se ingrese una de las opciones validas
		cout<<"Ingrese una opci"<<(char)162<<"n: ";
		gets(elegido);
		if(esUnDigito(elegido))elegido[0]=toupper(elegido[0]);
		if((elegido[0]!='1' and elegido[0]!='2' and elegido[0]!='3' and elegido[0]!='X') or !esUnDigito(elegido)){
			system("cls");
			cout<<endl;
			for(int i=0;i<centrar;i++)cout<<" ";
			cout<<encabezado<<endl;
			for(int i=0;i<100;i++) cout<<"=";
			for(int i=0;i<4;i++) cout<<opciones[i]<<endl;
			cout<<endl;
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	} while((elegido[0]!='1' and elegido[0]!='2' and elegido[0]!='3' and elegido[0]!='X') or !esUnDigito(elegido));
	salida=elegido[0];
	return salida;
}
