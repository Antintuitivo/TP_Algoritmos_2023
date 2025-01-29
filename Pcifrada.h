#include <iostream>
#include <string>
#include <windows.h>
#define fil 3
#define col 65
#include <cctype>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <stdio.h>


using namespace std;

string cifrar(string s, int tam);
void mostrar (char matriz[fil][col],int tl);
void tituloPalabraCifrada(char matrizCifrada[fil][col], int tl);
void agregarCelda (char matriz[fil][col], char celda[3][4], int & pos, int letras);
void crearMatrices(char matriz[fil][col], int tam);
void cargarPalabraCodificada(char matrizCifrada[fil][col], string palabra, int tam);
void alertaDeError (char letra[], char letrasIngresadas[], int k);
void vectorDeIntentos(char letrasIngresadas[], int tl);
void mostrarLetrasIngresadas(char escritas[], int k, int cantIntentos);
void fin (bool correctas[], int tam, bool& gano);
void completarMatriz(string palabra, char matriz[fil][col],char letra, int tam, bool correctas[]);
void adivino(string palabra, char matriz[fil][col],char letra[],int tam, bool correctas[], bool&gano);
void noAdivino(int& errores);



