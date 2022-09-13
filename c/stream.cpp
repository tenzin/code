#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  ifstream infile("test");
  char ch;
  infile >> ch;
  cout << ch << endl;
  return 0;
}
