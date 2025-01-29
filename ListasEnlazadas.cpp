#include <iostream>
#include "TDAlibro.h"
#include <cctype>
#include <cstring>
#include <windows.h>
#include "ListasEnlazadas.h"

#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void titulos(string);
bool esUnDigito(char []);
void guardarLista(Lista l);

void intercambiar(ptrNodo primero,ptrNodo segundo){
	int aux;
	aux=primero->rep;
	primero->rep=segundo->rep;
	segundo->rep=aux;
	char auxP[30];
	strcpy(auxP,primero->palabra);
	strcpy(primero->palabra,segundo->palabra);
	strcpy(segundo->palabra,auxP);
	return;
}
	
void ordenarLista(Lista ptrM){
	ptrNodo aux, aux2;
	aux=ptrM;
	while(aux!=NULL){
		aux2=ptrM;
		while(aux2->sig!=NULL){
			if((aux2->rep)<(aux2->sig->rep)){
				intercambiar(aux2,aux2->sig);
			}
			else if(((aux2->rep)==(aux2->sig->rep)) and ((strlen(aux2->palabra))<(strlen(aux2->sig->palabra)))){
				intercambiar(aux2,aux2->sig);
			}
			else if(((aux2->rep)==(aux2->sig->rep)) and ((strlen(aux2->palabra))==(strlen(aux2->sig->palabra))) and ((aux2->palabra[0])>(aux2->sig->palabra[0]))){
				intercambiar(aux2,aux2->sig);
			}
			aux2=aux2->sig;
		}
		aux=aux->sig;
	}
}

void palabraAMinuscula(char pal[]){
	int f=strlen(pal);
	for(int i=0;i<f;i++){
		if(isalpha(pal[i]))
			pal[i]=tolower(pal[i]);
	}
}

Lista crearLista(char pal[]){
	Lista l;
	l=new Nodo;
	strcpy(l->palabra, pal);
	l->rep=1;
	l->sig=NULL;
	return l;
}

bool aniadirNodo(char pal[], Lista l){
	ptrNodo	aux, nuevo;
	aux = l;
	bool b;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	nuevo = new Nodo;
	if(nuevo!=NULL){
		aux->sig= nuevo;
		aux=nuevo;
		
		aux->sig=NULL;
		strcpy(aux->palabra, pal);
		aux->rep=1;
		
		b=true;
	}else{
		b=false;//no hay suficiente espacio para crear un nuevo nodo
	}
	return b;
}

bool encontrarPalabra(Lista l, ptrNodo &ptr, char pal[]){
	bool encontrado=false;
	ptrNodo aux=l;
	while(!encontrado && aux->sig!=NULL){
		encontrado=(strcmp(aux->palabra,pal)==0);
		if(!encontrado)aux=aux->sig;
	}
	if(encontrado){
		ptr=aux;
	}
	return encontrado;
}

float longitudPromedio(Lista l){
	long long total=0, cant=0;
	float promedio=0;
	ptrNodo ptr=l;
	if(ptr->sig!=NULL){
		do{
			total+=((strlen(ptr->palabra))*(ptr->rep));
			cant+=ptr->rep;
			ptr=ptr->sig;
		}while(ptr->sig!=NULL);
		promedio=(float)total/cant;
	}
	return promedio;
}

void porcentajePalabras(Lista l){
	float voc,cons;
	long long total=0.0, cant=0.0;
	ptrNodo ptr=l;
	if(ptr->sig!=NULL){
		do{
			if(ptr->palabra[0]=='a'||ptr->palabra[0]=='e'||ptr->palabra[0]=='i'||ptr->palabra[0]=='o'||ptr->palabra[0]=='u'){
				cant+= ptr->rep;
			}
			total+=ptr->rep;
			ptr=ptr->sig;
		}while(ptr->sig!=NULL);
		voc=((float)cant/total)*100;
		cons=100-voc;
		cout<<fixed<<setprecision(2);
		cout<<"Porcentaje de palabras que comienzan en vocal: "<<voc<<"%"<<endl<<"Porcentaje de palabras que comienzan con consonante: "<<cons<<"%"<<endl;
	}
}

long long encontrarLetraLongitud(Lista l, char c, int n){//cuenta la cantidad de palabras distintas de esa longitud que comiencen por esa letra
	c=tolower(c);
	ptrNodo aux=l;
	long long cant=0;
	while(aux->sig!=NULL){
		if((int)strlen(aux->palabra)==n && aux->palabra[0]==c){
			cant++;
		}
		aux=aux->sig;
	}
	return cant;
}

void crearMatrizFrecuencia(Lista l,int matriz[26][33]){
	ptrNodo aux=l;
	int largo,primIndice,p;
	for(int i=0;i<26;i++) { 
		for(int j=0;j<33;j++) { 
			matriz[i][j]=0;
		}
	}
	while(aux!=NULL){
		p=0;
		while(!isalpha(aux->palabra[p])) p++;
		largo=((int)strlen(aux->palabra));
		primIndice=(aux->palabra[p])-'a';
		matriz[primIndice][largo]+=aux->rep;
		aux=aux->sig;
	}
	return;
}

