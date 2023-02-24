#include "header.h"
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
map<string, string> mp;
void callFun(string s) {
  if (s == "even")
    even();
  else if (s == "odd")
    odd();
  else if (s == "even_odd")
    even_odd();
  else if (s == "palindrome")
    palindrome();
  else if (s == "prime")
    isPrime();
  else if (s == "Happy")
    isHappy();
  else if (s == "armstrong")
    isArmstrong();
  else if (s == "nthprime")
    nthPrime();
  else if (s == "strong")
    isStrong();
  else if (s == "factorial")
    fact();
}
vector<string> files;
void Initialise() {

  mp["even"] = "Programs/even.txt";
  mp["odd"] = "Programs/odd.txt";
  mp["even_odd"] = "Programs/Even_Odd.txt";
  mp["palindrome"] = "Programs/palindrome.txt";
  mp["reverse"] = "Programs/reverse.txt";
  mp["nthprime"] = "Programs/nthprime.txt";
  mp["strong"] = "Programs/isstrong.txt";
  mp["armstrong"] = "Programs/armstrong.txt";
  mp["prime"] = "Programs/prime.txt";
  mp["happy"] = "Programs/happy.txt";
  mp["factorial"] = "Program/factorial.txt";

  files.push_back("even");
  files.push_back("odd");
  files.push_back("even_odd");
  files.push_back("reverse");
  files.push_back("palindrome");
  files.push_back("strong");
  files.push_back("happy");
  files.push_back("prime");
  files.push_back("armstrong");
  files.push_back("nthprime");
  files.push_back("factorial");
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

  vector<string> tokens;
  while (ss >> token) {
    if (mp[token] != "") {

      tokens.push_back(token);
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
        check = true;
        callFun(token);
      }
    }
  }
  if (tokens.size() > 1) {
    cout << "Is above Provide Information Right\n1:True and 2 False:";
    int op;
    cin >> op;
    if (op == 1)
      return;
    else if (op == 2) {
      set<string> st;
      for (int i = 0; i < tokens.size(); i++) {
        for (int j = 0; j < files.size(); j++) {
          if (files[j].find(tokens[i]) != string::npos)
            st.insert(files[j]);
        }
      }
      cout << "Choose Option from Below \n";
      int count = 1;
      for (auto &i : st) {
        cout << count++ << ": " << i << endl;
      }
      string New;
      cin >> New;
      solve(New);
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

  do {

    cout << "Enter Your Query: ";

    getline(cin, s);
    cout << endl;
    solve(s);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  } while (s != "__");
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
