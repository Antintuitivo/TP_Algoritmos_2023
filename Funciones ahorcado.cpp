#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <ctime>
#include <mmsystem.h>
#include "ahorcado.h"

bool descubrir(bool v[],int top){
	bool a=true;
	for(int i=0;i<top;i++){
		a=a&&v[i];
	}
	return a;
}
void tituloAhorcado(){//Muestra el titulo en el ahorcado
	string titulo="| Ahorcado |";
	int largoTitulo=titulo.length();
	int centrarTitulo=50-(largoTitulo/2);
	cout<<endl;
	for(int i=0;i<centrarTitulo;i++) cout<<" ";
	cout<<titulo<<endl;
	for(int i=0;i<100;i++) cout<<"=";
	cout<<endl;
	string preguntaPodrasAdivinar="Podras adivinar la palabra y salvarlo?";
	int centrarPreguntaAdivinar=50-(preguntaPodrasAdivinar.length()/2);
	cout<<endl;
	for(int i=0;i<centrarPreguntaAdivinar;i++) cout<<" ";
	cout<<"Podr"<<(char)160<<"s adivinar la palabra y salvarlo?"<<endl;
	cout<<endl;
	return;
}

void mostrarLetrasIngresadas(const char escritas[],const int k){//Muestra las letras ingresadas en el ahorcado
	cout<<"Letras ingresadas: ";
	if(k>0){
		for(int i=0;i<k;i++) cout<<escritas[i]<<" ";
	}
	cout<<endl;
	return;
}
