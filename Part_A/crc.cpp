#include <bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
    string res = "";
    int n = b.length();
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
        {
            res += "0";
        }
        else
        {
            res += "1";
        }
    }
    return res;
}

string div2mod(string divident, string divisor)
{
    int pick = divisor.length();
    int n = divident.length();
    string temp = divident.substr(0, pick);

    while (pick < n)
    {
        if (temp[0] == '1')
        {
            temp = xor1(divisor, temp) + divident[pick];
        }
        else
        {
            temp = xor1(string(pick, '0'), temp) + divident[pick];
        }
        pick++;
    }
    if (temp[0] == '1')
    {
        temp = xor1(divisor, temp);
    }
    else
    {
        temp = xor1(string(pick, '0'), temp);
    }
    return temp;
}
string encode(string data, string key)
{
    int key_l = key.length();
    string append_data = data + string(key_l - 1, '0');
    string remainder = div2mod(append_data, key);
    return remainder;
}

int main()
{
    string data = "100100";
    string key = "1101";
    cout << "remainder = " << encode(data, key) << endl;
    cout << "coded = " << data + encode(data, key) << endl;
}