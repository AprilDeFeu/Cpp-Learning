#include <cstdlib> 
#include <iostream>
#include <limits>
#include <string>

using namespace std;

string Error = "Error: You did not enter an integer.\n";

void tutorial() {
    cout << "You are a hacker attempting to save your city from a nuclear explosion!" << endl;
    cout << "Your task is to codebreak your way into the mainframe by guessing the password. Good luck." << endl;
    
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;
    
    cout << "+ You will be given 3 numbers which are added and multiplied together.\n+ You must guess correctly before you get detected." << endl;
    cout << "+ For example, you have 3 numbers that added together give " << CodeSum << endl;
    cout << "+ Multiplied together, they give " << CodeProduct << endl;
    cout << "+ So the three numbers are " << CodeA << ", " << CodeB << ", " << CodeC << endl;

    int PlayerGuess;
    cout << "First, let's make sure the terminal works. Enter an integer: " << endl;
    cin >> PlayerGuess;

    while(1)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << Error;
            cout << "Enter an integer: ";
            cin >> PlayerGuess;
        } else {
            break;
        }
    }
    cout << "You entered the number " << PlayerGuess << ", so the terminal seems to work.\n";
    cout << "You will have 3 attempts per level. Each failed one will send a warning to the system.\nIf you fail 3 attempts, the bomb explodes!\n\n";
}

bool game(int X, int Y, int Z)
{
    int Lives = 3;
    const int Sum = X + Y + Z;
    const int Product = X * Y * Z;

    int GuessA;
    int GuessB;
    int GuessC;

    int GuessSum;
    int GuessProduct;

    cout << "\tLEVEL " << Y << endl;
    while (Lives > 0)
    {
        cout << "You have " << Lives << " lives left.\n";
        cout << "The password has a sum: " << Sum << endl;
        cout << "The password has a product:" << Product << endl << endl;

        cout << "Enter your guess for the first number: ";
        cin >> GuessA;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << Error;
                cout << "Enter an integer: ";
                cin >> GuessA;
            } else {
                break;
            }
        }

        cout << "Enter your guess for the second number: ";
        cin >> GuessB;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << Error;
                cout << "Enter an integer: ";
                cin >> GuessB;
            } else {
                break;
            }
        }

        cout << "Enter your guess for the third number: ";
        cin >> GuessC;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << Error;
                cout << "Enter an integer: ";
                cin >> GuessC;
            } else {
                break;
            }
        }

        GuessSum = GuessA + GuessB + GuessC;
        GuessProduct = GuessA * GuessB * GuessC;

        if (GuessSum == Sum && GuessProduct == Product) 
        {
            cout << "Congratulations, LEVEL " << Y << " cleared.\n";
            return true; // Gamestate true, continue
        }
        else 
        {
            cout << "Oh no! Incorrect password, you lose 1 attempt.\n";
            Lives--;
        }
    }
    cout << "The bomb exploded and everyone died.\n\tGAME OVER.\n";
    return false; // Gamestate false, game over.r
}


int main()
{
    tutorial();

    for (int i = 1; i<11; i++)
    {
        int PwA = 1 + (rand() % i);
        int PwC = 1 + (rand() % i);
        bool GameState = game(PwA, i, PwC);
        if (!GameState) return 0; 
    }
    cout << "You deactivated the bomb. Everyone is safe.\n";
    return 0;
}