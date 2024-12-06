#pragma once
#include <iostream>
#include <string>

using namespace std;

class Money {
	long money;
	short cents;
public:
	// Конструктор за замовчуванням
	Money() : money(0), cents(0) {}

	// Конструктор з параметрами
	Money(long hrn, short kop) : money(hrn), cents(kop) {
		normalize();
	}

	// Копіюючий конструктор
	Money(const Money& other) {
		money = other.money;
		cents = other.cents;
	}

	void normalize();
	Money Init(long fir, short sec);
	void Read();
	void Display();
	string ToString();
	long GetMoney();
	short GetCents();
	void SetMoney(long hrn);
	void SetCents(short kop);

	// Перевантажені оператори
	Money operator+(const Money& other) const;
	Money operator-(const Money& other) const;
	Money operator*(double multiplier) const;
	Money operator/(double divisor) const;

	bool operator==(const Money& other) const;
	bool operator!=(const Money& other) const;
	bool operator<(const Money& other) const;
	bool operator<=(const Money& other) const;
	bool operator>(const Money& other) const;
	bool operator>=(const Money& other) const;

	Money& operator++();
	Money operator++(int);
	Money& operator--();
	Money operator--(int);

	Money& operator+=(const Money& other);
	Money& operator-=(const Money& other);
};
