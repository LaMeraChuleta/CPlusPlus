#include <iostream>
using namespace std;


class Nodo{
	
	private:
    	int dato;
    	Nodo *sigNodo;
    	
	public:
	    Nodo(){ 
		sigNodo = NULL;   
			dato=0;        
    	}
    	Nodo(int x){ 
			sigNodo = NULL;
			dato=x;        
    	}
    	void asigna_sig(Nodo *newNodo){
    		this->sigNodo = newNodo;
		}
		Nodo* obtener_sig(){
			return (this->sigNodo);
		}
		int obtener_dato(){
			return (this->dato);
		}
		void imprimir(){
			
			cout<<this->dato<<endl;
		}
	
};



class Cola{    
	private:
		
		Nodo *Inicio;
		Nodo *Fin;
						    
	public:
    	void meter(int);
    	void sacar();
    	void Imprimir();
    	int Primero();
    	int esvacia();
    	void vaciar();
    	int contar();
    	Cola(){
    		Inicio = NULL;
    		Fin = NULL;
    	}
    
};

void Cola::meter(int x){
	
	if(Inicio == NULL){
		cout<<"Sin Datos"<<endl;
		Inicio = new Nodo(x);
	}
	else{				
			Nodo *help = Inicio;		
																														
			//Solo termina el ciclo cuando el siguiente es null
			while(help->obtener_sig() != NULL){																				
				help = help->obtener_sig();					
			}								
				
			//help esta en el ultimo elemento de la lista						
			Nodo *datoNuevo = new Nodo(x);	
			help->asigna_sig(datoNuevo);	
				
	}
}
void Cola::sacar(){
	
		
	if(!Inicio){
		cout<<"Lista Vacia :c"<<endl;				
	}
	else{
				
		//Si solo tiene un elemento
		if(Inicio->obtener_sig() == NULL){
			delete Inicio;
			Inicio = NULL;
		}
		else{
					
			Nodo *help = Inicio;
			Inicio = Inicio->obtener_sig();
			help->asigna_sig(NULL);
			delete help;					
		}
	}
	
}
void Cola::Imprimir(){
	
	if(!Inicio){
				
		cout<<"Lista Vacio :("<<endl;
	}
	else{
				 
		Nodo *help = Inicio;
				
		while(help != NULL){
										
			help->imprimir();
			help = help->obtener_sig();					
		}
	}			
}
	

int Cola::Primero(){
	
	if(Inicio == NULL){
		
		cout<<"La Cola esta vacia!!"<<endl;
		return NULL;
	}
	else{
		
		return Inicio->obtener_dato();
	}
	
	
}
int Cola::esvacia(){
	
}
void Cola::vaciar(){
	
}
int Cola::contar(){
	
}


int main(int argc, const char * argv[]) {
    
    Cola A;
    int opc, dato;
    do{
        cout<<"1.- Meter"<<endl;
        cout<<"2.- Sacar"<<endl;
        cout<<"3.- Primero"<<endl;
        cout<<"4.- La cola esta vacia?"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Vaciar cola"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        system("CLS");
        
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.meter(dato);
                break;
            case 2:
                A.sacar();
                break;
            case 3:
                
                dato=A.Primero();                
                if(dato != NULL){
                	cout<<"El primer dato de la cola es:"<<dato<<endl;
				}                	
                break;
            case 4:
                dato=A.esvacia();
                if(dato==1)
                {
                    cout<<"cola vacia";
                }
                else
                    cout<<"Cola con elementos";
                break;
            case 5:
                dato=A.contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;     
            case 6:
                A.vaciar();
                break;
            case 7:
            	A.Imprimir();
            	break;            
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc<9);
    
    return 0;
}
