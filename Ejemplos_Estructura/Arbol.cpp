#include<iostream>

using namespace std;

class Arbol{
	private:
		Nodo *raiz;
	public:
		void Insertar(int);
		void Pre(); //RID
		void In(); //IN
		void Post(); //IDR
		Arbol(){
			raiz = NULL;
		}
};

void arbol::Insertar(int x){
	
	if(!raiz){
		raiz = new Nodo(x);
	}
	else{
		Nodo *aux = raiz;
		if(x > raiz->Obtinedato()){
			raiz = raiz->Obtiene_Derecha();
			Insertar(x);
			aux->Asigna_Derecha(raiz);

		}
		else{
			raiz = raiz->Obtiene_Izquierda();
			Insertar(x);
			aux->Asigna_Izquierda();			
		}
		raiz = aux;		
	}
}

void Arbol::Post(){
	
	if(raiz){
		Nodo *aux = raiz;
		raiz = raiz.Obtiene_Izquierda();
		Post();
		raiz = aux->Obtiene_Derecha();
		Post();
		raiz = aux;
		cout<<raiz->ObtirneDato();
	}	
}

class Nodo{
	
}



int main(int argc, const char* argv[]){
	
	Arbol A;
	int n,i,v;	
	cout<<"teclee el numero de elemetos a insertar"<<endl;
	cin>>n;
	for(i = 0; i < n; i++){
		cout<<"tecle el valor a insertar en el arbol";
		cin>>v;
		A.Insertar(v);
	}
	A.Post();
	return 0;
	
}
