#ifndef  MODULE_SERVICIO_H_
#define  MODULE_SERVICIO_H_

#include<iostream>
#include<string>
#include<iomanip>

#include "MODULE_PLANTILLA.h"
#include "MODULE_DERECHOHABIENTE.h"
#include "MODULE_MEDICO.h"
using namespace std;


class Servicio {
	
	public:
		
		string nombre;
	
	private:
				
		string jefe_servicio;		
		Plantilla plantilla;
		int camas_asignadas;
		int camas_ocupadas;
		Derechohabiente *pacientes;		

	public:
		
		Servicio(string nombre = "Sin Asignar", string jefe_servico = "Sin Asignar", int camas = 0){
			
			this->nombre = nombre;
			this->jefe_servicio = jefe_servico;						
			this->camas_asignadas = camas;						
			this->camas_ocupadas = 0;
			this->pacientes = new Derechohabiente[camas];									
		}
		~Servicio();
		
		void Inicializar_Plantilla();								
		void Agregar_Derechohabiente(string sub_esp);		
		void Imprimir();	
		void Imprimir_Pacientes();
		void Imprimir_Pacientes(string sub_esp);
		int Contar_Ocupado();	
		int Contar_Disponible();		
		void Menu_Servicios();		
		void Buscar_Paciente(string buscar, int tipo_busqueda);	
	
	private:
											
		void Menu_Opciones_Busqueda(Derechohabiente &actual_paciente, int index);		
		void Borrar(Derechohabiente &borrar_paciente, int index);		
		void Buscar_Medico();
		void Buscar_Enfermera();
								
};

void Servicio::Inicializar_Plantilla(){
	
	int num_medicos, num_enfermeras;
	
	cout<<"¿CUANTOS MEDICOS QUIERES AGREGAR A ESTE SERVICIO?"<<endl;
	cin>>num_medicos;
	cout<<"¿CUANTAS ENFERMERAS QUIERES AGREGAR A ESTE SERVICIO?"<<endl;
	cin>>num_enfermeras;
		
	this->plantilla = Plantilla(num_medicos,num_enfermeras);	
	
	char opc = ' ';
	cout<<"¿QUIERES INICIALIZAR LOS TRABAJADORES?  [s/n]"<<endl;
	cin>>opc;
	
	if(opc == 's'){
		
		int i = 0;
		
		while(i < num_medicos){
			
			plantilla.Agregar_Medico();
			i++;
		}
		
		i = 0;
		
		while(i < num_enfermeras){
			
			plantilla.Agregar_Enfermera();
			i++;
		}				
	}
	
	system("CLS");		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|                 BIENVENIDO!!!               |"<<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	system("PAUSE");
	
}

void Servicio::Agregar_Derechohabiente(string sub_esp){
			
	if(this->camas_asignadas == this->camas_ocupadas){
		
		cout<<"YA NO TEMOS LUGAR"<<endl;
	}			
	else{
	
			
		string nombre, num_seguro; 
		int edad;
	
		system("CLS");
	
		cout<<"+---------------------------------------------------+"<<endl;
		cout<<"|               AGREGAR DERECHOHABIENTE             |"<<endl;
		cout<<"+---------------------------------------------------+"<<endl;
		cout<<"| LUGARES DISPONIBLES: "<<this->camas_asignadas - this->camas_ocupadas<<setw(53 - (23 + 2))<<"|"<<endl;	
		cout<<"+---------------------------------------------------+"<<endl;
		cout<<"ESCRIBA EL NOMBRE PACIENTE"<<endl;
		fflush(stdin);	
		getline(cin, nombre);
		cout<<"ESCRIBA LA EDAD"<<endl;
		cin>>edad;	
		cout<<"ESCRIBA NUMERO DE SEGURO SOCIAL"<<endl;
		fflush(stdin);	
		getline(cin, num_seguro);
		
		this->pacientes[this->camas_ocupadas] = Derechohabiente(nombre, edad, num_seguro, sub_esp);
		this->camas_ocupadas += 1; 
	
	}		
			
}

void Servicio::Imprimir() {
	
	cout<<"+---------------------------------------------------+"<<endl;
	cout<<"|               INFORMACION SERVICIO                |"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;	
	cout<<"| NOMBRE: "<<this->nombre<<setw(53 - (10 + this->nombre.length()))<<"|"<<endl;
	cout<<"| JEFE: "<<this->jefe_servicio<<setw(53 - (8 + this->jefe_servicio.length()))<<"|"<<endl;			
	cout<<"| CAPACIDAD: "<<this->camas_asignadas<<setw(53 - (13 + 2))<<"|"<<endl;
	cout<<"| DISPONIBLES: "<<this->Contar_Disponible() - this->Contar_Ocupado()<<setw(53 - (15 + 2))<<"|"<<endl;
	cout<<"+---------------------------------------------------+"<<endl;
}

