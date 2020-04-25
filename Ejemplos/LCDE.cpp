Estructuras y Base de Datos
Fecha de entrega: 15:00
LCDE
100 puntos

Jafeth Alonso Carreón
13:03 (Última modificación: 13:51)
Ahora, desarrollaremos una Lista Circular Doblemente Enlazada.
Para ejemplificar, recuerdan como salían los elefantes en el circo?
Claro, agarrados de la cola y la trompa. Pues así, es una lista circular doblemente enlazada.
A continuación les dejo el archivo cpp y los dibujos.
Mismas reglas.
Los veo a las 14:30
Saludos!

main.cpp
C++
1 comentario de clase

Jafeth Alonso Carreón13:21
Jóvenes, me falto modificar la clase nodo, agreguen por favor el apuntador ant, la función obtineant y la función asignaant.
Por favor hagan esos cambios.
Saludos!!

Tu trabajo
Tarea asignada

LaMeraChuleta Benito Bonito - LCDE.pdf
PDF

LaMeraChuleta Benito Bonito - main.cpp
C++
Comentarios privados


//
//  main.cpp
//  LCDE
//
//  Created by Jafeth Alonso Carreón on 4/24/20.
//  Copyright © 2020 Jafeth Alonso Carreón. All rights reserved.
//

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
    Nodo()
    {    dato=0;
        sig=NULL;
        //Atributo Mio!!
        ant = NULL;
    }
    Nodo(int x)
    {    dato=x;
        sig=NULL;
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

void LCDE::InsertarI(int value){
	
	if(Inicio == NULL){
		
		Inicio = new Nodo(value);
		Inicio->Asignasig(Inicio);
		Inicio->asigna_ant(Inicio);
		
	}
	else{
		
	}
	
	
}


//METODOS DE LA CLASE NODO
void Nodo::Asignasig(Nodo *x)
{
    this->sig=x;
}
void Nodo::Leer(int x)
{
    this->dato=x;
}
void Nodo::Imprimir()
{
    cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{
    return(this->sig);
}
int Nodo::Obtienedato()
{
    return(this->dato);
}


//Metodos Mios!!
Nodo* Nodo::obtiene_ant(){	
	return(this->ant);	
}
void Nodo::asigna_ant(Nodo *x){
	this->ant = x;
}

//----------------------------



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

