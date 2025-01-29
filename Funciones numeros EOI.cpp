#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<windows.h>
#include <cstdio>
#include "numeros.h"
using namespace std;

typedef char palabra[9];

void tituloNumeros(){//Muestra el titulo
	string titulo="| Numeros en Otro Idioma |";
	int largoTitulo=titulo.length();
	int centrarTitulo=50-(largoTitulo/2);
	cout<<endl;
	for(int i=0;i<centrarTitulo;i++) cout<<" ";
	cout<<titulo<<endl;
	for(int i=0;i<100;i++) cout<<"=";
	cout<<endl;
	return;
}
void imprimirNum(int num, int aum){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int h=5, w=3;
	char disp[h][w]; //alto=5, ancho=3
	
	for(int i=0;i<h;i++)
	{
		for(int a=0;a<w;a++)//lleno la matriz de espacios vacios para no asignarlos dependiendo del numero
		{
			SetConsoleTextAttribute(hConsole, 0*16+0);
			disp[i][a]=' ';
		}
	}
	SetConsoleTextAttribute(hConsole, 0*16+7);
	//en adelante define el dibujo del numero
	
	if(num!=6&&num!=5)//posiciones:
	{
		disp[1][2]='|';//superior der
	}
	if(num!=2)
	{
		disp[3][2]='|';//inferior der
	}
	if (num!=1&&num!=2&&num!=3&&num!=7)
	{
		disp[1][0]='|';//superior izq
	}
	if (num==0||num==2||num==6||num==8)
	{
		disp[3][0]='|';//inferior izq
	}
	if (num!=4&&num!=1)
	{
		disp[0][1]='-';//superior
	}
	if (num!=0&&num!=1&&num!=7)
	{
		disp[2][1]='-';//central
	}
	if (num!=1&&num!=4&&num!=7)
	{
		disp[4][1]='-';//inferior
	}
	
	//impresion del numero
	barrasHorizontales(disp[0],aum);
	barrasVerticales(disp[1],aum);
	barrasHorizontales(disp[2],aum);
	barrasVerticales(disp[3],aum);
	barrasHorizontales(disp[4],aum);
	
	SetConsoleTextAttribute(hConsole, 0*16+11);
}

void barrasVerticales(char v[],int aumento){//imprime la linea de barras verticales con aumento
	
	for (int i=0;i<aumento;i++)
	{
		cout<<"    "<<v[0];
		
		for(int p=0;p<aumento;p++)
		{
			cout<<v[1];
		}
		
		cout<<v[2]<<endl;
	}
	
	return;
}
	
void barrasHorizontales(char v[],int aumento){//imprime la linea de barras horizontales con aumento
	cout<<"    "<<v[0];
	
	for (int i=0;i<aumento;i++)
	{
		cout<<v[1];
	}
	
	cout<<v[2]<<endl;
	
	return;
}
	
void imprimirPalabra(int num,int lang){//escribe el numero en su respectivo idioma
	
	palabra espanol[]={"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"};
	palabra ingles[]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	palabra italiano[]={"Zero", "Uno", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove"};
	palabra portugues[]={"Zero", "Um", "Dois", {'T','r',(char)136,'s'}, "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
	palabra frances[]={{'Z',(char)130,'r','o'}, "Un", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf"};
	
	cout<<"Forma escrita en ";
	switch (lang)
	{
	case 1:
		cout<<"espa"<<(char)164<<"ol: "<<espanol[num]<<endl;
		break;
		
	case 2:
		cout<<"ingl"<<(char)130<<"s: "<<ingles[num]<<endl;
		break;
		
	case 3:
		cout<<"italiano: "<<italiano[num]<<endl;
		break;
		
	case 4:
		cout<<"portugu"<<(char)130<<"s: "<<portugues[num]<<endl;
		break;
		
	case 5:
		cout<<"franc"<<(char)130<<"s: "<<frances[num]<<endl;
		break;
	}
	return;
}
