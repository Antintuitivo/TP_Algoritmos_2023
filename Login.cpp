#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "func_aux.h"
#include <ctime>
using namespace std;

struct Fecha{
	int tm_mday;
	int tm_mon;
	int tm_year;
};
struct Persona{
	char nombre[20], apellido[20], legajo[6], contra[6];
	char sexo, rol;
	char date[11];
};
bool ingresoCorrecto(const char x[]);
void leerContrasena(char password[], int tam);
void actualizarFechaDeUltimaVez(int pos, bool & valido);
void TomarFecha(char nuevaFecha[]);
	//Funciones

bool login(){//Devuelve la validacion del ingreso
	bool valido=true;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Usamos para cambiar el color de la consola en alguna linea especifica
	system("cls");
	char legajo[100];
	char contra[100];
	int pos=-1;//posicion del usuario
	Persona usuario;
	ifstream f;
	fflush(stdin);
	f.open("Usuarios.bin");
	if(f.fail()){
		system("cls");
		for(int i=0;i<18;i++) cout<<endl;
		for(int i=0;i<30;i++) cout<<" ";
		SetConsoleTextAttribute(hConsole, 4);
		cout<<"ERROR AL ABRIR ARCHIVO DE USUARIOS"<<endl;
		for(int i=0;i<15;i++) cout<<endl;
		SetConsoleTextAttribute(hConsole, 11);
		Sleep(3000);
		valido=false;//Si no se puede abrir el archivo finaliza el programa
	}else{
		bool existe=false;
		
	do{
		cout<<"Ingrese su id de usuario: ";
		gets(legajo);
		//si ingresa ENTER o un legajo incorrecto se imprime el mensaje
		if(legajo[0]==0 or !(ingresoCorrecto(legajo)) or (ingresoCorrecto(legajo) and (legajo[0]<'1' or legajo[0]>'8'))){
			system("cls");
			SetConsoleTextAttribute(hConsole, 4);//Muestra mensaje de error en rojo si el ingreso es invalido
			cout<<"LEGAJO INCORRECTO! El legajo es incorrecto"<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}else{
			do{
				f.read((char*)(&usuario), sizeof(usuario));
				if(!strcmp(usuario.legajo,legajo))//strcmp() devuelve 0 si son = y un numero mayor o menor si son diferentes
					existe=true;
				pos++;//va contando el numero del bloque del usuario;
			} while(!existe and !f.eof());
			
			if(!existe){
				system("cls");
				SetConsoleTextAttribute(hConsole, 4);//Muestra mensaje de error en rojo si el ingreso es invalido
				cout<<"LEGAJO INCORRECTO! El legajo no existe"<<endl;
				SetConsoleTextAttribute(hConsole, 11);
			}
		}
	}while(legajo[0]==0 or !(ingresoCorrecto(legajo)) or (ingresoCorrecto(legajo) and (legajo[0]<'1' or legajo[0]>'8')) or !existe);
	int intentos=0, contador=0;
	bool acceso;
	
	do{//Pide el ingreso de contrasenia hasta que sea valido o hasta que se alcancen los 3 intentos incorrectos
		if(contador==0){
			system("cls");
			cout<<"Ingrese su id de usuario: ";
			puts(legajo);
		}
		cout<<"Ingrese su contrase"<<(char)164<<"a: ";
		leerContrasena(contra,100);
		acceso=(!strcmp(usuario.contra, contra));//devuelve cero si las cadenas son iguales
		intentos++;
		if(intentos==3 and !acceso){
			system("cls");
			for(int i=0;i<15;i++) cout<<endl;
			for(int i=0;i<20;i++) cout<<" ";
			cout<<"Exediste el limite de intentos permitidos, vuelve mas tarde."<<endl;
			for(int i=0;i<15;i++) cout<<endl;
			Sleep(2000);
			valido=false;//Si alcanza los 3 intentos incorrectos, no valida el ingreso a la app
		}
		else if(!acceso){
			system("cls");
			cout<<"Ingrese su id de usuario: ";puts(legajo);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Contrase"<<(char)164<<"a incorrecta, intente nuevamente."<<endl;
			SetConsoleTextAttribute(hConsole, 11);
			contador++;
		}
	}while((!acceso) and intentos<3);
	}
	f.close();
	
	if(valido){
		system("cls");
		gotoxy(20,17); for(int i=0;i<60;i++) cout<<"-";
		gotoxy(20,18);cout<<"|      ";
		if(usuario.sexo=='F')cout<<"Bienvenida  ";
		else cout<<"Bienvenido  ";
		cout<<usuario.nombre<<" !";
		gotoxy(79,18);cout<<"|";
		gotoxy(20,19); cout<<"|";for(int i=0;i<58;i++)cout<<" ";cout<<"|";
		gotoxy(20,20);cout<<"|      Ultimo acceso a la aplicacion: "<<usuario.date<<" :)        |";
		gotoxy(20,21); for(int i=0;i<60;i++) cout<<"-";
		Sleep(4000);
	actualizarFechaDeUltimaVez(pos, valido);
	}
	
	return valido;
}
void leerContrasena(char password[], int tam){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char caracter;
	int i = 0;
	bool terminar=true;
	SetConsoleTextAttribute(hConsole, 15);//9,15,240
	/*lee caracteres individuales y los guarda en una cadena hasta que el usuario presione enter
	caracteres especiales en ascii:
	13---ENTER
	8---borrar/backspace*/
	do{
		caracter=getch();//oculta el caracter ingresado	
		if(i<tam){
			if(caracter==13){
				terminar=false;
			}else{
				if(caracter==8 and i>0){//preguntar como retroceder una posicion en la pantalla
					cout<<"\b \b";
					i--;
				}else if(i<tam and caracter>31 and caracter!=127){//condicion para escribir un caracter (menos caracteres que el tamaño físico y no debe se un caracter de control)
					password[i]=caracter;
					cout<<"*";
					i++;
				}
			}
		}
	}while(terminar);
	password[i]='\0';
	SetConsoleTextAttribute(hConsole, 11);
}
bool ingresoCorrecto(const char x[]){//valida que la cadena ingresada sea una de 5 números
	bool aprobado=true;
	if(strlen(x)!=5)aprobado=false;
	else {
		for(int i=0;i<5;i++) { 
			if(!(isdigit(x[i])))aprobado=false;
		}
	}
	return aprobado;
}
	
