#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<windows.h>
#include <cstdio>
#include "numeros.h"
#include "func_aux.h"
using namespace std;

void salir(char opcion='x');
void menuJuegos();
void escribirPalabrasEspeciales (int);

//Funciones

char numerosOtroIdioma(){
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int idioma, aumento=1, numero, chs,contadorIteracion=0;;
   // bool repetir;
    char numeroElegido[20],rango[20],idiomaElegido[10];
	//1=espaniol,2=ingles,3=italiano,4=portuguess,5=frances
	string elegirNumero="Ingrese un numero de 0 a 9: ";
	string elegirRango="Ingrese un aumento de 1 a 4 con el que mostrar el numero: ";
		do{
			if(contadorIteracion==0)tituloNumeros();
			cout<<elegirNumero;
			gets(numeroElegido);
			chs=strlen(numeroElegido);
			
            if(!isdigit(numeroElegido[0]) || chs!=1){//se debe ingresar un unico caracter
				system("cls");
				tituloNumeros();
				SetConsoleTextAttribute(hConsole, 4);
                cout<<"Ese no es un numero de un digito..."<<endl;  
				SetConsoleTextAttribute(hConsole, 11);
				contadorIteracion++;
            }
			else
            {
                numero=numeroElegido[0]-'0';//el caracter debe ser un numero
				
				if(numero>9||numero<0)
				{
					system("cls");
					tituloNumeros();
					SetConsoleTextAttribute(hConsole, 4);
					cout<<"El caracter ingresado no es un n"<<(char)163<<"mero!"<<endl;
					SetConsoleTextAttribute(hConsole, 11);
					contadorIteracion++;
				}
            }
		} while ((numero>9 || numero<0) || (!isdigit(numeroElegido[0]) || chs!=1));
		contadorIteracion=0;
		do{
			if(contadorIteracion==0){
				system("cls");
				tituloNumeros();
				cout<<elegirNumero;puts(numeroElegido);//imprime el numero elegido
			}
			cout<<elegirRango;//ingresa el aumento del numero 
			gets(rango);
			chs=strlen(rango);
			
            if(!isdigit(rango[0]) || chs!=1)//no se ingreso un caracter de un digito
			{
				system("cls");
				tituloNumeros();
				cout<<elegirNumero;puts(numeroElegido);
				SetConsoleTextAttribute(hConsole, 4);
                cout<<"Ese no es un numero de un digito..."<<endl;
				SetConsoleTextAttribute(hConsole, 11);
				contadorIteracion++;
            }
			else
            {
                aumento=rango[0]-'0';
				
				if(aumento>4 || aumento<1){//el caracter no esta en el rango permitido
					system("cls");
					tituloNumeros();
					cout<<elegirNumero;puts(numeroElegido);
					SetConsoleTextAttribute(hConsole, 4);
					cout<<" - Ese numero no esta en el rango - "<<endl;
					SetConsoleTextAttribute(hConsole, 11);
					contadorIteracion++;
			
				}
			}
			
		} while ((aumento>4 || aumento<1) || (!isdigit(rango[0]) || chs!=1));
		contadorIteracion=0;
		do
		{
			if(contadorIteracion==0){//imprime el numero elegido y el aumento
				system("cls");
				tituloNumeros();
				cout<<elegirNumero;puts(numeroElegido);
				cout<<elegirRango;puts(rango);
			}
			cout<<"En qu"<<(char)130<<" idioma desea mostrarlo?"<<endl;//pide el idioma y da las opciones
			for(int i=1;i<6;i++){
				cout<<i<<"-.";
				escribirPalabrasEspeciales(i);
				cout<<endl;
			}
			cout<<"Opci"<<(char)162<<"n: ";
			gets(idiomaElegido);
			chs=strlen(idiomaElegido);
			
            if(!isdigit(idiomaElegido[0]) || chs!=1){//valida la opcion
				system("cls");
				tituloNumeros();
				cout<<elegirNumero;puts(numeroElegido);
				cout<<elegirRango;puts(rango);
				SetConsoleTextAttribute(hConsole, 4);
                cout<<"Esa no es una de las opciones..."<<endl;
				SetConsoleTextAttribute(hConsole, 11);
				contadorIteracion++;
            }
			else
            {
                idioma=idiomaElegido[0]-'0';
				
				if(idioma>5||idioma<1){
					system("cls");
					tituloNumeros();
					cout<<elegirNumero;puts(numeroElegido);
					cout<<elegirRango;puts(rango);
					SetConsoleTextAttribute(hConsole, 4);
					cout<<" - Esa no es una de las opciones - "<<endl;
					SetConsoleTextAttribute(hConsole, 11);
					contadorIteracion++;
				}
			}
			
		} while ((idioma>5 || idioma<1) || (!isdigit(idiomaElegido[0]) || chs!=1));
		system("cls");
		tituloNumeros();//impreime todo lo anterior otra vez
		cout<<elegirNumero;puts(numeroElegido);
		cout<<elegirRango;puts(rango);
		cout<<"En qu"<<(char)130<<" idioma desea mostrarlo?"<<endl;
		for(int i=1;i<6;i++){
			cout<<i<<"-.";
			escribirPalabrasEspeciales(i);
			cout<<endl;
		}
		cout<<"Opci"<<(char)162<<"n: ";
		puts(idiomaElegido);
		imprimirPalabra(numero,idioma);
		imprimirNum(numero,aumento);
		
		char eleccion[200],salida;
		do{//muestra las opciones de salir o volver a empezar
			cout<<endl;
			cout<<"Desea volver al comienzo o al men"<<(char)163<<" anterior? (1/X): ";
			fflush(stdin);
			for(int i=0;i<(int)strlen(eleccion);i++) cout<<" ";
			for(int i=0;i<(int)strlen(eleccion);i++) cout<<'\b';
			gets(eleccion);
			if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
			if((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion))){//en caso de que el caracter ingresado sea inváido
				system("cls");
				tituloNumeros();
				cout<<elegirNumero;puts(numeroElegido);
				cout<<elegirRango;puts(rango);
				cout<<"En qu"<<(char)130<<" idioma desea mostrarlo?"<<endl;
				for(int i=1;i<6;i++){
					cout<<i<<"-.";
					escribirPalabrasEspeciales(i);
					cout<<endl;
				}
				cout<<"Opci"<<(char)162<<"n: ";
				puts(idiomaElegido);
				imprimirPalabra(numero,idioma);
				imprimirNum(numero,aumento);
				gotoxy(0,22);
				SetConsoleTextAttribute(hConsole, 4);
				cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
				SetConsoleTextAttribute(hConsole, 11);
			}
		}while((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion)));
		salida=eleccion[0];
    return salida;
}	

