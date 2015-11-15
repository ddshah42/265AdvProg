#include <iostream>
#include <string>
using namespace std;

int characterCounter(string );

/*
    Write a function that returns an integer and accepts a pointer to a
    C-string as an argument. the function should count the number of
    characters in the string and return that number. Demonstrate the fucntion
    in a simple program that asks the user toinput a string. Passes it to
    the function, and then displays the function's return value.
*/

int main() {
    string convert;
    int count;
    
    cout << "Please enter a string: ";
    cin >> convert;
    
    count = characterCounter(convert);
    cout << "There are " << count << " characters in this String.\n";
}

int characterCounter(string str){
    int count = 0, x = 0;
    
    while(str[x] != '\0'){
        count++;
        x++;
    }
    
    return count;
}