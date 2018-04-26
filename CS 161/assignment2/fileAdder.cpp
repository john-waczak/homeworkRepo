/********************************************************************* 
 ** Author: John Waczak 
 ** Date: 4/25/18
 ** Description: Read integers from txt file, add them, and write sum to another file. 
 *********************************************************************/ 




#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream; 

int main()
{
  string file; 
  ifstream inputFile;
  ofstream outputFile;

  int sum = 0;

  cout << "Please enter a valid txt file name." << endl;
  cin >> file;
  // must convert string to c-style char array
  inputFile.open(file.c_str());
  if(!inputFile){
    cout << "Something went wrong. Could not find file" << endl;
  }
  outputFile.open("sum.txt");


  int line;
  while(inputFile >> line)
  {
    sum += line; 
  }
  inputFile.close(); 

  outputFile << sum << endl;
  outputFile.close();

  return 0; 
  
}
