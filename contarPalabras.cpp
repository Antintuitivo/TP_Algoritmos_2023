#include <iostream>
#include "TDAlibro.h"
#include <cstdlib>
#include <windows.h>
#include <string>
#include "func_aux.h"
#include "ListasEnlazadas.h"
using namespace std;



void tituloFrecuenciaPal(){//Muestra el titulo en el ahorcado
	string titulo="| Estadisticas a nivel de palabras |";
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


