#ifndef  MODULE_PLANTILLA_H_
#define  MODULE_PLANTILLA_H_

#include<iostream>
#include<string>
#include<iomanip>
#include "MODULE_MEDICO.h"
#include "MODULE_ENFERMERA.h"
using namespace std;


class  Plantilla {

	
	private:	
				
		int num_medicos;
		int key_medico;
		int num_enfemeras;
		int key_enfermera;
		bool Ini_medico;
		bool Ini_enfermera;
		Medico *medicos;
		Enfermera *enfermeras;
		
								
	public:
			
		Plantilla(int num_medico = 0, int num_enfermera = 0){
							
			this->num_medicos = num_medico;
			this->num_enfemeras = num_enfermera;												
			this->key_medico = 0;
			this->key_enfermera = 0;			
			this->medicos = new Medico[num_medico];
			this->enfermeras = new Enfermera[num_enfermera];
	
		}
		~Plantilla();			
		void Agregar_Medico();		
		void Agregar_Enfermera();		
		void Imprimir_Medico();	
		void Imprimir_Enfermera();		
		void Buscar_Medico(string buscar, int tipo_busqueda);
		void Buscar_Enfermera(string buscar, int tipo_busqueda);
		
	private:		
																
		void Menu_Opciones_Medico(Medico &medico, int index);
		void Menu_Opciones_Enfermera(Enfermera &enfermera, int index);
		void Borrar_Medico(Medico &medico, int index);
		void Borrar_Enfermera(Enfermera &enfermera, int index);
};

void Plantilla::Agregar_Medico(){
				
		if(this->key_medico == this->num_medicos){
			
			cout<<"YA NO TENEMOS LUGAR"<<endl;
			
		}
		else{
			
			string nombre, plaza, descanso;
			int edad;
				
			cout<<"+---------------------------------------------------+"<<endl;
			cout<<"|           AGREGAR INFORMACION MEDICO              |"<<endl;
			cout<<"| LUGARES: "<<this->num_medicos - this->key_medico<<setw(54 - (11 + 2))<<"|"<<endl;
			cout<<"+---------------------------------------------------+"<<endl;
			
			cout<<"ESCRIBA EL NOMBRE"<<endl;
			fflush(stdin);	
			getline(cin, nombre);
		
			cout<<"ESCRIBA LA EDAD"<<endl;		
			cin>>edad;
		
			cout<<"ESCRIBA LA PLAZA"<<endl;
			fflush(stdin);	
			getline(cin, plaza);
		
			cout<<"ESCRIBA EL DESCANSO"<<endl;
			fflush(stdin);	
			getline(cin, descanso);
		
			this->medicos[this->key_medico] = Medico(nombre, edad, plaza, descanso);
			
			this->key_medico += 1;
		}								
}

void Plantilla::Agregar_Enfermera(){

			
		if(this->key_enfermera == this->num_enfemeras){
			
			cout<<"YA NO TENEMOS LUGAR"<<endl;
			
		}
		else{
			
			string nombre, plaza, descanso;
			int edad;
				
			cout<<"+---------------------------------------------------+"<<endl;
			cout<<"|           AGREGAR INFORMACION ENFERMERA           |"<<endl;
			cout<<"| LUGARES: "<<this->num_enfemeras - this->key_enfermera<<setw(54 - (11 + 2))<<"|"<<endl;
			cout<<"+---------------------------------------------------+"<<endl;
			
			cout<<"ESCRIBA EL NOMBRE"<<endl;
			fflush(stdin);	
			getline(cin, nombre);
		
			cout<<"ESCRIBA LA EDAD"<<endl;		
			cin>>edad;
		
			cout<<"ESCRIBA LA PLAZA"<<endl;
			fflush(stdin);	
			getline(cin, plaza);
		
			cout<<"ESCRIBA EL DESCANSO"<<endl;
			fflush(stdin);	
			getline(cin, descanso);
		
			this->enfermeras[this->key_enfermera] = Enfermera(nombre, edad, plaza, descanso);
			
			this->key_enfermera += 1;
		}	
}

