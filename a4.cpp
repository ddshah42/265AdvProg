#include <iostream>
using namespace std;

double calcTotalRain(double[]);
double calcAvgRain(double[]);
double getHRain(double[]);
double getLRain(double[], double);

const int TOTAL_MONTHS = 12;
double monthlyRain[TOTAL_MONTHS] = {0,0,0,0,0,0,0,0,0,0,0,0};
string months[TOTAL_MONTHS] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int highestMonth, lowestMonth;

int main() {
    double answer;
    
    cout<<TOTAL_MONTHS<<endl;
    for(int i = 0;i < TOTAL_MONTHS;i++){
        cout << "\nEnter the Rainfall for the month of "<<months[i]<<": ";
        cin >> answer;
        monthlyRain[i] = answer;
        cout << "You entered "<< monthlyRain[i] << " for the month of "<<months[i]<<".\n";
    }
    for(int i = 0;i < TOTAL_MONTHS;i++){
        cout << "[" << months[i] << ": "<< monthlyRain[i] << "]\n";
    }
    double totalRainFall = calcTotalRain(monthlyRain);
    cout << "\n Total yearly rainfall: "<< totalRainFall << endl;
    
    double avgRain = calcAvgRain(monthlyRain);
    cout << "\n Average yearly rainfall: "<< avgRain << endl;
    
    double highRain = getHRain(monthlyRain);
    cout << "\n Highest yearly rainfall is the month of "<< months[highestMonth] << " with " << highRain << endl;
    
    double lowRain = getLRain(monthlyRain, highRain);
    cout << "\n Lowest yearly rainfall is the month of "<< months[lowestMonth] << " with " << lowRain << endl;
}

double calcTotalRain(double rain[]){
    double totalRain;
    for(int i = 0; i < TOTAL_MONTHS;i++){
        totalRain += rain[i];
    }
    return totalRain;
}

double calcAvgRain(double rain[]){
    double totalRain;
    double avgRain;
    for(int i = 0; i < TOTAL_MONTHS;i++){
        totalRain += rain[i];
    }
    return avgRain = totalRain/12;
}

double getHRain(double rain[]){
    double target = 0;
    for(int i = 0; i < TOTAL_MONTHS;i++){
        if(rain[i] > target){
            target = rain[i];
            highestMonth = i;
        }
    }
    return target;
}

double getLRain(double rain[], double n){
    double target = n;
    for(int i = 0; i < TOTAL_MONTHS;i++){
        if(rain[i] < target){
            target = rain[i];
            lowestMonth = i;
        }
    }
    return target;
}