#include <iostream>
#include <ctime>
#include <iomanip>
#include <ostream>
#include <string>

using namespace std;
/*
 * write a program that prompts the user to enter the year and first day of the year
 * and displays the calendar table for the year on the console.
 *
 *  */

void getStartDay(int m, int y) {

}

void getNumberOfDaysInMonth(int m, int y) {

}

void getTotalNumberOfDays(int m, int y) {
    getNumberOfDaysInMonth(m, y);
}

void printMonthBody(int m, int y) {
    getStartDay(m, y);
    getNumberOfDaysInMonth(m, y);
}

void printMonthName(int m) {
    switch (m) {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 4:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "December";
            break;
    }
}
void printMonthTitle(int m, int y) {
    printMonthName(m);
    cout << year << endl;
    cout << "-----------------------------" << endl;
    cout << "Sun Mon Tues Weds Thurs Fri Sat" << endl;

}
void printMonth(int m, int y) {
    printMonthTitle(m, y);
    printMonthBody(m, y);
}

bool isLeapYear(int y) {
    return (y % 4 ==0 && y % 100 != 0) || (year % 400 == 0 || year % 4);
}

int main() {
//    get input from the user, and print the calendar for the month.
    int year;
    int month;
    cout << "Please enter a year:";
    cin >> year;
    cout << "Please enter a month (number representation):";
    cin >> month;
    printMonth(month, year);
    cout << "year: " << year << endl;
    cout << "month: " << month << endl;
    printMonth(year, month);
}

