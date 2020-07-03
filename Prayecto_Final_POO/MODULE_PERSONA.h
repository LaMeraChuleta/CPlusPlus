#ifndef  MODULE_PERSONA_H_
#define  MODULE_PERSONA_H_

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


class Persona {
	
	public:
		
		string nombre;
		int edad;
		
	public:
		
		Persona(string nombre = "Sin Asignar", int edad = 0){
			
			this->nombre = nombre;
			this->edad = edad;
		}
		~Persona();
};

Persona::~Persona(){
	
	//cout<<"Se borro a las personas"<<endl;
}

#endif

