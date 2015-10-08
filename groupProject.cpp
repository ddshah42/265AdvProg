#include <iostream>
using namespace std;
double dailyEats(double, double, double);
int main() {
    dailyEats(799,1500,2);
}
double dailyEats(double arrivalTime, double departureTime, double tripDays){
    int i, x, f, mealPos = 0, fDayMealStart = 0, onlyOnce = 0;
    int dMealVal = 3, intTripDays = tripDays;//sets double tripDays to int
    double cost = 0, covered = 0, totalDebt = 0, bExpense = 0;
    string mealType[3] = {"breakfast", "lunch", "dinner"};
    int mealMax[3] = {9, 12, 16};
    string answer = ""; //tripDays += 1; //tripDays needs to have one added to its value for it to work. The days start at 1 not 0. // If you uncomment this then you need to change the "<=" in "i <= tripDays" to an "<" sign
    for(i = 1;i <= tripDays;i++){
        if(i == intTripDays){
            if(departureTime < 700){
                mealType[1] = {"0"}; mealType[2] = {"0"};
                if(onlyOnce == 0){cout << "\n ****** Only breakfast is being covered ****** \n"; onlyOnce++;}
            }else if(departureTime < 1200){
                mealType[2] = {"0"};
                if(onlyOnce == 0){cout << "\n ****** Only breakfast & lunch is being covered ****** \n"; onlyOnce++;}
            }else if(departureTime < 1800){
                
            } else {
                mealType[0] = {"0"}; mealType[1] = {"0"}; mealType[2] = {"0"};
            }
        }
        for(x = mealPos;x < dMealVal;x++){ //could of reversed this for the departureTime functionallity *Face palm*
            if(fDayMealStart != 0){ //will not set the meal start for day one if
            }else if(fDayMealStart == 0){
                if(i = 1 && arrivalTime < 800){
                    fDayMealStart++; //Nothing. Program will go on as planned
                }else if(i = 1 && arrivalTime < 1300){
                    x = 1;
                    fDayMealStart++;
                    cout << "Only lunch and Dinner will be covered on the first day.\n";
                }else if(i = 1 && arrivalTime < 1900){
                    x = 2;
                    fDayMealStart++;
                    cout << "Only dinner will be covered on the first day.";
            }   }
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
                            covered = covered + mealMax[x];
                            cout <<"\n"<< mealType[x] << " expenses covered: " << mealMax[x] << endl;
                        }else if(cost > mealMax[x]){
                            double debt = 0;
                            debt = cost - mealMax[x];
                            totalDebt = totalDebt + debt;
                            bExpense = mealMax[x];
                            covered = covered + bExpense;
                            if(debt == 0){
                                cout << mealType[x] << " expenses covered: $"<<bExpense<<".\n\n";
                            } else {
                                cout << mealType[x] << " expenses covered: $"<< bExpense;
                                cout <<".\ndebt added: "<<debt<<".\n";
                            }
                        }
                    }else if(cost < mealMax[x]){
                        covered = covered + cost;
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
                            if(answer=="Y"||answer=="y"){cout<<"\nHow much did it cost?:";cin>>cost;while(cost<0){cout<<"Really? So you were paid to eat there?\n";cout <<"Please CORRECTLY enter the amount spent, value more than $0: ";cin>>cost;}if(cost>=mealMax[x]){if(cost==mealMax[x]){covered=covered+mealMax[x];cout<<"\n"<<mealType[x]<<"expenses covered: "<< mealMax[x]<<endl;}else if(cost>mealMax[x]){double debt=0;debt=cost-mealMax[x];totalDebt=totalDebt+debt;bExpense=mealMax[x];covered=covered+bExpense;if(debt==0){cout<<mealType[x]<<" expenses covered: $"<<bExpense<<".\n\n";}else{cout<<mealType[x]<< " expenses covered: $"<<bExpense;cout <<".\ndebt added: "<<debt<<".\n";}}}else if(cost<mealMax[x]){covered=covered+cost;cout<<mealType[x]<<" expenses covered: $"<<cost<<endl;}}else if(answer=="N"||answer=="n"){cout<<"No "<< mealType[x]<<", got it. \n";}
                //COPY OF LINES 48- --> 78 END      //COPY OF LINES 48- --> 78 END
                            break;
                        }
                    }
                }
            answer = ""; cost = 0;
            }
        }
    }
    cout << "\n\nTotal Debt: $" << totalDebt << endl;
    cout << "Food expenses covered: $" << covered << endl;
}

    //Program should only take the allowable meals
    //company allows up to:
    //$9 for breeakfast
    //$12 for lunch
    //$16 for dinner

    //Checks time of arrival
    //if arrival is before 8am, breakfast is allowed as an expense
    //if arrival is before 1pm, lunch is allowed as an expense
    //if arrival is before 7pm, dinner is allowed as an expense
    
    //Checks time of depature
    //if departure is before 7am, breakfast is allowed as an expense
    //if departure is before 12 noon, lunch is allowed as an expense
    //if departure is before 6pm, dinner is allowed as an expense 