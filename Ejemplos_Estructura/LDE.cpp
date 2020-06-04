
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
		system("cls");
		cout<<"Sali del while"<<endl;
		aux->Imprimir();
		if(aux->Obtienesig() == NULL){
			cout<<"EL siguiente es null"<<endl;
		}				
		newNodo->Asignaant(aux);
		aux->Asignasig(newNodo);				
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








int main(int argc, const char * argv[])
{
    
    
    
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
            case 7:
                A.Imprimir();
                break;
                
        /*          
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
                A.Borrar(dato);
                break;
                */
        
                /*
            case 8:
                A.ImprimirR();
                break;
                */                
            default:
                cout<<"opción salir...";
                break;
        }
        
        //system("cls");
        
    }while(opc<9);
    
    return 0;
}
