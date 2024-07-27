#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// struct definition
struct Reservation {
string name;
int size;
string date;
string time;
string phone;
string email;
string cc;
string exp;
};
void printReservation(const Reservation &res) {
cout << "Party Name: " << res.name << endl;
cout << "Size: " << res.size << endl;
cout << "Date: " << res.date << endl;
cout << "Time: " << res.time << endl;
cout << "Phone Number: " << res.phone << endl;
cout << "Email Address: " << res.email << endl;
cout << "Credit Card Number: " << res.cc << endl;
cout << "Expiration Date: " << res.exp << endl;
cout << endl;
}
int main() {
ifstream file("reservations.txt");
if (!file) {
cout << "Failed to open the file." << endl;
return 1;
}
string str;
Reservation reservations[10];
int i = 0;
// discard header
getline(file, str);
while (!file.eof()) {
if (i >= 10)
break;
Reservation *res = &reservations[i++];
string first, last;
file >> first >> last;
res->name = first + " " + last;
file >> res->size;
string mon, day, year;
file >> mon >> day >> year;
res->date = mon + " " + day + " " + year;
file >> res->time;
file >> res->phone;
file >> res->email;
file >> res->cc;
file >> mon >> day >> year;
res->exp = mon + " " + day + " " + year;
}
string userDate;
cout << "Enter a date (MM DD YYYY): ";
getline(cin, userDate);
bool reservationFound = false;
for (int i = 0; i < 10; ++i) {
if (reservations[i].date == userDate) {
cout << endl;
cout << "Reservation found for the date " << reservations[i].date << " : "
<< endl
<< endl;
printReservation(reservations[i]);
reservationFound = true;
}
}
if (!reservationFound) {
cout << "No reservations found for the date " << userDate << endl;
}
file.close();
return 0;
}
