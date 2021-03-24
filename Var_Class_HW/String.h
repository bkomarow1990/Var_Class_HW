#pragma once
#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	String();
	String(const size_t & size);
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	String operator*(String& other);
	String operator/(String& other);
	String operator+(String& other);
	String operator+(const char *other);
	String& operator++();
	String operator++(int);
	bool operator<(const String& obj)const;
	bool operator>(const String& obj)const;
	bool operator<=(const String& obj)const;
	bool operator>=(const String& obj)const;
	bool operator==(const String& obj)const;
	String operator!();
	string toString() const{
		return mstring;
	}
	const char* toCharArray() {
		return mstring;
	}
	bool operator!=(const String& obj)const;
	// char* operator + (const String& obj) const;
	String division(const String& other);
	void addArrElem(const char & symb);
	void getLine();
	void setStringSize(const size_t& size);
	String combinateStrings(const String& obj);
	const char* getStr()const;
	~String();
	friend ostream& operator << (ostream& out, const String& str);
	String concat(const String& obj);
	const size_t getSize()const;
private:
	size_t size;
	char* mstring;
};
void swapStrngs(String&& one,String&& other)noexcept;