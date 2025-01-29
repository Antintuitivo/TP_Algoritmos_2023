#include<iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
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
void generarContra(const char legajo[], char contra[]){
	for(int i=0;i<4;i++) contra[i]=legajo[4-i];
	contra[4]= (char)((((legajo[0]-'0')+(legajo[4]-'0'))%10)+'0');
	contra[5]='\0';
}
void convertirFecha(char fechaGral[], tm*fecha){
	//la funcion asigna la fecha del dia que se genere el archivo binario
	//a cada uno de los usuario,como "fecha de ultima vez"
	fechaGral[0]='0'+(fecha->tm_mday/10);
	fechaGral[1]='0'+(fecha->tm_mday%10);
	fechaGral[2]='/';
	fechaGral[3]='0'+(fecha->tm_mon/10);
	fechaGral[4]='0'+(fecha->tm_mon%10);
	fechaGral[5]='/';
	fechaGral[6]='0'+(fecha->tm_year/1000);
	fechaGral[7]='0'+((fecha->tm_year/100)%10);
	fechaGral[8]='0'+((fecha->tm_year/10)%10);
	fechaGral[9]='0'+(fecha->tm_year%10);
	fechaGral[10]='\0';
}
void MostrarArchivo(){
	ifstream bin;
	Persona x[100];
	bin.open("Usuarios.bin",ios::binary);
	if(bin.fail()) cout<<"ERROR al abrir el archivo"<<endl;
	else{
		
		cout<<"contenido del archivo binario:"<<endl<<endl;
		bin.read((char*)(&x), sizeof(x));
		for(int i=0;i<100;i++) { 
			cout<<x[i].apellido<<endl;
			cout<<x[i].nombre<<endl;
			cout<<x[i].contra<<endl;
			cout<<x[i].legajo<<endl;
			cout<<x[i].date<<endl;
			cout<<x[i].rol<<endl;
			cout<<x[i].sexo<<endl<<endl;
		}
	}
	bin.close();
}
int main (int argc, char *argv[]) {
	time_t ahora;
	struct tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	fecha->tm_mon++;
	fecha->tm_year+=1900;
	
	ifstream texto;
	Persona u[100];
	texto.open("Usuarios.txt");
	if(texto.fail()) cout<<"ERROR al abrir usuarios";
	else{
		char fechaGeneral[11];
		convertirFecha(fechaGeneral, fecha);
		for(int i=0;i<100;i++) { 
			texto>>u[i].nombre;
			texto>>u[i].apellido;
			texto>>u[i].legajo;
			texto>>u[i].sexo;
			texto>>u[i].rol;
			generarContra(u[i].legajo, u[i].contra);
			strcpy(u[i].date, fechaGeneral);
		}
		texto.close();
	}
	ofstream datos;
	datos.open("Usuarios.bin",ios::binary);
	if(datos.fail()) cout<<"ERROR al abrir el archivo"<<endl;
	else{
		datos.write((char*)u, sizeof(u));
	}
	datos.close();
	
	MostrarArchivo();

	
	return 0;
}

	
	
