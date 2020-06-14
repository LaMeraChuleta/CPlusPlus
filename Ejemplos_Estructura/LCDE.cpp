#include <iostream>

using namespace std;


//INICIO DE LA CLASE NODO

class Nodo
{
private:
    int dato;
    Nodo *sig;
    Nodo *ant;
public:
    Nodo(){    		
		dato = 0;
        sig = NULL;
        //Atributo Mio!!
        ant = NULL;
    }
    Nodo(int x){    
		dato = x;
        sig = NULL;
        ant = NULL;
    }
    void Asignasig(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    int Obtienedato();
    //Metodos Mios!!
    Nodo *obtiene_ant();
    void asigna_ant(Nodo*);
};

//INICIO DE LA CLASE LISTA CIRCULAR DOBLEMENTE ENLAZADA

class LCDE {

	private:
    	Nodo *Inicio;
    	
	public:
    	void InsertarI(int);
    	void InsertarF(int);
    	void Imprimir();
    	void ImprimirR();
    	void BorrarI();
    	void BorrarF();
    	int Contar();
    	Nodo *Buscar(int);
    	void Borrar(int);
    	LCDE(){
    		
    		Inicio=NULL;	
		}                
};


//METODOS DE LA CLASE LISTA CIRCULAR DOBLEMENTE ENLAZADA

void LCDE::Imprimir(){
	
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
void LCDE::ImprimirR(){
	
	if(Inicio == NULL){
		
		cout<<"LISTA VACIA!!!"<<endl;
	}
	else{
				
		Nodo *aux = Inicio->obtiene_ant();
		
		do{
									
			aux->Imprimir();
			aux = aux->obtiene_ant();
		}
		while(aux != Inicio->obtiene_ant());		
	}
}

void LCDE::InsertarF(int x){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Asignasig(Inicio);
		Inicio->asigna_ant(Inicio);
		
	}
	else{
				
		Nodo *newNodo = new Nodo(x);			
		Nodo *aux = Inicio;
			
		newNodo->Asignasig(aux);
		newNodo->asigna_ant(aux->obtiene_ant());
			
		aux->asigna_ant(newNodo);			
		aux = newNodo->obtiene_ant();
					
		aux->Asignasig(newNodo);										
	}	
}

void LCDE::InsertarI(int x) {
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Asignasig(Inicio);
		Inicio->asigna_ant(Inicio);		
	}
	else{		
	
		Nodo *newNodo = new Nodo(x);
		Nodo *aux = Inicio;
				
		newNodo->Asignasig(aux);
		newNodo->asigna_ant(aux->obtiene_ant());
			
		aux->asigna_ant(newNodo);			
		aux = newNodo->obtiene_ant();
		aux->Asignasig(newNodo);
			
		Inicio = newNodo;												
	}
	
}
void LCDE::BorrarI(){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia."<<endl;
	}
	else{
		
		if(this->Contar() == 1){
			
			Nodo *aux = Inicio;			
			aux->Asignasig(NULL);
			aux->asigna_ant(NULL);						
			delete Inicio;			
			Inicio = NULL;
		}
		else{
			
			Nodo *aux = Inicio->obtiene_ant();
			Nodo *help = Inicio;						
			aux->Asignasig(help->Obtienesig());			
			aux = aux->Obtienesig();			
			aux->asigna_ant(help->obtiene_ant());			
			help->asigna_ant(NULL);
			help->Asignasig(NULL);			
			Inicio = aux;			
			delete help;			
		}		
	}	
}
void LCDE::BorrarF(){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia."<<endl;
	}
	else{
		
		if(this->Contar() == 1){
			
			Nodo *aux = Inicio;
			
			aux->Asignasig(NULL);
			aux->asigna_ant(NULL);						
			delete Inicio;			
			Inicio = NULL;
		}
		else{
			
			Nodo *aux = Inicio->obtiene_ant();
			Nodo *help = aux->obtiene_ant();						
	
			help->Asignasig(aux->Obtienesig());
			
			Inicio->asigna_ant(aux->obtiene_ant());
			
			aux->Asignasig(NULL);
			aux->asigna_ant(NULL);
			
			delete aux;												
		}		
	}	
}
int LCDE::Contar(){
	
	if(Inicio == NULL){
			
		return 0;
	}
	else{
				
		Nodo *aux = Inicio->obtiene_ant();
		int conteo = 0;				
		do{	
		
			conteo += 1;											
			aux = aux->obtiene_ant();
		}
		while(aux != Inicio->obtiene_ant());		
		
		return conteo;
	}
}
Nodo* LCDE::Buscar(int x){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia"<<endl;
		
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
		
		cout<<"No se encontro ese dato"<<endl;
		return NULL;
	}
	
}
void LCDE::Borrar(int x){
	
	if(Inicio == NULL){
			
		cout<<"Lista vacia"<<endl;		
	}
	else{
		
						
		Nodo *query = this->Buscar(x);
		
		if(query != NULL){
			
			
			if(query->Obtienesig() == Inicio){
				
				this->BorrarF();
			}
			else if(query == Inicio){
				
				this->BorrarI();
			}
			else{
				
				Nodo *aux = query->obtiene_ant();
				
				aux->Asignasig(query->Obtienesig());
				
				aux = aux->Obtienesig();
				
				aux->asigna_ant(query->obtiene_ant());
				
				query->Asignasig(NULL);
				query->asigna_ant(NULL);
				
				delete query;
				
				
			}
								
		}	
	}		
}



//METODOS DE LA CLASE NODO
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
Nodo* Nodo::obtiene_ant(){	
	return(this->ant);	
}
void Nodo::asigna_ant(Nodo *x){
	this->ant = x;
}





//FUNCION MAIN
int main(int argc, const char * argv[]) {
    
    LCDE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Imprimir R"<<endl;
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
            case 8:
            	system("CLS");
                A.ImprimirR();
                break;
                
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc<9);
    
    return 0;
}

