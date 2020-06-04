#include <iostream>

using namespace std;


class Nodo{

	private:
		int dato;
		Nodo *Sig;	
	public:
	
		Nodo(){
			dato = 0; 
			Sig = NULL;
		}
		Nodo(int x){
			dato = x;
			Sig = NULL;
		}
		void AsignaSig(Nodo *newNodo){
			this->Sig = newNodo;
		}
		void Leer(int x){
			this->dato = x;
		}
		void Imprimir(){
			cout<<this->dato<<endl;
		}
		Nodo* ObtenerSig(){
			
			return (this->Sig);
		}
		int ObtenerDato(){
    		return (this->dato);
		}
		void imprime_direccion(){
			//cout<<"El Valor del nodo es:"<<this->Sig<<endl;
			cout<<"La Direccion Clase nodo del dato:"<<&this->Sig<<endl;
			cout<<"El Valor del dato es:"<<this->dato<<endl;
			cout<<"EL la direccion del dato es:"<<&this->dato<<endl;
			
		}		
};

class LSE{
	private:
		Nodo *Inicio;
	public:
		LSE(){
			Inicio = NULL;
		}
		void InsertarInicio(int x){
			
			if(!Inicio){
				
				Inicio = new Nodo(x);
			}			
			else{
				
				Nodo *help = new Nodo(x);
				help->AsignaSig(Inicio);
				Inicio = help;
			}
		}
		void  InsertarFinal(int x){			
			
			if(!Inicio){
				
				Inicio = new Nodo(x);
			}
			else{
				
				Nodo *help = Inicio;		
																							
								
				//Solo termina el ciclo cuando el siguiente es null
				while(help->ObtenerSig() != NULL){																				
					help = help->ObtenerSig();					
				}								
				
				//help esta en el ultimo elemento de la lista						
				Nodo *datoNuevo = new Nodo(x);	
				help->AsignaSig(datoNuevo);					
				
				
			}
		}
		void BorrarInicio(){
			
			if(!Inicio){
				cout<<"Lista Vacia :c"<<endl;				
			}
			else{
				
				//Si solo tiene un elemento
				if(Inicio->ObtenerSig() == NULL){
					delete Inicio;
					Inicio = NULL;
				}
				else{
					
					Nodo *help = Inicio;
					Inicio = Inicio->ObtenerSig();
					help->AsignaSig(NULL);
					delete help;					
				}
			}
		}
		void BorrarFinal(){
			
			if(!Inicio){
				cout<<"Lista Vacia :c"<<endl;
			}
			else{
				
				if(Inicio->ObtenerSig() == NULL){
					delete Inicio;
					Inicio = NULL;
				}
				else{
					Nodo *help, *aux;
					help = Inicio;
					
					while(help->ObtenerSig() != NULL){
						
						aux = help;
						help = help->ObtenerSig();
					}
					aux->AsignaSig(NULL);
					delete help;
				}
			}
		}
		int Contar(){
			
			int conteo = 0;
			if(!Inicio){
				
				return 0;
			}
			else{
				
				Nodo *help = Inicio;
				
				while(help != NULL){
					
					conteo++;
					help = help->ObtenerSig();
				}
				
				return conteo;
			}
		}
		Nodo* Buscar(int x){
									
			if(Inicio != NULL){
				
				Nodo *help = Inicio;
																		
				while(help != NULL){
					
					if(help->ObtenerDato() == x){						
						return help;
					}
					help = help->ObtenerSig();						
				}				
				return NULL;								
			}
			return NULL;
		}
		void Borrar(int x){
			
			Nodo *query = Buscar(x);
			
			if(query == NULL){
				
				cout<<"Dato no encontrado"<<endl;
			}
			else{
				
				if(query == Inicio){
					
					BorrarInicio();
				}
				else{
					
					if(query->ObtenerSig() == NULL){
						
						BorrarFinal();
					}
					else{
						
						Nodo *help = Inicio;
						
						while(help->ObtenerSig() != query){
							
							help = help->ObtenerSig();
						}
						help->AsignaSig(query->ObtenerSig());
						query->AsignaSig(NULL);
						delete query;
					}
				}
			}
		} 
		void Imprimir(){
			if(!Inicio){
				
				cout<<"Lista Vacio :("<<endl;
			}
			else{
				 
				Nodo *help = Inicio;
				
				while(help != NULL){
										
					help->Imprimir();
					help = help->ObtenerSig();					
				}
			}
		}
		void Invertir(){
			
			if(!Inicio){
				
				cout<<"Lista Vacio :("<<endl;
			}
			else{
				
				Nodo *aux = Inicio;
				
				while(aux != NULL){
										
					aux->Imprimir();
					aux->imprime_direccion();
					aux = aux->ObtenerSig();	
					system("PAUSE");									
				}																
				
			}
		}
};

int main(void){
	
	LSE newList;
	newList.InsertarInicio(1);
	newList.InsertarInicio(2);
	newList.InsertarInicio(3);
	newList.InsertarInicio(4);
	newList.InsertarInicio(5);	
	newList.InsertarFinal(12345);
	newList.Imprimir();
	
	/*
	cout<<"Antes de buscar"<<endl;	
	Nodo *Query = newList.Buscar(12345);
	Query->Imprimir();
	newList.Borrar(12345);
	newList.Imprimir();
	
	newList.Invertir();
	*/

	system("Pause");	
	return 0;
	
}


