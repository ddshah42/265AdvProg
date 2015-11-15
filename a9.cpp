#include <iostream>
#include <string>
using namespace std;
 
 /*
    Write a program that has an array of atleast 10 string objects that hold people's
    names and phone numbers. You may make up your own strings, or use the example. The
    program should ask the user to enter a name or partial to search for in the array.
    Any entries in the array that match the string entered should be displayed. For
    example, if the user enters "Palmer" the program should display all objects matching
    "Palmer" whether if its Many, One or No items are found.
 */

//Added constant because regular int in main body wont work for some reason.

const int NUM = 11;

int main() {
    int counter = 1;
    string userStr;
    string contacts[NUM] = {"Becky Warren --- 555-1223",
                            "Joe Looney ----- 555-0097",
                            "Geri Palmer ---- 555-8787",
                            "Lynn Presnell -- 555-1212",
                            "Holly Gaddis --- 555-8878",
                            "Sam Wiggins ---- 555-0998",
                            "Bob Kain ------- 555-8712",
                            "Tim Haynes ----- 555-7676",
                            "Warren Gaddis -- 555-9037",
                            "Jean James ----- 555-4939",
                            "Ron Palmer ----- 555-2783" };
    
    cout << " All Contacts in Phone Number List\n";
    cout << "-----------------------------------\n";
    for(int x = 0; x < NUM; x++){
        if(x <= 8){ // Displays the same thing, "If" is for cosmetic appearance
            cout << "   " << x + 1 << "  " << contacts[x] << endl;
        } else {
            cout << "   " << x + 1 << " " << contacts[x] << endl;
    }   }
    
    cout << "\nEnter a name or a partial to search the list: ";
    cin >> userStr;
    cout << "Names Matched:\n";
    for (int i = 0; i < NUM; i++){
        int finder = contacts[i].find(userStr, 0);
        if (finder > 0){
            cout << counter << ": " << contacts[i] << endl;
            counter++;
}   }   }