#include <iostream>
using namespace std;

class Nodo
{
private:
    float dato;
    int x,y;
    Nodo *sig;
    Nodo *ant;
public:
    Nodo()
    {
        dato=0.0;
        x=0;
        y=0;
        sig=NULL;
        ant=NULL;
    }
    Nodo(float a)
    {
        dato=a;
        x=0;
        y=0;
        sig=NULL;
        ant=NULL;
    }

    Nodo(float a,int b, int c)
    {
        dato=a;
        x=b;
        y=c;
        sig=NULL;
        ant=NULL;
    }
    void Asignasig(Nodo*);
    void Asignaant(Nodo*);
    void Leer(float);
    void Imprimir();
    Nodo *Obtienesig();
    Nodo *Obtieneant();
    float Obtienedato();
};

class LDE
{    private:
    Nodo *Inicio, *Fin;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    void Imprimir();
    void ImprimirR();
    int Contar();
    Nodo *Buscar(int);
    void Borrar(int);
    void Inicializar();
    void Leer();
    LDE operator + (LDE);
    LDE operator - (LDE);
    LDE operator * (LDE);
    LDE()
    {
        Inicio=NULL;
        Fin=NULL;
        
    }
    LDE(int,int,float);
    LDE(int,float);
    
};




void Nodo::Asignasig(Nodo *x)
{
    this->sig=x;
}
void Nodo::Asignaant(Nodo *x)
{
    this->ant=x;
}


void Nodo::Leer(float a)
{
    this->dato=a;
}
void Nodo::Imprimir()
{
    cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{
    return(this->sig);
}

Nodo* Nodo::Obtieneant()
{
    return(this->ant);
}


float Nodo::Obtienedato()
{
    return(this->dato);
}








int main(int argc, const char * argv[])
{

    return 0;
}
