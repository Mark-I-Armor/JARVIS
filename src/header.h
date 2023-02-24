#include <bits/stdc++.h>
using namespace std;

void even() {
  cout << "Enter Number to Check Even\n";
  int n;
  cin >> n;
  if (n % 2 == 0)
    std::cout << "Entered Number Is Even\n";
  else
    std::cout << "Entered Number Is Not Even\n";
}

void odd() {
  cout << "Enter Number to check odd\n";
  int n;
  cin >> n;
  if (n & 1)
    cout << "Entered Number is Odd\n";
  else
    cout << "Entered Number is not Odd\n";
}

void even_odd() {
  cout << "Enter Number to Check Even and odd\n";
  int n;
  cin >> n;
  if (n & 1)
    cout << "Entered Number is Odd\n";
  else
    cout << "Entered Number is even\n";
}

void palindrome() {
  cout << "Enter Input to check Number is Palindrome or Not\n";
  string s;
  cin >> s;
  string temp = s;
  reverse(s.begin(), s.end());
  if (temp == s)
    cout << "Entered Number is Palindrome\n";
  else
    cout << "Entered Number is not Palindrome\n";
}

void reverse() {
  cout << "Insert Input to Reverse\n";
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  cout << "Reverse of the Input is :"
       << " " << s << endl;
}
bool checkPrime(int n) {

  cin >> n;
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void isPrime() {
  int n;
  cout << "Enter a number to check if it's prime: ";
  cin >> n;
  if (n <= 1) {
    cout << n << " is not a prime number.\n";
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      cout << n << " is not a prime number.\n";
    }
  }
  cout << n << " is a prime number.\n";
}

// function to check if a number is a happy number
void isHappy() {
  int n;
  cout << "Enter a number to check if it's happy: ";
  cin >> n;
  unordered_set<int> visited;
  while (n != 1 && !visited.count(n)) {
    visited.insert(n);
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }
    n = sum;
  }
  if (n == 1) {
    cout << "The entered number is a happy number.\n";
  } else {
    cout << "The entered number is not a happy number.\n";
  }
}

// function to check if a number is an Armstrong number
void isArmstrong() {
  int n;
  cout << "Enter a number to check if it's an Armstrong number: ";
  cin >> n;
  int sum = 0, original = n;
  while (n > 0) {
    int digit = n % 10;
    sum += pow(digit, 3);
    n /= 10;
  }
  if (sum == original) {
    cout << "The entered number is an Armstrong number.\n";
  } else {
    cout << "The entered number is not an Armstrong number.\n";
  }
}

void nthPrime() {
  int n;
  cout << "Enter n to find nth prime: ";
  cin >> n;
  int count = 0, num = 2;
  while (count < n) {
    if (checkPrime(num)) {
      count++;
    }
    num++;
  }
  cout << "The " << n << "th prime is: " << num << endl;
}

int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

void fact() {
  cout << "Enter Number to find Factorail" << endl;
  int n;
  cin >> n;
  cout << factorial(n) << endl;
}

void isStrong() {
  int n;
  cout << "Enter n to check if it's a strong number: ";
  cin >> n;
  int sum = 0, original = n;
  while (n > 0) {
    int digit = n % 10;
    sum += factorial(digit);
    n /= 10;
  }

  if (sum == original) {
    cout << n << " is a strong number" << endl;
  } else {
    cout << n << " is not a strong number" << endl;
  }
}