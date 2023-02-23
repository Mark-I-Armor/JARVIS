#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
map<string, string> mp;
void Initialise() {

  mp["even"] = "Programs/even.txt";
  mp["odd"] = "Programs/odd.txt";
  mp["even_odd"] = "Programs/Even_Odd.txt";
}

int Choice() {
  cout << "1: Get The Code\n2: Run The Code\n";
  char ch;
  cin >> ch;

  if (ch == '1')
    return 1;
  else if (ch == '2')
    return 2;
  else {
    {
      cout << "Not A Valid Input\n";
      return 0;
    }
  }
}

void solve(string s) {

  stringstream ss(s);
  string token;
  bool check = false;
  while (ss >> token) {
    if (mp[token] != "") {
      check = true;
      int choice = Choice();
      if (choice == 1) {
        cout << "Processing";
        string Process = "...";
        for (int i = 0; i < Process.size(); i++) {
          std::cout << Process[i] << std::flush;
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        cout << endl;
        std::ifstream file(mp[token]);
        std::string line;
        while (std::getline(file, line)) {
          for (char c : line) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(
                75)); // Change the delay time as per your requirement
          }
          std::cout << std::endl;
        }

        cout.tie(NULL);
      } else if (choice == 2) {
        cout << "Enter Numbe to check value\n";
        int value;
        // check = true;
        cin >> value;
        if (value & 1)
          cout << "Entered Number is: Odd\n";
        else
          cout << "Entered Number is: Even\n";
      }
    }
  }
  // if (!check) {
  //   cout << "token not found\n";
  //   return;
  // }
}

void start() {
  Initialise();
  string s;
  cout << "Press __ to Stop The Program" << endl;
  cout << endl;
  cout << "Enter Your Query: ";
  getline(cin, s);

  while (s != "__") {
    solve(s);
    cout << endl;
    cout << "Enter Your Query: ";
    getline(cin, s);
  }
}
void print() {
  cout << "****** ****** ****** *          * ******  ****** " << endl;
  cout << "  *    *    * *    *  *        *    *     *      " << endl;
  cout << "  *    *    * *    *   *      *     *     *      " << endl;
  cout << "  *    ****** * * **    *    *      *     ****** " << endl;
  cout << "* *    *    * *   *      *  *       *          * " << endl;
  cout << "  *    *    * *    *      *       ******  ****** " << endl;

  cout << endl << endl;
}
int main() {
  ios_base::sync_with_stdio(true);
  cin.tie(NULL);
  cout.tie(NULL);
  print();
  start();
}
