#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
#include <iomanip>
#include <algorithm>
//calculate a hash value for the pair object
struct PairHash {
template <class T1, class T2>
size_t operator() (const pair<T1, T2>& p) const {
auto h1 = hash<T1>{}(p.first);
auto h2 = hash<T2>{}(p.second);
return h1 ^ h2; }
};
int main() {
//make a dictionary of pairs
unordered_map< pair<int , int>, string, PairHash > holidayDictionary;
holidayDictionary[make_pair (1 , 15)] = "Dr. King's Birthday";
holidayDictionary[make_pair (2 , 14)] = "Valentine's Day";
holidayDictionary[make_pair (3 , 17)] = "St. Patrick's Day";
holidayDictionary[make_pair (3 , 31)] = "Easter";
holidayDictionary[make_pair (5 , 27)] = "Memorial Day";
holidayDictionary[make_pair (6 , 19)] = "Juneteenth";
holidayDictionary[make_pair (7 , 4)] = "Independence Day";
holidayDictionary[make_pair (9 , 2)] = "Labor Day";
holidayDictionary[make_pair (10 , 31)] = "Halloween";
holidayDictionary[make_pair (11 , 28)] = "Thanksgiving";
holidayDictionary[make_pair (12 , 25)] = "Christmas";
// input month and day
int month;
int day;
cout << "Enter the month (1-12): ";
cin >> month;
cout << "Enter the day (1-31): ";
cin >> day;
//check if input correct
if (month < 1 || month > 12 || day < 1 || day > 31)
{
cout << "Invalid entry, please enter the correct format (1-12 and 1-31)" << endl;
return 1;
}
//check if input is a holiday
else {
if (holidayDictionary.count(make_pair(month, day)))
cout<<"Yes, the holiday is " << holidayDictionary[make_pair(month, day)] <<"." << endl;
else {
cout << "There is no holiday on " << month << "/" << day << "." << endl;
}
}
return 0;
}
