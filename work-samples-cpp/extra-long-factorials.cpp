#include "stdx.h"

using namespace std;

// adds two positive numbers represented as strings
// and returns the result in the form of a string
string addTwoStrings(string &a, string &b)
{
    int carry = 0;
    string res = "";
    int i = a.length() - 1;
    int j = b.length() - 1;

    // add each digit, starting from the least significant digit
    while (i >= 0 || j >= 0)
    {
        int tmp = carry;

        if (i >= 0)
            tmp += (a[i] - '0');
        if (j >= 0)
            tmp += (b[j] - '0');

        carry = tmp / 10;
        tmp %= 10;
        res = to_string(tmp) + res;
        i--;
        j--;
    }

    // if there is a carry, add it to the result
    if (carry > 0)
        res = to_string(carry) + res;

    return res;
}

// adds a list of positive numbers represented as strings
// and returns the result in the form of a string
string addStrings(vector<string> &arr)
{
    string result = (arr.size() > 0) ? arr[0] : "";

    for (int idx = 1; idx < arr.size(); idx++)
        result = addTwoStrings(result, arr[idx]);

    return result;
}

// multiplies two positive numbers represented as strings
// and returns the result in the form of a string
string multiplyStrings(string &a, string &b)
{
    int carry = 0;
    string res = "";
    vector<string> result;

    // starting from least significant digit in b, multiply each digit
    // with entire a, again starting from least significant digit in a
    for (int j = b.length() - 1; j >= 0; j--)
    {
        int x = b[j] - '0';
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int y = a[i] - '0';
            int tmp = (x * y) + carry;
            carry = tmp / 10;
            tmp %= 10;
            res = to_string(tmp) + res;
        }

        if (carry > 0)
            res = to_string(carry) + res;

        result.push_back(res);

        res = "";
        carry = 0;

        for (int k = 0; k < result.size(); k++)
            res += "0";
    }
    return addStrings(result);
}

// calculates the factorial of a number
// 1 <= num <= 100
void extraLongFactorials(int num)
{
    string result = "1";

    for (int i = 2; i <= num; i++)
    {
        string numString = to_string(i);
        result = multiplyStrings(result, numString);
    }

    // prints the factorial
    cout << result << endl;
}

int main()
{
    int num;
    cin >> num;
    extraLongFactorials(num);
    return 0;
}