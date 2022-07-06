#include <bits/stdc++.h>
using namespace std;

void recive(int msg[], int l)
{
    int res[50];
    int j = 0;
    int count = 0;
    for (int i = 8; i < l - 8; i++)
    {
        if (msg[i] == 0)
        {
            if (count == 5)
            {
                i++;
                res[j++] = msg[i];
                count = 0;
            }
            else
            {
                res[j++] = msg[i];
                count = 0;
            }
        }
        else
        {
            res[j++] = msg[i];
            count++;
        }
    }

    cout << "decoding\n";
    for (int i = 0; i < j; i++)
    {
        cout << res[i];
    }
}

void send()
{
    int res[100];
    int n;
    cout << "Enter the no. of bits\n";
    cin >> n;
    int msg[n];
    cout << "Enter the bits\n";
    for (int i = 0; i < n; i++)
    {
        cin >> msg[i];
    }

    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    res[3] = 1;
    res[4] = 1;
    res[5] = 1;
    res[6] = 1;
    res[7] = 0;
    int j = 8;
    int count = 0;
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (msg[i] == 0)
        {
            if (count == 5)
            {
                res[j++] = 0;
                zerocount++;
                res[j++] = msg[i];
                count = 0;
            }
            else
            {
                res[j++] = msg[i];
                count = 0;
            }
        }
        else
        {
            if (count == 5)
            {
                res[j++] = 0;
                zerocount++;
                res[j++] = msg[i];
                count = 0;
            }
            else
            {
                res[j++] = msg[i];
                count++;
            }
        }
    }

    res[j++] = 0;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 1;
    res[j++] = 0;

    int l = n + zerocount + 16;
    for (int i = 0; i < l; i++)
    {
        cout << res[i];
    }
    cout << endl;
    recive(res, l);
}

int main()
{
    send();
}