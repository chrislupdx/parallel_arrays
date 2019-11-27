//Parellell Arrays
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int loadData(ifstream &infile, string months[], int lows[], int highs[], int &rows);
 //reads from a text file and stores the data in par. arrays

void findLow(int lows[], int rows, int &lowtemp, int &month); 
//finds and returns the low temp+corresponding month

void findHigh(int highs[], int rows, int &hightemp, int &month);
 //finds+returns the high temp+corresponding month

int main()
{
ifstream inFile;

const int DAYS_IN_MONTH = 30;
const int UP_AND_DOWN = 2;

double allTemp[UP_AND_DOWN][DAYS_IN_MONTH];
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int lows[30];
int highs[30];
int rows;

//file io with a temps.txt 
loadData(inFile, months, lows, highs, rows );


return 0;
}

int loadData(ifstream &inFile, string months[], int lows[], int highs[], int &rows )
{
string query;

//prompts the user for a location -> takes it
cout << "input a file location" << endl;
cin >> query;

inFile.open(query);


return 1;
}