void Servicio::Imprimir_Pacientes(){
	
	
	int i = 0;
	
	while(i < this->camas_ocupadas){
		
		this->pacientes[i].Imprimir();
		i++;		
	}
		
}

void Servicio::Imprimir_Pacientes(string sub_esp){
	
	int i = 0;	
	while(i < this->camas_ocupadas){
		
		if(this->pacientes[i].sub_esp == sub_esp){
			
			this->pacientes[i].Imprimir();
			cout<<"\n"<<endl;
		}									
		i++;		
	}	
}

int Servicio::Contar_Ocupado(){
				
	return this->camas_ocupadas;
}

int Servicio::Contar_Disponible(){
	
	return this->camas_asignadas;
}

void Servicio::Menu_Servicios(){
				
	int opc;
	
	do{
		
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"|             OPCIONES DEL SERVICIO           |"<<endl;	
		cout<<"|         "<<this->nombre<<setw(46 - (9 + this->nombre.length()))<<"|"<<endl;
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"| Info del Servicio                     [1]   |"<<endl;
		cout<<"| Agregar Medico                        [2]   |"<<endl;		
		cout<<"| Agregar Enfermera                     [3]   |"<<endl;
		cout<<"| Imprimir Medicos                      [4]   |"<<endl;	
		cout<<"| Imprimir Enfermera                    [5]   |"<<endl;	
		cout<<"| Imprimir Plantilla                    [6]   |"<<endl;			
		cout<<"| Buscar Medico                         [7]   |"<<endl;	
		cout<<"| Buscar Enfermera                      [8]   |"<<endl;	
		cout<<"| Regresar                              [9]   |"  <<endl;	
		cout<<"+---------------------------------------------+"<<endl;
		cin>>opc;
		
		system("CLS");
					
		switch(opc) {
		
			case 1: 								
				this->Imprimir();			
				break;
			
			case 2:					
				this->plantilla.Agregar_Medico();
				break;
				
			case 3:	
							
				this->plantilla.Agregar_Enfermera();
				break;
				
			case 4:					
			
				this->plantilla.Imprimir_Medico();
				break;	
				
			case 5:									
				
				this->plantilla.Imprimir_Enfermera();	
				break;	
							
			case 6:									
									
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|                        MEDICOS                    |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"\n";
				this->plantilla.Imprimir_Medico();
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|                      ENFERMERAS                   |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"\n";
				this->plantilla.Imprimir_Enfermera();
				break;
				
						
			case 7:									
				
				this->Buscar_Medico();
				break;
				
						
			case 8:									
				
				this->Buscar_Enfermera();	
				break;	
			
			default:			
				cout<<"Adios!!!"<<endl;
				break;					
		}		
		system("PAUSE");
		system("CLS");
	}
	while(opc < 9);
}

