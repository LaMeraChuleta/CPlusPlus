#include <iostream>
using namespace std;

class Nodo
{
private:
    int dato;
    Nodo *sig;
    Nodo *ant;
public:
    Nodo(){    
		dato=0;
        sig=NULL;
        ant=NULL;
    }
    Nodo(int x){    
		dato=x;
        sig=NULL;
        ant=NULL;
    }
    void Asignasig(Nodo*);
    void Asignaant(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    Nodo *Obtieneant();
    int Obtienedato();
    ~Nodo(){
    	delete sig;
    	delete ant;
	}
};
class LDE{    
	private:
    Nodo *Inicio;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    void Imprimir();
    void ImprimirR();
    int Contar();
    Nodo *Buscar(int);
    void Borrar(int);
    LDE(){
    	
        Inicio = NULL;    
    }
    ~LDE(){
    	
    	delete Inicio;
	}
    
};
//Metodos de la clase Nodo
void Nodo::Asignasig(Nodo *x){
    this->sig=x;
}
void Nodo::Asignaant(Nodo *x){
    this->ant=x;
}
void Nodo::Leer(int x){
    this->dato=x;
}
void Nodo::Imprimir(){
	cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig(){
    return(this->sig);
}
Nodo* Nodo::Obtieneant(){
    return(this->ant);
}
int Nodo::Obtienedato(){
    return(this->dato);
}

//Metodo de la clase LDE
Nodo* LDE::Buscar(int x){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia :("<<endl;
		return NULL;		
	}
	else{
		
		Nodo *help = Inicio;				
	
		while(help != NULL){
										
			if(help->Obtienedato() == x){
				return help;
			}
			help = help->Obtienesig();					
		}
		return NULL;
	}			
}

void LDE::Borrar(int x){
			
	if(Inicio == NULL){		
	
		cout<<"Lista vacia :("<<endl;		
	}
	else{
												
		if(this->Buscar(x) != NULL){
	
			Nodo *aux = Inicio;	
			while(aux->Obtienesig() != NULL){
						
				if(aux->Obtienedato() == x){				
					break;
				}
				aux = aux->Obtienesig();
			}			
			
			if(aux->Obtieneant() == NULL){
				
				this->BorrarI();
			}
			else if(aux->Obtienesig() == NULL){
				
				this->BorrarF();
			}
			else{
						
				Nodo *help = aux->Obtieneant();
				help->Asignasig(aux->Obtienesig());
			
				aux->Asignasig(NULL);
			
				help = help->Obtienesig();
				help->Asignaant(aux->Obtieneant());			
				aux->Asignaant(NULL);
				delete aux;	
			}	
		}
		else{
			cout<<"No existe ese numero en la lista!!"<<endl;
		}
	}	
}
void LDE::InsertarI(int x){
			
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Imprimir();		
	}	
	else{	
				
		Nodo *newNodo = new Nodo(x);				
		Nodo *aux = Inicio;
		Inicio = newNodo;
		Inicio->Asignasig(aux);
		aux->Asignaant(Inicio);																		
	}
}
void LDE::InsertarF(int x){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Imprimir();		
	}	
	else{	
				
		Nodo *newNodo = new Nodo(x);				
		
		Nodo *aux = Inicio;
		
		while(aux->Obtienesig() != NULL){
			
			aux = aux->Obtienesig();
		}	
		aux->Imprimir();								
		newNodo->Asignaant(aux);
		aux->Asignasig(newNodo);

	}
	
}
void LDE::BorrarI(){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia :("<<endl;
	}
	else{
		
		if(Inicio->Obtienesig() == NULL){
			
			Inicio = NULL;
		}
		else{
			
			Nodo *aux = Inicio->Obtienesig();									
			aux->Asignaant(NULL);
			Inicio->Asignasig(NULL);
			delete Inicio;			
			Inicio = aux;									
		}				
	}
}
void LDE::BorrarF(){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia :("<<endl;
	}
	else{
		
		if(Inicio->Obtienesig() == NULL){
			
			Inicio = NULL;
		}
		else{		
			
			Nodo *aux = Inicio;
			
			while(aux->Obtienesig() != NULL){
			
				
				aux = aux->Obtienesig();
			}			
			aux = aux->Obtieneant();
						
			Nodo *help = aux->Obtienesig();
			
			aux->Asignasig(NULL);
			help->Asignaant(NULL);
			
			delete help;			
		}				
	}		
}
void LDE::Imprimir(){
	
	if(Inicio == NULL){
				
		cout<<"Lista Vacio :("<<endl;
	}
	else{				 
	Nodo *help = Inicio;				
	
	while(help != NULL){
										
			help->Imprimir();
			help = help->Obtienesig();					
		}
	}
}
void LDE::ImprimirR(){
	
	if(Inicio == NULL){
				
		cout<<"Lista Vacio :("<<endl;
	}
	else{				 
		Nodo *help = Inicio;				
	
		while(help->Obtienesig() != NULL){
													
			help = help->Obtienesig();								
		}
		while(help != NULL){
											
			help->Imprimir();		
			help = help->Obtieneant();								
		}					
	}	
}
int LDE::Contar(){
	
	if(Inicio == NULL){
				
		cout<<"Lista Vacio :("<<endl;
		return 0;
	}
	else{				 
		Nodo *help = Inicio;
		int contador = 1;				
	
		while(help->Obtienesig() != NULL){
									
			contador++;																			
			help = help->Obtienesig();								
		}
		return contador;				
	}		
}

int main(int argc, const char * argv[]){
            
    LDE A = LDE();
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Imprimir en Reversa"<<endl;
        cout<<"9.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc; 
		
		system("cls");               
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                system("cls");
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
                A.BorrarI();
                break;
            case 4:
                A.BorrarF();
                break;
            case 5:
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                system("cls");
                A.Borrar(dato);
                break;      
            case 7:
                A.Imprimir();
                break;       
            case 8:
                A.ImprimirR();
                break;             
            default:
                cout<<"opción salir...";
                break;
        }
        
        
        
    }while(opc<9);
    
    return 0;
}
