#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <ctime>
#include "ListasEnlazadas.h"
#include "menuEstadisticasPalabras.h"

using namespace std;

//Funciones

void bienvenida();
bool login();
char menuPrincipal();
char salir();
char numerosOtroIdioma();
void extraerPalabrasDeArchivo(string []);
char menuAbecedarios();
bool ABCespaniol();
bool ABCfrances();
bool ABCingles();
bool ABCitaliano();
bool ABCportugues();
char menuJuegos();
char numerosOtroIdioma();
char memoria(string []);
char ahorcado(string []);
char palabraCifrada(string []);
void pantallaCarga();
char menuProcesadorTexto();
bool contarCaracteres();
char menuEstadisticasPalabras();

//Funciones

int main(int argc, char *argv[]) {
	srand(time(NULL));//semilla para los juegos que usan la funcion rand()
	system("mode con: cols=100 lines=40");//Definimos el tamanio de la consola
	pantallaCarga();
	Lista l=abrirEstadisticasPalabras();
	system("cls");
	system("color 0B");//Definimos el color de fondo y de texto
	bienvenida(); //Ejecuta la pagina de inicio
	char eleccion;
	if(login()){//Llama a la funcion login, de validarse el usuario continua con el menu principal
		bool volver,repetirMenu,repetirMenu2;
		string palabras[100];
		extraerPalabrasDeArchivo(palabras);
		do{
			volver=false;
			eleccion=menuPrincipal();
			switch(eleccion){//Redirecciona en base a que fue lo que el usuario eligio
			case '1':{
				do{
					repetirMenu=false;
					eleccion=menuAbecedarios();
					switch(eleccion){//Redirecciona en base a que fue lo que el usuario eligio
					case '1':repetirMenu=ABCespaniol();break;
					case '2':repetirMenu=ABCingles();break;
					case '3':repetirMenu=ABCitaliano();break;
					case '4':repetirMenu=ABCportugues();break;
					case '5':repetirMenu=ABCfrances();break;
					case 'X':volver=true;break;
					}
				}while(repetirMenu);
			}break;
			case '2':{
				do{//Habilita volver de un juego otra vez al menu de juegos
					repetirMenu=false;
					bool volverAJugar;
					eleccion=menuJuegos();
					switch(eleccion){//Redirecciona en base a que fue lo que el usuario eligio
					case '1':{
						do{//Habilita volver a jugar el mismo juego sin volver al menu anterior
							volverAJugar=false;
							eleccion=ahorcado(palabras);
							if(eleccion=='1')volverAJugar=true;
							else repetirMenu=true;
						} while(volverAJugar);
					}break;
					case '2':{
						do{//Habilita volver a jugar el mismo juego sin volver al menu anterior
							volverAJugar=false;
							eleccion=palabraCifrada(palabras);
							if(eleccion=='1')volverAJugar=true;
							else repetirMenu=true;
						} while(volverAJugar);
					}break;
					case '3':{
						do{//Habilita volver a jugar el mismo juego sin volver al menu anterior
							volverAJugar=false;
							eleccion=numerosOtroIdioma();
							if(eleccion=='1')volverAJugar=true;
							else repetirMenu=true;
						} while(volverAJugar);
					}break;
					case '4':{
						do{//Habilita volver a jugar el mismo juego sin volver al menu anterior
							volverAJugar=false;
							eleccion=memoria(palabras);
							if(eleccion=='1')volverAJugar=true;
							else repetirMenu=true;
						} while(volverAJugar);
					}break;
					case 'X':volver=true;break;
					}
				}while(repetirMenu);
			}break;
			case '3':{
				do{
					repetirMenu=false;
					eleccion=menuProcesadorTexto();
					switch(eleccion){
					case '1':repetirMenu=contarCaracteres();break;
					case '2':{
						do{
							system("mode con: cols=100 lines=40");//Definimos el tamanio de la consola
							repetirMenu2=false;
							repetirMenu=false;
							eleccion=menuEstadisticasPalabras();
							switch(eleccion){
							case '1': repetirMenu2=menuLongitudPromedio(l); break;
							case '2': repetirMenu2=menuLetraInicial(l); break;
							case '3': repetirMenu2=menuPorcentajePalabras(l); break;
							case '4': repetirMenu2=escribirArchvo(l); break;
							case '5': repetirMenu2=menuPalabrasLongCharEspecif(l); break;
							case 'X': repetirMenu=true; break;
							}
						}while(repetirMenu2);
					}break;
					case 'X':volver=true;break;
					}
				}while(repetirMenu);
			}break;
			case 'X':{
				eleccion=salir();
				if(eleccion=='N')volver=true;
			}break;
			}
		} while(volver);
	}
	return 0;
}
