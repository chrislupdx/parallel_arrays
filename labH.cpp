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
int monthLength = 10;
int monthPos = 0;
char nowhere[length];
char monthWord[monthLength];
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
  inFile.getline(nowhere, length, '\0' );
//  cout << nowhere[i];  

//detect spaces
  if (nowhere[i] == ' ')
  {
  }
//detect if digit
if (isdigit(nowhere[i]))
  {
  } 

//detect new line
if (nowhere[i] == '\n')
  {
  }

//if you detect a capital letter, store contents[i] till you run into a space
//as a string and put into in months[0]
if (isupper(nowhere[i]))
  {
  //capital letter is assigned to the first slot of monthWord
  monthWord[monthPos] = nowhere[i]; 
  //cout << monthWord[monthPos] << endl;
  ++monthPos;
  }
  //if a noncapital character
 if (isalpha(nowhere[i]) && !isupper(nowhere[i]) )
  {
//  cout << nowhere[i];
  monthWord[monthPos] = nowhere[i];
  ++monthPos; 
  }
}
//uncomment the loop before and check it out yourself
  for (int i = 0; i < monthPos; i++)
  {
  //keeps running for a long ass time
  cout << monthWord[i];
  }

  cout << endl;


inFile.close();
//can we put filestream data into you know an array or cstring or enum

return 1;
}
