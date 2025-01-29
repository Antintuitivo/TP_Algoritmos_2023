#include <iostream>
#include "TDAlibro.h"
#include <cstdlib>
#include <windows.h>

struct tablaFrecuencia{
	char caracter;
	int frecuencia=0;
};


using namespace std;
int ordenarMayorMenor(tablaFrecuencia arr[]){
	tablaFrecuencia aux;
	int tl;
	for(int i=0;i<128;i++) { 
		for(int j=0;j<128;j++) { 
			if(arr[i].frecuencia>arr[j].frecuencia){
				aux=arr[j];
				arr[j]=arr[i];
				arr[i]=aux;
			}
		}
	}
	int h=0;
	bool bandera=true;
	while(bandera and h<128){
		if(arr[h].frecuencia==0){
			bandera=false;
			tl=h;
		}
		h++;
	}
	return tl;
}

void tituloFrecuenciaCar(){//Muestra el titulo en el ahorcado
	string titulo="| Estadisticas a nivel de caracteres |";
	int largoTitulo=titulo.length();
	int centrarTitulo=50-(largoTitulo/2);
	cout<<endl;
	for(int i=0;i<centrarTitulo;i++) cout<<" ";
	cout<<titulo<<endl;
	for(int i=0;i<100;i++) cout<<"=";
	cout<<endl;
	cout<<endl;
	return;
}	


