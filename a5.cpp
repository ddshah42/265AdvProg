#include <iostream>
#include <limits> //http://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c
using namespace std;

const int NUM_ROWS = 2;
const int NUM_COLS = 2;

int getTotal(int[][NUM_COLS]);
double getAverage(int);
int getRowTotal(int[][NUM_COLS],int);
int getColumnTotal(int[][NUM_COLS],int);
int getHighestInRow(int[][NUM_COLS],int);
int getLowestInRow(int[][NUM_COLS],int);

int main() {
    int x,y,value,answer;
    
    int num[NUM_ROWS][NUM_COLS]={10,20,30,40};
    cout << "The data values are: ";
    
    for(x = 0;x < NUM_ROWS;x++){
        for(y = 0;y < NUM_COLS;y++){
            if(y == NUM_COLS){
                cout << num[x][y];
            }else{
                cout << num[x][y] << " ";
    }   }   }

    cout << "\n\nChoices:\n";
    cout << "1 Get the total of all the values.\n";
    cout << "2 Get the average of all the values.\n";
    cout << "3 Get the total value of all the values in the specified row.\n";
    cout << "4 Get the total value of all the values in the specified column.\n";
    cout << "5 Get the highest value in the specified row.\n";
    cout << "6 Get the lowest value in the specified row.\n";
    cout << "7 exit\n";
    cout << "\nChoose one from 1 to 7: ";
    cin >> answer;
    
    if(answer < 1 && answer > 7){
    while(answer < 1 && answer > 7){
        cout << "Sorry, what Option do you want? [1-7]: ";
        cin >> answer;
    }   }
    
    switch(answer){
        case 1: cout << "The total is " << getTotal(num) << endl;
                break;
        case 2: value = getTotal(num);
                cout << "The average: " << getAverage(value) << endl;
                break;
        case 3: cout << "Enter Row Number: ";
                cin >> x;
                while(x < 0 || x > NUM_ROWS){
                    cout << "ERROR: Must be number 0 & " << NUM_ROWS << ": ";
                    cin >> x;
                }
                cout << "Row " << x << " total: " << getRowTotal(num, x) << endl; 
                break;
        case 4: cout << "Enter the column number: ";
                cin >> x;
                while(x < 0 || x > NUM_COLS){
                    cout << "ERROR: Must be a number between 0 & " << NUM_COLS << ": ";
                    cin >> x;
                }
                cout << "Column " << x << " total: " << getColumnTotal(num, x) << endl; 
                break;
        case 5: cout << "Enter the row number: ";
                cin >> x;
                while(x < 0 || x > NUM_ROWS){
                    cout << "ERROR: Must be a number between 0 & " << NUM_ROWS << ": ";
                    cin >> x;
                }
                cout << "Highest value in row " << x << " is: " << getHighestInRow(num, x) << endl; 
                break;
        case 6: cout << "Enter the row number: ";
                cin >> x;
                while(x < 0 || x > NUM_ROWS){
                    cout << "ERROR: Must be a number between 0 & " << NUM_ROWS << ": ";
                    cin >> x;
                }
                cout << "Lowest value in row " << x << " is: " << getLowestInRow(num, x) << endl; 
                break;
        case 7: cout << "Shutting Down...";
                break;
        default: cout << "ERROR: INVALID ACTION: Invalid option";
}   }

int getTotal(int row[][NUM_COLS]){
    int total = 0;
    for(int c = 0;c < NUM_ROWS;c++){
        for(int r = 0;r < NUM_COLS;r++){
            total += row[c][r];
    }   }
    return total;
}

double getAverage(int total){
    double average;
    average = total/(NUM_ROWS*NUM_COLS);
    return average;
}

int getRowTotal(int num[][NUM_COLS], int y){
    int x, value = 0;
    for(x = 0;x < NUM_COLS;x++){
        value += num[y][x];
    }
    return value;
}

int getColumnTotal(int num[][NUM_COLS], int y){
    int x, value = 0;
    for(x = 0;x < NUM_ROWS;x++){
        value += num[x][y];
    }
    return value;
}

int getHighestInRow(int num[][NUM_COLS], int y){
    int x, value = 0;
    value = num[y][0];
    for(x = 0;x < NUM_ROWS;x++){
        if(num[y][x] > value){
            value = num[y][x];   
    }   }
    return value;
}

int getLowestInRow(int num[][NUM_COLS], int y){
    int x, value = numeric_limits<int>::max(); //http://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c
    value = num[y][0];
    for(x = 0;x < NUM_COLS;x++){
        if(num[y][x] < value){
            value = num[y][x];   
    }   }
    return value;    
}