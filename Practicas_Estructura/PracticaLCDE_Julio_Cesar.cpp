#include <iostream>
#include <fstream>
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
    	void LeerFichero();
    	void LeerFicheroCifrado();
    	void CifrarFichero();
    	void DescifrarFichero();
    	void LimpiarLista();
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


void LCDE::DescifrarFichero(){

	
	ofstream f("C:/temporal/salida.txt" );
	
	LCDE Letra_May;
    LCDE Letra_Min;
	            
    for(int i = 65; i <= 90; i++){
    	
    	Letra_May.InsertarF(i);
	}
	for(int j = 97; j <= 122; j++){
    	
    	Letra_Min.InsertarF(j);
	}		
 	
 		 		 			
 		Nodo *aux = Inicio; 		 				 	 		
 		do {
		 	 			 		    			    			    				    		
			int letra = 0;
						
			if(aux->Obtienedato() >= 65 &&  aux->Obtienedato() < 91){
				
				Nodo *help = Letra_May.Buscar(aux->Obtienedato());								
																											
				int mayus = 1;
					
				while(mayus <= 5){
					
					help = help->obtiene_ant();
					mayus += 1;
				}
													
				letra = help->Obtienedato(); 															
			}
			else if(aux->Obtienedato() >= 97 && aux->Obtienedato() < 123){
				
				Nodo *help = Letra_Min.Buscar(aux->Obtienedato());																																				
				int mayus = 1;
						
				while(mayus <= 5){
					
					help = help->obtiene_ant();
					mayus += 1;
				}
								
				letra = help->Obtienedato(); 				
			}
			else{
				
				letra = aux->Obtienedato();
				
			}	
			
			aux = aux->Obtienesig();			
			cout<<(char)letra;																			
   		}
   		while(aux != Inicio);   
	
}

void LCDE::LimpiarLista(){
	
	
	if(Inicio == NULL){
		
		//cout<<"LISTA VACIA!!!"<<endl;
	}
	else{
		
		Nodo *aux = Inicio;
		
		int numElemt = this->Contar();		
		int i = 0;				
		do{
								
			this->BorrarF();
			i = i + 1;
		}
		while(i != numElemt);
				
	}
	
	
}

void LCDE::LeerFicheroCifrado(){
	
	
	this->LimpiarLista();
			                    
  	ifstream fe("C:/temporal/salida.txt"); 
	   		
    char parrafo[100];
    int bytes[100]; 
  	
  	while (!fe.eof()) {
    	   		
    	fe.getline(parrafo, 49, '\n');    		    	   		  		  
    	break;
	}	
	for(int i = 0; i < 100; i++){
    			    			    				
    	if(parrafo[i] ==  0){
    		
    		break;
		}
		else{								
					
    		bytes[i] = static_cast<unsigned char>(parrafo[i]);    			    		
    		this->InsertarF(bytes[i]);    				
    		//cout<<(char)bytes[i]<<endl;    							
		}
    }		    
  	fe.close();  
  	
  	this->Imprimir();
  	
	cout<<"\n";
  	
  	this->DescifrarFichero();
  	
  	cout<<"\n";  		   		
	  	
	
}

void LCDE::LeerFichero(){
	
	
	this->LimpiarLista();
		                    
  	ifstream fe("C:/temporal/archivo.txt"); 
	   		
    char parrafo[100];
    int bytes[100]; 
  	
  	while (!fe.eof()) {
    	   		
    	fe.getline(parrafo, 49, '\n');    		    	   		  		  
    	break;
	}	
	for(int i = 0; i < 100; i++){
    			    			    				
    	if(parrafo[i] ==  0){
    		
    		break;
		}
		else{								
					
    		bytes[i] = static_cast<unsigned char>(parrafo[i]);    			    		
    		this->InsertarF(bytes[i]);    				
    		//cout<<(char)bytes[i]<<endl;    							
		}
    }		
    
  	fe.close();  		
}

void LCDE::CifrarFichero(){
	
	ofstream f("C:/temporal/salida.txt" );
	
	LCDE Letra_May;
    LCDE Letra_Min;
        
    
    for(int i = 65; i <= 90; i++){
    	
    	Letra_May.InsertarF(i);
	}
	for(int j = 97; j <= 122; j++){
    	
    	Letra_Min.InsertarF(j);
	}
		
 	if(f.is_open()){
 		 		 			
 		Nodo *aux = Inicio;

 		do {
		 	 			 		    			    			    				    		
			int letra = 0;
						
			if(aux->Obtienedato() >= 65 &&  aux->Obtienedato() < 91){
				
				Nodo *help = Letra_May.Buscar(aux->Obtienedato());								
																											
				int mayus = 1;
					
				while(mayus <= 5){
					
					help = help->Obtienesig();
					mayus += 1;
				}
													
				letra = help->Obtienedato(); 															
			}
			else if(aux->Obtienedato() >= 97 && aux->Obtienedato() < 123){
				
				Nodo *help = Letra_Min.Buscar(aux->Obtienedato());																																				
				int mayus = 1;
						
				while(mayus <= 5){
					
					help = help->Obtienesig();
					mayus += 1;
				}
								
				letra = help->Obtienedato(); 				
			}
			else{
				
				letra = aux->Obtienedato();
				
			}	
			
			aux = aux->Obtienesig();			
			f<<(char)letra;																			
   		}
   		while(aux != Inicio);

	}
 	else{
 		cout<<"Error de apertura del archivo." << endl;	
	}
 	f.close();	
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
		
	cout<<(char)this->dato;		
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
int main() {

    LCDE A;
 
    int opc, dato;
    do{

        cout<<"1.- Leer Mensaje Sin Codificar"<<endl;
        cout<<"2.- Guardar Mensaje Cifrado"<<endl;
        cout<<"3.- Leer e Impirmir Mensaje Cifrado"<<endl;                       
        cout<<"4.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
            	system("CLS");
                A.LeerFichero();
                break;
            case 2:
            	system("CLS");                
				A.CifrarFichero();
                break;
            case 3:
            	system("CLS");
                A.LeerFicheroCifrado();
                break;	    
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc < 4);
    
    
    return 0;
}

