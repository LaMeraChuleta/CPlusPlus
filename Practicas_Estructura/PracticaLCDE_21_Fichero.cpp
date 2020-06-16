#include <iostream>
#include <string.h>

using namespace std;

class Nodo{
	
	private:
		
    	char *Nombre;
    	int Edad;
    	Nodo *sig;
    	Nodo *ant;
    	
	public:
		
    	Nodo(){   
			Edad=0;
        	Nombre=NULL;
        	sig=NULL;
        	ant=NULL;
    	}
    	Nodo(char * N, int E)
    	{
        	Nombre=new char [strlen(N)+1];
        	strcpy(Nombre,N);
        	Edad=E;
        	sig=NULL;
        	ant=NULL;
    	}
    	void Asignasig(Nodo*);
    	void Asignaant(Nodo *);    	
    	void Imprimir();
    	Nodo *Obtienesig();
    	Nodo *Obtieneant();
    	int ObtieneEdad();
    	char* ObtieneNombre();
};

class LCDE{    

	private:
		
    	Nodo *Inicio;
    	
	public:
		
    	void InsertarI(char *nombre, int edad);
    	void InsertarF(char *nombre, int edad);
    	void Imprimir();
    	void ImprimirR();
    	void BorrarI();
    	void BorrarF();
		void Inicializar();
		void Jugar();
    	int Contar();
    	Nodo *Buscar(char*);
    	void Borrar(char*);
    	LCDE(){
    		
    		Inicio=NULL;	
		}  
};


//METODOS DE LA CLASE LISTA CIRCULAR DOBLEMENTE ENLAZADA

void LCDE::Jugar(){
	
	if(Inicio == NULL){
		
		cout<<"Primero agregar los jugadores"<<endl;
	}
	else{
				
		Nodo *aux = Inicio;		
		int iter = 0;		
		int edad_actual = 21;
		
		//True == ir hacia adelante
		bool sig_ant = true;
								
		do{
			
			iter += 1; 
				
			if(iter == edad_actual){
				
				if(this->Contar() == 1){
						
					cout<<"El perdedor es: "<<aux->ObtieneNombre()<<endl;
					iter = edad_actual;
				}
				else{
					
					aux->Imprimir();					
					system("PAUSE");
					
					Nodo *help = aux;
					
					sig_ant = sig_ant == true ? false : true;
					edad_actual = aux->ObtieneEdad();						
					
					if(sig_ant){						
						aux = aux->Obtienesig();
						
					}
					else{						
						aux = aux->Obtieneant();						
					}
					
					//El que queremos borrar es help!!!
					
					Nodo *other_help = help->Obtieneant();
					
					other_help->Asignasig(help->Obtienesig());					
					other_help = other_help->Obtienesig();					
					other_help->Asignaant(help->Obtieneant());
										
					help->Asignaant(NULL);
					help->Asignasig(NULL);
					
					Inicio = aux;
					
					delete help;																							
					iter = 0;																							
				}
			}
			else{
				
				if(sig_ant){
					aux = aux->Obtienesig();
				}
				else{
					aux = aux->Obtieneant();
				}				
			}																							
		}
		while(iter != edad_actual);						
	}		
}

void LCDE::InsertarI(char *nombre, int edad) {
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(nombre, edad);
		Inicio->Asignasig(Inicio);
		Inicio->Asignaant(Inicio);		
	}
	else{		
	
		Nodo *newNodo = new Nodo(nombre, edad);
		Nodo *aux = Inicio;
				
		newNodo->Asignasig(aux);
		newNodo->Asignaant(aux->Obtieneant());
			
		aux->Asignaant(newNodo);			
		aux = newNodo->Obtieneant();
		aux->Asignasig(newNodo);
			
		Inicio = newNodo;												
	}
	
}

void LCDE::InsertarF(char *nombre, int edad){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(nombre, edad);
		Inicio->Asignasig(Inicio);
		Inicio->Asignaant(Inicio);
		
	}
	else{
				
		Nodo *newNodo = new Nodo(nombre, edad);			
		Nodo *aux = Inicio;
			
		newNodo->Asignasig(aux);
		newNodo->Asignaant(aux->Obtieneant());
			
		aux->Asignaant(newNodo);			
		aux = newNodo->Obtieneant();
					
		aux->Asignasig(newNodo);										
	}	
}


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
				
		Nodo *aux = Inicio->Obtieneant();
		
		do{
									
			aux->Imprimir();
			aux = aux->Obtieneant();
		}
		while(aux != Inicio->Obtieneant());		
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
			aux->Asignaant(NULL);						
			delete Inicio;			
			Inicio = NULL;
		}
		else{
			
			Nodo *aux = Inicio->Obtieneant();
			Nodo *help = Inicio;						
			aux->Asignasig(help->Obtienesig());			
			aux = aux->Obtienesig();			
			aux->Asignaant(help->Obtieneant());			
			help->Asignaant(NULL);
			help->Asignasig(NULL);			
			Inicio = aux;			
			delete help;			
		}		
	}	
}


