// This is the Exam Grader subproject

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void storeStudentAnswers(string x, int y, char studentAnswers[]); //This prototype establishes a function that stores the student's answers into an array for future comparison/grading
void storeAnswerKey(string x, int y, char answerKey[]); //This prototype establishes a function that stores the answer key into an array for future comparison
int calcWrongAnswers(char studentAnswers[], char answerKey[], int wrongStorage[], int y); //This prototype establishes a function that calculates the number of wrong answers and stores each specific one for future use
void writeReport(int wrongStorage[], char studentAnswers[], char answerKey[], int y, int z); //This prototype writes out the UI and calculates a Pass/Fail

int main()
{
    string studentAnswers = "StudentAnswers.txt";
    string correctAnswers = "CorrectAnswers.txt";

    const int numberOfQuestions = 20;  //You can alter this when you have a different number of questions
    char studentScoreArray[numberOfQuestions];
    char answerKeyArray[numberOfQuestions];

    storeStudentAnswers(studentAnswers, numberOfQuestions, studentScoreArray);
    storeAnswerKey(correctAnswers, numberOfQuestions, answerKeyArray);

    int wrongAnswerArray[20];


    int wrongAnswers = calcWrongAnswers(studentScoreArray, answerKeyArray, wrongAnswerArray, numberOfQuestions);
    writeReport(wrongAnswerArray, studentScoreArray, answerKeyArray, numberOfQuestions, wrongAnswers);

    return 0;
}




// Functions Below






void storeStudentAnswers(string x, int y, char studentAnswers[]) {
    ifstream inFile(x);
    char answer;

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        exit;
    }

    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        inFile >> answer;
        studentAnswers[incrementCount] = answer;
    }
    inFile.close();
}

void storeAnswerKey(string x, int y, char answerKey[]) {
    ifstream inFile(x);
    char answer;

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        exit;
    }

    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        inFile >> answer;
        answerKey[incrementCount] = answer;
    }
    inFile.close();
}

int calcWrongAnswers(char studentAnswers[], char answerKey[], int wrongStorage[], int y) {
    int wrongAnswers = 0, incrementCount = 0;

    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        if (studentAnswers[incrementCount] == answerKey[incrementCount]) {
            wrongStorage[incrementCount] = -1;
        }
        else {
            wrongStorage[incrementCount] = incrementCount + 1;
            ++wrongAnswers;
        }
    }
    return wrongAnswers;
}

void writeReport(int wrongStorage[], char studentAnswers[], char answerKey[], int y, int missed) {
    cout << "                   Exam Report" << endl;
    cout << "Number of Questions Missed: " << missed << endl;
    cout << "Missed Questions and Correct Answers:" << endl;
    cout << "Question       Correct Answer       Your Answer" << endl;
    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        if (wrongStorage[incrementCount] == -1) {

        }
        else {
            cout << wrongStorage[incrementCount] << setw(20) << studentAnswers[incrementCount] << setw(20) << answerKey[incrementCount] << endl;
        }
    }
    cout << "Number: " << (y - missed) / y << endl;
    cout << "Exam Score: " << (y - missed) / y << "%" << endl;
    if (((y - missed) / missed) >= 0.7) {
        cout << "You Passed!" << endl;
    }
    else {
        cout << "You Failed..." << endl;
    }
}