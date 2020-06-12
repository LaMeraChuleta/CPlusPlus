#include <iostream>
#include <string.h>

using namespace std;

//DECLARACION DE LA CLASE NODO

class Nodo{
	
	private:
    	char * Nombre;
    	Nodo *sig;
    	
	public:
    	Nodo(){    
			Nombre=NULL;
        	sig=NULL;
    	}
    	Nodo(char *N){    		
        	Nombre=new char(strlen(N)+1);
        	strcpy(Nombre,N);
        	sig=NULL;
    	}
    	void Asignasig(Nodo*);
    	void Leer(char *);
    	void Imprimir();
    	Nodo *Obtienesig();
    	char * ObtieneNombre();
};

//METODOS DE LA CLASE NODO

void Nodo::Asignasig(Nodo *newNodo){
	
	this->sig= newNodo;
}
void Nodo::Leer(char *nombre){
	
	Nombre = new char(strlen(nombre) + 1);
	strcpy(Nombre, nombre);
}
void Nodo::Imprimir(){
	
	cout<<this->Nombre<<endl;
}
Nodo* Nodo::Obtienesig(){
	
	return(this->sig);
}
char* Nodo::ObtieneNombre(){
	
	return(this->Nombre);
}



//DECLARACION DE LA CLASE LISTA CIRCULAR SIMPLEMTE ENLAZADA

class LCSE{    

	private:
    	Nodo *Inicio;
    	
	public:
    	void InsertarI(char *);
    	void InsertarF(char *);
    	void Inicializar();
    	void Imprimir();
    	void Jugar();
    	void BorrarI();
    	void BorrarF();
    	int Contar();
    	Nodo *Buscar(char *);
    	void Borrar(char *);    	
    	LCSE(){ Inicio=NULL; }
    
};


//DECLARACION DE LOS METODOS DE LA LISTA CIRCULAR SIMPLEMTE ENLAZADA
void LCSE::InsertarI(char* nombre){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(nombre);
		Inicio->Asignasig(Inicio);
	}
	else{
		
		Nodo *aux = Inicio;
						
		do{
			
			aux = aux->Obtienesig();			
		}
		//SI SON IGUALES SIGNIFICA QUE ES EL ULTIMO ELEMETO ED LA LISTA
		while(aux->Obtienesig() != Inicio);
		
		Nodo *self = new Nodo(nombre);
		aux->Asignasig(self);
		self->Asignasig(Inicio);
		Inicio = self;				
	}
		
}
void LCSE::Inicializar(){
	
	
    int numJugadores = 0;        
    cout<<"Imgrese el Numero de Jugadores!!"<<endl;
    cin>>numJugadores;    
        
    for(int i = 1; i <= numJugadores; i++) {
    	
    	cin.ignore();
    	//string name("");
    	char nombre[50];
    	cout<<"Ingrese el nombre del Jugador: "<<i<<endl;
    	//getline(cin, name);
    	cin.getline(nombre, 50);
    	//char* nombre = const_cast<char*>(name.c_str();    	
    	this->InsertarF(nombre);    	
	}
	system("CLS");		
}
void LCSE::InsertarF(char* nombre){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(nombre);
		Inicio->Asignasig(Inicio);							
	}
	else{
		
		Nodo *aux = Inicio;
		
		do{
			
			aux = aux->Obtienesig();			
		}
		while(aux->Obtienesig() != Inicio);
		
		Nodo *self = new Nodo(nombre);
		aux->Asignasig(self);
		self->Asignasig(Inicio);
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
//void LCSE

int main(int argc, const char * argv[]) {
    
	           
	LCSE A;	
    int opc, dato;
    do{                
        cout<<"1.- Inicializar"<<endl;                
        cout<<"2.- Jugar 18"<<endl;
        cout<<"3.- Contar"<<endl;        
        cout<<"4.- Imprimir"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
            	system("CLS");                                
                A.Inicializar();
                break;
            case 2:
            	system("CLS");                                            
                break;
            case 3:
            	system("CLS");
                A.Contar();
                break;
            case 4:
            	system("CLS");
                A.Imprimir();
                break;
            default:
            	system("CLS");
                cout<<"opción salir...";
                break;
        }
    }while(opc<5);
        
                
    return 0;
}