void LCDE::Inicializar(){
	
	int numJugadores = 0;        
    cout<<"Imgrese el Numero de Jugadores!!"<<endl;
    cin>>numJugadores;   
	
	if(numJugadores <= 1) {
		
		cout<<"Debes de ser almenos 2 jugadores."<<endl;
	}
	else{
	        
    	for(int i = 1; i <= numJugadores; i++) {
    	
    		cin.ignore(); 
			   		
    		char nombre[50];
    		int edad = 0;
    		
    		cout<<"Ingrese el nombre del Jugador: "<<i<<endl;    	
    		cin.getline(nombre, 50);    		    		
			cout<<"Ingrese la edad del jugador: "<<i<<endl;   
			cin>>edad;  				
			
			this->InsertarF(nombre, edad);			
		}
		system("CLS");
	}
}

int LCDE::Contar(){
	
	if(Inicio == NULL){
			
		return 0;
	}
	else{
				
		Nodo *aux = Inicio->Obtieneant();
		int conteo = 0;				
		do{	
		
			conteo += 1;											
			aux = aux->Obtieneant();
		}
		while(aux != Inicio->Obtieneant());		
		
		return conteo;
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
			aux->Asignaant(NULL);						
			delete Inicio;			
			Inicio = NULL;
		}
		else{
			
			Nodo *aux = Inicio->Obtieneant();
			Nodo *help = aux->Obtieneant();						
	
			help->Asignasig(aux->Obtienesig());
			
			Inicio->Asignaant(aux->Obtieneant());
			
			aux->Asignasig(NULL);
			aux->Asignaant(NULL);
			
			delete aux;												
		}		
	}	
}


Nodo* LCDE::Buscar(char *nombre){
	
	if(Inicio == NULL){
		
		cout<<"Lista vacia"<<endl;
		
	}
	else{
		
		Nodo *aux = Inicio;
		
		do{
			
			if(aux->ObtieneNombre() == nombre){
				
				return aux;
			}
			
			aux = aux->Obtienesig();
		}
		while(aux != Inicio);		
		
		cout<<"No se encontro ese dato"<<endl;
		return NULL;
	}
	
}

void LCDE::Borrar(char *nombre){
	
	if(Inicio == NULL){
			
		cout<<"Lista vacia"<<endl;		
	}
	else{
		
						
		Nodo *query = this->Buscar(nombre);
		
		if(query != NULL){
			
			
			if(query->Obtienesig() == Inicio){
				
				this->BorrarF();
			}
			else if(query == Inicio){
				
				this->BorrarI();
			}
			else{
				
				Nodo *aux = query->Obtieneant();
				
				aux->Asignasig(query->Obtienesig());
				
				aux = aux->Obtienesig();
				
				aux->Asignaant(query->Obtieneant());
				
				query->Asignasig(NULL);
				query->Asignaant(NULL);
				
				delete query;
				
				
			}
								
		}	
	}		
}




//METODOS DE LA CLASE NODO

void Nodo::Imprimir(){	
    cout<<this->Nombre<<" tiene "<<this->Edad<<endl;
}
Nodo* Nodo::Obtienesig(){
	
    return(this->sig);
}
Nodo* Nodo::Obtieneant(){
	
	return(this->ant);	
}
int Nodo::ObtieneEdad(){
	
    return(this->Edad);
}
char* Nodo::ObtieneNombre(){
	
	return(this->Nombre);
}
void Nodo::Asignasig(Nodo *x){
	
	this->sig = x;
}
void Nodo::Asignaant(Nodo *x){
	this->ant = x;
}



int main(int argc, const char * argv[]) {
	
	  LCDE A;
    int opc, dato;
    do{
        cout<<"1.- Agregar Jugadores"<<endl;
        cout<<"2.- Jugar"<<endl;
        cout<<"3.- Contar"<<endl;
        cout<<"4.- Imprimir"<<endl;
        cout<<"5.- Imprimir R"<<endl;                        
        cout<<"6.- Salir"<<endl;
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
         		A.Jugar();
                break;
            case 3:
            	system("CLS");
                A.Contar();
                break;
            case 4:
            	system("CLS");
                A.Imprimir();
                break;
            case 5:
            	system("CLS");
				A.ImprimirR();
                break;                   
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc < 6);
    
    return 0;
    
}
