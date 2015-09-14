#include <iostream>
using namespace std;

//Protoypes
double getSales();
void findHighest(double, double, double, double);

int main() {
    double  nE, sE, nW, sW;
    
    cout << "Please enter the sales profit for the North-East Division: ";
    nE = getSales();
    cout << "Please enter the sales profit for the South-East Division: ";
    sE = getSales();
    cout << "Please enter the sales profit for the North-West Division: ";
    nW = getSales();
    cout << "Please enter the sales profit for the South-West Division: ";
    sW = getSales();
    
    findHighest(nE,sE,nW,sW);
    return 0;
}

//takes and sets the value of each divisions profits/sales
double getSales(){
    double value;
    cin >> value;
    
    while(value <= 0){
        cout << "\nUhh, it has to be a number higher than 0.00: ";
        cin >> value;
        cout << "lets see...\n";
    }
    
    cout << "Okay, so $" << value << " this quarter. Got it.\n\n";
    return value;
}

void findHighest(double nE, double sE, double nW, double sW){
    //declare a double value for the final output of the winning division
    double winnerValue = 0;
    //declare a string value for the final output of the winning division
    string winnerString;
    
    //Declares the array and sets each double value in order in their respective positions in the array
    double value[4];
    value[0] = nE;
    value[1] = sE;
    value[2] = nW;
    value[3] = sW;
    
    //Decalres the array and sets each string value in order in thier respective positions in the array
    string division[4];
    division[0] = "North-East";
    division[1] = "South-East";
    division[2] = "North-West";
    division[3] = "South-West";
    
    //goes through each divisions value
    //Array starts at 0, Ends when "i" is equal or less than 3, therfore the "for" loop itterates 4 times
    for(int i = 0; i <= 3; i++){
        //checks in each itteration if the current array value is greater than the winning value
        if(value[i] > winnerValue){
            //if the condition is true, it sets the values of the winner avriables to the corresponding array item
            winnerValue = value[i];
            winnerString = division[i];
        }
    }
    
    cout << "\n\nThe winner is the " << winnerString << " with $" << winnerValue;
    cout << " in sales this quarter.\n";
    cout << "Congratulations " << winnerString << " Division. Keep it up!";
}