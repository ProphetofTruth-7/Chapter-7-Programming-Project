// This is the Exam Grader subproject

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void storeStudentAnswers(string x, int y, char studentAnswers[]); //This prototype establishes a function that stores the student's answers into an array for future comparison/grading
void storeAnswerKey(string x, int y, char answerKey[]); //This prototype establishes a function that stores the answer key into an array for future comparison
void compareAnswers(char studentAnswers[], char answerKey[], int y, int wrongQuestionStorage[], char correctAnswerStorage[][2], int& z); //This prototype establishes a function that compares the two arrays

void writeReport(int funcArray1[], char funcArray2[][2], int y, int z) { // Ignore this
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

    int wrongAnswerArray[20]; // An array that stores twenty zeroes. compareAnswers replaces Index with the Question number they got wrong
    char comparisonArray[20][2]; //A 2D array that stores forty Xs. compareAnswers replaces the Index(related to wrongAnswerArray) with the Student and Answer Key's letters

    //X and 0 are used as invalid values that are skipped in the function writeReport


    compareAnswers(studentScoreArray, answerKeyArray, numberOfQuestions, wrongAnswerArray, comparisonArray, wrongAnswers);

    cout << "Testing: " << wrongAnswerArray[8] << endl;
    cout << "Testing2: " << comparisonArray[8][0] << endl;  //This relates directly to question 9 on the File. For some reason, it returns an odd symbol ONLY here. It stores properly in the function compareAnswers

    cout << "Question " << wrongAnswerArray[2] << "     Comparison(student): " << comparisonArray[3][0] << "      Comparison(correct): " << comparisonArray[3][1] << endl;
    cout << "You've gotten this many wrong: " << wrongAnswers;

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
void compareAnswers(char studentAnswers[], char answerKey[], int y, int wrongQuestionStorage[], char correctAnswerStorage[][2], int& z) {
    for (int incrementCount = 0; incrementCount < y; ++incrementCount) {
        if (studentAnswers[incrementCount] == answerKey[incrementCount]) { // Compares the student's answer with the answer key. If they are the same, it stores values I use to skip these correct answers
            wrongQuestionStorage[incrementCount] = 0;
            correctAnswerStorage[incrementCount][0] = 'X';
            correctAnswerStorage[incrementCount][1] = 'X';
        }
        else { //If they're different, it stores...
            wrongQuestionStorage[incrementCount] = incrementCount + 1; //The specific question that was missed
            cout << "Increment(" << incrementCount << ").   Array Value(" << wrongQuestionStorage[incrementCount] << ")" << endl;    //This is simply visual verification that the questions are stored properly
            correctAnswerStorage[incrementCount + 1][0] = studentAnswers[incrementCount]; //The student's (incorrect) answer
            correctAnswerStorage[incrementCount + 1][1] = answerKey[incrementCount]; //The correct answer
            cout << correctAnswerStorage[incrementCount + 1][0] << " and " << correctAnswerStorage[incrementCount + 1][1] << endl; //This is simply visual verification that the answers are stored together and properly
            ++z;
        }

    }
}