//  a13.cpp
//
//  Created by Bernin A. Uben on 12/10/15.
//  Copyright © 2015 Bernin A. Uben. All rights reserved.
//

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
    void dateInformal();
    void dateFormal();
    void dateEurope();
    string getMonth(int);
};

//Constructor
Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::setDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void dateInformal(){
    //cout << "Informal: " << month << "/" << day << "/" << year << endl;
}

void dateFormal(){
    //cout << "Formal: " << month << " " << day << ", " << year << endl;
}

void dateEurope(){
    //cout << "EU Format: " << day << " " << month << ", " << year << endl;
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

int main(){
    //added main infront of variables for readability and clarity of main Variables
    int mainMonth, mainDay, mainYear;
    bool bVal;
    //constructor call
    Date mainDate(1,1,2001);
    
    //take user data
    cout << "Please enter the date.\n";
    cout << "Enter the month: ";
    cin >> mainMonth;
    
    if(mainMonth < 1 || mainMonth > 12){
        bVal = true;
        while(bVal){
            cout << "hmm... okay, Please enter the CORRECT MONTH VALUE: ";
            cin >> mainMonth;
            if(mainMonth >= 1 && mainMonth <= 12){
                bVal = false;
            }
        }
    }
    
    cout << "Enter the day: ";
    cin >> mainDay;
    
    if(mainDay < 1 || mainDay > 31){
        bVal = true;
        while(bVal){
            cout << "hmm... okay, Please enter the CORRECT DAY VALUE: ";
            cin >> mainDay;
            if(mainDay >= 1 && mainDay <= 31){
                bVal = false;
            }
        }
    }
    
    cout << "Enter the year: ";
    cin >> mainYear;
    
    if(mainYear < 1950){
        bVal = true;
        while(bVal){
            cout << "hmm... okay, Please enter a year after 1950: ";
            cin >> mainYear;
            if(mainYear > 1950){
                bVal = false;
            }
        }
    }

    return 0;
}





















