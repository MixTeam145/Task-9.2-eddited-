#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m, key;
    cout << "Choose variant: 1 or 2 ";
    cin >> key;
    if(key == 1)
    {
        cout << "Enter size of the matrix (n and m): ";
        cin >> n >> m;
        int **a = new int *[n];
        for (int i = 0; i < n; i++)
            a[i] = new int[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = abs(i-j) + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
    if(key == 2)
    {
        int x = 1;
        cout << "Enter size of the matrix (n and m): ";
        cin >> n >> m;
        int **a = new int *[n];
        for (int i = 0; i < n; i++)
            a[i] = new int[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
        for (int j = 0; j < m; j++)
        {
            a[0][j] = x;
            x++;
        }
        for (int i = 1; i < n; i++)
        {
            a[i][m - 1] = x;
            x++;
        }
        for (int j = m - 2; j >= 0; j--)
        {
            a[n - 1][j] = x;
            x++;
        }
        for (int i = n - 2; i >= 1; i--)
        {
            a[i][0] = x;
            x++;
        }
        int c = 1, d = 1;
        while (x < m * n)
        {
            while (a[c][d + 1] == 0)
            {
                a[c][d] = x;
                x++;
                d++;
            }
            while (a[c + 1][d] == 0)
            {
                a[c][d] = x;
                x++;
                c++;
            }
            while (a[c][d - 1] == 0)
            {
                a[c][d] = x;
                x++;
                d--;
            }
            while (a[c - 1][d] == 0)
            {
                a[c][d] = x;
                x++;
                c--;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 0)
                    a[i][j] = x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}
