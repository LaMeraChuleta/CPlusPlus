#include <iostream>
using namespace std;


class Nodo
{
private:
    int dato;
    Nodo *sig;
public:
    Nodo(){    
		dato=0;
    	sig=NULL;
    }
    Nodo(int x){    
		dato=x;
        sig=NULL;
    }
    void Asignasig(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    int Obtienedato();
};
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
class LSE
{    private:
    Nodo *Inicio;
public:
    void InsertarI(int);
    void InsertarF(int);
    void Imprimir();
    void BorrarI();
    void BorrarF();
    int Contar();
    Nodo *Buscar(int);
    void Borrar(int);
    LSE()
    {
        Inicio=NULL;
    }
    
};
void LSE::InsertarI(int x)
{      if(!Inicio)
    Inicio=new Nodo(x);
else
    
    {
        Nodo *helpx3=new Nodo(x);
        helpx3->Asignasig(Inicio);
        Inicio=helpx3;
    }
}
void LSE::InsertarF(int x)
{
    if(Inicio==NULL)
    Inicio=new Nodo(x);
    else
        {
            
            Nodo *help=Inicio;
            while(help->Obtienesig()!=NULL)
                help=help->Obtienesig();
            Nodo *helpx2=new Nodo(x);
            help->Asignasig(helpx2);
        }
}
void LSE::Imprimir()
{
    if(!Inicio)
    cout<<"Lista Vacia"<<endl;
    else
        {
            Nodo *Aux=Inicio;
            while(Aux!=NULL)
                {
                    Aux->Imprimir();
                    Aux=Aux->Obtienesig();
                }
        }
}
void LSE::BorrarI()
{
    if(!Inicio)
        cout<<"Lista Vacia"<<endl;
    else
        {
            if(Inicio->Obtienesig()==NULL)
                {
                    delete Inicio;
                    Inicio=NULL;
                }
            else
                {
                    Nodo *hay=Inicio;
                    Inicio=Inicio->Obtienesig();
                    hay->Asignasig(NULL);
                    delete hay;
                }
        }
}
void LSE::BorrarF()
{    if(!Inicio)
    cout<<"Lista Vacia";
else
{    if(Inicio->Obtienesig()==NULL)
{    delete Inicio;
    Inicio=NULL;
}
else
{    Nodo *Ad,*Sh;
    Ad=Inicio;
    while(Ad->Obtienesig()!=NULL)
    {    Sh=Ad;
        Ad=Ad->Obtienesig();
    }
    Sh->Asignasig(NULL);
    delete Ad;
}
}
}
int LSE::Contar()
{    int ESCA=0;
    if(!Inicio)       ESCA=0;
    else
    {    Nodo *REC=Inicio;
        while(REC!=NULL)
        {    ESCA++;
            REC=REC->Obtienesig();
        }
    }
return ESCA;
}
Nodo* LSE::Buscar(int x)
{
    Nodo *covid=Inicio;
    if(Inicio)
    {    while (covid!=NULL)
    {    if (covid->Obtienedato()==x)
        return covid;
        covid=covid->Obtienesig();
    }
    }
    return covid;
}
void LSE::Borrar(int x)
{      Nodo *simi=Buscar(x);
    if(simi==NULL)       cout<<"DATO NO ENCONTRADO";
    else
    {    if(simi==Inicio)           BorrarI();
    else
    {
        if(simi->Obtienesig()==NULL)    BorrarF();
        else
        {    Nodo *XL=Inicio;
            while(XL->Obtienesig()!=simi)
                XL=XL->Obtienesig();
            XL->Asignasig(simi->Obtienesig());
            simi->Asignasig(NULL);
            delete simi;
        }
    }
    }
}






int main(int argc, const char * argv[]) {

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
        default:
            cout<<"opción salir...";
            break;
    }
    }while(opc<8);
    
    return 0;
}
