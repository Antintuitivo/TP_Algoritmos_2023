#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>
#include "archivo.h"

using namespace std;
void extraerPalabrasDeArchivo(string palabras[]) {   
string linea;
int pos=0;

archivo Entrada;
Entrada=setup("Ahorcado en Español", "palabras-3.txt");
	
if (apertura(Entrada)==false){
	cout << "Error en apertura de archivo" << endl;
}
else {
	// leo todas las lineas hasta final del archivo
	bool final=false;
	do {//lee el archivo de la linea 1 a la 100+el eof
		linea= leerLinea(Entrada, final);//guarda cada palabra en el string linea
		if(pos<100){//cuando llega al eof (linea 101) no lo lee para evitar ERROR
		palabras[pos]=linea; 
		pos++;}
	} while (not final);
}
cierre(Entrada);
}
