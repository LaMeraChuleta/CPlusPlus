#include <iostream>

using namespace std;


//DEFINICION DE LA CLASE NODO

class Nodo{
private:
    int dato;
    Nodo *sig;
public:
    Nodo(){    
		dato=0;
        sig=NULL;
    }
    Nodo(int x){    
		dato=x;
        sig=NULL;
    }
    void Asignasig(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    int Obtienedato();
};

//DEFINICION DE LA CLASE LISTA CIRCULANTE SIMPLEMENTE ENLAZADA

class LCSE{    
	private:
    	Nodo *Inicio;
	public:
    	void InsertarI(int);
    	void InsertarF(int);
    	void Imprimir();
    	void BorrarI();
    	void BorrarF();
    	int Contar();
    	Nodo *Buscar(int);
    	void Borrar(int);
    	LCSE(){    			
        	Inicio=NULL;
    	} 	  	    
};


//DEFINICION DE LOS METODOS NODO

void Nodo::Asignasig(Nodo *x){
	
    this->sig=x;
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
int Nodo::Obtienedato(){
	
    return(this->dato);
}

//DEFINICON DE LOS METODOS LISTA CIRCULAR SIMPLEMENTE ENLAZADA

void LCSE::InsertarI(int x){
				
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Asignasig(Inicio);
	}
	else{
		
		Nodo *aux = Inicio;
		
		do{
			
			aux = aux->Obtienesig();			
		}
		//SI SON IGUALES SIGNIFICA QUE ES EL ULTIMO ELEMETO ED LA LISTA
		while(aux->Obtienesig() != Inicio);
		
		Nodo *self = new Nodo(x);
		aux->Asignasig(self);
		self->Asignasig(Inicio);
		Inicio = self;																
	}
}
void LCSE::InsertarF(int x){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Asignasig(Inicio);							
	}
	else{
		
		Nodo *aux = Inicio;
		
		do{
			
			aux = aux->Obtienesig();			
		}
		while(aux->Obtienesig() != Inicio);
		
		Nodo *self = new Nodo(x);
		aux->Asignasig(self);
		self->Asignasig(Inicio);
	}
	
}

void LCSE::Imprimir(){
				
	if(Inicio == NULL){
		
		cout<<"LISTA VACIA!!!"<<endl;
	}
	else{
		
		Nodo *aux = Inicio;						
		
		do{
			
			aux->Imprimir();
			aux = aux->Obtienesig();						
		}
		while(aux != Inicio);
	}
}

void LCSE::BorrarI(){
	
	if(Inicio == NULL){
		
		cout<<"LISTA VACIO :( !!!"<<endl;
	}
	else{
		
		if(Inicio->Obtienesig() == Inicio){
											
			Inicio->Asignasig(NULL);
			delete Inicio;
			Inicio = NULL;			
		}
		else{
			
			Nodo *aux = Inicio;
			
			do{
				
				aux = aux->Obtienesig();				
			}
			while(aux->Obtienesig() != Inicio);
			aux->Asignasig(Inicio->Obtienesig());
			Inicio->Asignasig(NULL);
			delete Inicio;
			Inicio = aux->Obtienesig();			
		}		
	}
	
}
void LCSE::BorrarF(){
	
	if(Inicio == NULL){
		
		cout<<"LISTA VACIA :(  !!!"<<endl;
	}
	else{
									
		if(Inicio->Obtienesig() == Inicio){
			
			Inicio->Asignasig(NULL);
			delete Inicio;
			Inicio = NULL;			
		}
		else{
			
			Nodo *aux = Inicio;
			Nodo *help = NULL;
			
			do{
				
				help = aux;
				aux = aux->Obtienesig();								
			}
			while(aux->Obtienesig() != Inicio);
						
			help->Asignasig(aux->Obtienesig());
			aux->Asignasig(NULL);
			delete aux;						
		}
	}	
}
int LCSE::Contar(){
	
	if(Inicio == NULL){
					
		return 0;		
	}
	else{
		
		Nodo *aux = Inicio;
		int conteo = 0;
				
		do{
			
			conteo += 1;	
			aux = aux->Obtienesig();
		}
		while(aux != Inicio);
		
		return conteo;
	}
	
}
Nodo* LCSE::Buscar(int x){
	
	if(Inicio == NULL){
		
		cout<<"LISTA VACIA :( !!!"<<endl;
		return NULL;
	}
	else{
		
		Nodo *aux = Inicio;
		
		do{
											
			if(aux->Obtienedato() == x){
				
				return aux;
			}
			aux = aux->Obtienesig();
		}
		while(aux != Inicio);							
	}
	return NULL;
	
	
}
void LCSE::Borrar(int x){
	
	
	
	if(Inicio == NULL){
		
		cout<<"LISTA VACIA :( !!!"<<endl;
	}
	else{
		
		Nodo *query = Buscar(x);	
		
		if(query == NULL){
			
			cout<<"Ninguno coincide"<<endl;
		}
		else{
		
			Nodo *aux = Inicio;
			Nodo *preFinal = NULL;
	
			if(query == aux){
		
				BorrarI();
			}
			else{
			
				do{
				
					aux = aux->Obtienesig();
					preFinal = aux->Obtienesig();
				}
				while(preFinal != query);
			
				aux->Imprimir();
				preFinal->Imprimir();
			
				if(preFinal->Obtienesig() == Inicio){
				
					BorrarF();
				}
				else{
				
					aux->Asignasig(preFinal->Obtienesig());
					preFinal->Asignasig(NULL);
					delete preFinal;								
				}		
			}
		}
	}	
}



int main(int argc, const char * argv[]) {
    
    LCSE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"9.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
            	system("CLS");
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                break;
            case 2:
            	system("CLS");
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
            	system("CLS");
                A.BorrarI();
                break;
            case 4:
            	system("CLS");
                A.BorrarF();
                break;
            case 5:
            	system("CLS");
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
            	system("CLS");
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                A.Borrar(dato);               	
                break;
            case 7:
            	system("CLS");
                A.Imprimir();
                break;
            default:
            	system("CLS");
                cout<<"opción salir...";
                break;
        }
    }while(opc<8);
    
    return 0;
}