void actualizarFechaDeUltimaVez(int pos, bool & valido){
	char nuevaFecha[11];
	TomarFecha(nuevaFecha);
	
	fstream file;
	file.open("Usuarios.bin",ios::binary|ios::in|ios::out);
	if(file.fail()) {
		cout<<"Error al abrir el archivo binario."<<endl;
	}else{
		pos=sizeof(Persona)*pos;
		file.seekg(pos, ios::beg);
		// Leer la información existente de la persona
		Persona usuario;
		file.read((char*)(&usuario), sizeof(Persona));
		strcpy(usuario.date, nuevaFecha);
		file.seekp(pos, ios::beg);
		file.write((char*)(&usuario), sizeof(Persona));
		file.close();
	}
}
void TomarFecha(char nuevaFecha[]){
	time_t ahora;
	struct tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	fecha->tm_mon++;
	fecha->tm_year+=1900;
	
	nuevaFecha[0]='0'+(fecha->tm_mday/10);
	nuevaFecha[1]='0'+(fecha->tm_mday%10);
	nuevaFecha[2]='/';
	nuevaFecha[3]='0'+(fecha->tm_mon/10);
	nuevaFecha[4]='0'+(fecha->tm_mon%10);
	nuevaFecha[5]='/';
	nuevaFecha[6]='0'+(fecha->tm_year/1000);
	nuevaFecha[7]='0'+((fecha->tm_year/100)%10);
	nuevaFecha[8]='0'+((fecha->tm_year/10)%10);
	nuevaFecha[9]='0'+(fecha->tm_year%10);
	nuevaFecha[10]='\0';
}
