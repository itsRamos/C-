//**********************************************************************************
// Test file for hashTable.h
// Author: Erick Ramos
// Date: December 11, 2017
//***********************************************************************************
#include <iostream>
#include "hashTable.h"
using namespace std;

int main( ) {
    HashTable<int> h1;
    HashTable<int> h2;

    const int NUMS = 400000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        h1.insert( i );
    
    h2 = h1;
    
    for( i = 1; i < NUMS; i += 2 )
        h2.remove( i );

    for( i = 2; i < NUMS; i += 2 )
        if( !h2.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 ) {
        if( h2.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }

    cout << "\nh1 size: " << h1.getCurrentSize()
         << "\nh2 size: " << h2.getCurrentSize();
    return 0;
}
