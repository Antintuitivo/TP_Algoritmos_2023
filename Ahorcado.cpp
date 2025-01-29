#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include "ahorcado.h"
#include "func_aux.h"
#include <cstdio>
using namespace std;

void menuPrincipal();
void salir(char opcion='x');
void menuAbecedarios();
void menuJuegos();

//Funciones

//int main(){ahorcado();return 0;}
char ahorcado(string palabras[]){
	int selectorPalabra=rand()%100;
	string palabraElegida=palabras[selectorPalabra];
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Las usamos para cambiar el color de la consola en una linea especifica
	int errores=0, puntos=100, k=0,tl;	
	const int a=6,b=7;
	char muneco[a][b]{
		{' ','_','_','_',' ',' ',' '},
	{'|',' ',' ',' ',' ',' ',' '},
		{'|',' ',' ',' ',' ',' ',' '},
	{'|',' ',' ',' ',' ',' ',' '},
		{'|',' ',' ',' ',' ',' ',' '},
	{'-','-','-','-','-','-','-'}};
	bool descubierto=false,mostrar[20];
	char adivina[20];
	tl=palabraElegida.size();
	for(int q=0;q<tl;q++){
		mostrar[q]=false;
	}		
	
	char escritas[30];
	for(int q=0;q<tl;q++){
		escritas[q]=' ';
	}
	while(errores<6 && !descubierto){
		tituloAhorcado();
		mostrarLetrasIngresadas(escritas,k);
		for(int i=0;i<a;i++)
		{//dibuja el munieco
			cout<<"             ";
			for(int q=0;q<b;q++){
				cout<<muneco[i][q];
			}
			cout<<endl;
		}
		
		cout<<"             ";
		for(int i=0;i<tl;i++){//muestra la palabra o espacios de letra segun si estan descubiertos o no
			if(mostrar[i]){
				cout<<palabraElegida[i]<<" ";
			}else{
				cout<<"_ ";
			}
		}
		cout<<endl<<endl;
		alertaDeError(adivina,escritas, k,14);
		
		int busqueda=palabraElegida.find(adivina[0]);
		if (busqueda==(-1)){
			//si la letra no está en la palabra, aumentan los errores y se dibuja el muñeco
			errores++;
			switch(errores){
			case 1:
				muneco[1][3]='o';//cabeza
				puntos-=10;
				break;
			case 2:
				muneco[2][3]='I';//cuerpo
				puntos-=10;
				break;
			case 3:
				muneco[2][2]='/';//brazo izquierdo
				puntos-=10;
				break;
			case 4:
				muneco[2][4]='\\';//brazo derecho
				puntos-=10;
				break;
			case 5:
				muneco[3][2]='/';//pierna izquierda
				puntos-=10;
				break;
			case 6:
				muneco[3][4]='\\';//pierna derecha
				puntos=0;
				break;
			}
		}else{
			for(int i=0;i<tl;i++){//revela las letras adivinadas de la palabra
				if(adivina[0]==palabraElegida[i])mostrar[i]=true;
			}
		}
		escritas[k++]=adivina[0];//almacena las letras escritas
		descubierto=descubrir(mostrar,tl);
		system("cls");
	}//fin del programa
	tituloAhorcado();
	mostrarLetrasIngresadas(escritas,k);
	for(int i=0;i<a;i++){//dibuja el munieco
		cout<<"             ";
		for(int q=0;q<b;q++)cout<<muneco[i][q];
		cout<<endl;
	}
	
	cout<<"             ";
	
	for(int i=0;i<tl;i++)cout<<palabraElegida[i]<<" ";//muestra la palabra
	if (errores==6){
		cout<<endl<<"Perdiste!"<<endl;
	}
	else if(descubierto)cout<<endl<<"Ganaste!"<<endl;
	cout<<"Tus puntos fueron: "<<puntos<<endl;
	char eleccion[200],salida;
	do{
		cout<<endl;
		cout<<"Desea volver a jugar o volver al menu anterior? (1/X): ";
		fflush(stdin);
		for(int i=0;i<(int)strlen(eleccion);i++) cout<<" ";
		for(int i=0;i<(int)strlen(eleccion);i++) cout<<'\b';
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion))){
			gotoxy(0,16);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. ";
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while((eleccion[0]!='1' and eleccion[0]!='X') or !(esUnDigito(eleccion)));
	salida=eleccion[0];
	return salida;//devuelve los puntos para sumar al puntaje del jugador
}

