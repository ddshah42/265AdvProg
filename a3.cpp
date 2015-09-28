#include <iostream>
using namespace std;

double inPatient(double, double, double, double);
double outPatient(double, double);

int main() {
    int sType = 0;
    double daysSpent, dailyRate, charges, serviceCharges, total;
    
    cout << "Was the patient admitted as an in or out patient?\n";
    cout << "1 for in-patient.\n2 for out-patient.\n1 or 2:";
    cin >> sType;
    
    while (sType != 1 && sType != 2){
        cout << sType << " is an invalid answer. 1 for IN-patient, 2 for OUT-patient\n";
        cout << "Lets try that again: ";
        cin >> sType;
    }
    
    if (sType == 1){
        cout << "\nThe person is an in-patient so how many days were spent in the hospital?\n";
        cin >> daysSpent;
        while(daysSpent < 0){
            cout << daysSpent <<" no negative answers please! Re-enter the value.\n";
            cin >> daysSpent;
        }
        
        cout << "\nOkay so whats the daily rate?\n$";
        cin >> dailyRate;
        while(dailyRate < 0){
            cout << dailyRate <<" no negative answers please! Re-enter the value.\n";
            cin >> dailyRate;
        }
        
        cout << "\nThanks. Whats the medication charges?\n$";
        cin >> charges;
        while(charges < 0){
            cout << charges <<" no negative answers please! Re-enter the value.\n";
            cin >> charges;
        }
        
        cout << "Okay and lastly, I need any and all charges for hospital services\n$";
        cin >> serviceCharges;
        while(serviceCharges < 0){
            cout << serviceCharges <<" no negative answers please! Re-enter the value.\n";
            cin >> serviceCharges;
        }
        
        total = inPatient(daysSpent, dailyRate, charges, serviceCharges);
        cout << "Send them a bill of $" << total << ".\n";
    } else if (sType == 2){
        cout << "What is the medication charges?\n$";
        cin >> charges;
        while(charges < 0){
            cout << charges <<" no negative answers please! Re-enter the value.\n";
            cin >> charges;
        }
        
        cout << "Okay and lastly, I need any and all charges for hospital services\n$";
        cin >> serviceCharges;
        while(serviceCharges < 0){
            cout << serviceCharges <<" no negative answers please! Re-enter the value.\n";
            cin >> serviceCharges;
        }
        
        total = outPatient(charges, serviceCharges);
        cout << "Send them a bill of $" << total << ".\n";
    }
}


double inPatient(double days, double rate, double charges, double hospital){
    return ((days*rate)+(charges+hospital));
}

double outPatient(double charges, double hospital){
    return (charges+hospital);
}