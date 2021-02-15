// My first program in C++

// Header inclusion
#include <iostream>
#include <limits>
#include <string>

// Namespace usage for cleaner code
using namespace std;

// Factorial function
int Factorial(int n)
{
    if (n <= 0) return 1;
    else return n * Factorial(n-1);
}

int main() 
{
    // Hello World!
    cout << "Hello World! \n";
    // Escaping characters in strings
    cout << "This (\") is a quote and this (\\) is a backspace. \n" ;

    // Exercise 0.10 from "Accelerated C++"
    string Sentence ("We will remove the spaces from this sentence.\n");
    cout << Sentence;
    for (int i = 0 ; i < Sentence.length() ; i++)
    {
        char c = Sentence.at(i);
        // Use ASCII value to compare character at i.
        if (int(c) == 32) Sentence.replace(i, 1, "");
    }

    cout << Sentence << endl;

    // Chapter 1.2 of "Acc C++"
    cout << "Please enter your name: ";

    
    // Will only add a single word with no spaces
    // string Name;
    // cin >> Name;
    
    // This will make a line of up to 250 characters, including spaces.
    char Name[250];
    cin.getline(Name, sizeof(Name));
    string Str(Name);

    string Greeting =  "*  Hello, " + Str + ", nice to meet you!   *\n";
    const string Spaces(Greeting.size(), ' ');
    const string Headers(Greeting.size(),  '*');

    const string Borders = "**" + Headers + "**\n";
    const string InterBody = "**" + Spaces + "**\n";

    cout << Borders << InterBody << Greeting << InterBody << Borders;

    int result;

    // Printing consecutive integers (Acc C++ 2.7)
    cout << "We will now show a script that prints integers from 10  to -5\n";
    for (int j = 10; -6 < j; j--) 
    {
        cout << j << ", ";
    }
    cout << endl;
    // Printing consecutive factorials (Acc C++, 2.8)
    cout << "Now, let us compute a factorials from 1 to 9\n";
    for (int i = 1; i < 10; i++) 
    {
        cout << i << "!=";
        for(int j = 1; j<=i; j++) 
        {
            if (j==i) cout << j << "=";
            else cout << j << "x";
        }
        result = Factorial(i);
        cout << result << endl;
    }

    // Ask for two integers and compare them (2.9)
    cout << "Please, enter two integers:\n";
    int IntegerA;
    int IntegerB;
    cout << "Integer A: ";
    cin >> IntegerA;
    string Error = "ERROR: You did not enter an integer. \n";
    while(1)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << Error;
            cout << "Integer A: ";
            cin >> IntegerA;
        } else {
            break;
        }
    }
    cout << "Integer B: ";
    cin >> IntegerB;
    while(1)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << Error;
            cout << "Integer B: ";
            cin >> IntegerB;
        } else {
            break;
        }
    }
    string Answer = "We have that ";
    if (IntegerA > IntegerB) 
    {
        cout << Answer << IntegerA << " is larger than " << IntegerB << ".\n"; 
    } else if (IntegerA < IntegerB)
    {
        cout << Answer << IntegerB << " is larger than " << IntegerA << ".\n"; 
    } else 
    {
        cout << Answer << IntegerA << " is equal to " << IntegerB << ".\n"; 
    }

    return 0;
}

