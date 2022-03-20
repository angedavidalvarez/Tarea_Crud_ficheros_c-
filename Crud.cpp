#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
const char *Estudiantes = "Alumnos.dat";
const char *temporal = "temporal.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
	char Direccion[50];
};
void crear();
void leer();
void actualizar();
void eliminar();
void Buscar();
main(){
	
	int op;
	cout<<"Selecciones una opcion"<<endl;
	cout<<"1. Mostrar Alumno"<<endl;
	cout<<"2. Agregar Alumno"<<endl;
	cout<<"3. Modificar Alumno"<<endl;
	cout<<"4. Eliminar Alumno"<<endl;
	cout<<"5. Buscar Alumno"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"Opcion: "<<endl;
	cin>>op;
	switch(op){
		case 1:
			leer();
			break;
		case 2:
			crear();
			break;
		case 3:
			actualizar();
			break;
		case 4:
			eliminar();
			break;
		case 5:
			Buscar();
			break;
		case 6:
			return 0;
			break;
	}
}
void leer(){
		system("cls");
		FILE* archivo = fopen(Estudiantes,"rb");	
		if (!archivo){
			archivo = fopen(Estudiantes,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<"|"<<"Direccion"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<"|"<<estudiante.Direccion
		<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
}
void Buscar(){
	FILE* archivo = fopen(Estudiantes,"r+b");
	int codigo;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"Ingres el Codigo que desa Buscar:";
	cin>>codigo;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if( estudiante.codigo ==codigo )
	{
		cout<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<"|"<<estudiante.Direccion
		<<endl;
	}
	
	
	
	
}
}
void actualizar(){
	FILE* archivo = fopen(Estudiantes,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"Ingres el ID que desa Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.Direccion,direccion.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(Estudiantes,"ab");
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.Direccion,direccion.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void eliminar(){
    FILE* archivo = fopen(Estudiantes,"r");
    FILE* archivo2 = fopen(temporal,"w+b");
	ofstream salida;
	Estudiante estudiante;
	int i=0;
	int codigo;
	string nombre,apellido,direccion;
	cout<<"Ingres el Codigo del Alumno que desa Eliminar:";
	cin>>codigo;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if( estudiante.codigo !=codigo )
	{
		fwrite(&estudiante,sizeof(Estudiante),1,archivo2);
	}
		else{
			cout<<"	Alumno Eliminado"<<endl;
			system("PAUSE");
		}
	}
	    fclose(archivo);
	    fclose(archivo2);
	    remove("Alumnos.dat");
	    rename("temporal.dat", "Alumnos.dat");
	    leer();
}
