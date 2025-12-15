// This is the Exam Grader subproject

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void storeStudentAnswers(string x, int y, char funcArray[]); //This prototype establishes a function that stores the student's answers into an array for future comparison/grading
void storeAnswerKey(string x, int y, char funcArray[]); //This prototype establishes a function that stores the answer key into an array for future comparison
void compareAnswers(char funcArray1[], char funcArray2[], int y, int funcArray3[], char funcArray4[][2], int& z); //This prototype establishes a function that compares the two arrays

void writeReport(int funcArray1[], char funcArray2[][2], int y, int z) {
    cout << "                   Exam Report" << endl;
    cout << "Number of Questions Missed: " << z << endl;
    cout << "Missed Questions and Correct Answers:" << endl;
    cout << "Question       Correct Answer       Your Answer" << endl;
    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        if (funcArray1[incrementCount] == 0) {

        }
        else {
            cout << funcArray1[incrementCount] << setw(20) << funcArray2[incrementCount+1][0] << setw(20) << funcArray2[incrementCount+1][1] << endl;
        }
    }
}

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

    cout << "Testing: " << wrongAnswerArray[8] << endl;
    cout << "Testing2: " << comparisonArray[8][0] << endl;  //This relates directly to question 9 on the File. For some reason, it returns an odd symbol ONLY here. It stores properly in the function compareAnswers

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
            cout << "Increment(" << incrementCount << ").   Array Value(" << funcArray3[incrementCount] << ")" << endl;    //This verifies that the function properly stores the specific question missed
            funcArray4[incrementCount + 1][0] = funcArray1[incrementCount];
            funcArray4[incrementCount + 1][1] = funcArray2[incrementCount];
            cout << funcArray4[incrementCount + 1][0] << " and " << funcArray4[incrementCount + 1][1] << endl; //This verifies that each incorrect choice and correct answer are stored together
            ++z; //And yet, the main function corrupts Line 111's verification
        }

    }
}