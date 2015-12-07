#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int DES = 20;
const int DATE = 10;

void Add();
void Show();
void Edit();

struct Inventory{
    int quantity;
    char item[DES];
    char date[DATE];
    double retail;
    double wholesale;
};

int main(){
    cout << "Options:\n1)  Add a record.\n2)  Show a record.\n3)  Edit a record.\n";
    cout << "WARNING: Anything other than the options listed above will close the program.\n";
    int answer = 1;
    
    while(answer > 0 && answer < 4){
        cout << "\nEnter in one choice from 1-3:";
        cin >> answer;
        
        switch(answer){
            case 1: Add();
                break;
            case 2: Show();
                break;
            case 3: Edit();
                break;
            default: cout << "ERROR: INVALID CHOICE\nPAUSING...\n";
        }
        
        if(answer < 1 || answer >= 4){
            cout << "\n\nTo Continue: Choose from options 1, 2, or 3.\n";
            cout << "To Exit: Enter anything else.\nAnswer:";
            cin >> answer;
            
            switch(answer){
                case 1: Add();
                    break;
                case 2: Show();
                    break;
                case 3: Edit();
                    break;
                default: cout << "Exiting....\n";
            }
        }
    }
    cout << "\n\nProgram Terminated\n";
    return 0;
}


void Add(){
    ofstream fout;
    fout.open("inventory.txt",ios::out);
    Inventory inventory;
    int num;
    
    //sets the product number to find in file
    cout << "WARNING: Will overwrite products with the same PRODUCT ID.\n";
    cout << "Enter the PRODUCT ID of the record: ";
    cin >> num;
    cout << num << " was set as the PRODUCT ID for this item.\n";
    
    
    //enter the information
    cout << "Enter the items Description:";
    cin.ignore();
    cin.getline(inventory.item, DES);
    
    cout << "Enter the amount currently on hand:";
    cin >> inventory.quantity;
    if(inventory.quantity < 0){
        while(inventory.quantity < 0){
            cout << "Amount cant be under Nothing(0).\n";
            cout << "Please correctly enter the correct amount currently on hand:";
            cin >> inventory.quantity;
        }
    }
    
    cout << "Enter the retail cost for the item:";
    cin >> inventory.retail;
    if(inventory.retail < 0.01){
        while(inventory.retail < 0.01){
            cout << "Price cant be under $0.01.\nPlease correctly enter the correct price:";
            cin >> inventory.retail;
        }
    }
    
    cout << "Enter the wholesale cost for the item:";
    cin >> inventory.wholesale;
    if(inventory.wholesale < 0.01){
        while(inventory.wholesale < 0.01){
            cout << "Price cant be under $0.01.\nPlease correctly enter the correct price:";
            cin >> inventory.wholesale;
        }
    }
    
    cout << "Enter the date that it was added into the inventory.(Format: MM/DD/YYYY): ";
    cin >> inventory.date;
    
    fout.seekp(num*sizeof(inventory),ios::beg);
    fout.write(reinterpret_cast<char*>(&inventory),sizeof(inventory));
    fout.close();
}

void Show(){
    ifstream fin;
    fin.open("inventory.txt",ios::in);
    Inventory inventory;
    
    int num;
    cout << "Please Enter the PRODUCT ID: ";
    cin >> num;
    
    fin.seekg(num*sizeof(inventory),ios::beg);
    fin.read(reinterpret_cast<char*>(&inventory),sizeof(inventory));
    
    cout << "\nDisplaying Item....\n";
    cout << "|=========================================|";
    cout << "\n   Description ----- ";
    cout << inventory.item;
    cout << "\n   Quantity -------- ";
    cout << inventory.quantity;
    cout << "\n   Whosesale Cost:-- $";
    cout << inventory.wholesale;
    cout << "\n   Retail ---------- $";
    cout << inventory.retail;
    cout << "\n   Date ------------ ";
    cout << inventory.date << endl;
    cout <<"|=========================================|\n\n";
    
    fin.close();
}

void Edit(){
    fstream fout;
    fout.open("inventory.txt",ios::in|ios::out);
    Inventory inventory;
    int num;
    
    cout << "Enter the Product ID of the item you want edited:";
    cin >> num;
    
    fout.seekg(num*sizeof(inventory),ios::beg);
    fout.read(reinterpret_cast<char*>(&inventory),sizeof(inventory));
    
    cout << "\nDisplaying Item....\n";
    cout << "|=========================================|";
    cout << "\n   Description ----- ";
    cout << inventory.item;
    cout << "\n   Quantity -------- ";
    cout << inventory.quantity;
    cout << "\n   Whosesale Cost:-- $";
    cout << inventory.wholesale;
    cout << "\n   Retail ---------- $";
    cout << inventory.retail;
    cout << "\n   Date ------------ ";
    cout << inventory.date << endl;
    cout <<"|=========================================|\n\n";
    
    cout << "Enter the new information.\n";
    
    cout << "Enter the items Description:";
    cin.ignore();
    cin.getline(inventory.item, DES);
    cout << "Enter the amount currently on hand:";
    cin >> inventory.quantity;
    cout << "Enter the retail cost for the item:";
    cin >> inventory.retail;
    cout << "Enter the wholesale cost for the item:";
    cin >> inventory.wholesale;
    cout << "Enter the date that it was added into the inventory.(Format: MM/DD/YYYY): ";
    cin >> inventory.date;
    
    fout.seekg(num*sizeof(inventory),ios::beg);
    fout.write(reinterpret_cast<char*>(&inventory),sizeof(inventory));
    fout.close();
}







