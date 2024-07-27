#include <iomanip>
#include <iostream>
using namespace std;
//function for table fill
void generateTable(int start, int end, int increment) {
int celsius = start;
int fahrenheit = (celsius * 9.0 / 5.0) + 32;
double kelvin = celsius + 273.15;
cout << fixed << setprecision(2) << setw(10) << celsius << setw(15)
<< fahrenheit << setw(15) << kelvin << endl;
cout << endl;
}
//function for table header
void header(){
cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
cout << setw(10) << "Celsius" << setw(15) << "Fahrenheit" << setw(15)
<< "Kelvin" << endl;
cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
}
int main() {
//initialize variable
int start, end, increment;
//get user input
cout << "Please enter a starting temperature in degrees Celsius:";
cin >> start;
cout << "Please enter an ending temperature in degrees Celsius:";
cin >> end;
cout << "Please enter the increment between temperatures in degrees Celsius:";
cin >> increment;
cout << endl;
//check if input is valid, prints error message if invalid input
if (cin.fail())
{cout << endl << "INVALID ENTRY, please make sure to enter a number" << endl;
return 1;
}
//stores start variable entered by user to avoid override
int initialStart = start;
// case 1 - while loop
cout << endl << "WHILE LOOP" << endl;
header();
while (initialStart <= end) {
generateTable(initialStart, end, increment);
initialStart += increment;
}
initialStart = start;
// case 2 - do while loop
cout << endl << "DO WHILE LOOP" << endl;
header();
do { generateTable(initialStart, end, increment);
initialStart += increment;}
while (initialStart <= end);
initialStart = start;
// case 3 - for loops
cout << endl << "FOR LOOP" << endl;
header();
for (; initialStart <= end; initialStart += increment) {
generateTable(initialStart, end, increment);
}
return 0;
}
