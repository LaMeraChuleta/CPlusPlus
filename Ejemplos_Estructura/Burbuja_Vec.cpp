//
//  main.cpp
//  Burbuja
//
//  Created by Jafeth Alonso Carreón on 5/19/20.
//  Copyright © 2020 Jafeth Alonso Carreón. All rights reserved.
//

#include <iostream>

using namespace std;


void Imprimir(int A[], int x)
{
    int i;
    for (i=0; i<x; i++)
    {
        
        cout<<A[i]<<endl;
    }
    
}

void Burbuja(int A[], int x)
{
    int i, j, a;
    
    for(i=0;i<x-1;i++)
    {
        for(j=i+1;j<x;j++ )
        {
            if(A[i]<A[j])
            {
                a=A[i];
                A[i]=A[j];
                A[j]=a;
            }
        }
    }
    cout<<"se imprime desde la función"<<endl;
    Imprimir(A,x);
    
}


int main(int argc, const char * argv[])
{
    int n,i, *V;
    
    cout<<"teclee el numero de elementos del vector";
    cin>>n;
    V=new int [n];
    for (i=0; i<n; i++)
    {
        cout<<"teclee el elemento ["<<i+1<<" ]"<<endl;
        cin>>V[i];
    }
    
    cout<<"Los datos son:"<<endl;
    Imprimir(V,n);
    
    Burbuja(V,n);
    cout<<"El vector ordenado es:"<<endl;
    Imprimir(V,n);


    
    
    return 0;
}



