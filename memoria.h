#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>
#include "func_aux.h"
using namespace std;

char memoria(string []);
void cargarCincoPalabras(string palabrasElegidas[], string const palabras[]);
void tituloMemoria();
void mostrarPalabrasMemoria(string []);
char salir();
char menuJuegos();
int calcularPuntajeLetraRepetida(string [],char[]);
int calcularPuntajeCantVocales(string [],char []);
int calcularPuntajePalabraLarga(string [],char []);
bool esVocal(char);
int pot(int,int);
