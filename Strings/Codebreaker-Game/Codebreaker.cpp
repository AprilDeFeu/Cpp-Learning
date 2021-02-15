#include <iostream>
#include <ctime> 

using namespace std;

int main()
{
    cout << "You are a hacker attempting to save your city from a nuclear explosion!" << endl;
    cout << "Your task is to codebreak your way into the mainframe by guessing the password. Good luck." << endl;
    
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;

    int Difficulty = 1;
    int MaxDifficulty = 10;
    
    cout << "+ You will be given 3 numbers which are added and multiplied together."  << endl << "+ ou must guess correctly before you get detected." << endl;
    cout << "+ For example, you have 3 numbers that added together give " << CodeSum << endl;
    cout << "+ Multiplied together, they give " << CodeProduct << endl;
    cout << "+ So the three numbers are " << CodeA << ", " << CodeB << ", " << CodeC << endl;

    int PlayerGuess;
    cout << "First, let's make sure the terminal works. Eneter an integer: " << endl;
    
    

    cout << "You entered the number " << PlayerGuess << endl; 
    return 0;
}