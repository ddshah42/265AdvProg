#include <iostream>
using namespace std;

int main() {
    // shouldnt have 0 floors
    int floors = 1, available = 0;
    //Double var so it can take 2 decimal places to * by 100 to get final %
    double percent = 0, totalRooms = 0, totalOccupied = 0;
    
    // enter how many floors there are in the hotel
    cout << "Please enter how many floors are in your hotel: " << endl;
    cin >> floors;
    cout << "You entered " << floors << " floors." << endl;
    
    //checks if there are more than 1 floor
    if (floors <= 1) {
        while (floors <= 1){
            cout << "The hotel has to have more than 1 floor. ";
            cout << "Please enter how many floors are in your hotel: ";
            cin >> floors;
        }
    }
    
    //itterates through each floor
    for(int x = 1; x <= floors; x++){
        int rooms, occupied, unoccupied;
        
        // this statement skips the 13th "floor"/iteration like the book says to.
        if (x == 13){
            //skip the 13th floor if there is one
        }else{
            //ask how many rooms there are on the current floor of the itteration
            cout << "How many rooms are on floor " << x << " ?" << endl;
            cin >> rooms;
            
            // this checks if there are at least 10 rooms per "floor"/iteration
            if (rooms < 10) {
                while (rooms < 10) {
                    cout << "There must be more than 10 rooms on this floor. ";
                    cout << "Please re-enter how many rooms are on floor "<<x<<": ";
                    cin >> rooms;
                }
            }   
            cout << rooms << " rooms on floor " << x << endl;
            
            //ask how many of the rooms on the current floor are occupied
            cout << "How many of the " << rooms << " rooms are occupied?" << endl;
            cin >> occupied;
            
            if(occupied == rooms){
                cout << "All the rooms are occupied on floor " << x << endl;
            } else if(occupied < rooms){
                cout << occupied << " occupied rooms on floor " << x << endl;
            } else if(occupied > rooms){
            //EXTRA: Prevents more occupied rooms than there are rooms on the x foor
                while (occupied > rooms){
                    cout << "Thats an invalid action: Cannot have " << occupied << " occupied rooms when there are only " << rooms << " rooms on the floor. Please re-enter the correct amount of occupied rooms: ";
                    cin >> occupied;
                    
                    if(occupied < rooms){
                        cout << occupied << " occupied rooms on floor " << x << endl;  
                    } else {
                        cout << "Uhh please re-read the error: " << endl;
                    }
                }
            }
            
            //using the global scope, this adds the current itterations amount of rooms
            //and amount of occupied rooms and adds them to the current total amount
            totalRooms = totalRooms + rooms;
            totalOccupied = totalOccupied + occupied;
            
            cout << "Floor " << x << " has " << rooms << " rooms but " << occupied << " are occupied!"<< endl << endl;
        }
    }
    
    // sets how many of all the rooms are occupied
    available = totalRooms - totalOccupied;
    percent = (totalOccupied/totalRooms)*100;
    
    cout << "The hotel has " << totalRooms << " rooms across " << floors << " floors.\n";
    cout << "There are "<< totalOccupied << " occupied rooms and " << available << " available rooms.\n";
    cout << percent << "% of the rooms are occupied.\n";
}