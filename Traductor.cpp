#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
const char *nombre_archivo = "archivo.txt";
struct Ptraductor{
	string palabra;
	string traduccion;
	string definicion;
	int menu;
	};
void crear();
void abrir();
void leer();
void buscar();
void actualizar();
void borrar();
int main (){
	int menu;
	
	do{
		system("cls");
		cout<<"1. Ingresar nueva palabra"<<endl;
		cout<<"2. Mostrar palabras"<<endl;
		cout<<"3. Buscar palabras"<<endl;
		cout<<"4. Modificar palabra"<<endl;
		cout<<"5. Borrar palabra"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"\nSeleccion: "<<endl;
		cin>>menu;
		
		switch (menu){
			case 1: 
			crear();
			break;
			case 2:
			leer();
			break;
			case 3:
			buscar();
			break;
			case 4:
			actualizar();
			break;
			case 5:
			borrar();
			break;
		}
		
	}while(menu<=5);
}
void abrir(){
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		do{
			getline(archivo,contenido);
			cout<<contenido<<endl;
			cout<<"______________________________"<<endl;
		}while(archivo.eof()==false);
	}
	archivo.close();
}
void crear (){
		ofstream archivo;
		char s;
	Ptraductor ptraductor;
	archivo.open(nombre_archivo,ios::app);
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		do{
			cout<<"Ingrese Palabra:";
			cin.ignore();
			getline(cin,ptraductor.palabra);
			cout<<"Ingrese Traduccion:";
			getline(cin,ptraductor.traduccion);
			cout<<"Ingrese definicion:";
			getline(cin,ptraductor.definicion);
			archivo<<ptraductor.palabra<<endl;
			archivo<<ptraductor.traduccion<<endl;
			archivo<<ptraductor.definicion<<endl;
			cout<<"Desea agregar otro Palabra (s/n): ";
			cin>>s;
			system("cls");
		}while (s=='s');
		archivo.close();
	}
}
void leer(){
	ifstream archivo;
	system ("cls");
	string texto,trad,defi;
	archivo.open("archivo.txt", ios::in);
	cout<<"-------PALABRAS REGISTRADAS--------"<<endl;
	while(!archivo.eof()){
	getline(archivo,texto);
	getline(archivo,trad);
	getline(archivo,defi);
		cout<<"PALABRA : "<< texto<<endl;
		cout<<"TRADUCCION : "<< trad<<endl;
		cout<<"DEFINICION : "<< defi <<endl;
		cout<<"-----------------------------------"<<endl;
	}
	archivo.close();
	system("Pause");
}
void buscar(){
	ifstream archivo;
	system("cls");
	archivo.open("archivo.txt",ios::in);
	string texto,trad,defi,palaaux;
	bool encontrado = false;
	cout<<"Digite la palabra: ";
	cin>>palaaux;
	archivo>>texto;
	while(!archivo.eof() && !encontrado){
		getline(archivo,defi);
		getline(archivo,trad);
		getline(archivo,defi);
		if(texto==palaaux){
		cout<<"PALABRA : "<< texto<<endl;
		cout<<"TRADUCCION : "<< trad<<endl;
		cout<<"DEFINICION : "<< defi<<endl;
		cout<<"-----------------------------------"<<endl;
		encontrado = true;
		}
		archivo>>texto;
	}
	archivo.close();
	
	if(!encontrado)
		cout<<"DATO NO ENCONTRADO"<<endl;
		system("pause");
}
void actualizar(){
	system("cls");
	ifstream archivo;
	string texto, trad, defi,palaaux;
	archivo.open("archivo.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if(archivo.is_open()){
		cout<<"PALABRA: ";
		cin>>palaaux;
		archivo>>texto;
		while(!archivo.eof()){
		getline(archivo,defi);
		getline(archivo,trad);
		getline(archivo,defi);
		if(texto == palaaux){
			cout<<"NUEVO NOMBRE: ";
			cin>>palaaux;
			aux<<palaaux<<" \n"<<trad<<" \n"<<defi<<endl;
		}else{
				aux<<texto<<" "<<trad<<" "<<defi<<endl;
		}
		archivo>>texto;
		}
		archivo.close();
		aux.close();
	}else
		cout<<"Error"<<endl;
	remove("archivo.txt");
	rename("auxiliar.txt", "archivo.txt");
	
}
void borrar(){
		system("cls");
		ifstream archivo;
		string texto, trad, defi,palaaux;
		archivo.open("archivo.txt",ios::in);
		ofstream aux("auxiliar.txt",ios::out);
		if(archivo.is_open()){
		cout<<"PALABRA: ";
		cin>>palaaux;
		archivo>>texto;
		while(!archivo.eof()){
		getline(archivo,defi);
		getline(archivo,trad);
		getline(archivo,defi);
		if(texto == palaaux){
			cout<<"Eliminado ";
			Sleep(1500);
		}else{
			getline(archivo,defi);
			getline(archivo,trad);
			getline(archivo,defi);
				aux<<texto<<" \n"<<trad<<" \n"<<defi<<endl;
		}
		archivo>>texto;
		}
		archivo.close();
		aux.close();
	}else
		cout<<"Error"<<endl;
	remove("archivo.txt");
	rename("auxiliar.txt", "archivo.txt");
}
