#include <iostream>
using namespace std;

void input(int a[][20], int &n, int &m);
bool change(int a[][20], int &n, int &m);
void output(int a[][20], int& n, int& m);

int main() 
{    
    setlocale(LC_ALL, "Russian");
    int a[10][20], n, m;

    input(a, n, m);
    cout << "Исходная матрица:\n";
    output(a, n, m);
    if (change(a, n, m)) {
        cout << "Изменённая матрица:\n";
        output(a, n, m);
    }
    else
        cout << "Нет двух нечётных элементов.";

    return 0;
}
bool change(int a[][20], int &n, int &m) 
{
    int i, *uj, *rep = NULL;

    for (i = n - 1; i >= 0; i--)
        for (uj = a[i] + m - 1; uj >= a[i]; uj--)
            if (*uj % 2 != 0)
                if (rep == NULL)
                    rep = uj;
                else {
                    swap(*uj, *rep);
                    return true;
                }

    return false;
}
void output(int a[][20], int& n, int& m) 
{
    int i, * uj;
    for (i = 0; i < n; i++) {
        for (uj = a[i]; uj < a[i] + m; uj++)
            cout << *uj << ' ';
        cout << '\n';
    }
}

void input(int a[][20], int &n, int &m)
{
    int i, *uj;
    cout << "Введите n и m" << endl;
    cin >> n >> m;
    cout << "Введите матрицу" << endl;
    for (i = 0; i < n; i++)
        for (uj = a[i]; uj < a[i] + m; uj++)
            cin >> *uj;
}
