#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

map<string, string>mp;
void Initialise()
{
    mp["even"] = "even.cpp";
    mp["odd"] = "odd.cpp";
    mp["even_odd"] = "even_odd.cpp";
}
void solve(string s)
{   Initialise();
    stringstream ss(s);
    string token;
    bool check = false;
    while (ss >> token)
    {
        if (mp[token] != "")
        {
            check = true;
            cout << mp[token] << endl;
        }

    }
    if (!check)
        cout << "token not found\n";
}
void start()
{
    string s;

    cout << "Press __ to Stop The Program" << endl;
    cout << endl;
    cout << "Enter Your Query: ";
    getline(cin, s);
    while (s != "__")
    {   solve(s);
        cout << endl;
        cout << "Enter Your Query: ";

        getline(cin, s);
    }


}
void print()
{
    cout << "****** ****** ****** *          * ******  ****** " << endl;
    cout << "  *    *    * *    *  *        *    *     *      " << endl;
    cout << "  *    *    * *    *   *      *     *     *      " << endl;
    cout << "  *    ****** * * **    *    *      *     ****** " << endl;
    cout << "* *    *    * *   *      *  *       *          * " << endl;
    cout << "  *    *    * *    *      *       ******  ****** " << endl; \

    cout << endl << endl;
}
int main()
{
    // print();
    // start();

    std::ifstream file("jarvis.cpp");
    std::string line;
    while (std::getline(file, line)) {
        for (char c : line) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(75)); // Change the delay time as per your requirement
        }
        std::cout << std::endl;
    }

    cout.tie(NULL);
}

