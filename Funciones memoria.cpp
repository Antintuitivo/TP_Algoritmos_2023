#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>
#include "func_aux.h"
#include "memoria.h"
using namespace std;


void tituloMemoria(){//Muestra el titulo en el juego
	string titulo="| Memoria |";
	int largoTitulo=titulo.length();
	int centrarTitulo=50-(largoTitulo/2);
	cout<<endl;
	for(int i=0;i<centrarTitulo;i++) cout<<" ";
	cout<<titulo<<endl;
	for(int i=0;i<100;i++) cout<<"=";
	cout<<endl<<endl;
	return;
}
	
void mostrarPalabrasMemoria(string palabras[]){//Muestra las 5 palabras por 2 segundos
	cout<<"Se mostraran 5 palabras por solo 2 segundos, presta atencion!"<<endl<<endl;
	Sleep(2000);
	for(int i=0;i<5;i++) { 
		cout<<"  -  "<<palabras[i]<<endl;
	}
	Sleep(2000);
	return;
}

int calcularPuntajeLetraRepetida(string palabras[],char letra[]){
	int iterador=0,largo,letrasRepetidas[30]={},mayor[3]={},puntajeFinal=0; 
	char top3[3];
	while(iterador<5){//Llena un arreglo contador con la posicion de cada letra y la cantidad de veces que se encontró
		largo=palabras[iterador].length();//Establece hasta donde debe leer el for segun el largo de cada palabra
		for(int i=0;i<largo;i++) { 
			letrasRepetidas[palabras[iterador][i]-'a']++;
		}
		iterador++;
	}
	for(int j=0;j<3;j++) { //Arma un top3 de las letras mas repetidas en las 5 palabras
		for(int i=0;i<27;i++) {
			if(j==0){
				if(letrasRepetidas[i]>mayor[j]){
					mayor[j]=letrasRepetidas[i];
					top3[j]=i+'a';
				}
			}
			else if(j==1){
				if(letrasRepetidas[i]>mayor[j] and i!=(top3[0]-'a')){//Admite la posibilidad de que varias letras tengan la misma cantidad de repeticiones y puedan entrar en el top 3
					mayor[j]=letrasRepetidas[i];
					top3[j]=i+'a';
				}
			}
			else {
				if(letrasRepetidas[i]>mayor[j] and i!=(top3[0]-'a') and i!=(top3[1]-'a')){//Admite la posibilidad de que varias letras tengan la misma cantidad de repeticiones y puedan entrar en el top 3
					mayor[j]=letrasRepetidas[i];
					top3[j]=i+'a';
				}
			}
		}
	}
	if(letra[0]==top3[0])puntajeFinal=30;//El puntaje empieza en 30 como puntaje perfecto, y va bajando segun la letra ingresada este en el top 3
	else if(letra[0]==top3[1])puntajeFinal=20;
	else if(letra[0]==top3[2])puntajeFinal=10;
	cout<<endl<<"Top 3 letra repetida: ";
	for(int i=0;i<3;i++) { //Muestra el top 3 para el usuario
		cout<<top3[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<"  -  Tu puntaje obtenido en elegir la letra repetida fue: "<<puntajeFinal<<endl<<endl;
	return puntajeFinal;
}

int calcularPuntajeCantVocales(string palabras[],char cantVocal[]){
	int puntajeFinal=0,iterador=0,acumVocales=0,largo,numeroReal=0;
	while(iterador<5){//Llena un arreglo contador de cuantas vocales hay entre las 5 palabras
		largo=palabras[iterador].length();//Establece hasta donde debe leer el for segun el largo de cada palabra
		for(int i=0;i<largo;i++) { 
			if(esVocal(palabras[iterador][i]))acumVocales++;//Busca ayudado de la funcion esVocal, cada vocal de las 5 palabras para aumentar el contador
		}
		iterador++;
	}
	int largoNumCantVocales=strlen(cantVocal),exponente=largoNumCantVocales-1;
	for(int i=0;i<largoNumCantVocales;i++) { //Convierte mi numero ingresado en una cadena de caracteres a un numero de tipo entero
		numeroReal+=((cantVocal[i]-'0')*(pot(10,exponente)));
		exponente--;
	}
	if(acumVocales==numeroReal)puntajeFinal=30;//Establece el puntaje final de acuerdo a que tan cerca estuvo de acertar(en rangos de 0, 5 y 8 )
	else if(acumVocales<numeroReal+5 and acumVocales>numeroReal-5)puntajeFinal=20;
	else if(acumVocales<numeroReal+8 and acumVocales>numeroReal-8)puntajeFinal=10;
	cout<<"Total de vocales: "<<acumVocales<<endl<<endl;
	cout<<"  -  Tu puntaje obtenido en la cantidad de vocales en total es: "<<puntajeFinal<<endl<<endl;
	return puntajeFinal;
}

void cargarCincoPalabras(string palabrasElegidas[], string const palabras[]){
	int valoresRandom[5],a=0,b=0,contador=0;
	bool repetido=true;
	for(int i=0;i<5;i++){
		valoresRandom[i]=rand()%100;
	}
	do{//para evitar palabras repetidas
		if(a!=b){
			if(valoresRandom[a]==valoresRandom[b]){
				valoresRandom[a]=rand()%100;
				repetido=true;
				contador=0;
			}
			else{
				contador++;
			}
		}if(contador==20){//condición de salida
			contador=0;
			repetido=false;
		}if(a==4){//repeticiones del bucle
			b++;
		}
		a++;
		a%=5;
		b%=5;
	} while(repetido);
	
	for(int i=0;i<5;i++){
		palabrasElegidas[i]=palabras[valoresRandom[i]];//Cargamos un arreglo de string con las 5 palabras aleatorias
	}
}	

int calcularPuntajePalabraLarga(string palabras[], char palabraEnviada[]){
	int masLarga=palabras[0].length(),subindice=0,largoPalabraEnviada=strlen(palabraEnviada),puntajeFinal=0;
	for(int i=1;i<5;i++) { //Busca entre las 5 palabras cual es la mas larga
		if((int)(palabras[i].length())>masLarga){
			masLarga=palabras[i].length();//Guarda el largo de la palabra en cuestion
			subindice=i;//Guarda su subindice
		}
	}
	for(int i=0;i<largoPalabraEnviada;i++) { //Se asegura que la palabra ingresada por usuario este totalmente en minuscula
		palabraEnviada[i]=tolower(palabraEnviada[i]);
	}
	if(largoPalabraEnviada==masLarga){//Establece el puntaje final, siendo el puntaje total 40 puntos, divididos por el largo de la palabra, solo si el usuario acierta en el largo podrá sumar
		int contadorIguales=0;
		float valorCadaLetra=(40.0/masLarga);//Establece el puntaje de cada letra acertada
		for(int i=0;i<masLarga;i++) { 
			if(palabras[subindice][i]==palabraEnviada[i]){
				puntajeFinal+=valorCadaLetra;
				contadorIguales++;
			}
		}
		if(contadorIguales==masLarga)puntajeFinal=40;//Si acerto perfectamente la palabra, le asigna el puntaje maximo
	}
	cout<<"La palabra mas larga fue: "<<palabras[subindice]<<endl<<endl;
	cout<<"  -  Tu puntaje obtenido en adivinar la palabra mas larga fue: "<<puntajeFinal<<endl<<endl;
	return puntajeFinal;
}

bool esVocal(char dig){//Devuelve true si el caracter a analizar es una vocal
	bool siEs=false;
	switch(dig){
	case 'a':siEs=true;break;
	case 'e':siEs=true;break;
	case 'i':siEs=true;break;
	case 'o':siEs=true;break;
	case 'u':siEs=true;break;
	}
	return siEs;
}
int pot(int base,int exp){//Funcion para calcular una potencia con enteros
	if(exp==0)return 1;
	if(exp==1)return base;
	return base*pot(base,exp-1);
}
