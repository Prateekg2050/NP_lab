#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the size of bucket\n";
    int cap;
    cin >> cap;
    cout << "Enter the output rate\n";
    int orate;
    cin >> orate;
    int inp[10] = {0};
    int i = 0;
    int flag;
    do
    {
        cout << "Enter the no. of packets coming at second\n";
        cin >> inp[i];
        if (inp[i] > cap)
        {
            cout << "bucket overflowed\n";
            cout << "packet discarded\n";
            exit(0);
        }
        i++;
        cout << "Enter 1 for continue or 0 to exit\n";
        cin >> flag;
    } while (flag);

    int nesc = i;
    int rem = 0;
    int x;
    int drop = 0;
    cout << "\nSecond\tRecived\tSent\tDropped\tRemaining\n";
    for (int i = 0; rem || i < nesc; i++)
    {
        cout << i + 1 << "\t" << inp[i] << "\t" << min(orate, inp[i] + rem);
        x = inp[i] + rem - orate;
        if (x > 0)
        {
            if (x > cap)
            {
                drop = x - cap;
                rem = cap;
            }
            else
            {
                drop = 0;
                rem = x;
            }
        }
        else
        {
            drop = 0;
            rem = 0;
        }

        cout << "\t" << drop << "\t" << rem << endl;
    }
}