#include <fstream>
#include <iomanip>
using namespace std;
int main() {
//open the input file (file must be in the same directory)
ifstream inputFile("temps.txt");
//check if the file is successfully opened
if (!inputFile){
cout << "Error opening file" << endl;
return 1;
}
else {
cout << "Input file opened successfully." << endl;}
//create and open the output file
ofstream outputFile("table.txt");
//check if the file is successfully opened
if (!outputFile){
cout << "Error opening file" << endl;
return 1;}
else {
cout << "Output file opened successfully." << endl;}
//header
outputFile << setw(8) << "Celsius" << setw(12) << "Fahrenheit" << setw(10) << "Kelvin" << endl;
//process temperature from the input file
double celsius;
while (inputFile >> celsius) {
double fahrenheit = 9.0 / 5.0 * celsius + 32.0;
double kelvin = celsius + 273.15;
// write the results
outputFile << fixed << setprecision(2);
outputFile << setw(8) << celsius << setw(12) << fahrenheit << setw(10) << kelvin << endl;
}
//close the files
inputFile.close();
outputFile.close();
//confirm completion
cout << "Conversion done! Results written to table.txt." << endl;
return 0;
}
