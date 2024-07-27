#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//function to calculate the maximum temperature
double maxTemperature(double** temperatures, int numRows, int numCols) {
double maxTemp = temperatures[0][0];
for (int i = 0; i < numRows; ++i) {
for (int j = 0; j < numCols; ++j) {
if (temperatures[i][j] > maxTemp) {
maxTemp = temperatures[i][j];
}
}
}
return maxTemp;
}
//function to calculate the minimum temperature
double minTemperature(double** temperatures, int numRows, int numCols) {
double minTemp = temperatures[0][0];
for (int i = 0; i < numRows; ++i) {
for (int j = 0; j < numCols; ++j) {
if (temperatures[i][j] < minTemp) {
minTemp = temperatures[i][j];
}
}
}
return minTemp;
}
//function to calculate the average temperature
double averageTemperature(double** temperatures, int numRows, int numCols) {
double total = 0.0;
for (int i = 0; i < numRows; ++i) {
for (int j = 0; j < numCols; ++j) {
total += temperatures[i][j];
}
}
return total / (numRows * numCols);
}
//function to free memory allocated for the 2D array
void deallocateArray(double** temperatures, int numRows) {
for (int i = 0; i < numRows; ++i) {
delete[] temperatures[i];
}
delete[] temperatures;
}
//function to print statistics
void printStatistics(double** temperatures, int numRows, int numCols) {
cout << "Maximum Temperature: " << fixed << setprecision(1) << maxTemperature(temperatures,
numRows, numCols) << endl;
cout << "Minimum Temperature: " << fixed << setprecision(1) << minTemperature(temperatures,
numRows, numCols) << endl;
cout << "Average Temperature: " << fixed << setprecision(1) << averageTemperature(temperatures,
numRows, numCols) << endl;
}
int main() {
string filename = "data";
string line;
int numRows, numCols;
// Open file
ifstream file(filename);
if (!file) {
cerr << "Failed to open the file: " << filename << endl;
return 1;
}
cout << "File opened successfully." << endl;
//read the first line to get the number of rows and columns
getline(file, line);
istringstream iss(line);
string temp;
iss >> temp >> temp >> temp >> numRows >> numCols;
cout << "Number of rows: " << numRows << ", Number of columns: " << numCols << endl;
//create dynamic 2D array
double** temperatures = new double*[numRows];
for (int i = 0; i < numRows; ++i) {
temperatures[i] = new double[numCols];
}
//read in all the temperatures
for (int i = 0; i < numRows; ++i) {
for (int j = 0; j < numCols; ++j) {
file >> temperatures[i][j];
}
}
//print statistics
cout << "Processing data file: " << filename << endl;
printStatistics(temperatures, numRows, numCols);
file.close();
return 0;
}
