#include <iostream>
#include <iomanip>

using namespace std;

class Calender {
public:
    bool isLeap(int year);
    bool checkDay(int year, int month, int day);
    const char* getWeekdayByYearday(int year, int month, int day);
    void printCalender(int year, int month, int day);
};

static int month_days[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
static const char* month_name[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
static const char* week_name[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

bool Calender::isLeap(int year)  // check whether the year is leap year
{
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;
}

bool Calender::checkDay(int year, int month, int day) {
    Calender calender;
    if (month == 1 || month == 3 || month == 5 ||
        month == 7 || month == 8 || month == 10 || month == 12) {
	    if (!(day > 0 && day <= 31)) return false;
    } else if (calender.isLeap(year) && month == 2) {
        if (!(day > 0 && day <= 29)) return false;
    } else if(!calender.isLeap(year) && month == 2) {
        if (!(day > 0 && day <= 28)) return false;
    } else {
	    if (!(day > 0 && day <= 30)) return false;
    }
    return true;
}

/* Use Kim larsson calculation formula: w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7*/
const char* Calender::getWeekdayByYearday(int year, int month, int day)
{
    int weekday = -1;
    // January and February of the current year should be calculated as
    // the 13th and 14th months of the previous year
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    weekday = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    switch(weekday) {   
        case 0 :  return "Sunday";    break;
        case 1 :  return "Monday";    break;
        case 2 :  return "Tuesday";   break;
        case 3 :  return "Wednesday"; break;
        case 4 :  return "Thursday";  break;
        case 5 :  return "Friday";    break;                                                             
        case 6 :  return "Saturday";  break;
        default : return NULL;        break;
    }
    return NULL;
}

void Calender::printCalender(int year, int month, int day)
{
    int first_day;
    int first_day_per_month;
    cout << year << "/" << month << "/" << day << endl;
    cout << "-----------------------------" << endl;
    cout << setw(18) << month_name[month - 1] << endl;
    cout << "-----------------------------" << endl;
    cout << " Sun Mon Tue Wed Thu Fri Sat " << endl;

    month_days[1] = isLeap(year) ? 29 : 28;  // judge the days of February
    first_day = (year - 1+ (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    for (int i = 0; i < (month - 1); i++) {
        first_day += month_days[i];  // count total, we get 308
    }
    first_day_per_month = (first_day + 1) % 7;  // then we get 1
    for (int i = 0; i < first_day_per_month; i++) {  // how many space we should insert in the month
        cout << setw(4) << setfill(' ') << "";
    }
    int count = first_day_per_month % 7;
    for (int i = 0; i < month_days[month - 1]; i++) {  // insert days 
        cout << setw(4) << setfill(' ') << i + 1;
        if (count >= 6) {
            cout << endl;
            count = 0;
        } else {
            count++;
        }
    }
    cout << endl;
    cout << "-----------------------------" << endl;
    const char* getweekday = getWeekdayByYearday(year, month, day);
    cout << year << "/" << month << "/" << day << " is on " << getweekday << endl;
}

int main()
{
    Calender calender;
    int year, month, day;
    cout << "----------CALENDER----------" << endl;
    cout << "Please enter year: ";
    cin >> year;
    if (!(year > 0)) {
        cout << "% Wrong year value." << endl;
        return false;
    }
    cout << endl << "Please enter month: ";
    cin >> month;
    if (!(month > 0 && month < 13)) {
        cout << "% Wrong month value." << endl;
        return false;
    }
    cout << endl << "Please enter day: ";
    cin >> day;
    cout << endl << endl;
    if (!calender.checkDay(year, month, day)) {
        cout << "% Wrong day value." << endl;
        return false;
    }
    calender.printCalender(year, month, day);  // print the calender and some infomation

    return 0;
}
