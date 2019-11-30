//Parellell Arrays
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

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
//string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
string months[12];
int lows[30];
int highs[30];
int rows;

//file io with a temps.txt 
loadData(inFile, months, lows, highs, rows);

return 0;
}

int loadData(ifstream &inFile, string months[], int lows[], int highs[], int &rows )
{
string query;
int length = 170;
char nowhere[length];
string recieved;
string elsewhere;
query = "temps.txt";
cout << "loaded" << endl;

inFile.open(query);

if (!inFile)
{
  cout << "Can't open the input file. "
       << "Bye!" << endl;
   return -1;
}

//do we do a conditional thing so it goes off only once?

for (int i = 0; i < length; i ++)
{
  inFile.getline(nowhere, length, '\0' );
  cout << nowhere[i];  
}
  cout << endl;



//we need to put the words (spaces between)
//we need first number and second number (which are both single chars)


inFile.close();
//can we put filestream data into you know an array or cstring or enum

return 1;
}
