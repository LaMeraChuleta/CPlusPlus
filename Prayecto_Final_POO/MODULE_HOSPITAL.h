#ifndef  MODULE_HOSPITAL_H_
#define  MODULE_HOSPITAL_H_

#include<iostream>
#include<string>
#include<iomanip>
#include "MODULE_SERVICIO.h"
#include "MODULE_DERECHOHABIENTE.h"

using namespace std;


class Hospital {
				
	private:
		
		string nombre_hospital;						
		string *sub_esp_array;
		string zona;
		int num_camas;
		int num_especialidades;				
		int num_servicios;													
		Servicio *servicios;
		bool disponibilidad;
				
	public:
		
		Hospital(string nombre = " ", string zona = " ", bool disponibilidad = true){
			
			this->nombre_hospital = nombre;
			this->zona = zona;			
			this->disponibilidad = disponibilidad;
			this->num_camas = num_camas;	
			this->Inicializar_Sub_Esp();
			this->Inicializar_Servicios();
			this->num_camas = this->Contar_Disponible();														
		}
		~Hospital();
		void Menu_Hospital();		
		
	private:
		
		void Imprimir();
		void Inicializar_Servicios();
		void Inicializar_Sub_Esp();					
		void Menu_Ingreso();			
		void Imprimir_Pacientes(); 	
		void Buscar_Paciente();	
		void Administrar_Servicio();
		int Contar_Ocupado();
		int Contar_Disponible();
		
};


void Hospital::Imprimir(){
								
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|           INFORMACION DEL HOSPITAL                |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"| NOMBRE: "<<this->nombre_hospital<<setw(53 - (10 + this->nombre_hospital.length()))<<"|"<<endl;
	cout<<"| UBICACION: "<<this->zona<<setw(53 - (13 + this->zona.length()))<<"|"<<endl;		
	cout<<"| NUMERO DE SUB-ESPECIALIDADES: "<<this->num_especialidades<<setw(53 - (32 + 1))<<"|"<<endl;	
	cout<<"| NUMERO DE SERVICIO: "<<this->num_servicios<<setw(53 - (22 +  1))<<"|"<<endl;	
	cout<<"| CAMAS DISPONIBLES: "<<this->Contar_Ocupado()<<setw(53 - (21 + 1))<<"|"<<endl;	
	cout<<"| DISPONIBILIDAD: "<<this->disponibilidad<<setw(53 - (18 + 1))<<"|"<<endl;	
	cout<<"+---------------------------------------------------+"<<endl;
}

void Hospital::Inicializar_Servicios(){
		
	
	cout<<"¿CUANTOS SERVICIOS QUIERE AGREGAR A SU HOSPITAL?"<<endl;
	cin>>this->num_servicios;
	
	this->servicios = new Servicio[this->num_servicios];	
	
	int i = 0;
	
	while(i < this->num_servicios){
		
		string nombre, jefe;
		int num_camas;
		
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"|            INICIALIZAR SERVICIO             |"<<endl;			
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"ESCRIBA EL NOMBRE DEL SERVICIO"<<endl;
		fflush(stdin);	
		getline(cin, nombre);
		cout<<"ESCRIBA EL NOMBRE DEL JEFE DEL SERVICIO"<<endl;
		fflush(stdin);	
		getline(cin, jefe);
		cout<<"ESCRIBA EL NUMERO DE CAMAS ASIGNADAS"<<endl;
		cin>>num_camas;
		
		
		this->servicios[i] = Servicio(nombre, jefe, num_camas);	
		this->servicios[i].Inicializar_Plantilla();
		
		i++;	
	}
		
}

