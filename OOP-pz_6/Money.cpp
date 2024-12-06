#include <iostream>
#include "Money.h"

using namespace std;

void Money::normalize() {
	if (cents >= 100) {
		money++;
		cents -= cents - 100;
	}
	if (cents >= 200) {
		money += 2;
		cents = cents - 200;
	}
}

Money Money::Init(long hrn, short kop) {
	Money m1;
	m1.money = hrn;
	m1.cents = kop;
	return m1;
}

void Money::Read() {
	int hrn, kop;
	cout << "¬вед≥ть к≥льк≥сть грошей: ";
	cin >> hrn;
	cout << endl;
	cout << "¬вед≥ть к≥льк≥сть коп≥йок: ";
	cin >> kop;
	cout << endl;
	SetMoney(hrn);
	SetCents(kop);
}

void Money::Display() {
	cout << money << " гривень " << cents << " коп≥йок" << endl;
}

string Money::ToString() {
	string str = "money = " + money;
	str += "\ncents = " + cents;
	return str;
}

Money Money::operator+(const Money& other) const {
	long totalHryvnias = money + other.money;
	short totalKopecks = cents + other.cents;
	Money result;
	result.money = totalHryvnias;
	result.cents = totalKopecks;
	result.normalize();
	return result;
}

Money Money::operator-(const Money& other) const {
	long totalHryvnias = money - other.money;
	int totalKopecks = cents - other.cents;
	Money result;
	result.money = totalHryvnias;
	result.cents = totalKopecks;
	result.normalize();
	return result;
}

Money Money::operator*(double multiplier) const {
	long totalKopecks = (money * 100 + cents) * multiplier;
	Money result;
	result.money = totalKopecks / 100;
	result.cents = totalKopecks % 100;
	result.normalize();
	return result;
}

Money Money::operator/(double divisor) const {
	long totalKopecks = (money * 100 + cents) / divisor;
	Money result;
	result.money = totalKopecks / 100;
	result.cents = totalKopecks % 100;
	result.normalize();
	return result;
}

bool Money::operator==(const Money& other) const {
	return (money == other.money && cents == other.cents);
}

bool Money::operator!=(const Money& other) const {
	return !(*this == other);
}

bool Money::operator<(const Money& other) const {
	if (money < other.money) return true;
	if (money == other.money && cents < other.cents) return true;
	return false;
}

bool Money::operator<=(const Money& other) const {
	return *this < other || *this == other;
}

bool Money::operator>(const Money& other) const {
	return !(*this <= other);
}

bool Money::operator>=(const Money& other) const {
	return !(*this < other);
}

Money& Money::operator-=(const Money& other) {
	money -= other.money;
	cents -= other.cents;
	normalize();
	return *this;
}

Money& Money::operator+=(const Money& other) {
	money += other.money;
	cents += other.cents;
	normalize();
	return *this;
}

Money& Money::operator--() {
	cents--;
	normalize();
	return *this;
}

Money Money::operator--(int) {
	Money temp = *this;
	--(*this);
	return temp;
}

Money& Money::operator++() {
	cents++;
	normalize();
	return *this;
}

Money Money::operator++(int) {
	Money temp = *this;
	++(*this);
	return temp;
}


void Money::SetMoney(long hrn) {
	this->money = hrn;
}

void Money::SetCents(short kop) {
	this->cents = kop;
}

long Money::GetMoney() {
	return this->money;
}

short Money::GetCents() {
	return this->cents;
}
