#include <iostream>
using namespace std;

double dailyEats(double, double, double);

int main() {
    dailyEats(7,7,2);
}


double dailyEats(double departureTime, double arrivalTime, double tripDays){
    double total, cost, bExpense, covered, totalDebt;
    String answer = "";
            
    //program should take the monitary amount of each meal eaten.
    for(double i = 0; i > tripDays; i++){
        cout << "Did you have breakfast on day " << i << "? [Y/N]:\n";
        cin << answer;
        
        while(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
            cout << "\nI didnt quite get that. Did you have Breakfast on day " << i << " ? [Y/N]: ";
            cin >> answer;
        }
        
        //Starts the Yes portion of the loop
        if(answer == "Y" || answer == "y"){
            cout << "\nHow much did it cost?: ";
            cin >> cost;
            
            /* IDEA: Itterate in an array for each item so add an array of:
            ["breakfast", "Lunch", "Dinner"],
            and use one amount variable(instead of b/l/d amount) to itterate and keep track. 
            
            Do the same with the amount limits in a different array that has [9,12,16]*/
            
            while(cost < 0){
                cout << "\nReally? So you were paid to eat there?\n";
                cout << "Please CORRECTLY enter the amount spent, value more than $0: ";
                cin << cost;
            }
            
            /*if the cost of breakfast is greater than 9, add $9 to covered,
            add the remainder to totalDebt*/
            if(cost >= 9){
                if(cost == 9){
                    cout << "\nBreakfast expenses covered: $9\n";
                } else if(cost > 9){
                    double debt = 0;
                    
                    debt = cost - 9;
                    totalDebt = totalDebt + debt;
                    bExpense = 9;
                    covered = covered + bExpense;
                    
                    if(debt == 0){
                        cout << "\nBreakfast expenses covered: "<<bExpense<<".\nDebt: "<<debt<<".\n";
                    }
                }
            } else if(cost < 9){
                covered = covered + cost;
                cout << "Expenses covered: " << cost << endl;
            }
        //Starts the NO portion of the loop
        } else if(answer == "N" || answer == "n"){
            cout << "Really? You should have at least something in the morning!"
        }
        
        //resets the answer variable so it doesnt carry over to the next question
        answer = "";
        cost = 0;
        /*     --------------------- LUNCH STAGE ---------------------   */
        
        /*     --------------------- DINNER STAGE ---------------------   */
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