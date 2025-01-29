#ifndef LISTASENLAZADAS_H
#define LISTASENLAZADAS_H
#include <string>
using namespace std;
struct Nodo{
	char palabra[40];
	int rep=0;
	Nodo *sig=NULL;
};

typedef Nodo * Lista;
typedef Nodo * ptrNodo;

void intercambiar(ptrNodo primero,ptrNodo segundo);
void ordenarLista(Lista ptrM);
void palabraAMinuscula(char pal[]);
Lista crearLista(char pal[]);
bool aniadirNodo(char pal[], Lista l);
bool encontrarPalabra(Lista l, ptrNodo &ptr, char pal[]);
float longitudPromedio(Lista l);
void porcentajePalabras(Lista l);
long long encontrarLetraLongitud(Lista l, char c, int n);
bool escribirArchvo(Lista l);
void palabrasLetraInicial(Lista l, string pals[], char c);
Lista abrirEstadisticasPalabras();
void crearMatrizFrecuencia(Lista l,int matriz[26][33]);
void mostrarMatrizFrecuencia(int [26][33]);
#endif
