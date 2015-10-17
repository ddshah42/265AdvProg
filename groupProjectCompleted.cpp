#include <iostream>
#include <cstdlib>
using namespace std;
//  Group 2 Project

//prototypes
int numDays ();
int departTime();
int arrivalTime();
double numAirfare();
double numCarRental();
double povCost();
double parkingCost();
double taxiFees();
double conferenceFees();
double hotelFees();
double dailyEats(double, double, double); //(ME)

//Global Variables CRITICAL for dailyEats();   (ME)
double allowedMeals = 0, totalMealDebt = 0, totalMealCost = 0;
/* double totalMealCost == ALL expenses added in by the user
double totalMealDebt == ALL expenses NOT COVERED by company that employee must pay
double allowedMeals  == ALL expenses COVERED by the company */

int main() {
    //variables, actual amount
    int days = 0;
    int depart, arrive = 0;
    double airfare = 0;
    double miles = 0;
    double carRental = 0;
    double parking = 0;
    double taxi = 0;
    double confCost = 0;
    double hotel = 0;
    double vehicleExpense = 0;
    double totalExp = 0;
    double reimburse = 0;
    double amountSaved = 0;
    
    //variables, allowed expenses
    double allowedParking;
    double allowedTaxi;
    double allowedHotel;
    double totalAllowedExp;
    double userFees; //amount BM spends on in total on parking, taci, hotel and meal
    
    //actual total expenses
    days = numDays();
    depart = departTime();
    arrive = arrivalTime();
    airfare = numAirfare();
    miles = povCost();
    vehicleExpense = miles * .27;
    carRental = numCarRental();
    parking = parkingCost();
    taxi = taxiFees();
    confCost = conferenceFees();
    hotel = hotelFees();
    dailyEats(depart,arrive,days); //ME - Supposed to send the user to insert all info to set the variables
    
    //allowed expenses
    allowedParking = days * 6;
    allowedTaxi = days * 10;
    allowedHotel = days * 90;
    //no need to overwrite allowedMeals
    
    //totals
    totalExp = airfare + vehicleExpense + carRental + parking + taxi +
                confCost + hotel + totalMealCost; //added totalMealCost for total cost of all the meals
    
    totalAllowedExp = allowedParking + allowedTaxi + allowedHotel + allowedMeals;// added allowedMeals for total cost of the company covered meals
    
    userFees = parking + taxi + hotel + totalMealDebt; //added totalMealDebt for total cost of meals not covered by the company
    
    //calculate total BM must reimburse to company or amount saved
    if (totalAllowedExp>userFees)
    {
        amountSaved = totalAllowedExp - userFees;
    }
    else
    {
        reimburse = userFees - amountSaved;
    }
  
    //display totals
    cout << "Total expenses incurred: $" << totalExp << endl;
    cout << "Total allowable expenses: $" << totalAllowedExp << endl;
    cout << "Amount to be reimbursed: $" << reimburse << endl;
    cout << "Amount saved: $" << amountSaved << endl;

    return 0;
}

//function #1 for days spent on the trip
int numDays()
{
    int days;
    cout << "How many days were you on the trip?: ";
    cin >> days;
    cout << endl;
    //input validation
    while (days < 1)
    {
        cout << "The number must be greater than 0, try again: ";
        cin >> days;
        cout << endl;
    }
    
    return days;
}

