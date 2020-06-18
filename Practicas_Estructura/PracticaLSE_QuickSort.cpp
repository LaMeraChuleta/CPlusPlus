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
};

class LSE{
	private:
		Nodo *Inicio;
	public:
		LSE(){
			Inicio = NULL;
		}
		void QuiuckSort(){
		
			if(Inicio == NULL){
				
				cout<<"Lista vacia"<<endl;
			}
			else{
				
				quicksort(0, this->Contar() - 1);
			}
						
		}	
		void quicksort(int izq, int der){
			
				int i, j, pivote, aux; 
				i = izq; 
				j = der;
				
				
				//Guardamos el nodo que sera el pivote
				Nodo *pivote = Inicio; 				
				int ayuda_int = ((izq + der) /2 );
				int iter = 1;
				while(iter <= pivote){
					
					pivote = pivote->ObtenerSig();
					iter += 1;
				}
		
    			do{ 
    
        			while( (A[i] < pivote) && (j <= der) ){         
            			i++;
        			}  	
						 		
        			while( (pivote < A[j]) && (j > izq) ){         	
            			j--;
        			} 
 
        			if( i <= j ){ 
        			
            			aux = A[i]; 
						A[i] = A[j]; 
						A[j] = aux; 
            			i++;  j--; 
        			}
        	 
     			}while( i <= j ); 

 
    			if( izq < j ) 
        			quicksort( A, izq, j ); 
    			if( i < der ) 
        			quicksort( A, i, der ); 
						
			
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
					//aux->imprime_direccion();
					aux = aux->ObtenerSig();	
					system("PAUSE");									
				}																
				
			}
		}
};

int main(void){
	
	LSE A;
	
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
		cout<<"8.- Burbuja"<<endl;         
        cout<<"9.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc; 
		
		system("cls");               
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarInicio(dato);
                system("cls");
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarFinal(dato);
                break;
            case 3:
                A.BorrarInicio();
                break;
            case 4:
                A.BorrarFinal();
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
                A.Burbuja();
                break;                     
            default:
                cout<<"opción salir...";
                break;
        }    
		                    
    }while(opc < 9);
	
}




