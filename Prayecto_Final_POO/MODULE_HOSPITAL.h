#ifndef  MODULE_HOSPITAL_H_
#define  MODULE_HOSPITAL_H_

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


class Hospital {
	
	public:
		
		string nombre_hospital;
		string especialida;
		bool disponibilidad;
		string sub_especialidad;
		int num_camas;
		int num_especialidades;
	
	public:
		
		Hospital(string nombre = " ", string especialidad = " ", bool disponibilidad = true, int num_camas = 0){
			
			this->nombre_hospital = nombre;
			this->especialida = especialidad;			
			this->disponibilidad = disponibilidad;
			this->num_camas = num_camas;
		}
		void Imprimir();
		void Leer();
		~Hospital(void);
	
};

void Hospital::Imprimir(){
				
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|           INFORMACION DEL HOSPITAL                |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"| NOMBRE: "<<this->nombre_hospital<<setw(53 - (10 + this->nombre_hospital.length()))<<"|"<<endl;
	cout<<"| ESPECIALIDAD: "<<this->especialida<<setw(53 - (16 + this->especialida.length()))<<"|"<<endl;	
	cout<<"| CAMAS DISPONIBLES: "<<this->num_camas<<setw(53 - (21 + 3))<<"|"<<endl;
	cout<<"| DISPONIBILIDAD: "<<this->disponibilidad<<setw(53 - (18 + 1))<<"|"<<endl;	
	cout<<"+---------------------------------------------------+"<<endl;
}

void Hospital::Leer(){
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|         AGREGAR INFORMACION DEL HOSPITAL          |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"ESCRIBA EL NOMBRE DEL HOSPITAL"<<endl;
	fflush(stdin);	
	getline(cin, this->nombre_hospital);
	cout<<"ESCRIBA LA ESPECIALIDAD"<<endl;
	fflush(stdin);	
	getline(cin, this->especialida);
	cout<<"ESCRIBA El NUMERO DE CAMAS"<<endl;
	cin>>this->num_camas;			
}

Hospital::~Hospital(){
	
	cout<<"Eliminamos el hospital"<<endl;
}


#endif
