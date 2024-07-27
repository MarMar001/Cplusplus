#include <cctype>
#include <iostream>
#include <sstream>
using namespace std;
int main() {
// get user input
string userInput;
cout << "Enter your sentence containing numbers to calculate the sum: ";
getline(cin, userInput);
double sum = 0;
// build the number string
stringstream numberStream;
for (int i = 0; i < userInput.length(); i++) {
// iterate and check if the current character is a number or a decimal point
if (isdigit(userInput[i]) || userInput[i] == '.') {
numberStream << userInput[i];
} else {
if (!numberStream.str().empty()) {
sum += stod(numberStream.str());
numberStream.str("");
}
}
}
// add the numbers
if (!numberStream.str().empty()) {
sum += stod(numberStream.str());
}
// print the sum
cout << "The sum is " << sum << endl;
return 0;
}
