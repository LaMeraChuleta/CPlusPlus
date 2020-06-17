#include<iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Archivo{	
	
	public:
		fstream A;
		fstream Marca;
		fstream Modelo;
		fstream Cilindro;
	
	public:
		
	friend class LSE;
		
		void Inicializar(){
			
						
			A.open("D:\Carros.txt", ios::out);
			if(A.fail()){
				
				cout<<"No se pudo abrir el archivo"<<endl;
				system("Pause");
				exit(0);				
			}
			cout<<"Soy un master en manejo de archivos .txt"<<endl;
			system("Pause");
			
		}
		void EscribirCarros(string a, string b, string c, string d, string e,string f,string g){				
			A<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<endl;																																
		}
		void InicializarMarca(){
			
						
			Marca.open("D:\Marca.txt", ios::out);
			if(Marca.fail()){
				
				cout<<"No se pudo abrir el archivo"<<endl;
				system("Pause");
				exit(0);				
			}
			cout<<"Soy un master en manejo de archivos .txt"<<endl;			
			
		}
		void EscribirMarca(string a, string b, string c, string d, string e,string f,string g){				
			Marca<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<endl;																																
		}
		void FinalizarMarca(){
			Marca.close();
			
		}		
		void InicializarModelo(){
			
						
			Modelo.open("D:\Modelo.txt", ios::out);
			if(Modelo.fail()){
				
				cout<<"No se pudo abrir el archivo"<<endl;
				system("Pause");
				exit(0);				
			}
			cout<<"Soy un master en manejo de archivos .txt"<<endl;			
			
		}
		void EscribirModelo(string a, string b, string c, string d, string e,string f,string g){				
			Modelo<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<endl;																																
		}
		void FinalizarModelo(){
			Modelo.close();
		}
		void InicializarCilindros(){
			
						
			Cilindro.open("D:\Cilindros.txt", ios::out);
			if(Cilindro.fail()){
				
				cout<<"No se pudo abrir el archivo"<<endl;
				system("Pause");
				exit(0);				
			}
			cout<<"Soy un master en manejo de archivos .txt"<<endl;
			
			
		}
		void EscribirCilindros(string a, string b, string c, string d, string e,string f,string g){				
			Cilindro<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<endl;																																
		}
		void FinalizarCilindro(){
			Cilindro.close();
		}
		void Finalizar(){
			
			A.close();
		}	
		
		void InicializarLec(){
			A.open("D:\Carros.txt", ios::in);
			if(A.fail()){
				
				cout<<"No se abrio el archivo"<<endl;
				system("Pause");
				exit(0);
			}
			cout<<"Soy un master en el manejo de archivos"<<endl;			
		}
	
};




class Nodo{

	private:
		
		string marca;
		string modelo;
		string categoria;
		string transmicion;
		string year;
		string cilindros;
		string color;
		int dato;
		Nodo *Sig;	
	public:
	
		Nodo(){
			marca = " ";
			modelo = " ";
			categoria = " ";
			transmicion = " ";
			year = " ";
			cilindros = " ";
			color = " ";					
			dato = 0; 
			Sig = NULL;
		}
		Nodo(string a, string b, string c, string d, string e,string f,string g){
			marca = a;
			modelo = b;
			categoria = c;
			transmicion = d;
			year = e;
			cilindros = f;
			color = g;
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
		void AsignarDatos(string a, string b, string c, string d, string e,string f,string g){			
			this->marca = a;
			this->modelo = b;
			this->categoria = c;
			this->transmicion = d;
			this->year = e;
			this->cilindros = f;
			this->color = g;
				
		}	
		void Leer(int x){
			this->dato = x;
		}
		void Imprimir(){
			cout<<this->marca<<" "<<this->modelo<<" "<<this->categoria<<" "<<this->transmicion<<" "<<this->year<<" "<<this->cilindros<<" "<<this->color<<endl;
		}
		Nodo* ObtenerSig(){
			
			return (this->Sig);
		}
		int ObtenerDato(){
    		return (this->dato);
		}
		string ObtenerDatoMarca(){
    		return (this->marca);
		}
		string ObtenerDatoModelo(){
    		return (this->modelo);
		}		
		string ObtenerDatoCategoria(){
    		return (this->categoria);
		}
		string ObtenerDatoTransmicion(){
    		return (this->transmicion);
		}
		string ObtenerDatoYear(){
    		return (this->year);
		}
		string ObtenerDatoCilindros(){
    		return (this->cilindros);
		}
		string ObtenerDatoColor(){
    		return (this->color);
		}
		
		
};

class LSE{
	private:
		Nodo *Inicio;
	public:
		
