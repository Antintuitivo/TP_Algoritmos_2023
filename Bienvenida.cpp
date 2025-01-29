#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include "func_aux.h"
using namespace std;

void bienvenida(){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int j=0;j<2;j++) { //Dibuja dos lineas superiores para darle un marco al logo
		for(int i=0;i<100;i++)cout<<"-";
		cout<<endl;
	}
	cout<<endl;
	string logo[8]= {
		{"     ..     .....      ......     "},
		{"     ##    .#####.    .######.    "},
		{"     ##    ##    #    ##    ##    "},
		{"     ##    ##    #    ##    ##    "},
		{"     ##    ######'    ########    "},
		{"     ##    ##         ##    ##    "},
		{"     ##    ##         ##    ##    "},
		{"     ##    ##         ##    ##    "}};
	string name={"Idiomas Para Aprender"};
	string cerveza[]={
		{"  o  o   o   o   o  o  "},
		{"   o  o  o  o  o  o  o "},
		{"  o  o  o  o  o  o  o  "},
		{"  OOOOOOOOOOOOOOOOOOOO "},
		{" |OOOOOOOOOOOOOOOOOOOO|"},
		{" |OOOOOOOOOOOOOOOOOOOO|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |88888888888888888888|"},
		{" |____________________|"}};
	int h=0;
	int x=(logo[0].length()+cerveza[0].length());
	x/=2;x-=50;
	if(x<0)x*=(-1);
	int f=logo[0].length()+2;//calculos utilizados para centrar el logo
	int largoCerveza=cerveza[0].length();
		for(int i=0;i<17;i++) {//Muestra el logo centrado en la consola, y con un recuadro especifico
			for(int i=0;i<x;i++) cout<<" ";
			for(int j=0;j<largoCerveza;j++) { 
				if(cerveza[i][j]=='O'){
					SetConsoleTextAttribute(hConsole, (7*16+7));
					cout<<cerveza[i][j];
					SetConsoleTextAttribute(hConsole, (0*16+11));
				}
				else if(cerveza[i][j]=='8'){
					SetConsoleTextAttribute(hConsole, (6*16+6));
					cout<<cerveza[i][j];
					SetConsoleTextAttribute(hConsole, (0*16+11));
				}
				else if(cerveza[i][j]=='|' or cerveza[i][j]=='_'){
					SetConsoleTextAttribute(hConsole, (8*16+8));
					cout<<cerveza[i][j];
					SetConsoleTextAttribute(hConsole, (0*16+11));
				}
				else if(cerveza[i][j]=='o'){
					SetConsoleTextAttribute(hConsole, (0*16+7));
					cout<<cerveza[i][j];
					SetConsoleTextAttribute(hConsole, (0*16+11));
				}
				else cout<<cerveza[i][j];
			}
			if(h>3 and h<13){
				if(h==4){
					for(int i=0;i<5;i++) cout<<" ";
					for(int i=0;i<f;i++) cout<<"";
				}
				else{
					for(int i=0;i<5;i++) cout<<" ";
					cout<<"";
					cout<<logo[h-5]<<"";
				}
			}
			if(h==13){
				for(int i=0;i<5;i++) cout<<" ";
				for(int i=0;i<f;i++) cout<<"";
			}
			h++;
			cout<<endl;
		}
		cout<<endl<<endl;
	gotoxy(57,19);
	SetConsoleTextAttribute(hConsole, (7));
	cout<<name<<endl;
	SetConsoleTextAttribute(hConsole, (0*16+11));
	gotoxy(0,22);
	for(int j=0;j<2;j++) { 
		for(int i=0;i<100;i++)cout<<"-";
		cout<<endl;
	}
	cout<<endl;
	string integrantes[4]={
		{"by"},
	{"Guillermina Belletti -- guillerminabelletti@gmail.com -- Comision E"},
		{"Luis Meister -- luis.meister@hotmail.com -- Comision E"}};
	int in;
	for(int i=0;i<3;i++) { //Muestra los datos de cada integrante del grupo, centrado
		in=integrantes[i].length();
		in/=2;in-=50;in*=(-1);
		for(int j=0;j<in;j++) cout<<" ";
		cout<<integrantes[i]<<endl;
	}
	for(int i=0;i<22;i++)cout<<" ";
	cout<<"Tom"<<(char)160<<"s Rold"<<(char)160<<"n  -- tomasroldan.work@gmail.com -- Comision E"<<endl;
	cout<<endl;
	for(int i=0;i<100;i++)cout<<"-";
	cout<<endl;
	string pasar="Presione Enter para continuar";
	x=pasar.length();
	x/=2;x-=50;x*=(-1);
	for(int i=0;i<x;i++) cout<<" ";
	cout<<pasar;
	int puntos=0;
	bool band=true;
	while(band){//Muestra 3 puntos suspensivos "animados" junto al string pasar mientras se espera que se presione enter
		cout<<".";
		Sleep(500);
		puntos++;
		if(puntos==3){//Borra los 3 puntos suspensivos ya escritos para volver a escribirlos y dar sensacion de animacion
			for(int i=0;i<3;i++)cout<<'\b';//Vuelve 3 posiciones para atras en lo escrito en la consola
			for(int i=0;i<3;i++)cout<<' ';
			for(int i=0;i<3;i++)cout<<'\b';
			puntos=0;
		}
		Sleep(500);
		if (_kbhit()) {//Detecta el enter y sale del while
			char key = _getch();
			if (key==13) {
				band=false;
				cout<<endl;
			}
		}
	}
	return;
}
	
