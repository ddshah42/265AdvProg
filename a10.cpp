#include <iostream>
#include <string>
using namespace std;
//*R
/*
    Write a program that uses a structure named "MovieData" to store the 
    following information about a movie:
    
    Title
    Director
    Year Released
    Running Time (in minutes)
    
    The program should create two MovieData variables, store variables in
    their members, and pass each one, in turn, to a function that displays the 
    information about the movie in a clearly formatted Manner.
*/

struct MovieData{
    string title;
    string director;
    int releaseYear;
    int runningTime;
};

void movieDisplay(MovieData);

const int MOVIEDB = 2;

int main(){
    int hours, minutes, year;
    string title, director;
    MovieData movArray1;
    MovieData movArray2;
    
    //Movie Array 1
        cout << "Please enter the movie title for movie 1: ";
        getline(cin, title);
        movArray1.title = title;
        
        cout << "Please enter the directors name for movie 1: ";
        getline(cin, director);
        movArray1.director = director;
        
        cout << "Please enter the year it was released for movie 1: ";
        cin >> movArray1.releaseYear;
        
        cout << "\n------------------------------------------------------------------\n";
        cout << "|  Intructions                                                   |\n";
        cout << "------------------------------------------------------------------\n";
        cout << "|Well ask how long the movie is in hours first                   |\n|Next We'll ask for the remading minutes.                        |\n";
        cout << "|EX: Movie length is 2:34. You enter 2 for hours, 34 for minutes.|\n";
        cout << "------------------------------------------------------------------\n\n";
        
        cout << "Please enter how long is movie 1 in hours: ";
        cin >> hours;
        
        cout << "Please enter how long is movie 1 in minutes: ";
        cin >> minutes;
        
        movArray1.runningTime = (hours * 60) + minutes;
        cout << "\n\n";
        
    //Movie Array 2
        cout << "Please enter the movie title for movie 2: ";
        cin.ignore();
        getline(cin, title);
        movArray2.title = title;
        
        cout << "Please enter the directors name for movie 2: ";
        getline(cin, director);
        movArray2.director = director;
        
        cout << "Please enter the year it was released for movie 2: ";
        cin >> movArray2.releaseYear;
        
        cout << "\n------------------------------------------------------------------\n";
        cout << "|  Intructions                                                   |\n";
        cout << "------------------------------------------------------------------\n";
        cout << "|Well ask how long the movie is in hours first                   |\n|Next We'll ask for the remading minutes.                        |\n";
        cout << "|EX: Movie length is 2:34. You enter 2 for hours, 34 for minutes.|\n";
        cout << "------------------------------------------------------------------\n\n";
        
        cout << "Please enter how long is movie 2 in hours: ";
        cin >> hours;
        
        cout << "Please enter how long is movie 2 in minutes: ";
        cin >> minutes;
        
        movArray2.runningTime = (hours * 60) + minutes;
        cout << "\n\n";
    
    //Calls to display movies
        movieDisplay(movArray1);
        movieDisplay(movArray2);

    return 0;
}

void movieDisplay(const MovieData movie){
        cout << "   Movie: " <<      movie.title << endl;
        cout << "-------------------------------------------------------\n";
        cout << " Director:     " << movie.director << endl;
        cout << " Year:         " << movie.releaseYear << endl;
        cout << " Running Time: " << movie.runningTime << " Min\n";
        cout << "-------------------------------------------------------\n\n";
}