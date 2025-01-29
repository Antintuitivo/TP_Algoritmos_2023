#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include "func_aux.h"
#include <cstdio>

void menuPrincipal();
void menuAbecedarios();
void menuJuegos();
void ABCingles();
void ABCespaniol();
void ABCfrances();
void ABCitaliano();
void ABCportugues();

using namespace std;
char salir(){//Opcion de salir de la app
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Las usamos para cambiar el color de la consola en lineas especificas
	string consulta="Seguro que quieres salir de la app?(Y/N): ";
	int largoConsulta=50-(consulta.length()/2);//Centrar el mensaje en la consola
	char x[20],salida;
	int contador=0;
	do{
		if(contador==0) for(int i=0;i<10;i++)cout<<endl;//Solo si es la primera vez a ejecutarse y es para poner el mensaje en el centro de la consola
		for(int i=0;i<largoConsulta;i++) cout<<" ";
		cout<<consulta;
		gets(x);
		if(esUnDigito(x))x[0]=toupper(x[0]);//Admite ingresos tanto de mayus como de minus
		if((x[0]!='Y' and x[0]!='N') or !(esUnDigito(x))){
			system("cls");
			SetConsoleTextAttribute(hConsole, 4);//Cambia el color de la consola en una linea especifica
			for(int i=0;i<largoConsulta;i++) cout<<" ";
			for(int i=0;i<9;i++)cout<<endl;//Usados para centrar el texto
			for(int i=0;i<largoConsulta;i++) cout<<" ";
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
			contador++;//Establece que ya se ejecuto una vez, para evitar la primera linea del do
		}
	} while((x[0]!='Y' and x[0]!='N') or !(esUnDigito(x)));//Bucle hasta que se ingrese alguna de las opciones requeridas
	salida=x[0];
	if(x[0]=='Y'){//Cierra la app
		string saludo="Gracias por utilizarnos! Espero que vuelvas";
		int largoSaludo=50-(saludo.length()/2);
		for(int i=0;i<largoSaludo;i++)cout<<" ";
		cout<<saludo<<endl;
	}
	return salida;
}
	//Funcion para ver si solo se ingresa un digito como opcion de seleccion
bool esUnDigito(char cadena[]){
	bool verificado=true;
	if(strlen(cadena)>1)verificado=false;
	return verificado;
}
	
void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}  
	
bool esRepetido(char revisar[], char letra,int l,int y){//devuelve si la letra ya fue escrita
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool reply=false;
	
	for(int i=0;i<l;i++){
		if (revisar[i]==letra)reply=true;
	}
	
	if(reply){
		gotoxy(0,y);
		SetConsoleTextAttribute(hConsole, 4);
		cout<<" - Ya ingresaste esa letra - "<<endl;
		SetConsoleTextAttribute(hConsole, 11);
	}
	
	return reply;
}
void alertaDeError (char letra[], char letrasIngresadas[], int k,int y){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool repetido;
	do{//permite ingresar unicamente una letra
		cout<<"Ingrese una letra a adivinar: ";
		fflush(stdin);
		for(int i=0;i<(int)strlen(letra);i++) cout<<" ";
		for(int i=0;i<(int)strlen(letra);i++) cout<<'\b';
		gets(letra);
		if(esUnDigito(letra)){
			if(letra[0]==(-92) or letra[0]==(-91))letra[0]=(-92);
			else letra[0]=tolower(letra[0]);
		}
		if (!((isalpha(letra[0])) or (letra[0]==(-92))) or !(esUnDigito(letra)))
		{
			gotoxy(0,y);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<(char)173<<"Ese caracter no es una letra!"<<endl;//mensaje de error
			SetConsoleTextAttribute(hConsole, 11);
		}else{
			repetido=esRepetido(letrasIngresadas,letra[0],k,y);
		}
	}while(!((isalpha(letra[0])) or (letra[0]==(-92))) || repetido or !(esUnDigito(letra)));
}
void escribirPalabrasEspeciales (int palabra){
	switch(palabra){
	case 1: cout<<"Espa"<<(char)164<<"ol"; break;
	case 2: cout<<"Ingl"<<(char)130<<"s"; break;
	case 3: cout<<"Italiano"; break;
	case 4:cout<<"Portugu"<<(char)130<<"s"; break;
	case 5:cout<<"Franc"<<(char)130<<"s"; break;
	case 6:cout<<"X.- Volver al men"<<(char)163<<" principal"; break;
	//case 7:cout<<"opci"<<(char)162"n"; break;
	
	}
}
