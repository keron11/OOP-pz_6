#include <iostream>
#include <Windows.h>
#include "Money.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Money m1(10, 50), m2(5, 30);

    // Використання інкременту
    ++m1;
    cout << "Після ++m1: " << m1.GetMoney() << " гривень " << m1.GetCents() << " копійок" << endl;

    // Використання декременту
    m2--;
    cout << "Після m2--: " << m2.GetMoney() << " гривень " << m2.GetCents() << " копійок" << endl;

    // Використання оператора +=
    m1 += m2;
    cout << "Після m1 += m2: " << m1.GetMoney() << " гривень " << m1.GetCents() << " копійок" << endl;

    // Використання оператора -=
    m1 -= m2;
    cout << "Після m1 -= m2: " << m1.GetMoney() << " гривень " << m1.GetCents() << " копійок" << endl;

    system("pause");
}
