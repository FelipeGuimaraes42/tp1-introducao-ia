#include <iostream>
#include <string>
#include <vector>
#include "BFS.cpp"
#include "ReadFile.cpp"

using namespace std;

int main(int argc, char **argv)
{
    string fileName(argv[1]);
    ReadFile readFile(fileName);
    vector<string> map = readFile.read();
    return 0;
}