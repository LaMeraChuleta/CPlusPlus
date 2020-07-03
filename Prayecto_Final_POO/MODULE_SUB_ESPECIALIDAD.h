/*
#ifndef  MODULE_SUB_ESPECIALIAD_H_
#define  MODULE_SUB_ESPECIALIAD_H_

#include<iostream>
#include<string>
#include<iomanip>
#include "MODULE_SERVICIO.h"
#include "MODULE_DERECHOHABIENTE.h"

using namespace std;

class Sub_Especialidad{
	
	public:
		
		string nombre;
		string jefe_nombre;		
		int num_camas;
		Servicio *servicios;
		
	public:
		
		Sub_Especialidad(string nombre = " ", string jefe = " ", int  num_camas = 0){
			
			this->nombre = nombre;
			this->jefe_nombre = jefe;
			this->num_camas = num_camas;
			//Contruimos 2 servicio ( consultas, internados )
			this->servicios = new Servicio[2];
			this->servicios[0] = Servicio("Urgencias", "Daniela Cruz", 25);
			this->servicios[1] = Servicio("Internado","Armado Peña",25);										
		}
		void Imprimir();
		void Leer();
		void Mostra_Servicios();
		void Menu_Sub_Especialidad();		
		bool Mostrar_Ingreso();
		void Imprimir_Pacientes();
		int Buscar_Paciente(string buscar, int tipo_busqueda);
		~Sub_Especialidad();
		
	
};

int Sub_Especialidad::Buscar_Paciente(string buscar, int tipo_busqueda){
	
	int i = 0;
			
	while(i < 2){	
								
		return this->servicios[i].Buscar_Paciente(this->nombre, buscar, tipo_busqueda);		
		i++;					
	}
	
}

void Sub_Especialidad::Imprimir_Pacientes(){
	
	int i = 0;
		
	while(i < 2){	
				
		this->servicios[i].Imprimir_Pacientes();		
		i++;			
		
	}
}	

void Sub_Especialidad::Imprimir() {
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|           INFORMACION SUB-ESPECIALIDAD            |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"| NOMBRE: "<<this->nombre<<setw(53 - (10 + this->nombre.length()))<<"|"<<endl;
	cout<<"| JEFE: "<<this->jefe_nombre<<setw(53 - (8 + this->jefe_nombre.length()))<<"|"<<endl;	
	cout<<"| CAMAS DISPONIBLES: "<<this->num_camas<<setw(53 - (21 + 1))<<"|"<<endl;		
	cout<<"+---------------------------------------------------+"<<endl;
	
}

bool Sub_Especialidad::Mostrar_Ingreso(){
	
	system("CLS");			
	int opc;
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|           RECEPCION DEL PACIENTE            |"<<endl;	
	cout<<"|---------------------------------------------|"<<endl;		
	cout<<"|             ELIGA EL SERVICIO               |"<<endl;
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| "<<this->servicios[0].nombre<<setw(53 - (8 + this->servicios[0].nombre.length()))<<"[1]  |"<<endl;
	cout<<"| "<<this->servicios[1].nombre<<setw(53 - (8 + this->servicios[1].nombre.length()))<<"[2]  |"<<endl;			
	cout<<"| Cancelar                               [3]  |"  <<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
		
		switch(opc){
								
			case 1: 								
				this->servicios[0].Agregar_Derechohabiente();
				return false;
				break;
			
			case 2:					
				this->servicios[1].Agregar_Derechohabiente();
				return false;
				break;			
				
			default:			
				cout<<"Adios!!!"<<endl;
				return true;
				break;	
		}
		system("PAUSE");
		system("CLS");	
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

void Sub_Especialidad::Menu_Sub_Especialidad(){
	
		
	int opc;
	
	do{
		
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"|        OPCIONES DE LA SUB-ESPECIALIDAD      |"<<endl;	
		cout<<"|              "<<this->nombre<<setw(46 - (14 + this->nombre.length()))<<"|"<<endl;
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"| Info de la Sub-Especialidades         [1]   |"<<endl;
		cout<<"| Ver Servicio                          [2]   |"<<endl;	
		cout<<"| Regresar                              [3]   |"  <<endl;	
		cout<<"+---------------------------------------------+"<<endl;
		cin>>opc;
		
		system("CLS");
					
		switch(opc) {
		
			case 1: 								
				this->Imprimir();			
				break;
			
			case 2:					
				this->Mostra_Servicios();
				break;
			
			default:			
				cout<<"Adios!!!"<<endl;
				break;					
		}		
		system("PAUSE");
		system("CLS");
	}
	while(opc < 3);
	
}

void Sub_Especialidad::Mostra_Servicios(){
	
	
	int i = 0;
	char si_no;
	while(i < 2){	
	
		this->servicios[i].Imprimir();	
		cout<<"Quiere administrar este servico...[S/N]"<<endl;
		cin>>si_no;
		if(si_no == 's'){
			
			system("CLS");
			this->servicios[i].Menu_Servicios();		
			break;
		}	
		system("CLS");			
		i++;		
	}
}

Sub_Especialidad::~Sub_Especialidad(){
	
	//cout<<"Eliminamos la sub-especialidad"<<endl;
}


#endif

*/