void Hospital::Inicializar_Sub_Esp(){
	
	cout<<"¿CUANTAS SUB-ESPECIALIDADES QUIERE AGREGAR A SU HOSPITAL?"<<endl;
	cin>>this->num_especialidades;
	
	this->sub_esp_array = new string[this->num_especialidades];	
	
	int i = 0;
	
			
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|        INICIALIZAR SUB-ESPECIALIDAD         |"<<endl;			
	cout<<"+---------------------------------------------+"<<endl;
	
	while(i < this->num_especialidades){
		
		string nombre;		
		cout<<"ESCRIBA EL NOMBRE DE LA SUB-ESPECIALIDAD"<<endl;
		fflush(stdin);	
		getline(cin, nombre);
		this->sub_esp_array[i]	= nombre;				
		i++;	
	}
	
}

void Hospital::Menu_Ingreso(){	
		
		int opc;
		bool retu = false;
			
		system("CLS");
				
		do{
			
													
			cout<<"+---------------------------------------------+"<<endl;
			cout<<"|           RECEPCION DEL PACIENTE            |"<<endl;	
			cout<<"|---------------------------------------------|"<<endl;		
			cout<<"|         ELIGA LA SUB-ESPECIALIDAD           |"<<endl;
			cout<<"+---------------------------------------------+"<<endl;			
			int i = 0;
			while(i < this->num_especialidades){				
				cout<<"| "<<this->sub_esp_array[i]<<setw(53 - (13 + this->sub_esp_array[i].length()))<<"["<<i+1<<"]  |"<<endl;
				i++;
			}	
			cout<<"| Cancelar                               ["<<this->num_especialidades + 1<<"]  |"<<endl;	
			cout<<"+---------------------------------------------+"<<endl;
			cin>>opc;
			
			
			if(opc >= 1 && opc < this->num_especialidades + 1) {
				
					
					system("CLS");														
					int opc2;
					
					cout<<"+---------------------------------------------+"<<endl;
					cout<<"|           RECEPCION DEL PACIENTE            |"<<endl;	
					cout<<"|---------------------------------------------|"<<endl;		
					cout<<"|         ELIGA LA SUB-ESPECIALIDAD           |"<<endl;
					cout<<"+---------------------------------------------+"<<endl;
								
					int i = 0;
					while(i < this->num_servicios){				
						cout<<"| "<<this->servicios[i].nombre<<setw(53 - (13 + this->servicios[i].nombre.length()))<<"["<<i + 1<<"]  |"<<endl;
						i++;
					}						
					cout<<"| Cancelar                               ["<<this->num_servicios + 1<<"]  |"<<endl;	
					cout<<"+---------------------------------------------+"<<endl;
					cin>>opc2;
					
					
					if(opc2 >= 1 && opc2 < this->num_servicios + 1){
						
						this->servicios[opc2 - 1].Agregar_Derechohabiente(this->sub_esp_array[opc - 1]);
					}
																																	
				break;
			}

		}
		while(opc < 4);									
}

void Hospital::Menu_Hospital(){
	
	int opc;
	
	do{
		
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"|           OPCIONES DEL HOSPITAL             |"<<endl;	
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"| Info del hospital                     [1]   |"<<endl;
		cout<<"| Recibir paciente                      [2]   |"<<endl;
		cout<<"| Buscar  paciente                      [3]   |"<<endl;
		cout<<"| Imprimir paciente                     [4]   |"<<endl;		
		cout<<"| Administar Servicios                  [5]   |"<<endl;	
		cout<<"| Salir                                 [6]   |"  <<endl;	
		cout<<"+---------------------------------------------+"<<endl;
		cin>>opc;
		
		system("CLS");
					
		switch(opc) {
		
			case 1: 								
				this->Imprimir();			
				break;
			
			case 2:					
				this->Menu_Ingreso();
				break;
															
			case 3:					
			
				this->Buscar_Paciente();
				break;			
			
			case 4:					
				this->Imprimir_Pacientes();
				break;
				
			case 5:					
				this->Administrar_Servicio();
				break;

				
			default:			
				cout<<"Adios!!!"<<endl;
				break;					
		}		
		system("PAUSE");
		system("CLS");
	}
	while(opc < 6);
			
}

