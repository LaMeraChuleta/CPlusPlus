#ifndef  MODULE_MEDICO_H_
#define  MODULE_MEDICO_H_

#include<iostream>
#include<string>
#include<iomanip>
#include "MODULE_TRABAJADOR.h"
using namespace std;


class Medico : public Trabajador {
	
	public:
				
		string descanso;		
						
	public:
		
		Medico(string nombre = "Sin Asignar", int edad = 0, string num_plaza = "Sin Asignar", string descanso = "Sin Asignar") : Trabajador(nombre, edad, num_plaza) {			
		
			this->descanso = descanso;
		}			
		~Medico();
		void Imprimir();
		void Leer();	
};

void Medico::Imprimir(){
			
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|               INFORMACION DEL MEDICO              |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"| NOMBRE: "<<this->nombre<<setw(53 - (10 + this->nombre.length()))<<"|"<<endl;
	cout<<"| EDAD: "<<this->edad<<setw(53 - (8 + 2))<<"|"<<endl;
	cout<<"| PLAZA: "<<this->num_plaza<<setw(53 - (9 + this->num_plaza.length()))<<"|"<<endl;
	cout<<"| DESCANSO: "<<this->descanso<<setw(53 - (12 + this->descanso.length()))<<"|"<<endl;		
	cout<<"+---------------------------------------------------+"<<endl;
}
void Medico::Leer(){
	
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|         CAMBIAR INFORMACION DEL MEDICO           |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"ESCRIBA EL NOMBRE DEL MEDICO"<<endl;
	fflush(stdin);	
	getline(cin, this->nombre);
	cout<<"ESCRIBA LA EDAD"<<endl;
	cin>>this->edad;
	cout<<"ESCRIBA El NUMERO DE PLAZA"<<endl;
	fflush(stdin);	
	getline(cin, this->num_plaza);	
	cout<<"ESCRIBA El DESCANSO"<<endl;
	fflush(stdin);	
	getline(cin, this->descanso);		
}
Medico::~Medico(){
	
	//cout<<"Se elimino el medico"<<endl;
}

#endif
