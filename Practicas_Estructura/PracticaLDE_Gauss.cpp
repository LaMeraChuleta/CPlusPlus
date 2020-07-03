#include <iostream>

using namespace std;

class Nodo{
	
	private:    
    	int x,y;
    	float dato;
    	Nodo *sig;
	public:
    
    Nodo(int a, int b, float c){
        x = a;
        y = b;
        dato = c;
        sig = NULL;
    }
    
};


class matrix{
	
	private:
    	Nodo *inicio,* fin;
	public:
    	void crear (int);
    	void insertarf (int,int,float);
    	Nodo * buscarxy (int,int);
    	void leer ();
    	void imprimir();
    	void imprimirV();
    	void creaM (int , int );
    	void gauss();
    	matrix() {
			inicio=fin=NULL; 
		}
    
};

int main(){
	
	
	/*	
    int n;
    
    matrix A,B;
    cout<<"Teclee el numero de ecuaciones: "<< " ";
    cin>>n;
    A.crear (n);
    A.leer();
    cout<<"  "<<endl<<endl<<endl;
    
    A.gauss();        
    system("pause");
    */
}


