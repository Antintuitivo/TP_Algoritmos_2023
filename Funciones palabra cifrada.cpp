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

//Funciones

bool esRepetido(char [], char ,int );

//Funciones
using namespace std;

string cifrar(string s, int tam){//cifra caracter por caracter la palabra
	string cifrada;
	for(int i=0;i<tam;i++){
		cifrada+=(char)((s[i]+3-'a')%26+'a');
	}
	return cifrada;
}
void mostrar (char matriz[fil][col],int tl){//impreime una matriz de 3 de alto del largo de la palabra cifrada
	for(int i=0;i<3;i++){
		for(int j=0;j<tl;j++){
			cout<<matriz[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
	
void tituloPalabraCifrada(char matrizCifrada[fil][col], int tl){//imprime el encabezado
	string encabezado= "| Palabra Cifrada |";
	cout<<endl;
	int largo_encabezado=(50-(encabezado.length()/2));
	for(int i=0;i<largo_encabezado;i++)cout<<" ";
	cout<<encabezado<<endl;
	for(int i=0;i<100;i++) cout<<"=";
	cout<<endl;
	string consigna="Adivina la siguiente palabra codificada:";
	cout<<consigna<<endl;
	mostrar(matrizCifrada,tl);
	
}
void agregarCelda (char matriz[fil][col], char celda[3][4], int & pos, int letras){
	//genera tantas celdas como letras tenga la palabra
	int concat=0, f, c;
	while(concat<letras){
		f=0;
		for(int i=0;i<3;i++){
			c=pos;
			for(int j=0;j<4;j++){
				matriz[f][c]=celda[i][j];
				c++;
			}
			f++;
		}
		pos+=4;
		concat++;
	}
}

void crearMatrices(char matriz[fil][col], int tam){
	char LUp= -38, LDown= -64, midV=-77, midH=-60, RUp=-65, RDown=-39;//caracteres de celdas
	matriz[0][0]=LUp;
	matriz[1][0]=midV;
	matriz[2][0]=LDown;
	char celda[3][4]={{midH, midH, midH,RUp},{' ',' ',' ', midV},{midH, midH, midH,RDown}};
	int pos=1;
	agregarCelda(matriz, celda, pos, tam);
}
void cargarPalabraCodificada(char matrizCifrada[fil][col], string palabra, int tam){
	int pos=2;
	for(int i=0;i<tam;i++){
		matrizCifrada[1][pos]= palabra[i];
		pos+=4;
	}
}

void mostrarLetrasIngresadas(char escritas[], int k, int cantIntentos){//Muestra las letras ingresadas por el usuario
	cout<<"Cantidad de intentos: "<<cantIntentos-k<<endl;
	cout<<"Letras ingresadas: ";
	for(int i=0;i<k;i++) cout<<escritas[i]<<" ";
	cout<<endl;
}
void vectorDeIntentos(char letrasIngresadas[], int tl){//inicializa con espacios vacios el vector que muestra las letras ingresadas
	for(int i=0;i<tl;i++){
		letrasIngresadas[i]=' ';
	}
}

void fin (bool correctas[], int tam, bool& gano){//devuelve si hay todavia letras sin resolver
	int i=0;
	bool incorrectas=false;
	while(i<tam and !incorrectas){
		if(!correctas[i]){
			incorrectas=true;
		}else if(i==tam-1) gano=true;
		i++;
	}
}
void completarMatriz(string palabra, char matriz[fil][col],char letra[], int tam, bool correctas[]){ //completa la matriz que se muestra con las letras ingresadas correctamente
	int pos=2;
	for(int i=0;i<tam;i++){
		if(palabra[i]==letra[0]){
			matriz[1][pos]=letra[0];
			correctas[i]=true;
		}
		pos+=4;
	}
}
	
void adivino(string palabra, char matriz[fil][col],char letra[],int tam, bool correctas[], bool&gano){
	completarMatriz(palabra, matriz, letra, tam, correctas);
	fin(correctas, tam, gano);
}
	
void noAdivino(int& errores){//aumenta la cantidad de errores
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout<<"Intenta con otra letra\n";
	Sleep(1000);
	SetConsoleTextAttribute(hConsole, 11);
	errores++;
}
