#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
//initalize variables
string dataLine;
string substringTMAX;
string substringTMIN;
string substringPRCP;
string substringSTATION;
unsigned int positionTMAX;
unsigned int positionTMIN;
unsigned int positionPRCP;
unsigned int positionSTATION;
double prcp, tmax, tmin;
ifstream inputFile;
ofstream outputFile;
//open the input file (program expects the file to be in the same directory as the program)
inputFile.open("weatherStationData.txt");
//check if the file is successfully opened
if (!inputFile){
cout << "Error opening file" << endl;
return 1;
}
else {
cout << "Input file opened successfully." << endl;}
//creates and open the output file
outputFile.open("Filtered_AL_Weather_Station.txt");
//check if the file is successfully opened
if (!outputFile){
cout << "Error opening file" << endl;
return 2;}
else{
cout << "Output file opened successfully." << endl;}
getline(inputFile, dataLine);
outputFile << dataLine << endl;
positionPRCP = dataLine.find("PRCP");
positionTMAX = dataLine.find("TMAX");
positionTMIN = dataLine.find("TMIN");
positionSTATION = dataLine.find("STATION");
getline(inputFile, dataLine);
outputFile << dataLine << endl;
//loop : read input file and filter invalid data
while (!inputFile.eof())
{
getline(inputFile,dataLine);
substringPRCP = dataLine.substr(positionPRCP,5);
substringTMAX = dataLine.substr(positionTMAX,5);
substringTMIN = dataLine.substr(positionTMIN,5);
substringSTATION = dataLine.substr(positionSTATION,18);
//convert to float type
tmax = stof(substringTMAX);
tmin = stof(substringTMIN);
prcp = stof(substringPRCP);
//check if the data is valid, write valid data to output file
if (tmax != -9999 && tmin != -9999 && prcp != -9999)
{
outputFile << dataLine << endl;
}
}
cout << "Filtered data file created successfully." << endl;
//close the files
inputFile.close();
outputFile.close();
return 0;
}
