#include<iostream>
#include <thread>
#include <chrono>

using namespace std;
int main(){
    cout<<"Hola Mundo!!"<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));    
    return 0;
}