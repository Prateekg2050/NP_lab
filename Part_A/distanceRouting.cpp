#include <bits/stdc++.h>
using namespace std;

struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main()
{
    int n;
    cout << "Enter the no. of nodes\n";
    cin >> n;
    int dmat[n][n];
    cout << "Enter the cost of matrix\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dmat[i][j];
            dmat[i][i] = 0;
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }
    int count;
    do
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (rt[i].dist[j] > (dmat[i][k] + rt[k].dist[j]))
                    {
                        rt[i].dist[j] = (dmat[i][k] + rt[k].dist[j]);
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    for (int i = 0; i < n; i++)
    {
        cout << "\nstate for routes " << i + 1 << endl;
        for (int j = 0; j < n; j++)
        {
            cout << "\nnodes\tvia\tdist\n";
            cout << j + 1 << "\t" << rt[i].from[j] + 1 << "\t" << rt[i].dist[j] << endl;
        }
    }
}