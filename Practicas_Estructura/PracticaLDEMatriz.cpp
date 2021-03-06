#include <iostream>
using namespace std;

class Nodo{
	
	private:
		
    	float dato;
    	int x,y;
    	Nodo *sig;
    	Nodo *ant;
    	
	public:
		
    	Nodo(){    
    	
			dato = 0.0;
			x = 0;
			y = 0;
        	sig = NULL;
        	ant = NULL;
    	}
    	Nodo(float a){    
    	
			dato = a;
			x = 0;
			y = 0;
        	sig = NULL;
        	ant = NULL;
    	}
    	Nodo(float a, int b, int c){
    		
    		dato = a;
    		x = b;
    		y = c;
    		sig = NULL;
    		ant = NULL;
		}
    	void Asignasig(Nodo*);
    	void Asignaant(Nodo*);
    	void Leer(float);
    	void Imprimir();
    	Nodo *Obtienesig();
    	Nodo *Obtieneant();
    	float Obtienedato();
    	int Obtiene_X();
    	int Obtiene_Y();
};


//Lista con Inicio y Fin
class LDE{    

	private:
			
    	Nodo *Inicio, *Fin;
		    	
	public:
			
    	void InsertarI(float, int, int);
    	void InsertarF(float, int, int);
    	void BorrarI();
    	void BorrarF();
    	void Imprimir();
    	void ImprimirR();
    	int Contar();
    	Nodo *Buscar(float);
    	Nodo *Buscar(int, int);
    	void Borrar(float);
    	void Inicializar();
    	void Leer();
    	void Limpiar();
    	LDE operator + (LDE);
    	LDE operator - (LDE);
    	LDE operator * (LDE);
    	LDE(){
	        Inicio=NULL;
    	    Fin=NULL;        
    	}
    	LDE(int,int,float);
    	LDE(int,float);    
};


//Metodos de la clase LDE

void LDE::Limpiar(){
	
		
	if(Inicio == NULL){
				
		cout<<"Lista Vacio :("<<endl;
	}
	else{
					 
		Nodo *help = Inicio;				
	
		while(help != NULL){
			
			help = help->Obtienesig();							
			this->BorrarI();							
		}
	}	
}

