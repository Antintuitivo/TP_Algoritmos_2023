#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#define TAM 100
#include "func_aux.h"
using namespace std;

void mostrarDibujo (int filas, int columnas, int centrar, char dibujo[][TAM]);
void matrizBarras(char barra[TAM][TAM], int columnas, int filas);
void agregarBarra(int filBarras,int colBarras,char barra[][TAM],char cargas[3][3],int & pos);
void pantallaCarga() {
	system("color B0");
	char logoUTN[TAM][TAM]={
	{" ########%:       -########*        *########-"},
	{" =#########       -########*       =######### "},
	{"  #########*      -########*      =#########- "},
	{"  :##########-    -########*    :*#########+  "},
	{"  :##########-    -########*    :##########+  "},
	{"    +###########. -########* .############:   "},
	{"      :*###############################=      "},
	{"        :+##########################*-        "},
	{"          :+###################%*-            "},
	{".%###########################################+"},
	{".%###########################################+"},
	{".%###########################################+"},
	{".%###########################################+"},
	{"           :=*%##################+-           "},
	{"        .=##########################*-        "},
	{"      .+###############################-      "},
	{"     =###########.##########.+##########*.    "},
	{"   .*##########*=:-########*.-+###########=   "},
	{"  .##########=.   -########*    -##########=  "},
	{"  ##########.     -########*      +########%: "},
	{" =#########.      -########*       +######### "},
	{" ########%:       -########*        *########:"},
	};
	int filArania=22, colArania=46, centrarLOGO=((colArania/2)-50)*(-1);
	cout<<endl<<endl<<endl;
	mostrarDibujo(filArania, colArania,centrarLOGO, logoUTN);
	
	char utn[TAM][TAM]={
	{" @@*  *@@ @@@@@@@ @@@+ +@@ "},
	{" @@*  *@@   @@%   @@#@\\#@@ "},
	{" %@%-.*@@   @@%   @@ \\@@@@ "},
	{"  *####*    @#+   #@  \\@@@ "},
	};
	int filUTN=4, colUTN=27, centrarUTN=((colUTN/2)-50)*(-1);
	cout<<endl<<endl;
	mostrarDibujo (filUTN, colUTN, centrarUTN, utn);
	Sleep(1000);
	system("color 0B");
}
void mostrarDibujo (int filas, int columnas, int centrar, char dibujo[][TAM]){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int i=0;i<filas;i++){
		for(int k=0;k<centrar;k++){
			cout<<" ";
		}
		
		for(int j=0;j<columnas;j++){
		SetConsoleTextAttribute(hConsole, 240);//11 celeste
			cout<<dibujo[i][j];
		}
		SetConsoleTextAttribute(hConsole, 176);
		cout<<endl;
	}
}
