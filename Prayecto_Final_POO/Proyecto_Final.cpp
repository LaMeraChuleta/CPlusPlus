#include<iostream>
#include "MODULE_HOSPITAL.h"
#include "MODULE_SUB_ESPECIALIDAD.h"

using namespace std;


int main(){
	
		
	Hospital new_hospital("Centro Medico", "General", "Corazones", true, 100);
	
	new_hospital.Imprimir();
	
	Sub_Especialidad *sub_esp;
	
	sub_esp = new Sub_Especialidad[3];
		

	sub_esp[0].Imprimir();
	sub_esp[1].Imprimir();
	sub_esp[2].Imprimir();
	
	system("PAUSE");
			
		
	sub_esp = new Sub_Especialidad[2];
	
	
	sub_esp[0].Imprimir();
	sub_esp[1].Imprimir();
	sub_esp[100].Imprimir();
	
	
}