void Servicio::Buscar_Paciente(string buscar, int tipo_busqueda){
	
	int i = 0;
	char opc;
	
	while(i < this->camas_ocupadas){
				
		//Tipo 1 es para buscar por nombre
		if(tipo_busqueda == 1){
			
			if(this->pacientes[i].nombre == buscar){
											
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|               PACIENTE ENCONTRADO                 |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;	
				cout<<"| NOMBRE: "<<this->pacientes[i].nombre<<setw(53 - (10 + this->pacientes[i].nombre.length()))<<"|"<<endl;
				cout<<"| EDAD: "<<this->pacientes[i].edad<<setw(53 - (7 + 2))<<"|"<<endl;			
				cout<<"| NUM SEGURO: "<<this->pacientes[i].num_seguro<<setw(53 - (14 + this->pacientes[i].num_seguro.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"| ESPECIALIDAD: "<<this->pacientes[i].sub_esp<<setw(53 - (16 + this->pacientes[i].sub_esp.length()))<<"|"<<endl;
				cout<<"| SERVICIO: "<<this->nombre<<setw(53 - (12 + this->nombre.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
								
				cout<<"DESEA HACER ALGO CON ESTE PACIENTE [s/n]"<<endl;
				cin>>opc;
				
				if(opc == 's')				
					this->Menu_Opciones_Busqueda(this->pacientes[i], i);
											
			}
		}
		//Tipo 2 es para buscar por num seguro
		else if(tipo_busqueda == 2){
			
			if(this->pacientes[i].num_seguro == buscar){
				
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|               PACIENTE ENCONTRADO                 |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;	
				cout<<"| NOMBRE: "<<this->pacientes[i].nombre<<setw(53 - (10 + this->pacientes[i].nombre.length()))<<"|"<<endl;
				cout<<"| EDAD: "<<this->pacientes[i].edad<<setw(53 - (7 + 2))<<"|"<<endl;			
				cout<<"| NUM SEGURO: "<<this->pacientes[i].num_seguro<<setw(53 - (14 + this->pacientes[i].num_seguro.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"| ESPECIALIDAD: "<<this->pacientes[i].sub_esp<<setw(53 - (16 + this->pacientes[i].sub_esp.length()))<<"|"<<endl;
				cout<<"| SERVICIO: "<<this->nombre<<setw(53 - (12 + this->nombre.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
					
						
				cout<<"DESEA HACER ALGO CON ESTE PACIENTE [s/n]"<<endl;
				cin>>opc;
				
				if(opc == 's')				
					this->Menu_Opciones_Busqueda(this->pacientes[i], i);
											
			}
		}
		else{
			
			cout<<"Sin coincidencia"<<endl;
			
		}
		
		i++;
	}								
}

void Servicio::Menu_Opciones_Busqueda(Derechohabiente &actual_paciente, int index){
		
	int opc;		
		
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"|      OPCIONES DEL DERECHOHABIENTE           |"<<endl;			
		cout<<"+---------------------------------------------+"<<endl;
		cout<<"| Editar Info Personal                  [1]   |"<<endl;
		cout<<"| Dar de alta paciente                  [2]   |"<<endl;					
		cout<<"| Cancelar                              [3]   |"  <<endl;	
		cout<<"+---------------------------------------------+"<<endl;
		cin>>opc;
		
		system("CLS");
					
		switch(opc) {
		
			case 1: 												
				actual_paciente.Leer();				
				break;
			
			case 2:					
							
				this->Borrar(actual_paciente, index);
				break;
				
			default:			
											
				break;					
		}		
		system("PAUSE");
		system("CLS");
}

void Servicio::Borrar(Derechohabiente &actual_paciente, int index){

	
	Derechohabiente *new_pa = new Derechohabiente[this->camas_asignadas];
	
	int i = 0;
	int j = 0;
	
	while(i < this->camas_ocupadas){
		
		if(i != index){
			
			new_pa[j] = this->pacientes[i];
			j++;
			
		}
		i++;
		
	}	
	this->camas_ocupadas = this->camas_ocupadas - 1;			
	this->pacientes = new_pa;	
	
}

void Servicio::Buscar_Medico(){
	
	
	int opc;
	string buscar;
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|              BUSCAR MEDICO                  |"<<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| Buscar por Nombre                     [1]   |"<<endl;
	cout<<"| Buscar por Numero de Plaza            [2]   |"<<endl;
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
			
	int i = 0;	
	
	if(opc == 1){
		
		cout<<"Escriba el nombre del paciente"<<endl;
		fflush(stdin);	
		getline(cin, buscar);
		this->plantilla.Buscar_Medico(buscar, 1);
	}
	else{
		
		cout<<"Escriba el numero de plaza"<<endl;
		fflush(stdin);	
		getline(cin, buscar);
		this->plantilla.Buscar_Medico(buscar, 2);
	}
			
	
}

void Servicio::Buscar_Enfermera() {
	
	
	int opc;
	string buscar;
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|              BUSCAR ENFERMERA                  |"<<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| Buscar por Nombre                     [1]   |"<<endl;
	cout<<"| Buscar por Numero de Plaza            [2]   |"<<endl;
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
			
	int i = 0;	
	
	if(opc == 1){
		
		cout<<"Escriba el nombre del paciente"<<endl;
		fflush(stdin);	
		getline(cin, buscar);
		this->plantilla.Buscar_Enfermera(buscar, 1);
	}
	else{
		
		cout<<"Escriba el numero de plaza"<<endl;
		fflush(stdin);	
		getline(cin, buscar);
		this->plantilla.Buscar_Enfermera(buscar, 2);
	}
			
	
}

Servicio::~Servicio(){
			
	//cout<<"Eliminamos el servico"<<endl;
}


#endif

