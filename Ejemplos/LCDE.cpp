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

class LCDE
{    private:
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
    LCDE()
    {
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
		
		Nodo *aux = Inicio;
		
		do{
			
			aux->Imprimir();
			aux = aux->Obtienesig();
		}
		while(aux != Inicio);		
	}
}

void LCDE::InsertarF(int x){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Asignasig(Inicio);
		Inicio->asigna_ant(Inicio);
		
	}
	else{
		
		Nodo *aux = Inicio;
		
		do{
			
			aux = aux->Obtienesig();
		}
		while(aux != Inicio);
		Nodo *self = new Nodo(x);
		//ASIGNAMOS EL NUEVO NODO AL FINAL
		self->Asignasig(aux->Obtienesig());
		self->asigna_ant(aux);
		aux->Asignasig(self);							
	}	
}

void LCDE::InsertarI(int x) {
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(x);
		Inicio->Asignasig(Inicio);
		Inicio->asigna_ant(Inicio);
		
	}
	else{
		
		Nodo *aux = Inicio->Obtienesig();		
		Nodo *self = new Nodo(x);
		
		self->asigna_ant(Inicio);
		self->Asignasig(Inicio->Obtienesig());
		Inicio->Asignasig(self);
		
		
		
								
	}
	
}
void LCDE::BorrarI(){
	
}
void LCDE::BorrarF(){
	
}
int LCDE::Contar(){
	
}
Nodo* LCDE::Buscar(int x){
	
}
void LCDE::Borrar(int x){
	
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
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
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