//function #2a Departure time
int departTime(){
    
    int depart;
    int hour,minute;//declaring variables
    char day;//declaring char for switch later on
    
    //decided to let the user input AM/PM for convenience incase the person
    //doesn't know how to convert to military time. The function will take in
    //user input for time as standard 12 hour system, then convert to military time.
    //,then pass back to main, without having the user to do so.
    
    cout<<"did you leave in the morning or the afternoon?\n type in A for AM or P for PM.\n";
    cin>>day;
    
    
    //a while loop in case the user inputs any value other than A or P
    while(day!='a'&&day!='A'&&day!='P'&&day!='p')
    {cout<<"Please enter either P or A\n";
        cin>>day;
    }
    
    //switch, directing to different cases depending on the value 'day' that the user
    //chose.
    switch(day)
    
    {
            //case 'a' if user's input was A for AM
        case 'a':case'A':
            cout<<"Enter the hour of departure\n";
            cin>>hour;
            
            //while loop incase the user types in negative hours or value over 12
            while(hour<0||hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }
            
            cout<<"Enter the minute of departure\n";
            cin>>minute;
            //another while loop in case user error
            while(minute<=0|minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }
            //converting input values into military standard time, then returning to main.
            hour=100*hour;
            depart=hour+minute;
            return depart;
            break;
            
            
            //case 2 for p inputs for PM
        default:
            
            cout<<"Enter the hour of departure\n";
            cin>>hour;
            //while loop for input error
            while(hour<0|hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }
            cout<<"Enter the minute of departure\n";
            cin>>minute;
            //while loop for input error
            while(minute<=0||minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }
            //if..else statement to adjust to military standard time being +12 hours in
            //the afternoon.
            if(hour==12)
            {hour=hour*100;
                depart=hour+minute;
            }
            
            
            else
            {
                
                hour=hour*100;
                depart=hour+minute+1200;
            }
            //converts to military time, then returns to main.
            return depart;
            break;
    }
    
}

//function #2B arrival time
int arrivalTime()
{
    int arrive;
    int hour,minute;//declaring variables
    char day;//declaring char for switch later on
    
    //decided to let the user input AM/PM for convenience incase the person
    //doesn't know how to convert to military time. The function will take in
    //user input for time as standard 12 hour system, then convert to military time.
    //,then pass back to main, without having the user to do so.
    
    cout<<"did you leave in the morning or the afternoon?\n type in A for AM or P for PM.\n";
    cin>>day;
    
    //a while loop in case the user inputs any value other than A or P
    while(day!='a'&&day!='A'&&day!='P'&&day!='p')
    {cout<<"Please enter either P or A\n";
        cin>>day;
    }
    
    //switch, directing to different cases depending on the value 'day' that the user
    //chose.
    switch(day)
    
    {
            //case 'a' if user's input was A for AM
        case 'a':case'A':
            cout<<"Enter the hour of arrival\n";
            cin>>hour;
            
            //while loop incase the user types in negative hours or value over 12
            while(hour<0||hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }
            
            cout<<"Enter the minute of arrival\n";
            cin>>minute;
            //another while loop in case user error
            while(minute<=0|minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }
            //converting input values into military standard time, then returning to main.
            hour=100*hour;
            arrive=hour+minute;
            return arrive;
            break;
            
            
            //case 2 for p inputs for PM
        default:
            
            cout<<"Enter the hour of arrival\n";
            cin>>hour;
            //while loop for input error
            while(hour<0|hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }
            cout<<"Enter the minute of arrival\n";
            cin>>minute;
            //while loop for input error
            while(minute<=0||minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }
            //if..else statement to adjust to military standard time being +12 hours in
            //the afternoon.
            if(hour==12)
            {hour=hour*100;
                arrive=hour+minute;
            }
            
            
            else{
                
                hour=hour*100;
                arrive=hour+minute+1200;
            }
            //converts to military time, then returns to main.
            return arrive;
            break;
    }
    
}

//function #3 for airplane expenses
double numAirfare ()
{
    double airfare;
    cout << "What was the total cost of air fare?: ";
    cin >> airfare;
    cout << endl;
    //input validation
    while (airfare < 0)
    {
        cout << "The number must be greater than 0, try again: ";
        cin >> airfare;
        cout << endl;
    }
    
    return airfare;
}

//function #4 for car rental costs
double numCarRental ()
{
    double carRental;
    cout << "What was the total cost of car rentals?: ";
    cin >> carRental;
    cout << endl;
    //input validation
    while (carRental < 0)
    {
        cout << "The number must be greater than 0, try again: ";
        cin >> carRental;
        cout << endl;
    }
    
    return carRental;
}

