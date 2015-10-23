#include <iostream>
using namespace std;
/* a6.cpp: Array Allocator 
Write a function that dynamically allocates an array of integers.The function
should accept an integer argument indicating the number of elements to allocate.
this function should return a pointer to the array. */
int arrayAllocator(int);

int main(){
    int number;
    int arrayPtr;
    
    cout << "How big is the array?:";
    cin >> number;
    cout << endl;
    arrayPtr = arrayAllocator(number);
    cout << "Outside, It's located at the address " << &arrayPtr << endl;
    cout << "\nThe array has space for " << number << " different integers.\n";
}

int arrayAllocator(int num){
    int *arrayPtr = new int[num];
    cout << "Inside, the arrayAllocator function, its located at ";
    cout << arrayPtr << endl;
    return *arrayPtr;
}