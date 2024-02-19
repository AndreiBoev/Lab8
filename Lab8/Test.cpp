#include <iostream> //��������� ���� � �����
using namespace std;

// ���������� �������� ������� ������������
bool sort(int len, int a[]);

int main()
{
    int a[50], len, i;

    cout << "������� 0<len<=50 len = ";
    cin >> len;

    cout << "������� �������� �������\n";
    for (i = 0; i < len; i++) cin >> *(a + i);

    if (sort(len, a)) // ����� ������� ����������
    {
        cout << "��������������� ������:\n";
        for (i = 0; i < len; i++)
            cout << "  " << *(a + i);
        cout << " \n";
    }
    else
        cout << "��� ���������\n";
    return 0; // ������� ��������� ���������� ���������
}

bool sort(int len, int a[]) // ������� ����������
{
    int b, * i, nc = -1, * j; // �������� ����������

    for (i = a; i < a + len; i++)
        if (*i >= 0)
        {
            if (nc != -1) /* ����� ������, ������� � ���������� */
            {
                for (b = *i, j = i; j >= a + nc + 1; j--)
                    *j = *(j - 1);
                *(a + nc++) = b;
            }
        }
        else if (nc == -1)
            nc = i - a;
    if (nc != -1) return true;
    else return false;
}
