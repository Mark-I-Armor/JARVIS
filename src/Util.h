#include "Implement.h"
#include "header.h"
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);

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

  mp["even"] = "even.txt";
  mp["odd"] = "odd.txt";
  mp["even_odd"] = "Even_Odd.txt";
  mp["palindrome"] = "palindrome.txt";
  mp["reverse"] = "reverse.txt";
  mp["nthprime"] = "nthprime.txt";
  mp["strong"] = "isstrong.txt";
  mp["armstrong"] = "armstrong.txt";
  mp["prime"] = "prime.txt";
  mp["happy"] = "happy.txt";
  mp["factorial"] = "factorial.txt";
  mp["subarraysum"] = "subarraysum.txt";

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
  tolower(s);
  stringstream ss(s);
  string token;
  bool check = false;

  vector<string> tokens;
  while (ss >> token) {
    if (mp[token] != "") {

      tokens.push_back(token);
      string add = "";
      check = true;
      int choice = Choice();
      if (s.find("optimised") != string::npos)
        add += "optimised";
      if (choice == 1) {
        cout << "Choose in which language you want code.\n1: C++\n2: Java\n3: "
                "Python\n";
        int Lang = 1;
        cin >> Lang;
        string source = "";
        if (Lang == 1) {
          source += "cpp";
        } else if (Lang == 2) {
          source += "java";
        } else if (Lang == 3) {
          source += "python";
        } else {
          cout << "Invalid Choice\n";
          return;
        }
        if (add == "optimised") {
          source += "/optimised";
        } else {
          source += "/";
        }

        cout << "Processing";
        string Process = "...";
        for (int i = 0; i < Process.size(); i++) {
          std::cout << Process[i] << std::flush;
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        cout << "\n\n";
        std::ifstream file(source + mp[token]);
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
  if (!check) {
    findMostAppropriateKeyword(files, s);
    return;
  }
}

void start() {
  Initialise();
  string s;
  cout << "Press __ to Stop The Program" << endl;
  cout << endl;

  do {

    cout << "Enter Your Query: ";

    getline(cin, s);
    string query = removeWordsFromQuery(s, commonWords);
    cout << endl;
    solve(query);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  } while (s != "___");
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