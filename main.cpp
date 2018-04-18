#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * write a program that prompts the user to enter the year and first day of the year
 * and displays the calendar table for the year on the console.
 *
 *  */

int main() {
    int y, startDay, numberOfDaysInMonth;
    cout << "Enter a year: ";
    cin >> y;
    cout << "Enter the first day of the year: ";
    cin >> startDay;

    for (int month = 1; month <= 12; month++) {
        cout << "          ";
        switch (month) {
            case 1:
                cout << "January " << y << endl;
                numberOfDaysInMonth = 31;
                break;
            case 2:
                cout << "February " << y << endl;
                if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) {
                    numberOfDaysInMonth = 29;
                } else {
                    numberOfDaysInMonth = 28;
                }
                break;
            case 3:
                cout << "March " << y << endl;
                numberOfDaysInMonth = 31;
                break;
            case 4:
                cout << "April " << y << endl;
                numberOfDaysInMonth = 30;
                break;
            case 5:
                cout << "May " << y << endl;
                numberOfDaysInMonth = 31;
                break;
            case 6:
                cout << "June " << y << endl;
                numberOfDaysInMonth = 30;
                break;
            case 7:
                cout << "July " << y << endl;
                numberOfDaysInMonth = 31;
                break;
            case 8:
                cout << "August " << y << endl;
                numberOfDaysInMonth = 31;
                break;
            case 9:
                cout << "September " << y << endl;
                numberOfDaysInMonth = 30;
                break;
            case 10:
                cout << "October " << y << endl;
                numberOfDaysInMonth = 31;
                break;
            case 11:
                cout << "November " << y << endl;
                numberOfDaysInMonth = 30;
                break;
            case 12:
                cout << "December " << y << endl;
                numberOfDaysInMonth = 31;
        }

        cout << "-----------------------------" << endl;
        cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
        // padding before first date of month
        int i;
        for (i = 0; i < startDay; i++) {
            cout << "    ";
        }

        for (int currentDay = 1; currentDay <= numberOfDaysInMonth; currentDay++) {
            if ((currentDay + startDay) % 7 == 0) {
                cout << endl;
            }
            if (currentDay < 10) {
                cout << "   " << currentDay;
            } else {
                cout << "  " << currentDay;
            }
        }
//      keep track of the next day of the following month
        startDay = (startDay + numberOfDaysInMonth) % 7;
        cout << endl;
    }
}

