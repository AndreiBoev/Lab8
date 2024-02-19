#include <iostream> 
using namespace std;

bool input(int a[], int &na, int b[], int &nb);
void calc(int a[], int &na, int b[], int &nb, int c[], int &nc);
void output(int c[], int &nc);

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[50], b[50], c[50], na, nb, nc = 0, i;

    if (!input(a, na, b, nb)) {
        cout << "Длина массива должна быть больше нуля.";
        return 0;
    }
    
    calc(a, na, b, nb, c, nc);

    if (nc == 0) {
        cout << "Нет неповторяющихся элементов в массиве A, присутствующих в массиве B.";
        return 0;
    }

    output(c, nc);

}

void output(int c[], int &nc)
{
    int *u;
    cout << "Массив С:\n";
    for (u = c; u < c + nc; u++)
        cout << "  " << *u;
}

void calc(int a[], int &na, int b[], int &nb, int c[], int &nc) 
{
    int *u, *j;
    int flag;

    for (u = a; u < a + na; u++) {
        flag = 0;
        for (j = a; j < a + na; j++)
            if (*u == *j)
                flag++;

        for (j = b; j < b + nb; j++)
            if (*u == *j)
            {
                if (flag == 1) {
                    *(c + nc) = *u;
                    nc++;
                }
                break;
            }
    };
    
}

bool input(int a[], int& na, int b[], int& nb) 
{
    int i = 0;

    cout << "Введите 0<na<=50 len = ";
    cin >> na;
    cout << "Введите 0<nb<=50 len = ";
    cin >> nb;

    if ((na <= 0) || (nb <= 0)) {
        return 0;
    }

    cout << "Введите элементы массива А\n";
    for (i = 0; i < na; i++) cin >> *(a + i);

    cout << "Введите элементы массива В\n";
    for (i = 0; i < nb; i++) cin >> *(b + i);

    return 1;
}