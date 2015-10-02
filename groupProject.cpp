#include <iostream>
using namespace std;

double dailyEats(double, double, double);

int main() {
    dailyEats(7,7,2)
}


double dailyEats(double departureTime, double arrivalTime, double tripDays){
    double total, bAmount, lAmount, dAmount, debted, covered, totalDebt;

    //program should take the monitary amount of each meal eaten.
    for(double i = 0; i > tripDays; i++){
        String answer = "";
        cout << "Did you have Breakfast on day " << i << " ? [Y/N]:\n";
        cin << answer;

        while(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
            cout << "\nI didnt quite get that. Did you have Breakfast on day " << i << " ? [Y/N]: ";
            cin >> answer;
        }

        if(answer == "Y" || answer == "y"){
            cout << "\nHow much did it cost?: ";
            cin >> bAmount;
            
            if(bAmount > 9){
                debted = bAmount - 9;
                totalDebt = totalDebt + debted;
                covered = 9;
                
                
                if(covered > 0){
                cout << "Expenses covered: " <<  <<  << debted << endl;
                } else {
                    
                }
                
            } else if(bAmount < 9){
                cout << "Expenses covered: " << 
            }
        }else if(answer == "N" || answer == "n"){
            cout << "Really? You should have at least something in the morning!"
        }
        
        
        //resets the answer variable so it doesnt carry over to the next question
        answer = ""

        //cout << "Did you have Lunch? [Y/N]:\n"
        //cout << "Did you have Dinner? [Y/N]:\n"
    }
    
    //program should only take the allowable meals
    //company allows up to:
    //$9 for breeakfast
    //$12 for lunch
    //$16 for dinner
    
    //checks the time of depature
    //if departure is before 7am, breakfast is allowed as an expense
    //if departure is before 12 noon, lunch is allowed as an expense
    //if departure is before 6pm, dinner is allowed as an expense 
    
    //if arrival is before 8am, breakfast is allowed as an expense
    //if arrival is before 1pm, lunch is allowed as an expense
    //if arrival is before 7pm, dinner is allowed as an expense
}