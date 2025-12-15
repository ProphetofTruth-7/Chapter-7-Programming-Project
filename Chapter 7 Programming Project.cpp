// This is the World Series Champions Subproject!

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void teamGathering(string x, vector<string>& TeamVector);

int main()
{
    string teamNames = "TeamNames.txt";
    string worldSeriesVictories = "WorldSeriesChamps.txt";

    vector<string> TeamNameVector;

    teamGathering(teamNames,TeamNameVector);


    return 0;
}


// Functions Below

void teamGathering(string x, vector<string>& TeamVector) {
    ifstream inFile(x);
    string line;

    if (!inFile) {
        cerr << "Error opening file!" << endl;
    }
    getline(inFile, line);

    cout << line;
    
    inFile.close();
}