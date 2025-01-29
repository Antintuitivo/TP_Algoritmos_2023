#include "TDAlibro.h"
#include <iostream>
#include <string>
using namespace std;

Libro crearLibro(){
	Libro arch;
	return arch;
}

bool confirmarLibro(Libro &arch){//confirma si se abrió correctamente
	return !arch.arc.fail();
}
	
bool abrirLibro(Libro &arch, char modo, string nombre){//abre el archivo para leer o escribir según el modo elegido

	switch(modo){
	case 'l'://leer
		arch.arc.open(nombre,ios::in);
		break;
	case 'e'://escribir
		arch.arc.open(nombre,ios::out);
		break;
	case 'b'://binario
		arch.arc.open(nombre,ios::binary);
		break;
	}
	
	return confirmarLibro(arch);
}

void cerrarLibro(Libro &arch){
	arch.arc.close();
}

char leerCaracterLibro(Libro &arch){
	char c;
	arch.arc.get(c);
	return c;
}

string leerPalabraLibro(Libro &arch){
	string cad;
	getline(arch.arc,cad);
	return cad;
	
}

void escribirPalabraLibro(Libro &arch, char cad[]){
	arch.arc<<cad;
}

bool finLibro(Libro &arch){
	return arch.arc.eof();
}

void escribirString(Libro &arch,string frase){
	arch.arc<<frase;
}
void escribirChar(Libro &arch,char caracter){
	arch.arc<<caracter;
}
void escribirNum(Libro &arch,long long num){
	arch.arc<<num;
}
