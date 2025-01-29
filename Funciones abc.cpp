#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
using namespace std;

//Funciones

void bienvenida();
void login();
int digitos(int);
bool validarContra(char [],int);
void invertir(int,char[]);
int primDig(int);
void menuPrincipal();
void salir(char opcion='x');
void abecedarios();
void juegos();
int potencia(int,int);
void ABCingles();
void show(char[], int,int,int []);
void mayusculas (char[], int);
void minusculas (char[], int);
void showABC (char, int);
void ABCespaniol();
void ABCfrances();
void ABCitaliano();
void ABCportugues();
bool esRepetido(char revisar[], char letra,int l);
void ahorcado();
bool descubrir(bool v[],int top);
void tituloAhorcado();
void mostrarLetrasIngresadas(const char escritas[],const int k);
void escribirPalabrasEspeciales (int);
//Funciones

void showABC (char s[], int tam){	//MUESTRA EL ALFABETO QUE LE PASEN
	int i=0, j=0;
	while(i<tam){
		while(j<10 and i<tam){
			cout<<s[i]<<" ";
			j++;
			i++;
		}
		j=0;
		cout<<endl;
	}
	cout<<endl;
}
void minusculas (char s[], int tam){		//Convierte de MAY a MIN una cadena
	for(int i=0;i<tam;i++){
		s[i]=tolower(s[i]);
	}
	return;
}
void mayusculas (char s[], int tam){		//Convierte de MIN a MAY una cadena
	for(int i=0;i<tam;i++){
		s[i]=toupper(s[i]);
	}
}
void show(char s[], int tam,int idioma,int vocales[],int tl){ 		//Muestra el abecedario en MAY y MIN
	cout<<"Abecedario en ";escribirPalabrasEspeciales(idioma);cout<<":"<<endl<<endl;
	minusculas(s,tam);
	if(idioma==1) s[14]=(char)164;
	showABC(s, tam);
	mayusculas(s,tam);
	if(idioma==1) s[14]=(char)165; //agragamos la Ñ
	showABC(s, tam);
	if(idioma==2)cout<<"El idioma Ingles no cuenta con letras acentuadas."<<endl;
	for(int i=0;i<tl;i++) { //Muestra las vocales solamente en el caso de que estas existan
		if(i==0){cout<<"Letras acentuadas del abecedario ";escribirPalabrasEspeciales(idioma);cout<<": ";}
		cout<<(char)(vocales[i])<<" ";
	}
	cout<<endl<<endl;
	return;
}
