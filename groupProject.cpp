#include <iostream>
using namespace std;

double dailyEats(double, double, double);

int main() {
    dailyEats(800,700,3);
}

double dailyEats(double departureTime, double arrivalTime, double tripDays){
    int i, x, dayOne = 1, mealPos = 0, fDayMealStart = 0, dMealVal = 3;
    double cost = 0, covered = 0, totalDebt = 0, bExpense = 0;
    string mealType[3] = {"breakfast", "lunch", "dinner"};
    int mealMax[4] = {0, 9, 12, 16};
    string answer = "";
    tripDays += 1; //tripDays needs to have one added to its value for it to work. The days start at 1 not 0
    for(i = dayOne;i < tripDays;i++){
        for(x = mealPos;x < dMealVal;x++){
            if(fDayMealStart != 0){
                //will not set the meal start for day one if
            }else if(fDayMealStart == 0){
                if(i = 1 && arrivalTime < 700){
                    fDayMealStart++;
                    //Nothing. Program will go on as planned
                }else if(i = 1 && arrivalTime < 1200){
                    x = 1;
                    fDayMealStart++;
                    cout << "Only lunch and Dinner will be covered on the first day.\n";
                }else if(i = 1 && arrivalTime < 1800){
                    x = 2;
                    fDayMealStart++;
                    cout << "Only dinner will be covered on the first day.";
                }
            }
            cout << "\nDid you have " << mealType[x] << " on day " << i << "? [Y/N]: ";
            cin >> answer;
            
            if(answer == "Y" || answer == "y"){
                cout << "\nHow much did it cost?:";
                cin >> cost;
                while(cost < 0){
                    cout << "Really? So you were paid to eat there?\n";
                    cout << "Please CORRECTLY enter the amount spent, value more than $0: ";
                    cin >> cost;
                }
                if(cost >= mealMax[x+1]){
                    if(cost == mealMax[x+1]){
                        covered = covered + mealMax[x+1];
                        cout <<"\n"<< mealType[x] << " expenses covered: " << mealMax[x+1] << endl;
                    }else if(cost > mealMax[x+1]){
                        double debt = 0;
                        debt = cost - mealMax[x+1];
                        totalDebt = totalDebt + debt;
                        bExpense = mealMax[x+1];
                        covered = covered + bExpense;
                        
                        if(debt == 0){
                            cout << mealType[x] << " expenses covered: $"<<bExpense<<".\n\n";
                        } else {
                            cout << mealType[x] << " expenses covered: $"<< bExpense;
                            cout <<".\ndebt added: "<<debt<<".\n";
                        }
                    }
                }else if(cost < mealMax[x+1]){
                    covered = covered + cost;
                    cout <<  mealType[x] << " expenses covered: $" << cost << endl;
                }
            } else if(answer == "N" || answer == "n"){
                cout << "No " << mealType[x] << ", got it. \n";
            }
            answer = ""; cost = 0;
        }
        dayOne++;
    }
    cout << "\n\nTotal Debt: " << totalDebt << endl;
    cout << "Food expenses covered: " << covered << endl;
}

/*        
    if(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
        while(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
            cout << "\nI didnt quite get that. ";
            cout << "Did you have " << mealType[x] << " on day " << i << " ? [Y/N]: ";
            cin >> answer;
    } else {
        cout << "\nOh Okay, ";
    }
*/
    
    /* IDEA: Itterate in an array for each item so add an array of:
    ["breakfast", "Lunch", "Dinner"],
    and use one amount variable(instead of b/l/d amount) to itterate and keep track. 
    Do the same with the amount limits in a different array that has [9,12,16]*/
    
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