//  Created by Bernin A. Uben on 12/10/15.
//  Copyright © 2015 Bernin A. Uben. All rights reserved.
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
public:
    Date(int, int, int);
    void setDate(int, int, int);
    string getMonth(int);
    void dateInformal();
    void dateFormal();
    void dateEurope();
};

int main(){
    //added main infront of variables for readability and clarity of main Variables
    int mainMonth, mainDay, mainYear;
    bool bVal;
    Date mainDate(1,1,2001);//constructor call
    
    cout << "Please enter a date.\n";//take user data start
    cout << "Ex:1 = January, 12 = December.\nEnter the month number: ";
    cin >> mainMonth;
    if(mainMonth < 1 || mainMonth > 12){
        bVal = true;
        while(bVal){
            cout << "hmm... okay, Please enter a CORRECT MONTH VALUE: ";
            cin >> mainMonth;
            if(mainMonth >= 1 && mainMonth <= 12){
                bVal = false;
            }
        }
    }
    cout << "Enter the day number: ";
    cin >> mainDay;
    if(mainDay < 1 || mainDay > 31){
        bVal = true;
        while(bVal){
            cout << "hmm... okay, Please enter a CORRECT DAY VALUE: ";
            cin >> mainDay;
            if(mainDay >= 1 && mainDay <= 31){
                bVal = false;
            }
        }
    }
    cout << "Enter the year: ";
    cin >> mainYear;
    
    mainDate.setDate(mainMonth, mainDay, mainYear);	cout << endl;
    mainDate.dateInformal();						cout << endl;
    mainDate.dateFormal();							cout << endl;
    mainDate.dateEurope();
    return 0;
}

Date::Date(int m, int d, int y){//Constructor
    month = m;
    day = d;
    year = y;
}
void Date::setDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

string Date::getMonth(int m){
    string month;
    switch(m){
        case 1: month = "January";
            break;
        case 2: month = "February";
            break;
        case 3: month = "March";
            break;
        case 4: month = "April";
            break;
        case 5: month = "May";
            break;
        case 6: month = "June";
            break;
        case 7: month = "July";
            break;
        case 8: month = "August";
            break;
        case 9: month = "September";
            break;
        case 10: month = "October";
            break;
        case 11: month = "November";
            break;
        case 12: month = "December";
            break;
        default: cout << "Invalid Number\n";
    }
    return month;
}

void Date::dateInformal(){
    cout << "Informal:  \n" << month << "/" << day << "/" << year << endl;
}
void Date::dateFormal(){
    string monthString = getMonth(month);
    cout << "Formal:    \n" << monthString << " " << day << ", " << year << endl;
}
void Date::dateEurope(){
    string monthString = getMonth(month);
    cout << "EU Format: \n" << day << " " << monthString << " " << year << endl;
}