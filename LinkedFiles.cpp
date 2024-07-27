#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// struct for employee data
struct EmployeeData {
string first = "";
string last = "";
string initial = "";
int id = 0;
int hours = 0;
double wage = 0;
double pay = 0;
EmployeeData *next = nullptr;
};
// print employee data function
void printEmployeeData(EmployeeData *employee) {
cout << "First Name: " << employee->first << endl;
cout << "Last Name: " << employee->last << endl;
cout << "Initial: " << employee->initial << endl;
cout << "ID: " << employee->id << endl;
cout << "Hours Worked: " << employee->hours << endl;
cout << "Wage: " << employee->wage << endl;
cout << "Gross Pay: " << employee->pay << endl << endl;
}
int main() {
ifstream file("employees_data.txt");
if (!file) {
cout << "Failed to open the file." << endl;
return 1;
}
// ignore the first two lines
string line;
getline(file, line);
getline(file, line);
EmployeeData *head = new EmployeeData;
EmployeeData *current = head;
int i = 0;
// read employee data and create linked list
while (!file.eof()) {
file >> current->first >> current->last >> current->initial >>
current->id >> current->hours >> current->wage >> current->pay;
if (i++ < 9) {
current->next = new EmployeeData;
current = current->next;
}
}
cout << "Read employees data." << endl << endl;
file.close();
// prompt user
string searchFirstName, searchLastName;
cout << "Enter the first name of the employee, please make sure to "
"capitalize the first letter: ";
cin >> searchFirstName;
cout << "Enter the last name of the employee, please make sure to capitalize "
"the first letter: ";
cin >> searchLastName;
cout << endl;
i = 0;
EmployeeData *node = head;
// traverse the linked list to find the employee
while (node != nullptr) {
if (node->first == searchFirstName && node->last == searchLastName) {
cout << "Employee Found" << endl;
cout << "Node Number: " << i << endl;
printEmployeeData(node);
}
node = node->next;
i++;
}
return 0;
}
