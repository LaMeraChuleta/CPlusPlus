#ifndef  MODULE_SUB_ESPECIALIAD_H_
#define  MODULE_SUB_ESPECIALIAD_H_

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Sub_Especialidad{
	
	public:
		
		string nombre;
		string jefe_nombre;
		int num_camas;
		
	public:
		
		Sub_Especialidad(string nombre = " ", string jefe = " ", int  num_camas = 0){
			
			this->nombre = nombre;
			this->jefe_nombre = jefe;
			this->num_camas = num_camas;
		}
		void Imprimir();
		void Leer();
		~Sub_Especialidad();
		
	
};


void Sub_Especialidad::Imprimir() {
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|           INFORMACION SUB-ESPECIALIDAD            |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"| NOMBRE: "<<this->nombre<<setw(53 - (10 + this->nombre.length()))<<"|"<<endl;
	cout<<"| JEFE: "<<this->jefe_nombre<<setw(53 - (8 + this->jefe_nombre.length()))<<"|"<<endl;	
	cout<<"| CAMAS DISPONIBLES: "<<this->num_camas<<setw(53 - (21 + 1))<<"|"<<endl;		
	cout<<"+---------------------------------------------------+"<<endl;
}

void Sub_Especialidad::Leer(){
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|       AGREGAR INFORMACION SUB-ESPECIALIDAD        |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"ESCRIBA EL NOMBRE DE LA SUB-ESPECIALIDAD"<<endl;
	fflush(stdin);	
	getline(cin, this->nombre);
	cout<<"ESCRIBA EL NOMBRE DEL JEFE"<<endl;
	fflush(stdin);	
	getline(cin, this->jefe_nombre);
	cout<<"ESCRIBA El NUMERO DE CAMAS"<<endl;
	cin>>this->num_camas;
}

Sub_Especialidad::~Sub_Especialidad(){
	
	cout<<"Eliminamos la sub-especialidad"<<endl;
}


#endif