void Hospital::Imprimir_Pacientes(){
	
	int opc;	
	int i = 0;
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|              IMPRIMIR PACIENTE              |"<<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| Imprimir por Sub-Esp                    [1] |"<<endl;
	cout<<"| Imprimir por Servicio                   [2] |"<<endl;
	cout<<"| Imprimir Todos                          [3] |"<<endl;
	cout<<"| Cancelar                                [4] |"<<endl;
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
		
	switch(opc){
		
		case 1:
			
			i = 0;
			while(i < this->num_especialidades){
							
				cout<<"+---------------------------------------------+"<<endl;
				cout<<"|         "<<this->sub_esp_array[i]<<setw(47 - (10 + this->sub_esp_array[i].length()))<<"|"<<endl;	
				cout<<"|---------------------------------------------|"<<endl;
				
				int j = 0;								
				
				while(j < this->num_servicios){									
													
					this->servicios[j].Imprimir_Pacientes(this->sub_esp_array[i]);															
					j++;							
				}																														
				i++;		
			}
						
			break;
			
		case 2:
			
			i = 0;
			while(i < this->num_servicios){
							
				cout<<"+---------------------------------------------+"<<endl;
				cout<<"|         "<<this->servicios[i].nombre<<setw(47 - (10 + this->servicios[i].nombre.length()))<<"|"<<endl;	
				cout<<"|---------------------------------------------|"<<endl;										
				this->servicios[i].Imprimir_Pacientes();		
				cout<<"\n\n"<<endl;								
				i++;		
			}
	
			break;
		
		case 3:
			
			cout<<"+---------------------------------------------+"<<endl;
			cout<<"|              LISTA DE PACIENTES             |"<<endl;
			cout<<"|---------------------------------------------|"<<endl;				
			i = 0;
			while(i < this->num_servicios){
																				
				this->servicios[i].Imprimir_Pacientes();													
				i++;		
			}
	
			break;
			
		default:
			
			cout<<"Adios!"<<endl;
			break;
	}
		
}

void Hospital::Buscar_Paciente(){
	
	int opc;
	string buscar;
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|              BUSCAR PACIENTE                |"<<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| Buscar por Nombre                     [1]   |"<<endl;
	cout<<"| Buscar por Num Seguro                 [2]   |"<<endl;
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
			
	int i = 0;	
	
	if(opc == 1){
		
		cout<<"Escriba el nombre del paciente"<<endl;
		fflush(stdin);	
		getline(cin, buscar);
	}
	else{
		
		cout<<"Escriba el nombre del paciente"<<endl;
		fflush(stdin);	
		getline(cin, buscar);
	}
	
	while(i < this->num_servicios){
		
		
		if(opc == 1){
			
			this->servicios[i].Buscar_Paciente(buscar, 1);			
		}														
		else{
			
			this->servicios[i].Buscar_Paciente(buscar, 2);						
		}								
			
												
		i++;		
	}	
}

void Hospital::Administrar_Servicio(){
	
	int i = 0;
	char opc = ' ';
	
	while(i < this->num_servicios){
		
		
		this->servicios[i].Imprimir();
		
		cout<<"DESEA ADMINISTRAR ESTE SERVICIO [S/N]"<<endl;
		cin>>opc;
		if(opc == 's'){
			
			this->servicios[i].Menu_Servicios();
		}
		system("CLS");
		i++;
	}		
}

int Hospital::Contar_Ocupado(){
	
	int i = 0;
	int total = 0;
	
	while(i < this->num_servicios){
		
		total += this->servicios[i].Contar_Ocupado();
		i++;
	}
	if(this->num_camas - total == 0){
		this->disponibilidad = false;
	}
	
	return this->num_camas - total;
}

int Hospital::Contar_Disponible(){
	
	int i = 0;
	int total = 0;
	
	while(i < this->num_servicios){
		
		total += this->servicios[i].Contar_Disponible();
		i++;
	}
	return total;
}

Hospital::~Hospital(){
		
	//cout<<"Eliminamos el hospital"<<endl;
}


#endif
