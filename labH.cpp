//Parellell Arrays
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int loadData(ifstream &infile, string months[], int lows[], int highs[], int &rows);

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
string months[12];
int lows[30];
int highs[30];
int rows;
loadData(inFile, months, lows, highs, rows);

return 0;
}

int loadData(ifstream &inFile, string months[], int lows[], int highs[], int &rows )
{
int numbers[24];
int i = 0;
int numsIt = 0;
int monthsIt = 0;
int highsIt = 0;
int lowsIt = 0;
string query = "temps.txt";
string recieved;
inFile.open(query);

if (!inFile)
{
  cout << "Can't open the input file. "
    << "Bye!" << endl;
  return -1;
}

while (inFile >> recieved)
{
  if(recieved.length() == 2) //well hey, number vals are 2 letters
  {
    numbers[numsIt] = stoi(recieved); 
    numsIt++;
  }

  if(recieved.length() >= 3) //well hey, months are longer than 3 chars
  { 
    months[monthsIt] = recieved;
    monthsIt++;
  }
}

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

inFile.close();

return 1;
}
