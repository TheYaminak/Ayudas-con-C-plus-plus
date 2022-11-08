#include <string>
#include <iostream>
#include <conio.h>
using namespace std;
/*
Hacer una estructura llamada alumno, en la cual se tendrán los siguientes Campos: Nombre, edad,  notas, 
pedir datos al usuario para 3 alumnos, comprobar cuál  de los 3 tiene el mejor promedio y posteriormente 
imprimir los datos del alumno.
*/

struct Notas {
	int creditos;
	float nota1;
	float nota2;
	float nota3;
	float asistencia;
}Nota[3];

struct Alumno {
	string Nombre;
	int Edad;
	Notas Nota[3];
}Alum[3];

void imprimirAlumnoMayorPromedio(){
	float promedio[3], mayor=0, tProm = 0, tCred =0;
	int index=0, prom=0;
	
	for(int i = 0; i<3 ; i++){
		tProm = 0, tCred = 0;
		for(int j = 0; j<3 ; j++){
			promedio[i] = 0;
			promedio[i] += Alum[i].Nota[j].nota1;
			promedio[i] += Alum[i].Nota[j].nota2;
			promedio[i] += Alum[i].Nota[j].nota3;
			promedio[i] += Alum[i].Nota[j].asistencia;
			
			if(promedio[i]>89){
				prom =4;
			}else if(promedio[i]>=80 && promedio[i]<=89){
					prom = 3;
			}else if(promedio[i]>=70 && promedio[i]<=79){
				  	prom = 2;
			}else if(promedio[i]>=60 && promedio[i]<=69){
				  	prom = 1;
			}else{
				  	prom = 0;
			}
		
		cout<<"\nEl promedio de la nota"<<prom;
		tProm += prom * (Alum[i].Nota[j].creditos);
		cout<<"\nEl total del promedio"<<tProm;
		tCred += Alum[i].Nota[j].creditos;
		cout<<"\nEl total de  credito"<<tCred;
		}
		promedio[i] = (tProm)/(tCred);
		
		if(promedio[i] > mayor){
			index = i;
			mayor=promedio[i];
		}
	}
	cout<<"El nombre del alumno con el mayor promedio es: "<<Alum[index].Nombre;
	cout<<"\nEl promedio  es: "<<promedio[index];
	cout<<"\nLa edad es: "<<Alum[index].Edad;
}



int main(){
	//Ingreso las notas de los alumnos
	for(int i=0; i<3;i++){
		cout<<"Ingrese los datos del alumno: "<<i+1 <<"\n";
		cout<<"\nIngrese el nombre:\n";
		cin>>Alum[i].Nombre;
		cout<<"\nIngrese la edad:\n";cin>>Alum[i].Edad;
		
		for(int j =0; j<3;j++){
			cout<<"\nIngrese el valor de la nota: "<<j+1<<"\n";
			
			cout<<"Ingrese los creditos de la materia \n";
			cin>>Alum[i].Nota[j].creditos;
			
			cout<<"\nIngrese el valor del primer parcial \n";
			cin>>Alum[i].Nota[j].nota1;
			
			cout<<"Ingrese El valor del segundo parcial \n";
			cin>>Alum[i].Nota[j].nota2;
			
			cout<<"Ingrese El valor del tercer parcial \n";
			cin>>Alum[i].Nota[j].nota3;
			
			cout<<"Ingrese El valor de la asistencia \n";
			cin>>Alum[i].Nota[j].asistencia;
		}
		
		cout<<"\n\n\n\n";
	}
	
	
	imprimirAlumnoMayorPromedio();
	
	getch();
	return 0;
}
