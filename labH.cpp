//Parellell Arrays
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int loadData(ifstream &infile, string months[], int lows[], int highs[], int &rows);

void findLow(int lows[], int rows, int &lowtemp, int &month); 
//finds and returns the lowest temp+corresponding month

void findHigh(int highs[], int rows, int &hightemp, int &month);
 //finds+returns the highest temp+corresponding month

int main() //check that high, low, names can print in mian
{
ifstream inFile;

const int DAYS_IN_MONTH = 30;
const int UP_AND_DOWN = 2;

double allTemp[UP_AND_DOWN][DAYS_IN_MONTH];
string months[12]; //NEEDS VARS
int lows[30]; //NEEDS VARS
int highs[30]; //NEEDS VARS
int rows; //LOL COULD WE HARD CODE THAT
int month = 12; //need var
int lowtemp = 0;
cout << "this program takes a file of month, high, and low temp data and" << endl;
loadData(inFile, months, lows, highs, rows);

findLow(lows, rows, lowtemp, month);

return 0; //at some point print everything out pretty
}

//find the lowest temp and resspective month
void findLow(int lows[], int rows, int &lowtemp, int &month)
{
  int lowest = lows[0];
  for (int i = 0; i < 12; i++) //iterate through and compare their vals
  {
     if (lows[i] < lowest) 
      {
      lowest = lows[i];
      }
  cout << lowest << endl;
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
} //still needs code to not read more rows than the # of slots in arrays
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
inFile.close();

return 1;
}
