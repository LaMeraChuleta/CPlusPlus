#include<iostream>


using namespace std;


void Imprimir(int A[], int x)
{
    int i;
    for (i=0; i<x; i++)
    {
        
        cout<<A[i]<<endl;
    }
    
}

void quicksort(int A[],int izq, int der ){ 


	int i, j, pivote, aux; 
	i = izq; 
	j = der; 
	pivote = A[ (izq + der) /2 ]; 
	
    do{ 
    
        while( (A[i] < pivote) && (j <= der) ){   
            i++;
        }  		 		
        while( (pivote < A[j]) && (j > izq) ){ 
            j--;
        } 
 
        if( i <= j )
        { 
            aux = A[i]; 
			A[i] = A[j]; 
			A[j] = aux; 
            i++;  j--; 
        }
         
    }while( i <= j ); 
    

 
    if( izq < j ) 
        quicksort( A, izq, j ); 
    if( i < der ) 
        quicksort( A, i, der ); 
}

int main(){
	
	
	int *V, n;
	
	cout<<"Cuantos numero quiere ordenar"<<endl;	  
    cin>>n;
    V = new int[n];
    
    for (int i = 0; i < n; i++){
        cout<<"Teclee el elemento ["<<i+1<<" ]"<<endl;
        cin>>V[i];
    }
	
	
	cout<<"Los datos desardenados son"<<endl;
	Imprimir(V, n);
	
	quicksort(V, 0, n-1);
	
	cout<<"Los datos ordenados son"<<endl;
	Imprimir(V, n);
	
	
	
	return 0;
}
