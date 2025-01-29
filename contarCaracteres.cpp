#include <iostream>
#include "TDAlibro.h"
#include <cstdlib>
#include <windows.h>
#include <string>
#include "func_aux.h"
struct tablaFrecuencia{
	char caracter;
	int frecuencia=0;
};

using namespace std;
int ordenarMayorMenor(tablaFrecuencia []);
void tituloFrecuenciaCar();
void imprimirCaracteresEnPantalla(int tl, tablaFrecuencia cont[]);
bool contarCaracteres(){
	system("cls");//Limpia la consola
	system("mode con: cols=100 lines=100");//Definimos el tamanio de la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Las usamos para cambiar el color de la consola en una linea especifica
	tituloFrecuenciaCar();
	Libro abrir=crearLibro();
	tablaFrecuencia contador[128];
	if(! abrirLibro(abrir,'l',"Pride and Prejudice.txt"))cout<<"Error al abrir archivo"<<endl;
	else{
		while(!(finLibro(abrir))){
			char a=leerCaracterLibro(abrir);
			if(contador[(int)a].frecuencia==0)contador[(int)a].caracter=a;
			contador[(int)a].frecuencia++;
		}
	}
	cerrarLibro(abrir);
	
	int tl=ordenarMayorMenor(contador);
	imprimirCaracteresEnPantalla(tl, contador);//mostramos la tabla de frecuencia
	Libro crear;
	if(!abrirLibro(crear,'e',"frecuencia.txt")){cout<<"Error al abrir archivo"<<endl;}
	else{
		escribirString(crear,"Tabla de frecuencias de cada caracter\n");
		for(int i=0;i<tl;i++) { //guardamos tabla de frecuencia en archivo
			if(contador[i].caracter==32) escribirString(crear,"" "(espacio)");
			else if(contador[i].caracter==10)escribirString(crear,"(nueva linea)");
			else if(contador[i].caracter==9)escribirString(crear,"(tabulacion)");
			else if(contador[i].caracter==0)escribirString(crear,"(NULL)");
			else escribirChar(crear,contador[i].caracter);
			escribirString(crear,": ");
			escribirNum(crear,contador[i].frecuencia);
			escribirString(crear,"\n");
		}
	}
	cerrarLibro(crear);
	char eleccion[10];
	
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		
		gets(eleccion);
		eleccion[0]=toupper(eleccion[0]);
		
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			tituloFrecuenciaCar();
			imprimirCaracteresEnPantalla(tl, contador);//mostramos tabla de frecuencia
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}
void imprimirCaracteresEnPantalla(int tl, tablaFrecuencia contador[]){
	cout<<"Tabla de frecuencia de cada caracter en el libro"<<endl;
	for(int i=0;i<tl;i++) { 
		if(contador[i].caracter==32)cout<<"" "(espacio)";
		else if(contador[i].caracter==10)cout<<"(nueva linea)";
		else if(contador[i].caracter==9)cout<<"(tabulacion)";
		else if(contador[i].caracter==0)cout<<"(NULL)";
		else cout<<contador[i].caracter;
		cout<<": "<<contador[i].frecuencia<<endl;
	}
}
