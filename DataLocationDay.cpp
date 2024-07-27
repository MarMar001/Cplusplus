#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
// initalize variables
string dataLine;
double NL;
double SL;
double WL;
double EL;
int records=0;
string substringStationName;
string substringElevation;
string substringLat;
string substringLon;
string substringPRCP;
string substringTMAX;
string substringTMIN;
unsigned int positionStationName;
unsigned int positionElevation;
unsigned int positionLat;
unsigned int positionLon;
unsigned int positionPRCP;
unsigned int positionTMAX;
unsigned int positionTMIN;
unsigned int userInputDay;
unsigned int positionDATE;
unsigned int positionDay;
ifstream inputFile;
ofstream outputFile;
// open the input file (program expects the file to be in the same directory as the program)
inputFile.open("reduced_columns.txt");
// check if the file is successfully opened
if (!inputFile) {
cout << "Error opening file" << endl;
return 1;
} else {
cout << "Input file opened successfully." << endl;
}
//creates and open the output file
outputFile.open("specificAreaData.txt");
//check if the file is successfully opened
if (!outputFile){
cout << "Error opening file" << endl;
return 2;}
else{
cout << "Output file opened successfully." << endl;}
getline(inputFile, dataLine);
// find positions in header
positionStationName = dataLine.find("STATION");
positionElevation = dataLine.find("ELEVATION");
positionLat = dataLine.find("LATITUDE");
positionLon = dataLine.find("LONGITUDE");
positionPRCP = dataLine.find("PRCP");
positionTMAX = dataLine.find("TMAX");
positionTMIN = dataLine.find("TMIN");
positionDATE = dataLine.find("DATE");
positionDay = positionDATE + 3;
// get user input
cout << "Enter the regional coordinates: " << endl;
cout << "Please enter the coordinates, North Latitude: ";
cin >> NL;
cout << "Please enter the coordinates, South Latitude: ";
cin >> SL;
cout << "Please enter the coordinates, West Longitude: ";
cin >> WL;
cout << "Please enter the coordinates, East Longitude: ";
cin >> EL;
cout << "Please enter the day (from 1 to 31) you would like to see the data from: ";
cin >> userInputDay;
// loop
while (!inputFile.eof()) {
getline(inputFile, dataLine);
// needed to avoid out of range error (last line empty)
if (dataLine.length() == 0) {
break;
}
// loop for station
string stationName = dataLine.substr(positionStationName, 40);
string elevation = dataLine.substr(positionElevation, 6);
double lat = stod(dataLine.substr(positionLat, 7));
double lon = stod(dataLine.substr(positionLon, 8));
int day = stoi(dataLine.substr(positionDay, 2));
string prcp = dataLine.substr(positionPRCP, 4);
string tmax = dataLine.substr(positionTMAX, 5);
string tmin = dataLine.substr(positionTMIN, 5);
if ((day == userInputDay) && (lat < NL) && (lat > SL) && (lon > WL) && (lon < EL)){
getline(inputFile, dataLine);
records += 1;
outputFile << dataLine<< endl;}
} cout << "
File of weather steations in NW Alabama created with "
<<records <<" records." << endl;
// close file
inputFile.close();
outputFile.close();
return 0;
}
