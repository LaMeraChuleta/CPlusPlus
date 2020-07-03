#ifndef  MODULE_TRABAJADOR_H_
#define  MODULE_TRABAJADOR_H_

#include<iostream>
#include<string>
#include<iomanip>
#include "MODULE_PERSONA.h"
using namespace std;


class Trabajador : public Persona {
	
	public:
				
		string num_plaza;
						
	public:
		
		Trabajador(string nombre = "Sin Asignar", int edad = 0, string num_plaza = "-----") : Persona(nombre, edad) {			
		
			this->num_plaza = num_plaza;
		}			
		~Trabajador();
		void Imprimir();	
};

void Trabajador::Imprimir(){
	
	cout<<this->nombre<<endl;	
}
Trabajador::~Trabajador(){
	
	//cout<<"Se borro a las personas"<<endl;
}

#endif
