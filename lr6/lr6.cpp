#include <iostream>
#include <Windows.h>
#include "Money.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Money m1(10, 50), m2(5, 30);

    // ������������ ����������
    ++m1;
    cout << "ϳ��� ++m1: " << m1.GetMoney() << " ������� " << m1.GetCents() << " ������" << endl;

    // ������������ ����������
    m2--;
    cout << "ϳ��� m2--: " << m2.GetMoney() << " ������� " << m2.GetCents() << " ������" << endl;

    // ������������ ��������� +=
    m1 += m2;
    cout << "ϳ��� m1 += m2: " << m1.GetMoney() << " ������� " << m1.GetCents() << " ������" << endl;

    // ������������ ��������� -=
    m1 -= m2;
    cout << "ϳ��� m1 -= m2: " << m1.GetMoney() << " ������� " << m1.GetCents() << " ������" << endl;

    system("pause");
}
