#include<iostream>
#include<string>
#include "MODULE_HOSPITAL.h"

using namespace std;


int main(){

	string nombre, zona;
	
	cout<<"ESCRIBA EL NOMBRE DE SU HOSPITAL"<<endl;
	fflush(stdin);	
	getline(cin, nombre);
			
	cout<<"ESCRIBA LA ZONA O UBICACION DEL HOSPITAL"<<endl;
	fflush(stdin);	
	getline(cin, zona);
												
	Hospital new_hospital(nombre, zona, true);	
	new_hospital.Menu_Hospital();
				
}
