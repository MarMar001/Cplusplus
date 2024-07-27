#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
//initalize variables
string dataLine;
int dayInput;
double rainTotal=0.0;
string substringDay;
int positionDATE;
int positionDay;
string substringRain;
int positionRain;
ifstream inputFile;
//open the input file (program expects the file to be in the same directory as the program)
inputFile.open("reduced_columns.txt");
//check if the file is successfully opened
if (!inputFile){
cout << "Error opening file" << endl;
return 1;
}
else {
cout << "Input file opened successfully." << endl;}
//get the day from user input
//since the data file only contains dates from December 2023, the user input will be limited to the days
from December 2023. If more months or years would be in the data file, we would have to make sure
the user input will ignore anything that would not be in December 2023.
cout << "Enter the day (1-31) you would like to see the total rainfall for : ";
cin >> dayInput;
if (dayInput < 1 || dayInput > 31){
cout << "Invalid input. Please enter a number between 1 and 31." << endl;
cout << "Enter the day from 1 to 31 : ";
cin >> dayInput;}
//find position of date and rain in the header
getline(inputFile, dataLine);
positionDATE = dataLine.find("DATE");
positionDay = positionDATE + 3;
positionRain = dataLine.find("PRCP");
//compare user input to the day in the array
while (!inputFile.eof())
{
getline(inputFile, dataLine);
if (dataLine.length() == 0) {break;}
double rain = stod(dataLine.substr(positionRain, 4));
int day = stoi(dataLine.substr(positionDay,2));
if (dayInput == day)
rainTotal += rain;
}
inputFile.close();
cout << "The total rain for the " << dayInput<< " of December 2023 is: " << rainTotal << endl;
return 0;
}
