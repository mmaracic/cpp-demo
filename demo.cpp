#include <iostream>
#include <vector>
#include <string>
#include "addition.hpp"
#include "subtraction.hpp"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << "Add 5 and 8 is " << Addition::add(5,8) << endl;
    cout << "Subtracting 5 from 8 is " << Subtraction::sub(8,5) << endl;
}