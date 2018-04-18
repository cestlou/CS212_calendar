#include <iostream>
#include <iomanip>


/*
 * write a program that prompts the user to enter the year and first day of the year
 * and displays the calendar table for the year on the console.
 *
 *  */



// function prototypes
void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);

using namespace std;
int getNumberOfDaysInMonth(int y, int m) {
    bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
//    static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//    return (m == 2 && isLeapYear) ? 29 : (days[m - 1]);

//    save if your code above is garbage
    if (m < 1 || m > 13) { return 0; }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else if (m == 2) {
        return isLeapYear ? 29 : 28;
    } else {
        return 31;
    }
}

int getTotalNumberOfDays(int y, int m) {
    int tot = 0;
//    get total days from 1800 to (current year - 1)
    for (int i=1800; i < y; i++) {
        if (getNumberOfDaysInMonth(y, m) == 29) {
            tot += 366;
        } else {
            tot += 365;
        }
    }
//    add days from Jan to prior calendar month
    for (int i = 0; i < m; i ++) {
        tot += getNumberOfDaysInMonth(y, i);
    }
    return tot;
}

int getStartDay(int y, int m) {
//    Get total number of days since 1//1/1800
    int startDay1800 = 3;
    int totalNumberOfDays = getTotalNumberOfDays(y, m);

    // Return the start day
    return (totalNumberOfDays + startDay1800) % 7;
}

void printMonthBody(int y, int m) {
    int startDay = getStartDay(y, m);
    int daysInMonth = getNumberOfDaysInMonth(y, m);
    int i;
    // add space to show current start day of month to correct
    for (i = 0; i < startDay; i++) {
        cout << "   ";
    }

    for (i = 1; i <= daysInMonth; i++) {
        cout << setw(4) << i;

        if ((i + startDay) % 7 == 0) {
            cout << endl;
        }
    }
}

void printMonthName(int m) {
    switch (m) {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 4:
            cout << "March ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        case 12:
            cout << "December ";
    }
}
void printMonthTitle(int y, int m) {
    printMonthName(m);
    cout << y << endl;
    cout << "-----------------------------" << endl;
    cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;

}
void printMonth(int y, int m) {
    printMonthTitle(y, m);
    printMonthBody(y, m);
}

int main() {
//    get input from the user, and print the calendar for the month.
    int year, month;
    cout << "Please enter a year (yyyy): ";
    cin >> year;
    cout << "Please enter the first day of month (e.g., Sunday = 1, etc.): ";
    cin >> month;
    printMonth(year, month);

    return 0;
}

