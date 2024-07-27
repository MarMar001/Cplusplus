#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

    //initalize variables

    string dataLine;

    ifstream inputFile;
    ofstream outputFile;

    //open the input file (program expects the file to be in the same directory as the program)
    inputFile.open("Filtered_AL_Weather_Station.txt");

    //check if the file is successfully opened
    if (!inputFile) {
        cout << "Error opening file" << endl;
        return 1;
    }
    else {
        cout << "Input file opened successfully." << endl;
    }

    //creates and open the output file
    outputFile.open("reduced_columns.txt");

    //check if the file is successfully opened
    if (!outputFile) {
        cout << "Error opening file" << endl;
        return 2;
    }
    else {
        cout << "Output file opened successfully." << endl;
    }

    //read header line and find position of columns
    getline(inputFile, dataLine);

    //find where the column starts in the line
    int posName = dataLine.find("STATION_NAME");
    int posElev = dataLine.find("ELEVATION");
    int posLat = dataLine.find("LATITUDE");
    int posLon = dataLine.find("LONGITUDE");
    int posDate = dataLine.find("DATE");
    int posMDPR = dataLine.find("MDPR");
    int posPRCP = dataLine.find("PRCP");
    int posSNWD = dataLine.find("SNWD");
    int posTMAX = dataLine.find("TMAX");
    int posTMIN = dataLine.find("TMIN");
    int posAWND = dataLine.find("AWND");

    //save columns sizes
    int columnSTATIONLength = posElev - posName;
    int columnELEVATIONLength = posLat - posElev;
    int columnLATITUDELength = posLon - posLat;
    int columnLONGITUDELength = posDate - posLon;
    int columnDATELength = posMDPR - posDate;
    int columnPRCPLength = posSNWD - posPRCP;
    int columnTMAXLength = posTMIN - posTMAX;
    int columnTMINLength = posAWND - posTMIN;


    //build substrings
    stringstream temp;
    temp << dataLine.substr(posName, columnSTATIONLength) 
        << dataLine.substr(posElev, columnELEVATIONLength)
        << dataLine.substr(posLat, columnLATITUDELength) 
        << dataLine.substr(posLon, columnLONGITUDELength)
        << dataLine.substr(posDate, columnDATELength) 
        << dataLine.substr(posPRCP, columnPRCPLength) 
        << dataLine.substr(posTMAX, columnTMAXLength) 
        << dataLine.substr(posTMIN, columnTMINLength)
        << endl;
    //print header to output file
    outputFile << dataLine.substr(posName, columnSTATIONLength) 
        << dataLine.substr(posElev, columnELEVATIONLength)
        << dataLine.substr(posLat, columnLATITUDELength)  
        << dataLine.substr(posLon, columnLONGITUDELength) 
        << dataLine.substr(posDate, columnDATELength)<< "  "
        << dataLine.substr(posPRCP, columnPRCPLength) 
        << dataLine.substr(posTMAX, columnTMAXLength) 
        << dataLine.substr(posTMIN, columnTMINLength)
        << endl;

    //ignore dashed line
    getline(inputFile, dataLine);


    //loop and read input file and filter data
    while (!inputFile.eof()) {
        getline(inputFile, dataLine);

        //last line has a length of 0, so break to prevent out of range
        if (dataLine.length() == 0) break;

        //add the name to the output file and left justify
        string str = dataLine.substr(posName, posElev - posName);
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[i] == ' ') {
                str.erase(i, 1);
                i--;
            }
            else {
                break;
            }
        }
        outputFile << setw(posElev - posName) << left << str;

      
        //add elevation as a floating point number with precision 2
        double elevation = stod(dataLine.substr(posElev, columnELEVATIONLength));
        outputFile << setw(columnELEVATIONLength) << fixed << setprecision(2) << elevation;

      
        //add latitude and longitude with precision 4
        double latitude = stod(dataLine.substr(posLat, columnLATITUDELength));
        outputFile << setw(columnLATITUDELength) << fixed << setprecision(4) << latitude;
        double longitude = stod(dataLine.substr(posLon, columnLONGITUDELength));
        outputFile << setw(columnLONGITUDELength) << fixed << setprecision(4) << longitude;

      
       //add formatted dates
        string date = dataLine.substr(posDate, columnDATELength);
        string newDate = date.substr(4, 4) + date.substr(0, 4);
        string month = newDate.substr(0, 2);
        string day = newDate.substr(2, 2);
        string year = newDate.substr(4, 4);
        outputFile  << setw(columnDATELength-8)<< month <<' ' << day << ' ' << year<< ' ';

      
        //add prcp
        double prcp = stod(dataLine.substr(posPRCP, columnPRCPLength));
        outputFile << setw(columnPRCPLength) << fixed << setprecision(2) << prcp;

      
        //add tmin and tmax
        double tmax = stod(dataLine.substr(posTMAX, columnTMAXLength));
        outputFile << setw(columnTMAXLength) << fixed << setprecision(2) << tmax;
        double tmin = stod(dataLine.substr(posTMIN, columnTMINLength));
        outputFile << setw(columnTMINLength) << fixed << setprecision(2) << tmin;
        outputFile << endl;


    }
    cout << "Filtered data file created successfully." << endl;

    // close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
