#include<iostream>
#include<cmath>
#include<string.h>
#include <thread>
#include <chrono>
using namespace std;

#include <windows.h>
void ClearScreen(){
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };
    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;
    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;
  /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
    )) return;
  /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;
    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}
class Euler{
    public:
        float x;
        float y;
        float h;
        float limiteX;
    public:
        Euler(float, float, float, float);
        void Iterar_Formula_Normal();
        void Iterar_Formula_Mejorada();
        void Formula_Normal(); 
        void Formula_Mejorada(float, float); 
        ~Euler();                     
};
Euler::Euler(float x, float y, float h, float limite){
    this->x = x;
    this->y = y;
    this->h = h;
    this->limiteX = limite;
}
Euler::~Euler(){ cout<<"Ejecutando Destructor!"<<endl; }
void Euler::Iterar_Formula_Normal(){
    cout<<"Iterando..."<<endl;    
    cout<<"x: "<<this->x<<"\t"<<"y: "<<this->y<<endl;    
    while(x <= this->limiteX){        
        this->Formula_Normal();
        cout<<"x: "<<this->x<<"\t"<<"y: "<<this->y<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));    
    }       
    cin.ignore().get();
}
void Euler::Formula_Normal(){
    //Para el caso especifico de estaecuacion diferencial
    this->y = this->y + this->h * (this->x + 2.0 * this->x * this->y);
    this->x = this->x + this->h;
}
void Euler::Iterar_Formula_Mejorada(){
    float _x, _y, _limiteX;
    cout<<"Iterando..."<<endl;    
    //Guardamos los datos anteriores    
    _x = this->x; _y = this->y;      
    cout<<"Yp: "<<this->x<<"\t"<<this->y<<"\t";
    this->Formula_Normal();   
    this->Formula_Mejorada(_x, _y);   
    cout<<"Yc: "<<this->x<<"\t"<<this->y<<"\n";    
    while(x <= this->limiteX){
        _x = this->x; _y = this->y;          
        cout<<"Yp: "<<this->x<<"\t"<<this->y<<"\t"; 
        this->Formula_Normal();  
        this->Formula_Mejorada(_x, _y);  
        cout<<"Yc: "<<this->x<<"\t"<<this->y<<"\n";                      
        std::this_thread::sleep_for(std::chrono::milliseconds(200));    
    }        
    cin.ignore().get();
}
void Euler::Formula_Mejorada(float _x, float _y){
    this->y = _y + this->h / 2.0 * (_x + 2.0 * _x * _y + this->x + 2.0  * this->x * this->y);
}
float* Menu_Inicio(){
    float* datos = new float[4];
    cout<<"Valores Inciales"<<endl;
    cout<<"Ingrese el valor de x0\t";
    cin>>datos[0];cout<<"\n";  
    cout<<"Ingrese el valor de y0\t";
    cin>>datos[1];cout<<"\n";
    cout<<"Ingrese el limite de h\t";
    cin>>datos[2];cout<<"\n";
    cout<<"Ingrese el limite de x\t";
    cin>>datos[3];cout<<"\n";
    return datos;
}
int main() {
    int opc;
    do {        
        cout<<"METODO DE EULER\n\n";
        cout<<"Ecuacion Diferencial: y´ - 2xy = x\n\n";
        cout<<"Euler            [1]"<<endl;
        cout<<"Euler Mejorado   [2]"<<endl;
        cout<<"Salir            [3]"<<endl; 
        cout<<"Seleccione la opcion:\t";cin>>opc;
        ClearScreen();
        switch (opc){
            case 1:{
                float* datos = Menu_Inicio();                    
                Euler e(datos[0],datos[1],datos[2],datos[3]); 
                e.Iterar_Formula_Normal();            
            }
            break; 
            case 2:  {
                float* datos = Menu_Inicio();
                Euler e(datos[0],datos[1],datos[2],datos[3]); 
                e.Iterar_Formula_Mejorada();            
            }
            break;                     
            default:
                cout<<"Adios"<<endl;
                cin.ignore().get();
                opc = 3;
                break;
        }                              
        ClearScreen();
    }
    while(opc < 3);   
    return 1;
}