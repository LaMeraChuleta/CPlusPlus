#include<iostream>
#include<string.h>

using namespace std;

//Inicio de la clase Perro
class Perro {
	
	private:
		string Nombre;
		int Edad;
		float Peso;
	public:		
		Perro( string N = " ", int E = 0, float P = 0.0);
		Perro(const Perro& P);
		Perro operator=(const Perro& P);
		void Leer(void);
		void Imprimir(void);
		string RetornarNombre(void);
		void AsignarNombre(string x);
		~Perro(void);
		
};
//Constructor con parametros por omision
Perro::Perro(string N, int E, float P){
	
	Nombre = N;
	Edad = E;
	Peso = P;
}
//Constructor Copia
Perro::Perro(const Perro& P){
	
	Nombre = P.Nombre;
	Edad = P.Edad;
	Peso = P.Peso;
}
//Sobrecarga del operador asignado (operator=)
Perro Perro::operator=(const Perro& P){
	
	this->Nombre = P.Nombre;
	this->Edad = P.Edad;
	this->Peso = P.Peso;
	return *this;	
}
//Metodo leer para tener la posibilidad de ingresar los datos del objeto implementado
void Perro::Leer(void){
	
	cout<<"Nombre: "<<endl;
	fflush(stdin);
	getline(cin, Nombre);
	cout<<"Edad: "<<endl;
	cin>>Edad;
	cout<<"Peso: "<<endl;
	cin>>Peso;
	cout<<endl;	
}
//Metodo Imprimir para tener la posibilidad de mostrar los datos del objeto en pantalla
void Perro :: Imprimir(void){
    cout << " Nombre: " << Nombre << endl;
    cout << " Edad: " << Edad << endl;
    cout << " Peso: " << Peso << endl;
}
//Metodos Retornar
//Se usan para poder conocer el valor de un atributo en especifico
string Perro::RetornarNombre(void){
	
	return Nombre;
}
//Metodos Asignar
//Se usan para poder cambiar el valor d eun atrubuto en especifico
void Perro::AsignarNombre(string x){
	
	Nombre = x;
}
Perro::~Perro(void){
	
	cout << endl << endl << "Se libero la memoria B|" << endl << endl;
}


int main(){
	
	  // Se declara un objeto de nombre Chato, de tipo Perro
    Perro Chato;
    string X;
    Chato.Imprimir(); // Imprime los datos asignados por omision
    
    cout << endl << " Ahora ingresa los datos de tu Mascota " << endl;
    Chato.Leer(); // Se leen los datos desde el teclado
    
    cout << endl << " Los datos de tu Mascota son " << endl;
    Chato.Imprimir(); // Imprime los datos asignados atraves del metodo Leer()
    
    cout << endl << " La copia de los datos de tu Mascota son " << endl;
    Perro Rex( Chato ); // Se declara un objeto de nombre Rex de tipo Perro el cual usando el constructor copia; copia los datos que tiene el objeto chato
    Rex.Imprimir(); // Se debe imprimir lo mismo que Chato
    
    cout << endl << " Ingresa el nombre correcto de la mascota: ";
    fflush( stdin );
    getline( cin, X ); // Se lee el dato que se enviara al metodo asignar nombre, debe ser del mismo tipo de dato, en este caso string
    Chato.AsignarNombre( X ); // Con el metodo AsignarNombre podemos cambiar el nombre del Perro
    
    cout << endl << " Los nuevos datos de tu Mascota son " << endl;
    Chato.Imprimir(); // Imprime los datos asignados, debe mostrar el cambio efectuado en el atributo nombre
    
    // La copia debe permanecer con los datos de Chato antes de cambiar el nombre
    cout << endl << " Los datos originales de tu Mascota eran " << endl;
    Rex.Imprimir(); // Se debe imprimir lo mismo que Chato antes de cambiar el nombre
    
    // Se declara un objeto de nombre Fifi, y atraves del operador asignacion se le asignan los datos que tiene el objeto Chato
    Perro Fifi;
    Fifi = Chato;
    cout << endl << " La copia con los nuevos datos de tu Mascota son " << endl;
    Fifi.Imprimir(); // Debera imprimir los mismos datos que chato, reflejando ya el cambio en el atributo nombre
	return 0;
}
