//Parellell Arrays
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int loadData(ifstream &infile, string months[], int lows[], int highs[], int &rows);

void findLow(int lows[], int rows, int &lowtemp, int &month);

void findHigh(int highs[], int rows, int &hightemp, int &month);

int main()
{
ifstream inFile;

const int DAYS_IN_MONTH = 30;
const int UP_AND_DOWN = 2;

double allTemp[UP_AND_DOWN][DAYS_IN_MONTH];
int months_in_year = 12;
string months[months_in_year]; 
int lows[months_in_year];
int highs[months_in_year]; 
int rows; 
int month;
int lowtemp;
int hightemp;
cout << "takes a file with month, high, and low temp data and prints out the lowest+highest and the rest of the data" << endl << endl;
loadData(inFile, months, lows, highs, rows);

cout << "High:" << setw(13) << "Low:" << setw(15) << "Month:" << endl;
for (int i = 0; i < rows; i++)
{
  cout << highs[i] << setw(15) << lows[i] << setw(15) << months[i] << endl;
}
  cout << endl;


if (!(rows <= 1)) //we need to figure out a way to rig loaddata to modify rows
{
findLow(lows, rows, lowtemp, month); //if theres only one row don't run both high+low
cout << "Lowest temp month is: " << months[month] << " the temp is " << lowtemp << endl << endl;

findHigh(highs, rows, hightemp, month);
cout << "Highest temp month is: " << months[month] << " the temp is " << hightemp << endl << endl;
}


return 0;
}


//fine the higest temp and respective month
void findHigh(int highs[], int rows, int &hightemp, int &month)
{
  cout << "findHigh called" << endl << endl;
  int highest = highs[0];
  for (int i = 0; i < rows; i++)
  {
    if(highs[i] > highest)
    {
    highest = highs[i];
    month = i;
    }
  }
  hightemp = highest;
}

//find the lowest temp and resspective month
void findLow(int lows[], int rows, int &lowtemp, int &month)
{
  cout << "findLow called" << endl << endl;
  int lowest = lows[0];
  for (int i = 0; i < rows; i++) //iterate through and compare for the lowest value
  {
     if (lows[i] < lowest)
      {
      lowest = lows[i];
      month = i;  //assign ordinal address to month
     }
     lowtemp = lowest;
  }
}

//consumes a file input, parses+returns months, high and low temp in arrays respectively
int loadData(ifstream &inFile, string months[], int lows[], int highs[], int &rows )
{ //how do we want to refactor to include &rows:
int high_and_low = 24;
int numbers[high_and_low];
int i = 0;
int numsIt = 0;
int monthsIt = 0;
int highsIt = 0;
int lowsIt = 0;
int lines = 0;
string gotLine;
string query = "temps.txt";
string recieved;
inFile.open(query);
cout << "loaddata called" << endl << endl;

if (!inFile)
{
  cout << "Can't open the input file. "
    << "Bye!" << endl;
  return -1;
}


while (inFile >> recieved) //tried putting my inner get loop before and after all of my if statements, none worked. clearing after use did not work, resorted to this and it worked
{

  while (getline(inFile, gotLine))
  {
 ++lines; 
  inFile.clear();
  }
rows = lines;
}
inFile.close();
inFile.clear();

inFile.open(query);

while (inFile >> recieved)
{

  if(recieved.length() == 2) //well hey, number vals are 2 letters
  {
    numbers[numsIt] = stoi(recieved);
    numsIt++; // i think the stop logic happens here
  }
  if(recieved.length() >= 3) //well hey, months are longer than 3 chars
  {
    months[monthsIt] = recieved;
    monthsIt++; //does the stop logic happen here, we don't have rows yet
  }
} 
  cout << "number of months in the file: " << monthsIt << endl;
for (int i = 0; i < numsIt; i++) //work with numbers to get high and low
{

if (i % 2 == 0) //if i is divisible by 2, it's high
  {
    highs[highsIt] = numbers[i];
    highsIt++;
  }
if (!(i % 2 == 0))
  {
  lows[lowsIt] = numbers[i];
  lowsIt++;
  }

}


return 0;
}