void mostrarMatrizFrecuencia(int matriz[26][33]){
	cout<<"Inicial y frecuencias de aparicion de 1 a 30"<<endl;
	cout<<endl;
	for(int i=0;i<(((30*5)/2)-((int)strlen("Cantidad de caracteres")/2));i++) cout<<" ";
	cout<<"Cantidad de caracteres"<<endl;
	for(int i=0;i<30;i++) { 
		if(i==0)cout<<"     |";
		if(i+1>9)cout<<" "<<i+1<<" |";
		else cout<<"  "<<i+1<<" |";
	}
	cout<<endl;
	for(int i=0;i<30*5+6;i++) cout<<"=";
	cout<<endl;
	for(int i=0;i<26;i++) { 
		cout<<" - "<<(char)('a'+i)<<" |";
		for(int j=0;j<30;j++) { 
			if(matriz[i][j]>999)cout<<matriz[i][j]<<"|";
			else if(matriz[i][j]>99)cout<<matriz[i][j]<<" |";
			else if(matriz[i][j]>9)cout<<matriz[i][j]<<"  |";
			else cout<<matriz[i][j]<<"   |";
			
		}
		cout<<endl;
	}
	return;
}
	
bool escribirArchvo(Lista l){//función 4
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Lo usamos para cambiar los colores de la consola en una linea especifica
	ptrNodo aux;
	Libro escribir=crearLibro();
	char a[15];
	titulos("Generar archivo de palabras que empiecen con X letra.");
	do{
		fflush(stdin);
		cout<<"Ingrese la letra inicial a buscar: ";
		gets(a);
		a[0]=toupper(a[0]);
		if (!(esUnDigito(a)) or !(isalpha(a[0]))){
			system("cls");
			titulos("Generar archivo de palabras que empiecen con X letra.");
			//vuelve a mostrar toda la funcion para volver a elegir la opcion
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	} while(!(esUnDigito(a)) or !(isalpha(a[0])));
	
	char nombreArchivo[]="palabrasX.txt";
	char letra[]={a[0],'\0'};
	nombreArchivo[8]=a[0];
	abrirLibro(escribir,'e',nombreArchivo);
	letra[0]=tolower(letra[0]);
	if(!confirmarLibro(escribir))cout<<"Error al abrir"<<endl;
	else {
		string pal;
		cout<<"Archivo generado con exito."<<endl;
		aux=l;
		while(aux!=NULL){
			if((aux->palabra[0])==letra[0]){
				pal=aux->palabra;
				escribirString(escribir,pal);
				escribirString(escribir,": ");
				escribirNum(escribir,(long long)aux->rep);
				escribirChar(escribir,'\n');
			}
			aux=aux->sig;
		}
	}
	cerrarLibro(escribir);
	char eleccion[20];
	do{//Pide y valida que se ingrese una de las opciones validas
		cout<<"Ingrese (X) para volver al menu anterior: ";
		gets(eleccion);
		if(esUnDigito(eleccion))eleccion[0]=toupper(eleccion[0]);
		if(!(eleccion[0]=='X')){
			system("cls");
			cout<<endl;
			titulos("Generar archivo de palabras que empiecen con X letra.");
			cout<<"Archivo generado con exito."<<endl;
			
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(!(eleccion[0]=='X'));
	return true;
}

void palabrasLetraInicial(Lista l, string pals[], char c){//retorna las primeras 5 palabras que empiezan con una letra designada
	c=tolower(c);
	int i=0;
	ptrNodo aux = l;
	while(aux!=NULL&&i<5){
		if(aux->palabra[0]==c){
			pals[i++]=aux->palabra;
		}
		aux=aux->sig;
	}
}

	Lista abrirEstadisticasPalabras(){
		Libro abrir;
		int largo,i;
		ptrNodo lectura=NULL;
		Lista l=NULL;
		if(!(abrirLibro(abrir,'l',"Pride and Prejudice.txt")))cout<<"Error al abrir archivo"<<endl;
		else{
			while(!finLibro(abrir)){
				string cadena;
				char cad[40];
				cadena=leerPalabraLibro(abrir);
				stringstream ss(cadena);
				string palabra;
				while(ss>>palabra){
					largo=palabra.length();
					for(i=0;i<largo;i++) { 
						cad[i]=palabra[i];
					}
					cad[i]='\0';
					palabraAMinuscula(cad);
					if(l==NULL)l=crearLista(cad);
						
					if(!encontrarPalabra(l,lectura,cad)){
						if(!aniadirNodo(cad,l)){
							cout<<"Espacio insuficiente para almacenar la palabra."<<endl;
						}
					}else{
						lectura->rep++;
					}
				}
			}
			
			ordenarLista(l);
			guardarLista(l);
		}
		cerrarLibro(abrir);
		return l;
	}
void guardarLista(Lista l){
	ptrNodo aux=l;
	fstream archivo("Lista Ordenada.txt",ios::out);
	if(archivo.fail())cout<<"Error"<<endl;
	else{
		while(aux!=NULL){
			archivo<<aux->palabra<<" "<<aux->rep<<endl;
			aux=aux->sig;
		}
	}
	archivo.close();
}
