// This is the Exam Grader subproject

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void storeStudentAnswers(string x, int y, char funcArray[]); //This prototype establishes a function that stores the student's answers into an array for future comparison/grading
void storeAnswerKey(string x, int y, char funcArray[]); //This prototype establishes a function that stores the answer key into an array for future comparison
void compareAnswers(char funcArray1[], char funcArray2[], int y, int funcArray3[], char funcArray4[][2], int& z); //This prototype establishes a function that compares the two arrays

int main()
{
    string studentAnswers = "StudentAnswers.txt";
    string correctAnswers = "CorrectAnswers.txt";

    const int numberOfQuestions = 20;  //You can alter this when you have a different number of questions
    char studentScoreArray[numberOfQuestions];
    char answerKeyArray[numberOfQuestions];
    int wrongAnswers = 0;

    storeStudentAnswers(studentAnswers, numberOfQuestions, studentScoreArray);
    storeAnswerKey(correctAnswers, numberOfQuestions, answerKeyArray);

    int wrongAnswerArray[20];
    char comparisonArray[20][2];

    compareAnswers(studentScoreArray, answerKeyArray, numberOfQuestions, wrongAnswerArray, comparisonArray, wrongAnswers);
    cout << wrongAnswerArray[1] << endl;
    cout << "Question " << wrongAnswerArray[2] << "     Comparison(student): " << comparisonArray[3][0] << "      Comparison(correct): " << comparisonArray[3][1] << endl;
    cout << "You've gotten this many wrong: " << wrongAnswers;

    return 0;
}




// Functions Below






void storeStudentAnswers(string x, int y, char funcArray[]) {
    ifstream inFile(x);
    char answer;

    if (!inFile) {    //Warns the user that there was an error opening the file, then ends the whole program
        cerr << "Error opening file!" << endl;
        exit;
    }

    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {  //This ticks through all of the student's answers, reference-storing them into an array
        inFile >> answer;
        funcArray[incrementCount] = answer;
    }
    inFile.close();
}

void storeAnswerKey(string x, int y, char funcArray[]) {
    ifstream inFile(x);
    char answer;

    if (!inFile) {    //Warns the user that there was an error opening the file, then ends the whole program
        cerr << "Error opening file!" << endl;
        exit;
    }

    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {  //This ticks through all of the answer key, reference-storing them into an array
        inFile >> answer;
        funcArray[incrementCount] = answer;
    }
    inFile.close();
}
void compareAnswers(char funcArray1[], char funcArray2[], int y, int funcArray3[], char funcArray4[][2], int& z) {
    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        if (funcArray1[incrementCount] == funcArray2[incrementCount]) {
            funcArray3[incrementCount] = 0;
            funcArray4[incrementCount][0] = 'X';
            funcArray4[incrementCount][1] = 'X';
        }
        else {
            funcArray3[incrementCount] = incrementCount + 1;
            cout << "Increment(" << incrementCount << ").   Array Value(" << funcArray3[incrementCount] << ")" << endl;    //This properly stores the specific question missed
            funcArray4[incrementCount + 1][0] = funcArray1[incrementCount];
            funcArray4[incrementCount + 1][1] = funcArray2[incrementCount];
            ++z;
        }

    }
}