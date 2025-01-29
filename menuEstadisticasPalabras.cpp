#include <iostream>
#include <windows.h>
#include "func_aux.h"
#include "ListasEnlazadas.h"
#include <iomanip>
using namespace std;

void titulos(string titulo){//Muestra el titulo
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
void tituloLargo(string titulo){//Muestra el titulo
	int largoTitulo=titulo.length();
	int centrarTitulo=80-(largoTitulo/2);
	cout<<endl;
	for(int i=0;i<centrarTitulo;i++) cout<<" ";
	cout<<titulo<<endl;
	for(int i=0;i<160;i++) cout<<"=";
	cout<<endl;
	cout<<endl;
	return;
}

void tituloFrecuenciaPal();

char menuEstadisticasPalabras() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	system("cls");//Limpia la consola
	tituloFrecuenciaPal();
	string opciones2_3[]={
		"1.- Ver la longitud promedio de las palabras del archivo.",
		"2.- Ver 5 palabras con una letra X inicial de acuerdo a su frecuencia de aparicion.",//palabrasLetraInicial
		"3.- Porcentaje de palabras que inician con vocal vs consonante.",//encontrarLetraLongitud
		"4.- Generar archivo de palabras que empiecen con X letra.",//en listasEnlazadas, función escribirArchivo(Lista l);
		"5.- Cantidad de palabras diferentes con caracter y longitud especificada",
		"X.- Volver al menu anterior."
	};
	for(int i=0;i<6;i++) cout<<opciones2_3[i]<<endl<<endl;//Muestra las opciones
	char eleccion[20],salida;
	do{//Pide y valida que se ingrese una de las opciones validas
		cout<<"Ingrese una opci"<<(char)162<<"n: ";
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if(!((eleccion[0]>='1' and eleccion[0]<='5') or eleccion[0]=='X') or !(esUnDigito(eleccion))){
			system("cls");
			cout<<endl;
			tituloFrecuenciaPal();
			for(int i=0;i<=5;i++) cout<<opciones2_3[i]<<endl<<endl;//Muestra las opciones
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(!((eleccion[0]>='1' and eleccion[0]<='5') or eleccion[0]=='X') or !(esUnDigito(eleccion)));
	salida=eleccion[0];	
	return salida;
}

bool menuLetraInicial(Lista l){//función 2
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	string palabras[5];
	char a[15];
	titulos("| Cinco palabras mas repetidas con X letra inicial |");
	do{
		fflush(stdin);
		cout<<"Ingrese una letra: ";
		gets(a);
		a[0]=toupper(a[0]);
		if (!(esUnDigito(a)) or !(isalpha(a[0]))){
			system("cls");
			titulos("| Cinco palabras mas repetidas con X letra inicial |");
			//vuelve a mostrar toda la funcion para volver a elegir la opcion
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	} while(!(esUnDigito(a)) or !(isalpha(a[0])));
	a[0]=tolower(a[0]);
	palabrasLetraInicial(l,palabras,a[0]);
	cout<<"Las palabras mas frecuentes son: "<<endl;
	for(int i=0;i<5;i++){
		cout<<i+1<<"- "<<palabras[i]<<endl;
	}
	char eleccion[15];
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		
		gets(eleccion);
		eleccion[0]=toupper(eleccion[0]);
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			titulos("| Cinco palabras mas repetidas con X letra inicial |");
			cout<<"Ingrese una letra: ";puts(a);
			cout<<"Las palabras mas frecuentes son: "<<endl;//vuelve a mostrar toda la funcion para volver a elegir la opcion
			for(int i=0;i<5;i++){
				cout<<i+1<<"- "<<palabras[i]<<endl;
			}
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}

bool menuPorcentajePalabras(Lista l){//función 3
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	titulos("Porcentaje de palabras que inician con vocal vs consonante.");
	porcentajePalabras(l);
	char eleccion[15];
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		
		gets(eleccion);
		eleccion[0]=toupper(eleccion[0]);
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			titulos("Porcentaje de palabras que inician con vocal vs consonante.");
			porcentajePalabras(l);
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}

bool menuPalabrasLongCharEspecif(Lista l){//función 5
	system("mode con: cols=160 lines=40");//Definimos el tamanio de la consola
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	tituloLargo("Cantidad de palabras diferentes con caracter y longitud especifica");
	cout<<"Tabla con frecuencia de aparicion segun letra inicial y largo: "<<endl;;
	int matriz[26][33];//Buscamos la palabra mas larga del archivo y determinamos que tiene 33 caracteres, por lo cual ese es nuestro TF
	crearMatrizFrecuencia(l,matriz);
	mostrarMatrizFrecuencia(matriz);
	char eleccion[15];
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<endl<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		
		gets(eleccion);
		eleccion[0]=toupper(eleccion[0]);
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			tituloLargo("Cantidad de palabras diferentes con caracter y longitud especifica");
			cout<<"Tabla con frecuencia de aparicion segun letra inicial y largo: "<<endl;;
			mostrarMatrizFrecuencia(matriz);
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<endl<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}
bool menuLongitudPromedio(Lista l){ //Funcion 1
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	titulos("Longitud promedio de las palabras del archivo.");
	float largo;
	largo=longitudPromedio(l);
	cout<<endl<<fixed<<setprecision(3);
	cout<<"La longitud promedio es: "<<largo<<endl<<endl;
	char eleccion[15];
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		
		gets(eleccion);
		eleccion[0]=toupper(eleccion[0]);
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			titulos("Longitud promedio de las palabras del archivo.");
			cout<<"La longitud promedio es: "<<largo<<endl<<endl;
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}