		friend class Archivo;
		~LSE(){
			delete Inicio;
			cout<<"Memoria Liberada"<<endl;
		}
		LSE(){
			Inicio = NULL;
		}
		void InsertarInicio(string a, string b, string c, string d, string e,string f,string g){
			
			if(!Inicio){
				
				Inicio = new Nodo(a,b,c,d,e,f,g);
			}			
			else{
				
				Nodo *help = new Nodo(a,b,c,d,e,f,g);
				help->AsignaSig(Inicio);
				Inicio = help;
			}
		}
		void  InsertarFinal(string a, string b, string c, string d, string e,string f,string g){			
			
			if(!Inicio){
				
				Inicio = new Nodo(a,b,c,d,e,f,g);
			}
			else{
				
				Nodo *help = Inicio;																					
								
				//Solo termina el ciclo cuando el siguiente es null
				while(help->ObtenerSig() != NULL){																				
					help = help->ObtenerSig();					
				}								
				
				//help esta en el ultimo elemento de la lista						
				Nodo *datoNuevo = new Nodo(a,b,c,d,e,f,g);	
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
		LSE BuscarMarca(string marca){									
									
			if(Inicio != NULL){
				
				LSE listaReturn;
				Nodo *help = Inicio;
																		
				while(help != NULL){
					
					if(help->ObtenerDatoMarca() == marca){						
						listaReturn.InsertarFinal(help->ObtenerDatoMarca(),help->ObtenerDatoModelo(), help->ObtenerDatoCategoria(), help->ObtenerDatoTransmicion(), help->ObtenerDatoYear(), help->ObtenerDatoCilindros(), help->ObtenerDatoColor());
					}
					help = help->ObtenerSig();						
				}				
				return listaReturn;								
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
		Editar(){
			
			if(!Inicio){
				
				cout<<"Lista Vacia :c"<<endl;
			}
			else{
								
														
				char strMarca[120], strModelo[120], strCategoria[120], 
					 strTransmision[120], strColor[120], strYear[120], strCilindros[120];
				Nodo *help = Inicio;
				
				char answer;
				
				cin.ignore();
				char query[120];
				cout<<"Escriba la marca de Auto que quiere Editar"<<endl;
				cin.getline(query, 120);
				
																		
				while(help != NULL){
					
					if(help->ObtenerDatoMarca() == query){
						
						
						cout<<"Se encontro esta concidencia"<<endl;
						cout<<help->ObtenerDatoMarca()<<' '<<help->ObtenerDatoModelo()<<' '<<help->ObtenerDatoCategoria()<<' '<<help->ObtenerDatoTransmicion()<<' '<<help->ObtenerDatoYear()<<' '<<help->ObtenerDatoCilindros()<<' '<<help->ObtenerDatoColor()<<' '<<endl; 
						cout<<"Quieres editar este elemento??"<<endl;
						cin>>answer;
						
						
						if(answer == 'S' || answer == 's'){
						
											
						cin.ignore();				
						cout<<"Agregar la Nueva Info Del Automovil"<<endl;
						cout<<"Escribe la Marca"<<endl;
						cin.getline(strMarca, 120);	
						cout<<"Escribir Modelo"<<endl;
						cin.getline(strModelo,120);			
						cout<<"Escribe la Categoria"<<endl;
						cin.getline(strCategoria, 120);	
						cout<<"Escribir Transmision"<<endl;
						cin.getline(strTransmision,120);
						cout<<"Escribe la Year"<<endl;
						cin.getline(strYear, 120);	
						cout<<"Escribir Cilindros"<<endl;
						cin.getline(strCilindros,120);
						cout<<"Escribe el Color"<<endl;
						cin.getline(strColor, 120);
						
						help->AsignarDatos(strMarca, strModelo, strCategoria, strTransmision, strYear, strCilindros, strColor);
						
					}
																								
				}					
				help = help->ObtenerSig();						
			}				
												
		}
	
	}	
	void EscribirPorMarca(Archivo& A, string marca){
				
			
			if(Inicio != NULL){
				
				Nodo *help = Inicio;
																		
				while(help != NULL){
					
					if(help->ObtenerDatoMarca() == marca){						
						A.EscribirMarca(help->ObtenerDatoMarca(), help->ObtenerDatoModelo(), help->ObtenerDatoCategoria(), help->ObtenerDatoTransmicion(), help->ObtenerDatoYear(), help->ObtenerDatoCilindros(), help->ObtenerDatoColor());
					}
					help = help->ObtenerSig();						
				}				
												
			}				
	}
	void EscribirPorModelo(Archivo& A, string modelo){
				
		
			if(Inicio != NULL){
				
				Nodo *help = Inicio;
																		
				while(help != NULL){
					
					if(help->ObtenerDatoModelo() == modelo){						
						A.EscribirModelo(help->ObtenerDatoMarca(), help->ObtenerDatoModelo(), help->ObtenerDatoCategoria(), help->ObtenerDatoTransmicion(), help->ObtenerDatoYear(), help->ObtenerDatoCilindros(), help->ObtenerDatoColor());
					}
					help = help->ObtenerSig();						
				}				
												
			}				
	}
	void EscribirPorCilindros(Archivo& A, string cilindros){
				
		
			if(Inicio != NULL){
				
				Nodo *help = Inicio;
																		
				while(help != NULL){
					
					if(help->ObtenerDatoCilindros() == cilindros){						
						A.EscribirCilindros(help->ObtenerDatoMarca(), help->ObtenerDatoModelo(), help->ObtenerDatoCategoria(), help->ObtenerDatoTransmicion(), help->ObtenerDatoYear(), help->ObtenerDatoCilindros(), help->ObtenerDatoColor());
					}
					help = help->ObtenerSig();						
				}				
												
			}				
	}
	void EscribirTodo(Archivo& A){
				
		
			if(Inicio != NULL){
				
				Nodo *help = Inicio;
																		
				while(help != NULL){
										
					A.EscribirCarros(help->ObtenerDatoMarca(), help->ObtenerDatoModelo(), help->ObtenerDatoCategoria(), help->ObtenerDatoTransmicion(), help->ObtenerDatoYear(), help->ObtenerDatoCilindros(), help->ObtenerDatoColor());					
					help = help->ObtenerSig();						
				}				
												
			}				
	}
		
};



int main(void){
	
	bool stop = false;
	int answer;
			char strMarca[120], strModelo[120], strCategoria[120], 
				 strTransmision[120], strColor[120], strYear[120], strCilindros[120];
		
	Archivo A;
	LSE list;
	
	A.InicializarLec();
	A.InicializarMarca();
	A.InicializarModelo();
	A.InicializarCilindros();
	

		
	while(!A.A.eof()){
				
				
				char Marca[20], Modelo[20], Categoria[20], Transmision[20], Year[20], Cilindros[20], Color[20];
				A.A.getline(Marca,20, '\t');
				A.A.getline(Modelo,20,'\t');
				A.A.getline(Categoria,20,'\t');
				A.A.getline(Transmision,20,'\t');
				A.A.getline(Year,20,'\t');
				A.A.getline(Cilindros,20,'\t');
				A.A.getline(Color,20);				
				list.InsertarFinal(Marca,Modelo,Categoria,Transmision,Year,Cilindros,Color);												
			}
			
	cout<<"Se cargo el archivo Correctamente!!!!"<<endl;

		
	system("Pause");
		
	do{
			
	cout<<"\t\tSelecione una opcion!"<<endl;
	cout<<"Insertar al Inico [1]"<<endl;
	cout<<"Insertar al Final [2]"<<endl;
	cout<<"Borrar el Primero [3]"<<endl;
	cout<<"Borrar el Ultimo [4]"<<endl;
	cout<<"Imprimir [5]"<<endl;
	cout<<"Contar [6]"<<endl;
	cout<<"Editar [7]"<<endl;
	cout<<"Generar Reporte Busqueda [8]"<<endl;
	cout<<"Salir[9]"<<endl;
	cin>>answer;	
	
	switch(answer){
		
		
		case 1:
			
			system("CLS");
						
	
				 
			cout<<"\t\tAgregar Automovil Al Inicio"<<endl;
						
				cin.ignore();				
				cout<<"Agregar Info Del Automovil"<<endl;
				cout<<"Escribe la Marca"<<endl;
				cin.getline(strMarca, 120);	
				cout<<"Escribir Modelo"<<endl;
				cin.getline(strModelo,120);			
				cout<<"Escribe la Categoria"<<endl;
				cin.getline(strCategoria, 120);	
				cout<<"Escribir Transmision"<<endl;
				cin.getline(strTransmision,120);
				cout<<"Escribe la Year"<<endl;
				cin.getline(strYear, 120);	
				cout<<"Escribir Cilindros"<<endl;
				cin.getline(strCilindros,120);
				cout<<"Escribe el Color"<<endl;
				cin.getline(strColor, 120);
				cin.ignore();
				list.InsertarInicio(strMarca, strModelo, strCategoria, strTransmision, strYear, strCilindros, strColor);
			
			break;
			
		case 2:
			
				system("CLS");
						
				 
			cout<<"\t\tAgregar Automovil Al Final"<<endl;
						
				cin.ignore();				
				cout<<"Agregar Info Del Automovil"<<endl;
				cout<<"Escribe la Marca"<<endl;
				cin.getline(strMarca, 120);	
				cout<<"Escribir Modelo"<<endl;
				cin.getline(strModelo,120);			
				cout<<"Escribe la Categoria"<<endl;
				cin.getline(strCategoria, 120);	
				cout<<"Escribir Transmision"<<endl;
				cin.getline(strTransmision,120);
				cout<<"Escribe la Year"<<endl;
				cin.getline(strYear, 120);	
				cout<<"Escribir Cilindros"<<endl;
				cin.getline(strCilindros,120);
				cout<<"Escribe el Color"<<endl;
				cin.getline(strColor, 120);
				cin.ignore();
				list.InsertarFinal(strMarca, strModelo, strCategoria, strTransmision, strYear, strCilindros, strColor);
			
			break;
			
		case 3:
			
			system("CLS");
			cout<<"Se Borrara el Primer Elemento"<<endl;
			list.BorrarInicio();
			
			break;
			
		case 4:
			
			system("CLS");
			cout<<"Se Borrara el Ultimo Elemento"<<endl;
			list.BorrarInicio();
			
			break;
			
		case 5:
			
			system("CLS");			
			cout<<"Los Elemento de la lista son:"<<endl;
			list.Imprimir();						
			break;
		
		case 6:
			
			system("CLS");
			cout<<"La lista contiene: "<<list.Contar()<<" elementos"<<endl;
			break;
			
		case 7:
			system("CLS");
			list.Editar();
			break;
		
		case 8:
			
			system("PAUSE");
			
			int decide;
			
			cout<<"Buscar y Escribir:"<<endl;
			cout<<"Buscar por Marca    [1]"<<endl;
			cout<<"Buscar por Modelo   [2]"<<endl;
			cout<<"Buscar por Cilindros[3]"<<endl;
			cin>>decide;
			
			switch(decide){
				case 1:
					char query1[120];
					cin.ignore();
					cout<<"Escriba la marca que quiere filtrar"<<endl;
					cin.getline(query1, 120);
					list.EscribirPorMarca(A,query1);
				break;
				
				
				case 2:
					
					char query2[120];
					cin.ignore();
					cout<<"Escriba el modelo que quiere filtrar"<<endl;
					cin.getline(query2, 120);
					list.EscribirPorModelo(A,query2);				
				break;
				
				case  3:
					char query3[120];
					cin.ignore();
					cout<<"Escriba los cilindros que quiere filtrar"<<endl;
					cin.getline(query3, 120);				
					list.EscribirPorCilindros(A,query3);
				
				break;	
				
				default:
					cout<<"Opcion Incorrecta"<<endl;
				break;			
			}
			
		break;
		
		default:
			
			A.Finalizar();
			A.Inicializar();
			list.EscribirTodo(A);
			cout<<"Adios!!"<<endl;
			break;
					
	}
		
}	
while(answer <= 8);
	
	A.Finalizar();
	A.FinalizarCilindro();
	A.FinalizarMarca();
	A.FinalizarModelo();


	
	
	return 0;
}	
	

