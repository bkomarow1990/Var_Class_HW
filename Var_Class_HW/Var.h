#pragma once
#include <iostream>
#include <algorithm>
#include "String.h"
using namespace std;
class Var
{
public:
	Var(const char * str)
	{
		pos = 3;
		this->str=new String(str);
	}
	Var(const int& int_)
	{
		pos = 1;
		this->int_=new int(int_);
	}
	Var(String* str) {
		if (str!= nullptr)
		{
			this->str = str;
		}
		
	}
	Var(String str) {
		this->str = new String(str);
	}
	Var(const double& double_)
	{
		pos = 2;
		this->double_ = new double(double_);
	}
	Var() = default;
	void show() const;
	const size_t& getPos()const;
	void toString();
	void toInt();
	void toDouble();
	const Var operator+(const Var& obj)const;
	const Var operator-(const Var& obj)const;
	const Var operator*(const Var& obj)const;
	const Var operator/(const Var& obj)const;
	Var* operator+=(const Var& obj);
	Var* operator-=(const Var& obj);
	Var* operator*=(const Var& obj);
	Var* operator/=(const Var& obj);
	const bool& operator< (const Var& obj) const;
	const bool& operator> (const Var& obj) const;
	const bool& operator<= (const Var& obj) const;
	const bool& operator>= (const Var& obj) const;
	const bool& operator== (const Var& obj) const;
	const bool& operator!= (const Var& obj) const;
	friend std::ostream& operator<< (std::ostream& stream, const Var& var) {
		switch (var.getPos())
		{
		case 1:
			cout << *var.int_;
			break;
		case 2:
			cout << *var.double_;
			break;
		case 3:
			cout << *var.str;
			break;
		default:
			cout << "nullptr" << endl;
			break;
		}
		return stream;
	}
private:
	int *int_=nullptr;
	double *double_= nullptr;
	String * str= nullptr;
	size_t pos=4;
};