Nodo* LDE::Buscar(int x, int y){
	
	if(Inicio == NULL){
			
		cout<<"Lista vacia :("<<endl;
		return NULL;		
	}
	else{
		
		Nodo *help = Inicio;				
				
		while(help != NULL){
										
			if(help->Obtiene_X() == x && help->Obtiene_Y()){
				return help;
			}
			help = help->Obtienesig();					
		}
		return NULL;
	}
}
LDE LDE::operator+(LDE matriz_param){
	
	LDE C,F;		
	
	if(this->Contar() == matriz_param.Contar()){
		
		cout<<"Sumando..."<<endl;
		
		Nodo *aux = Inicio;		

		while(aux != NULL){
			
			float m1 = aux->Obtienedato();			
			Nodo *help = matriz_param.Buscar(aux->Obtiene_X(), aux->Obtiene_Y());			
			m1 += help->Obtienedato();						
			//cout<<m1<<endl;
			aux->Leer(m1);
			F.InsertarF(m1, aux->Obtiene_X(), aux->Obtiene_Y());
			
			aux = aux->Obtienesig();
		}
		system("PAUSE");
		
		//F.Imprimir();
		
		return F;
	}
	else{
		
		cout<<"Tus matrices deben de tener las mismas filas y columnas!!"<<endl;
		return F;
	}
}
LDE LDE::operator-(LDE matriz_param){
	
	LDE C,F;		
	
	if(this->Contar() == matriz_param.Contar()){
		
		cout<<"Sumando..."<<endl;
		
		Nodo *aux = Inicio;		

		while(aux != NULL){
			
			float m1 = aux->Obtienedato();			
			Nodo *help = matriz_param.Buscar(aux->Obtiene_X(), aux->Obtiene_Y());			
			m1 -= help->Obtienedato();						
			//cout<<m1<<endl;
			aux->Leer(m1);
			F.InsertarF(m1, aux->Obtiene_X(), aux->Obtiene_Y());
			
			aux = aux->Obtienesig();
		}
		system("PAUSE");
		
		//F.Imprimir();
		
		return F;
	}
	else{
		
		cout<<"Tus matrices deben de tener las mismas filas y columnas!!"<<endl;
		return F;
	}
}
LDE LDE::operator*(LDE matriz_param){
	
	LDE C,F;		
	
	if(this->Contar() == matriz_param.Contar()){
		
		cout<<"Sumando..."<<endl;
		
		Nodo *aux = Inicio;		

		while(aux != NULL){
			
			float m1 = aux->Obtienedato();			
			Nodo *help = matriz_param.Buscar(aux->Obtiene_X(), aux->Obtiene_Y());			
			m1 *= help->Obtienedato();						
			//cout<<m1<<endl;
			aux->Leer(m1);
			F.InsertarF(m1, aux->Obtiene_X(), aux->Obtiene_Y());
			
			aux = aux->Obtienesig();
		}
		system("PAUSE");
		
		//F.Imprimir();
		
		return F;
	}
	else{
		
		cout<<"Tus matrices deben de tener las mismas filas y columnas!!"<<endl;
		return F;
	}
}
void LDE::Inicializar(){
	
	
	int fila, columna;
	cout<<"Ingresa la cantidad de filas"<<endl;	
	cin>>fila;
	cout<<"Ingresa la cantidad de columnas"<<endl;
	cin>>columna;
	
	if(fila == columna){
		
		//int size_lista = fila * columna;
		
		for(int i = 1; i <= fila; i++){
			
			for(int j = 1; j <= columna; j++ ){
								
				this->InsertarF(0.0, i, j);
			}
		}		
	}
	else{
			
		cout<<"Fila y columna debe ser iguales"<<endl;		
	}			
}
void LDE::Leer(){
	
	if(Inicio == NULL)	{
		
		cout<<"Lista Vacia :("<<endl;		
	}
	else{
		
		float dato;
		
		Nodo *aux = Inicio;
		
		while(aux != NULL){
					
			cout<<"Ingrese el dato:"<<endl;
			cin>>dato;
			aux->Leer(dato);										
			aux = aux->Obtienesig();			
		}
	}
		
	
}
Nodo* LDE::Buscar(float x){
	
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
			Fin = NULL;
		}
		else{		
			
			Nodo *aux = Fin;
			
			Fin = aux->Obtieneant();
			aux->Asignaant(NULL);
			Fin->Asignasig(NULL);			
			delete aux;				
		}				
	}
}
void LDE::Borrar(float x){

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
void LDE::InsertarI(float value, int x, int y){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(value, x, y);
		Fin	= Inicio;				
	}	
	else{	
					
		Nodo *newNodo = new Nodo(value, x, y);				
		Nodo *aux = Inicio;
		Inicio = newNodo;
		Inicio->Asignasig(aux);
		aux->Asignaant(Inicio);																		
	}	
}
void LDE::InsertarF(float value, int x, int y){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(value, x, y);
		Fin = Inicio;
	}	
	else{	
						
		Nodo *newNodo = new Nodo(value, x, y);		
		Fin->Asignasig(newNodo);		
		newNodo->Asignaant(Fin);		
		Fin = newNodo;								
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
			cout<<"\b\b";
			help = help->Obtienesig();	
		}
	}
}
void LDE::ImprimirR(){
	
	if(Inicio == NULL){
				
		cout<<"Lista Vacio :("<<endl;
	}
	else{				 
		Nodo *help = Fin;				
	
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






//Metodos de la clase Nodo
void Nodo::Asignasig(Nodo *x){
    this->sig=x;
}
void Nodo::Asignaant(Nodo *x){
    this->ant=x;
}
void Nodo::Leer(float x){
    this->dato=x;
}
void Nodo::Imprimir(){    

    cout<<"La cordenas es [x,y] "<<"["<<x<<" , "<<y<<"]"<<" y tiene el dato: "<<this->dato<<endl;  
}
Nodo* Nodo::Obtienesig(){
    return(this->sig);
}
Nodo* Nodo::Obtieneant(){
    return(this->ant);
}
float Nodo::Obtienedato(){
    return(this->dato);
}
int Nodo::Obtiene_X(){
    return(this->x);
}
int Nodo::Obtiene_Y(){
    return(this->y);
}

int main(int argc, const char * argv[]){
	
            
    LDE A,B,C;
    int opc;
	float dato;
	
    do{
        cout<<"1.- Inicializar"<<endl;
        cout<<"2.- Leer"<<endl;
        cout<<"3.- Sumar"<<endl;
        cout<<"4.- Restar"<<endl;
        cout<<"5.- Multiplicar"<<endl;        
        cout<<"6.- Imprimir"<<endl;        
        cout<<"7.- Limpiar"<<endl;   
        cout<<"8.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        system("cls");        
       
        switch(opc){
        	
            case 1:                                
                A.Inicializar();
                break;
            case 2:
				if(A.Contar() != 0){					
					A.Leer();
				}
				else{
					cout<<"Debes Inicializar la Matriz!!"<<endl;
				}                                                
                break;
            case 3:            	            	
            	cout<<"Inicialice la matriz nueva para sumar."<<endl;            	
            	B.Inicializar();
            	B.Leer();
            	system("CLS");
				C = A + B;
				B.Limpiar();				
				C.Imprimir();				
                break;
            case 4:
				cout<<"Inicialice la matriz nueva para restar."<<endl;            	
            	B.Inicializar();
            	B.Leer();
            	system("CLS");
				C = A - B;
				B.Limpiar();				
				C.Imprimir();	
                break;
            case 5:
				cout<<"Inicialice la matriz nueva para restar."<<endl;            	
            	B.Inicializar();
            	B.Leer();
            	system("CLS");
				C = A * B;
				B.Limpiar();				
				C.Imprimir();
                break;
            case 6:            	
                A.Imprimir();                                
                break;
            case 7:            	
                A.Limpiar();
                break;
            default:
                cout<<"opci�n salir...";
                break;
        }
    }while(opc<8);
    
    return 0;
}