void Plantilla::Imprimir_Medico(){
	
	int i = 0;
	
	while(i != this->key_medico){
		
		this->medicos[i].Imprimir();		
		i++;
	}
}
	
void Plantilla::Imprimir_Enfermera(){
	
	
	int i = 0;
	
	while(i != this->key_enfermera){
		
		this->enfermeras[i].Imprimir();		
		i++;
	}	
}

void Plantilla::Buscar_Medico(string buscar, int tipo_busqueda){
	
	int i = 0;
	char opc;
	
	while(i < this->key_medico){
		
		
		//Tipo 1 es para buscar por nombre
		if(tipo_busqueda == 1){
			
			if(this->medicos[i].nombre == buscar){
											
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|                 MEDICO ENCONTRADO                 |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;	
				cout<<"| NOMBRE: "<<this->medicos[i].nombre<<setw(53 - (10 + this->medicos[i].nombre.length()))<<"|"<<endl;
				cout<<"| EDAD: "<<this->medicos[i].edad<<setw(53 - (7 + 2))<<"|"<<endl;			
				cout<<"| NUM PLAZA: "<<this->medicos[i].num_plaza<<setw(53 - (13 + this->medicos[i].num_plaza.length()))<<"|"<<endl;
				cout<<"| DESCANSO: "<<this->medicos[i].descanso<<setw(53 - (12 + this->medicos[i].descanso.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
								
				cout<<"DESEA HACER ALGO CON ESTE PACIENTE [s/n]"<<endl;
				cin>>opc;
				
				if(opc == 's')				
					this->Menu_Opciones_Medico(this->medicos[i], i);
											
			}
		}
		//Tipo 2 es para buscar por numero plaza
		else if(tipo_busqueda == 2){
			
			if(this->medicos[i].num_plaza == buscar){
				
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|                 MEDICO ENCONTRADO                 |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;	
				cout<<"| NOMBRE: "<<this->medicos[i].nombre<<setw(53 - (10 + this->medicos[i].nombre.length()))<<"|"<<endl;
				cout<<"| EDAD: "<<this->medicos[i].edad<<setw(53 - (7 + 2))<<"|"<<endl;			
				cout<<"| NUM PLAZA: "<<this->medicos[i].num_plaza<<setw(53 - (13 + this->medicos[i].num_plaza.length()))<<"|"<<endl;
				cout<<"| DESCANSO: "<<this->medicos[i].descanso<<setw(53 - (12 + this->medicos[i].descanso.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;												
											
				cout<<"DESEA HACER ALGO CON ESTE PACIENTE [s/n]"<<endl;
				cin>>opc;
				
				if(opc == 's')				
					this->Menu_Opciones_Medico(this->medicos[i], i);
											
			}
		}
		else{			
			cout<<"Sin coincidencia"<<endl;			
		}		
		i++;
	}									
}

void Plantilla::Buscar_Enfermera(string buscar, int tipo_busqueda){
	
	int i = 0;
	char opc;
	
	while(i < this->key_enfermera){
		
		
		//Tipo 1 es para buscar por nombre
		if(tipo_busqueda == 1){
			
			if(this->enfermeras[i].nombre == buscar){
											
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|              ENFERMERA ENCONTRADO                 |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;	
				cout<<"| NOMBRE: "<<this->enfermeras[i].nombre<<setw(53 - (10 + this->enfermeras[i].nombre.length()))<<"|"<<endl;
				cout<<"| EDAD: "<<this->enfermeras[i].edad<<setw(53 - (7 + 2))<<"|"<<endl;			
				cout<<"| NUM PLAZA: "<<this->enfermeras[i].num_plaza<<setw(53 - (13 + this->enfermeras[i].num_plaza.length()))<<"|"<<endl;
				cout<<"| DESCANSO: "<<this->enfermeras[i].descanso<<setw(53 - (12 + this->enfermeras[i].descanso.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;
								
				cout<<"DESEA HACER ALGO CON ESTE PACIENTE [s/n]"<<endl;
				cin>>opc;
				
				if(opc == 's')				
					this->Menu_Opciones_Enfermera(this->enfermeras[i], i);
											
			}
		}
		//Tipo 2 es para buscar por numero plaza
		else if(tipo_busqueda == 2){
			
			if(this->enfermeras[i].num_plaza == buscar){
				
				cout<<"+---------------------------------------------------+"<<endl;
				cout<<"|              ENFERMERA ENCONTRADO                 |"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;	
				cout<<"| NOMBRE: "<<this->enfermeras[i].nombre<<setw(53 - (10 + this->enfermeras[i].nombre.length()))<<"|"<<endl;
				cout<<"| EDAD: "<<this->enfermeras[i].edad<<setw(53 - (7 + 2))<<"|"<<endl;			
				cout<<"| NUM PLAZA: "<<this->enfermeras[i].num_plaza<<setw(53 - (13 + this->enfermeras[i].num_plaza.length()))<<"|"<<endl;
				cout<<"| DESCANSO: "<<this->enfermeras[i].descanso<<setw(53 - (12 + this->enfermeras[i].descanso.length()))<<"|"<<endl;
				cout<<"+---------------------------------------------------+"<<endl;												
					
						
				cout<<"DESEA HACER ALGO CON ESTE PACIENTE [s/n]"<<endl;
				cin>>opc;
				
				if(opc == 's')				
					this->Menu_Opciones_Enfermera(this->enfermeras[i], i);
											
			}
		}
		else{			
			cout<<"Sin coincidencia"<<endl;			
		}
		
		i++;
	}		
}

void Plantilla::Menu_Opciones_Medico(Medico &medico, int index){
	
	int opc;		
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|           OPCIONES DEL MEDICO               |"<<endl;			
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| Editar Info Medico                    [1]   |"<<endl;
	cout<<"| Quitar de la Plantilla                [2]   |"<<endl;					
	cout<<"| Cancelar                              [3]   |"  <<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
		
	system("CLS");
					
	switch(opc) {
		
		case 1: 												
		
			medico.Leer();
			break;
			
		case 2:					
							
			this->Borrar_Medico(medico, index);
			break;
				
		default:			
											
			break;					
	}		
	system("PAUSE");
	system("CLS");
}

void Plantilla::Menu_Opciones_Enfermera(Enfermera &enfermera, int index){
	
	int opc;		
		
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"|           OPCIONES DE LA ENFERMERA          |"<<endl;			
	cout<<"+---------------------------------------------+"<<endl;
	cout<<"| Editar Info Enfermera                 [1]   |"<<endl;
	cout<<"| Quitar de la Plantilla                [2]   |"<<endl;					
	cout<<"| Cancelar                              [3]   |"  <<endl;	
	cout<<"+---------------------------------------------+"<<endl;
	cin>>opc;
		
	system("CLS");
					
	switch(opc) {
		
		case 1: 												
		
			enfermera.Leer();
			break;
			
		case 2:					
							
			this->Borrar_Enfermera(enfermera, index);
			break;
				
		default:			
											
			break;					
	}		
	system("PAUSE");
	system("CLS");
}

void Plantilla::Borrar_Medico(Medico &medico, int index){
		
	Medico *new_pa = new Medico[this->num_medicos];
	
	int i = 0;
	int j = 0;
	
	while(i < this->key_medico){
		
		if(i != index){
			
			new_pa[j] = this->medicos[i];
			j++;
			
		}
		i++;
		
	}	
	this->key_medico = this->key_medico - 1;			
	this->medicos = new_pa;	
}

void Plantilla::Borrar_Enfermera(Enfermera &enfermera, int index){
		
	Enfermera *new_pa = new Enfermera[this->num_medicos];
	
	int i = 0;
	int j = 0;
	
	while(i < this->key_enfermera){
		
		if(i != index){
			
			new_pa[j] = this->enfermeras[i];
			j++;
			
		}
		i++;
		
	}	
	this->key_enfermera = this->key_enfermera - 1;			
	this->enfermeras = new_pa;	
	
}

Plantilla::~Plantilla(){
			
	//cout<<"Se elimino la platilla"<<endl;
}

#endif
