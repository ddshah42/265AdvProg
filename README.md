# C++ Assignment Solutions
##### Class Name: 
CIS-265 Adv. Programming Concepts 
##### Textbook:
Starting Out with C++ Brief Version, 7th Edition
##### Author:
Tony Gaddis
##### Misc:
- Pearson 2012
- ISBN 10: 0-13-277289-2
- ISBN 13: 978-0-13-277289-1

## Assignments:
> TIP: press " CMD + F " to search for specific assignments faster

##### **[Full Group Project] / [DailyEats()]**
#
##### 1. **[Hotel Occupancy]**
##### 2. **[Winning Division]**
##### 3. **[Overloaded Hospital]**
##### 4. **[Rainfall Statistics]**
##### 5. **[2D Array Operations]**
##### 6. **[Array Allocator]**
##### 7. **[Array Expander]**
##### 8. **[String Length]**
##### 9. **[Phone Number List]**
##### 10. **[Movie Data]**
##### 11. **[Monthly Budget]**
##### 12. **[Inventory Program]**
##### 13. **[Date]**
#
#### Group Project -- Travel Expenses

- **[DailyEats()]** - Link to my portion of the project
- **[Full Group Project]** - Link to the full project

##### Group Members: 
- ###### Elizabeth Boby - Project Manager
 
- ###### Lient Blanco - Project Manager / Programmer
 
- ###### **Bernin Uben - Programmer (ME)**
  - **void dailyEats();**
 
- ###### Mike Chazulle - Programmer
  - double numAirfare (double airfare);
  - double numCarRental (double carRental);
 
- ###### Kang Bae - Programmer
  - double depTimeDepart(double departure);
  - double depTimeArrival(double arrival);
  - double miles(double miles);
  - double parking (double park);
 
- ###### Joseph Salsbury - Programmer
  - double numConference (double conference);
  - double numTaxi (double taxi);
  - double numHotel (double hotel);

#### Assigment directions for [DailyEats()]
- Main: Get the $ ammount of each allowed meal eaten on each day.
- On the first day of the trip: 
    - Breakfast is allowed if time of departure is before 7 a.m. 
    - Lunch is allowed if time of departure is before 12 NOON
    - Dinner is allowed if time of departure is before 6 p.m.
- On the last day of the trip: 
    - Breakfast is allowed if time of arrival is after 8 a.m. 
    - Lunch is allowed if time of arrival is after 1 p.m.
    - Dinner is allowed if time of arrival is after 7 p.m.
- Days in between will have breakfast lunch and dinner.
- Company allows up to:
    - $9 -  Breakfast
    - $12 - Lunch
    - $16 - Dinner

#### 1. Hotel Occupancy
##### Assignment Directons:
#
###### Page 295, Problem #9 
#### 2. Winning Division
##### Assignment Directons:
#
###### Page 369, Problem #3
#### 3. Overloaded Hospital: [A3.CPP](<https://github.com/Uben/CPP/blob/master/a3.cpp>)
##### Assignment Directons:
#
###### Page 373, Problem #14
Write a Program that computes and displays the charges for a patient's hospital stay. First, the program should ask if the patient was admmited as an in-patient or an out-patient. If the patient was an in-patient, the following data should be entered:
- Number of Days spent in the hospital
- The Daily Rate
- Hosptial Medication Charges
- Charges for hospital services

The program should ask for the folowing data if the patient was an out-patient: 
- Charges for Hospital services
- Hospital Charges

The program should use two overloaded functions to calculate the total charges. One of the functions should accept arguments for the in-patient data, while the other function accepts arguments for out-patients information. Both functions should return the total charges.

> Input Validation: Do not accept negative numbers or any data.

#### 4. Rainfall Statistics [A4.CPP](<https://github.com/Uben/CPP/blob/master/a4.cpp>)
##### Assignment Directons:
#

> Input Validation: Do not accept negative numbers for monthly rainfall statistics.
###### Page 444, Problem #2

#### 5. 2D Array Operations [A5.CPP](<https://github.com/Uben/CPP/blob/master/a5.cpp>)
##### Assignment Directons:
#
###### Page 448, Problem #16

#### 6. Array Allocator [A6.CPP](<https://github.com/Uben/CPP/blob/master/a6.cpp>)
##### Assignment Directons:
#
###### Page 537, Problem #1
Write a function that dynamically allocates an array of integers.The function should accept an integer argument indicating the number of elements to allocate. This function should return a pointer to the array.

#### 7. Array Expander [A7.CPP](<https://github.com/Uben/CPP/blob/master/a7.cpp>)
##### Assignment Directons:
#
###### Page 539, Problem #11
Write a function that accepts an INT array and the array's size as arguments. The function should create a new array that is twice the size of the argument array. The function should copy the contents of the argument array to the new array, and initialize the unused elements of the second array with 0. The function should return a pointer to the new array.

