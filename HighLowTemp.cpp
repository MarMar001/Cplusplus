#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
// initalize variables
string dataLine;
string stationName;
string substringMaxTemp;
string substringLowTemp;
int positionMaxTemp;
int positionLowTemp;
double maxTemp = 0.0;
double minTemp = 99.9;
int positionStationName = 0;
ifstream inputFile;
// open the input file (program expects the file to be in the same directory as the program)
inputFile.open("reduced_columns.txt");
// check if the file is successfully opened
if (!inputFile) {
cout << "Error opening file" << endl;
return 1;
} else {
cout << "Input file opened successfully." << '\n' << endl;
}
getline(inputFile, dataLine);
// find position of temperatures in the header
positionMaxTemp = dataLine.find("TMAX");
positionLowTemp = dataLine.find("TMIN");
positionStationName = dataLine.find("STATION");
// loop through each lined of the file
while (!inputFile.eof()) {
getline(inputFile, dataLine);
// needed to avoid out of range error (last line empty)
if (dataLine.length() == 0) {
break;
}
// loop for maxTemp
double currentMax = stod(dataLine.substr(positionMaxTemp, 5));
string stationName = dataLine.substr(positionStationName, 40);
if (currentMax > maxTemp) {
maxTemp = currentMax;
}
// loop for minTemp
double currentLow = stod(dataLine.substr(positionLowTemp, 5));
if (currentLow < minTemp) {
minTemp = currentLow;
}
}
inputFile.close();
inputFile.open("reduced_columns.txt");
getline(inputFile, dataLine);
while (!inputFile.eof()) {
getline(inputFile, dataLine);
// needed to avoid out of range error (last line empty)
if (dataLine.length() == 0) {
break;
}
// loop for maxTemp
double currentMax = stod(dataLine.substr(positionMaxTemp, 5));
string stationName = dataLine.substr(positionStationName, 40);
if (currentMax == maxTemp) {
cout << stationName << "recorded a maximum temperature of " << fixed << setprecision(2) <<
maxTemp<< endl;
}
// loop for minTemp
double currentLow = stod(dataLine.substr(positionLowTemp, 5));
if (currentLow == minTemp) {
cout << stationName << "recorded a minimum temperature of " << minTemp<< endl;
}
}
cout << endl << "The lowest temperature in december 2023 was " << fixed << setprecision(2) <<
minTemp << endl;
cout << "The highest temperature in december 2023 was " << fixed << setprecision(2) <<maxTemp
<< endl;
// close file
inputFile.close();
return 0;
}
