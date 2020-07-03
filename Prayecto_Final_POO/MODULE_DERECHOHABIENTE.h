#ifndef  MODULE_DERECHOHABIENTE_H_
#define  MODULE_DERECHOHABIENTE_H_

#include<iostream>
#include<string>
#include<iomanip>
#include "MODULE_PERSONA.h"
using namespace std;


class Derechohabiente : public Persona {
	
	public:
				
		string num_seguro;
		string sub_esp;		
						
	public:
		
		Derechohabiente(string nombre = "Sin Asignar", int edad = 0, string num_seguro = "-----", string sub_esp = "Sin Asignar") : Persona(nombre, edad) {			
		
			this->num_seguro = num_seguro;			
			this->sub_esp = sub_esp;
		}
		~Derechohabiente();
		void Imprimir();
		void Leer();
	
};

void Derechohabiente::Imprimir(){
	
	cout<<"| PACIENTE: "<<this->nombre<<"\t"<<" EDAD: "<<this->edad<<"\t"<<" # SEGURO: "<<this->num_seguro<<"\t"<<" ESPECIALIDAD: "<<this->sub_esp<<"\t"<<endl;	
}
void Derechohabiente::Leer(){
		
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|         CAMBIAR INFORMACION DEL PACIENTE          |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"ESCRIBA EL NOMBRE DEL PACIENTE"<<endl;
	fflush(stdin);	
	getline(cin, this->nombre);
	cout<<"ESCRIBA LA EDAD"<<endl;
	cin>>this->edad;
	cout<<"ESCRIBA El NUMERO DE SEGURO"<<endl;
	fflush(stdin);	
	getline(cin, this->num_seguro);		
}
Derechohabiente::~Derechohabiente(){
	
	//cout<<"Se borro a las personas"<<endl;
}

#endif
