#include <iostream>
#include <string>
using namespace std;
/*
    A student has estalbished the following monthly budget:
    Housing
    Utilities
    Household Expenses
    Transportation
    Food
    Medical
    Insurance
    Entertainment
    Clothing
    Miscellaneous
    
    Write a program that has a MonthlyBudget structure designed to hold each of
    these expense categories. The program should pass the structure to a function
    that asks the user to enter the ammounts spent in each budget caegory during
    a month. The origram shuld then passthe structure to a function that displays
    a report indicating the amount over or under in each category, as well as the
    amount over or under for the entire monthly budget.
*/

struct MonthlyBudget{
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

void getMonth(MonthlyBudget &);
void displayMonthlyBudget(MonthlyBudget);

const int ARRAYSIZE = 10;

int main() {
    cout << "-------------------------------------------------------\n";
    cout << "|-------------------- Budget Program -----------------|\n";
    cout << "-------------------------------------------------------\n";
    
    MonthlyBudget month;
    
    getMonth(month);
    displayMonthlyBudget(month);
    
    return 0;
}

void getMonth(MonthlyBudget &m){
    cout << "Enter the amount spent on:\n";
    
    cout << "Housing:";
    cin >> m.housing;

    cout << "Utilities:";
    cin >> m.utilities;
    
    cout << "Household Expenses:";
    cin >> m.householdExpenses;
    
    cout << "Transportation:";
    cin >> m.transportation;
    
    cout << "Food:";
    cin >> m.food;
    
    cout << "Medical:";
    cin >> m.medical;
    
    cout << "Insurance:";
    cin >> m.insurance;
    
    cout << "Entertainment:";
    cin >> m.entertainment;
    
    cout << "Clothing:";
    cin >> m.clothing;
    
    cout << "Miscellaneous:";
    cin >> m.miscellaneous;
}

void displayMonthlyBudget(MonthlyBudget m){
    double total=0, totalM=1420, difference=0;
    double val[ARRAYSIZE] = { m.housing, m.utilities, m.householdExpenses,
                      m.transportation, m.food, m.medical, m.insurance,
                      m.entertainment, m.clothing, m.miscellaneous };
    double amounts[ARRAYSIZE] = { 500.00, 150.00, 65.00, 50.00, 250.00,
                                 30.00, 100.00, 150.00, 75.00, 50.00 };
    string cat[ARRAYSIZE] = { "Housing", "Utilities", "Household Expenses",
                      "Transportation", "Food", "Medical", "Insurance",
                      "Entertainment", "Clothing", "Miscellaneous" };
    cout << "\n\n------------------------------------------------------\n";  
    cout << "|------------------ Monthly Report ------------------|\n";
    cout << "------------------------------------------------------\n\n"; 
    
    for(int x = 0;x < ARRAYSIZE;x++){
        difference = amounts[x] - val[x];
        if(val[x] == amounts[x]){
            cout << cat[x] << ": $" << difference << " --- UNDER BUDGET\n";
        }else if(difference < 0){
            cout << cat[x] << ": $" << difference << " --- OVER BUDGET\n";
        }else if(difference >= 0){
            cout << cat[x] << ": $" << difference << " --- UNDER BUDGET\n";
        }
    }
    
    total = m.housing + m.utilities + m.householdExpenses +
            m.transportation + m.food + m.medical + m.insurance +
            m.entertainment + m.clothing + m.miscellaneous;

    cout << "\n\n------------------------------------------------------\n";
    cout << "|------------------ Summary: Total ------------------|\n";
    cout << "------------------------------------------------------\n";
    
    if(total > 1420){
        cout << "Maximum expenses for the month are: $1420\nExpenses ";
        cout << "for this month are: $" << total << "\nMonthly Expenses OVER BUDGET by";
        cout << " $" << 1420 - total << ".\n";
    }else {
        cout << "Maximum expenses for the month are: $" << totalM << "\nExpenses ";
        cout << "for this month are: $" << total << "\nMonthly Expenses UNDER BUDGET by";
        cout << " $" << totalM - total << ".\n";
    }
}
