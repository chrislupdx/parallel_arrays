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
int length = 168;
int monthLength = 10;
int monthPos = 0;
int totalNums = 46;
char nowhere[length];
char monthWord[monthLength];
char numCharBuff[totalNums];
int numCharBuffPos = 0;
string recieved;
string elsewhere;
query = "temps.txt";
//cout << "loaded" << endl;

inFile.open(query);

if (!inFile)
{
  cout << "Can't open the input file. "
    << "Bye!" << endl;
  return -1;
}

//yes we're doing it for the iterating variable, but what's being iterated actually
for (int i = 0; i < length; i ++)
{
  //i'm guessing that we could use read :(
  inFile.getline(nowhere, length, '\0' );
  //  cout << nowhere[i];

  //if you detect a capital letter, store contents[i] till you run into a space
if (isupper(nowhere[i]))
{
  //capital letter is assigned to the first slot of monthWord
  monthWord[monthPos] = nowhere[i]; 
  //cout << monthWord[monthPos] << endl;
  ++monthPos; //wats monthPos for and do we really need it
}

if (isalpha(nowhere[i]) && !isupper(nowhere[i]) )
{
  monthWord[monthPos] = nowhere[i];
  ++monthPos; 
}

if(isdigit(nowhere[i]))
{ 
  numCharBuff[numCharBuffPos] = nowhere[i];
  ++numCharBuffPos;
}

}


  
  //this loop shows how we're putting months into string
//  for (int i = 0; i < monthPos; i++)
//  {
  //keeps running for a long ass time
//  cout << monthWord[i];
//  }

//  this loop checks how we're putting highs into high
  for (int i = 0; i < totalNums; i++)
  {
  cout << "totalNums are " << numCharBuff[i] << endl;
  }  
  cout << endl;
  inFile.close();
return 1;
}
