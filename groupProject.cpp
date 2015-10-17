#include <iostream>
using namespace std;
double dailyEats(double, double, double);//departureTime,arrivalTime,tripDays

double allowedMeals = 0, totalMealDebt = 0, totalMealCost = 0;

int main() {
    dailyEats(700,1950,2);
    cout << "\nWe're back in main!\n";
    cout << "\nEmployees Expenses: $" << totalMealDebt << "\n Employees food expenses covered: $";
    cout << allowedMeals << "\nTotal Expenses, debt and covered expenses: $" << totalMealCost;
}

double dailyEats(double departureTime, double arrivalTime, double tripDays){
    int i, x, setX = 0, fDayMealStart = 0, onlyOnce = 0;
    double cost = 0, bExpense = 0;
    string mealType[3] = {"breakfast", "lunch", "dinner"};
    int mealMax[3] = {9, 12, 16};
    string answer = ""; //tripDays += 1; //tripDays needs to have one added to its value for it to work. The days start at 1 not 0. // If you uncomment this then you need to change the "<=" in "i <= tripDays" to an "<" sign
    
    for(i = 1;i <= tripDays;i++){
        setX = 0;
        if(fDayMealStart == 0 && i == 1){ //will not set the meal start for day one if
            if(departureTime >= 0 && departureTime <= 699){// if arrival is before 7am, breakfast is allowed as an expense
                cout << "You're covered. ᕕ(՞ ᗜ ՞)ᕗ";
                fDayMealStart++;
            }else if(departureTime >= 700 && departureTime < 1200){// if arrival is before 12pm, breakfast is allowed as an expense
                cout << "Only lunch and Dinner is covered on the first day. ┌(▀¯▀)┘ \n";
                setX = 1; fDayMealStart++;
            }else if(departureTime >= 1200 && departureTime < 1800){// if arrival is before 6pm, breakfast is allowed as an expense
                cout << "Only dinner is covered on the first day. ლ(ಥДಥ)ლ \n";
                setX = 2; fDayMealStart++;
            }else if(departureTime >= 1800 && departureTime <= 2400){
                cout << "Sorry nothing is covered on the first day. Its after 6pm.  (╯°□°)╯︵ ┻━┻ \n";
                setX = 3; fDayMealStart++;
        }   }
        
        if(i == tripDays){
            if(0 <= arrivalTime && arrivalTime <= 800){
                mealType[0] = "0"; mealType[1] = "0"; mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nSorry, nothing is covered on the last day, day "<<i<<".  (╯°□°)╯︵ ┻━┻ \n"; onlyOnce++;}
            }else if(800 < arrivalTime && arrivalTime <= 1300){ //if arrival is after 8am, breakfast is allowed as an expense
                mealType[1] = "0"; mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nOnly breakfast is covered on the last day. ლ(ಥДಥ)ლ "; onlyOnce++;}
            }else if(1300 < arrivalTime && arrivalTime <= 1900){ //if arrival is after 1pm, lunch is allowed as an expense
                mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nOnly breakfast & lunch is covered on the last day. ┌(▀¯▀)┘ \n"; onlyOnce++;}
            }else if(1900 < arrivalTime && arrivalTime <= 2400){ //if arrival is after 7pm, dinner is allowed as an expense 
                if(onlyOnce == 0){cout << "\nYou're covered on the last day, day "<<i<<". ᕕ(՞ ᗜ ՞)ᕗ \n"; onlyOnce++;}
        }   }
        
        for(x = setX;x < 3;x++){ //could of reversed this for the departureTime functionallity *Face palm*
            if(mealType[x] != "0"){
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
                    if(cost >= mealMax[x]){
                        if(cost == mealMax[x]){
                            allowedMeals = allowedMeals + mealMax[x];
                            totalMealCost = totalMealCost + cost;
                            cout <<"\n"<< mealType[x] << " expenses covered: " << mealMax[x] << endl;
                        }else if(cost > mealMax[x]){
                            double debt = 0;
                            debt = cost - mealMax[x];
                            totalMealDebt = totalMealDebt + debt;
                            totalMealCost = totalMealCost + cost;
                            bExpense = mealMax[x];
                            allowedMeals = allowedMeals + bExpense;
                            if(debt == 0){
                                cout << mealType[x] << " expenses covered: $"<<bExpense<<".\n\n";
                            } else {
                                cout << mealType[x] << " expenses covered: $"<< bExpense;
                                cout <<".\ndebt added: "<<debt<<".\n";
                            }
                        }
                    }else if(cost < mealMax[x]){
                        allowedMeals = allowedMeals + cost;
                        totalMealCost = totalMealCost + cost;
                        cout <<  mealType[x] << " expenses covered: $" << cost << endl;
                    }
                } else if(answer == "N" || answer == "n"){
                    cout << "No " << mealType[x] << ", got it. \n"; } 
                else if(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
                    while(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
                        cout << "\nI didnt quite get that. ";
                        cout << "Did you have " << mealType[x] << " on day " << i << " ? [Y/N]: ";
                        cin >> answer;
                        if(answer == "Y" || answer == "y" || answer == "N" || answer == "n"){
                //COPY OF LINES 48- --> 78 START        //COPY OF LINES 48- --> 78 START
                //ugly code but I hacked it together for it to work so whatever. Had to do it this way because this crap ass language wont let me do what I wanted to do. It kept throwing an error. so I compressed a copy of lines 48 --> 78 and inserted it here.
                            if(answer == "Y" || answer == "y"){cout << "\nHow much did it cost?:";cin >> cost;while(cost < 0){cout << "Really? So you were paid to eat there?\n";cout << "Please CORRECTLY enter the amount spent, value more than $0: ";cin >> cost;}if(cost >= mealMax[x]){if(cost == mealMax[x]){allowedMeals = allowedMeals + mealMax[x];totalMealCost = totalMealCost + cost;cout <<"\n"<< mealType[x] << " expenses covered: " << mealMax[x] << endl;}else if(cost > mealMax[x]){double debt = 0;debt = cost - mealMax[x];totalMealDebt = totalMealDebt + debt;totalMealCost = totalMealCost + cost;bExpense = mealMax[x];allowedMeals = allowedMeals + bExpense;if(debt == 0){cout << mealType[x] << " expenses covered: $"<<bExpense<<".\n\n";} else {cout << mealType[x] << " expenses covered: $"<< bExpense;cout <<".\ndebt added: "<<debt<<".\n";}}}else if(cost < mealMax[x]){allowedMeals = allowedMeals + cost;totalMealCost = totalMealCost + cost;cout <<  mealType[x] << " expenses covered: $" << cost << endl;}}else if(answer == "N" || answer == "n"){cout << "No " << mealType[x] << ", got it. \n"; }  
                //COPY OF LINES 48- --> 78 END      //COPY OF LINES 48- --> 78 END
                            break;
                        }
                    }
                }
            answer = ""; cost = 0;
            }
        }
    }
}

    //Program should only take the allowable meals
    //company allows up to:
    //$9 for breeakfast
    //$12 for lunch
    //$16 for dinner