//calculates miles driven if privately owned vehicle was used
double povCost()
{
    double miles;
    char answer;
    
    cout<<"Did you travel via privately owned vehicle? Y or N\n";
    cin>>answer;
    //in case user inputs are not Y or N
    if(answer!= 'Y'&&answer!='y'&&answer!='n'&&answer!='N')
    {
        cout<<"Type Y for yes, or N for no.\n";
        cin>> answer;
    }
    //switch statement to calculate or return 0 according to the user input.
    switch(answer)
    {
            
        case 'y':case 'Y':
            cout<<"How many miles did you travel?\n";
            cin>>miles;
            //if statement in case the user enters negative value
            if(miles<=0)
            {
                cout<<"Please enter the miles traveled.\n";
                cin>>miles;
            }
            
            return miles;
            break;
            
        default:
            miles = 0;
            return miles;
            break;
    }
}

//function 6 calculates parking fee
double parkingCost(){
    double park;
    cout<<"How much did parking cost?";
    cin>>park;
    while (park<0)
    {
        {cout<<"Please enter a positive value\n";
            cin>>park;
        }
    }
    
    return park;
    
    
}

//#7 calculate taxi fees
double taxiFees()
{
    double taxiFee;
    cout << "How much was spent on taxi fees? $";
    cin >> taxiFee;
    cout << endl;
    
    while (taxiFee<0)
    {
        cout << "Please enter a positive value.  ";
        cin >> taxiFee;
    }
    
    return taxiFee;
}

//#8 calculate conference and seminar fees
double conferenceFees()
{
    double confFee;
    cout << "How much was spent on conference/seminar fees? $";
    cin >> confFee;
    cout << endl;
    
    while (confFee<0)
    {
        cout << "Please enter a positive value.  ";
        cin >> confFee;
    }
    
    return confFee;
}

//#9 Calculate hotel fees
double hotelFees()
{
    double hotelFee;
    cout << "How much was spent on hotel fees? $";
    cin >> hotelFee;
    cout << endl;
    
    while (hotelFee<0)
    {
        cout << "Please enter a positive value.  ";
        cin >> hotelFee;
    }
    
    return hotelFee;
}

//#10 (ME) Calculate Meal Fees
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
                cout << "All you're meals are covered* on your first day.";
                fDayMealStart++;
            }else if(departureTime >= 700 && departureTime < 1200){// if arrival is before 12pm, breakfast is allowed as an expense
                cout << "Only lunch and Dinner is covered on the first day. \n";
                setX = 1; fDayMealStart++;
            }else if(departureTime >= 1200 && departureTime < 1800){// if arrival is before 6pm, breakfast is allowed as an expense
                cout << "Only dinner is covered on the first day.\n";
                setX = 2; fDayMealStart++;
            }else if(departureTime >= 1800 && departureTime <= 2400){
                cout << "Sorry nothing is covered on the first day. Its after 6pm. \n";
                setX = 3; fDayMealStart++;
        }   }
        
        if(i == tripDays){
            if(0 <= arrivalTime && arrivalTime <= 800){
                mealType[0] = "0"; mealType[1] = "0"; mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nSorry, nothing is covered on the last day, day "<<i<<". \n"; onlyOnce++;}
            }else if(800 < arrivalTime && arrivalTime <= 1300){ //if arrival is after 8am, breakfast is allowed as an expense
                mealType[1] = "0"; mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nOnly breakfast is covered on the last day. \n"; onlyOnce++;}
            }else if(1300 < arrivalTime && arrivalTime <= 1900){ //if arrival is after 1pm, lunch is allowed as an expense
                mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nOnly breakfast & lunch is covered on the last day. \n"; onlyOnce++;}
            }else if(1900 < arrivalTime && arrivalTime <= 2400){ //if arrival is after 7pm, dinner is allowed as an expense 
                if(onlyOnce == 0){cout << "\nYou're meals will be covered on the last day, day "<<i<<". \n"; onlyOnce++;}
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
    cout << "\nEmployee debt: $" << totalMealDebt << "\nEmployees food expenses covered: $";
    cout << allowedMeals << "\nTotal employee meal expenses, debt & covered expenses: $" << totalMealCost << endl;
}