#### 8. String Length [A8.CPP](<https://github.com/Uben/CPP/blob/master/a8.cpp>)
##### Assignment Directons:
#
###### Page 588, Problem #1
Write a function that returns an integer and accepts a pointer to a C-string as an argument. the function should count the number of characters in the string and return that number. Demonstrate the function in a simple program that asks the user to input a string. Passes it to the function, and then displays the function's return value.

#### 9. Phone Number List [A9.CPP](<https://github.com/Uben/CPP/blob/master/a9.cpp>)
##### Assignment Directons:
#
###### Page 592, Problem #18
Write a program that has an array of atleast 10 string objects that hold people's names and phone numbers. You may make up your own strings, or use the example. The program should ask the user to enter a name or partial to search for in the array. Any entries in the array that match the string entered should be displayed. For example, if the user enters "Palmer" the program should display all objects matching "Palmer" whether if its Many, One or No items are found.

#### 10. Movie Data [A10.CPP](<https://github.com/Uben/CPP/blob/master/a10.cpp>)
##### Assignment Directons:
#
###### Page 645, Problem #1
Write a program that uses a structure named "MovieData" to store the following information about a movie:
- Title
- Director
- Year Released
- Running Time (in minutes)
    
The program should create two MovieData variables, store variables in their members, and pass each one, in turn, to a function that displays the information about the movie in a clearly formatted Manner.

#### 11. Monthly Budget [A11.CPP](<https://github.com/Uben/CPP/blob/master/a11.cpp>)
##### Assignment Directons:
#
###### Page 647, Problem #11
A student has estalbished the following monthly budget:
- Housing
- Utilities
- Household Expenses
- Transportation
- Food
- Medical
- Insurance
- Entertainment
- Clothing
- Miscellaneous

Write a program that has a MonthlyBudget structure designed to hold each of these expense categories. The program should pass the structure to a function that asks the user to enter the ammounts spent in each budget caegory during a month. The origram shuld then passthe structure to a function that displays a report indicating the amount over or under in each category, as well as the amount over or under for the entire monthly budget.

#### 12. Inventory Program [A12.CPP](<https://github.com/Uben/CPP/blob/master/a12.cpp>)
##### Assignment Directons:
#
###### Page 702, Problem #13
Write a program that uses a structure to store the following inventory data in a file:
- Inventory Description
- Quantity on Hand
- Wholesale Cost
- Retail Cost
- Date Added to Inventory

The program should have a menu that allows the user to preform the following tasks:
- Add New Records to a file
- Display Any Record in the file
- Change Any Record in the file

> Input Validation: The program should not accept any quantities, or wholesale, or retail costs, less than 0. The program should not accept dates that the programmer determines are unreasonable.

#### 13. Date [A13.CPP](<https://github.com/Uben/CPP/blob/master/a13.cpp>)
##### Assignment Directons:
#
###### Page 791, Problem #1
Design a CLASS called "Date". The class should store a date in three integers: "month", "day", and "year". There should be member functions to print the date in the following forms:

- 12/25/2012
- December 25, 2012
- 25 December 2012

Demonstrate the class by writing a complete program implementing it.

> Input Validation: Do not accept values for the day greater than 31 or less than 1. Do not accept values for the month greater than 12 or less than 1.

#
#
#
### Bernin Alejandro Uben Santana

[Hotel Occupancy]: <https://github.com/Uben/CPP/blob/master/a1.cpp>
[Winning Division]: <https://github.com/Uben/CPP/blob/master/a2.cpp>
[Overloaded Hospital]: <https://github.com/Uben/CPP/blob/master/a3.cpp>
[Rainfall Statistics]: <https://github.com/Uben/CPP/blob/master/a4.cpp>
[2D Array Operations]: <https://github.com/Uben/CPP/blob/master/a5.cpp>
[Array Allocator]: <https://github.com/Uben/CPP/blob/master/a6.cpp>
[Array Expander]: <https://github.com/Uben/CPP/blob/master/a7.cpp>
[String Length]: <https://github.com/Uben/CPP/blob/master/a8.cpp>
[Phone Number List]: <https://github.com/Uben/CPP/blob/master/a9.cpp>
[Movie Data]: <https://github.com/Uben/CPP/blob/master/a10.cpp>
[Monthly Budget]: <https://github.com/Uben/CPP/blob/master/a11.cpp>
[Inventory Program]: <https://github.com/Uben/CPP/blob/master/a12.cpp>
[Date]: <https://github.com/Uben/CPP/blob/master/a13.cpp>
[My Portion]: <https://github.com/Uben/CPP/blob/master/groupProject.cpp>
[DailyEats()]: <https://github.com/Uben/CPP/blob/master/groupProject.cpp>
[Full Group Project]: <https://github.com/Uben/CPP/blob/master/groupProjectCompleted.cpp>
