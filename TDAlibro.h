#ifndef TDALIBRO_H
#define TDALIBRO_H
#include <fstream>
#include <string>
using namespace std;

struct Libro{
	fstream arc;
};

void cerrarLibro(Libro &arch);
bool abrirLibro(Libro &arch, char modo, string nombre);
Libro crearLibro();
char leerCaracterLibro(Libro &arch);
string leerPalabraLibro(Libro &arch);
void escribirPalabraLibro(Libro &arch, char cad[]);
void escribirNumeroLibro(Libro &arch, long long num);
bool finLibro(Libro &arch);
bool confirmarLibro(Libro &arch);
void escribirNum(Libro &arch,long long num);
void escribirChar(Libro &arch,char caracter);
void escribirString(Libro &arch,string frase);
	
#endif
