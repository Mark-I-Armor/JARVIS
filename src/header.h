// function to check if a number is prime
void isPrime()
{
    int n;
    cout << "Enter a number to check if it's prime: ";
    cin >> n;
    if (n <= 1)
    {
        cout << n << " is not a prime number.\n";
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << n << " is not a prime number.\n";
        }
    }
    cout << n << " is a prime number.\n";
}

// function to check if a number is a happy number
void isHappy()
{
    int n;
    cout << "Enter a number to check if it's happy: ";
    cin >> n;
    unordered_set<int> visited;
    while (n != 1 && !visited.count(n))
    {
        visited.insert(n);
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    if (n == 1)
    {
        cout << "The entered number is a happy number.\n";
    }
    else
    {
        cout << "The entered number is not a happy number.\n";
    }
}

// function to check if a number is an Armstrong number
void isArmstrong()
{
    int n;
    cout << "Enter a number to check if it's an Armstrong number: ";
    cin >> n;
    int sum = 0, original = n;
    while (n > 0)
    {
        int digit = n % 10;
        sum += pow(digit, 3);
        n /= 10;
    }
    if (sum == original)
    {
        cout << "The given entered number is an Armstrong number.\n";
    }
    else
    {
        cout << "The entered number is not an Armstrong number.\n";
    }
}

void nthPrime()
{
    int n;
    cout << "Enter n to find nth prime: ";
    cin >> n;
    int count = 0, num = 2;
    while (count < n)
    {
        if (isPrime(num))
        {
            count++;
        }
        num++;
    }
    cout << "The " << n << "th prime is: " << nthPrime(n) << endl;
}

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void isStrong()
{
    int n;
    cout << "Enter n to check if it's a strong number: ";
    cin >> n;
    int sum = 0, original = n;
    while (n > 0)
    {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }

    if (sum == original)
    {
        cout << n << " is a strong number" << endl;
    }
    else
    {
        cout << n << " is not a strong number" << endl;
    }
    return sum == original;
}