#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>

using namespace std;

bool esRepetido(char revisar[], char letra,int l,int y);
void alertaDeError (char letra[], char letrasIngresadas[], int k,int y);
void escribirPalabrasEspeciales (int palabra);
char salir();
bool esUnDigito(char cadena[]);
void gotoxy(int x,int y);
