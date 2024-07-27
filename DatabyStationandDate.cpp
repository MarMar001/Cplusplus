//Please note this program will find and return station containing the same word(s) than the user input
and not an exact match. If two stations share the same city name and the user only enter the city name,
the program will return both station. This approach seems more user friendly but might not be as
accurate. We could add a prompt listing the exact station name and requesting the user to choose from
those.
//It might also need some more input sanitization as, right now, we rely a lot on the user reading the
prompts correctly.
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
// initalize variables
string dataLine;
string stationName;
string userInputStationName;
int userInputDay;
int positionMaxTemp;
int positionLowTemp;
int positionPRCP;
int positionStationName = 0;
int positionDATE;
int positionDay;
ifstream inputFile;
// open the input file (program expects the file to be in the same directory
// as the program)
inputFile.open("reduced_columns.txt");
// check if the file is successfully opened
if (!inputFile) {
cout << "Error opening file" << endl;
return 1;
} else {
cout << "Input file opened successfully." << endl;
}
getline(inputFile, dataLine);
// find positions in header
positionMaxTemp = dataLine.find("TMAX");
positionLowTemp = dataLine.find("TMIN");
positionStationName = dataLine.find("STATION");
positionPRCP = dataLine.find("PRCP");
positionDATE = dataLine.find("DATE");
positionDay = positionDATE + 3;
// get user input
cout << "Please enter the name of the station you would like to see the data for, please make sure the
name is in all caps : ";
// cin >> userInputStationName;
getline(cin, userInputStationName);
cout << userInputStationName << endl;
cout << "Please enter the day (from 1 to 31) you would like to see the data from: ";
cin >> userInputDay;
// track whether a matching station and date has been found
bool found = false;
// loop
while (!inputFile.eof()) {
getline(inputFile, dataLine);
// needed to avoid out of range error (last line empty)
if (dataLine.length() == 0) {
break;
}
// loop for station
string stationName = dataLine.substr(positionStationName, 40);
int day = stoi(dataLine.substr(positionDay, 2));
string prcp = dataLine.substr(positionPRCP, 4);
string tmax = dataLine.substr(positionMaxTemp, 5);
string tmin = dataLine.substr(positionLowTemp, 5);
if ((stationName.find(userInputStationName) != string::npos) &&
(day == userInputDay)) {
cout << endl;
cout << "Data from Station " << stationName << " on the " << day
<< " of December :" << endl;
cout << "PRCP = " << prcp << endl;
cout << "TMAX = " << tmax << endl;
cout << "TMIN = " << tmin << endl;
found = true;
}
}
if (!found) {
cout << "No data for this station on this day" << endl;
}
// close file
inputFile.close();
return 0;
}
