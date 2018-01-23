#include <iostream>
#include "SeparateChaining.h"

int main(){
    HashTable<int> h1;
    HashTable<int> h2;
    
    const int NUMS = 400000;
    const int GAP = 37;
    int i;
    
    cout << "Loading..." << endl;
    
    for(i = GAP; i != 0; i = (i + GAP) % NUMS){
        h1.insert(i);
    }
    
    cout << "Blockchain has been loaded" << endl;
    h2 = h1;
    
    for(i = 1; i < NUMS; i += 2){
        h2.remove(i);
    }
    
    for(i =2; i < NUMS; i +=2){
        if(!h2.contains(i)){
           cout << "Contains fails " << i << endl; 
        }
    }
    
    for(i = 1; i < NUMS; i +=2){
        if(h2.contains(i)){
            cout << "Unable to load. Please Retry" << i << endl;
        }
    }
    
    cout << "Size of h1: " << h1.getCurrentSize() <<
    endl << "Size of h2: " << h2.getCurrentSize();
         
    return 0;
}