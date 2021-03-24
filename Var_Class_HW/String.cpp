#include "String.h"

String::String()
	:String(80)
{

}

String::String(const size_t& size)
{
	this->size = size;
	mstring = new char[size] {};
}

String::String(const char* str)
{
	if (str==nullptr)
	{
		setStringSize(80);
		return;
	}
	setStringSize(strlen(str) + 1);
	strcpy_s(this->mstring, size, str);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		if (mstring != nullptr)
		{
			mstring = nullptr;
			delete[] mstring;
		}
		mstring = new char[size = other.size];
		strcpy_s(this->mstring, size, other.mstring);
	}
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this!=&other)
	{
		if (mstring!=nullptr)
		{
			delete[]mstring;
			this->size = other.size;
			this->mstring = other.mstring;
			other.mstring = nullptr;
			other.size = 0;
		}
	}
	return *this;
}

String String::operator*(String& other)
{
	String result;
	if (this!=&other)
	{
		return combinateStrings(other);
	}
	return result;
}

String String::operator/(String& other)
{
	String result = division(other);
	return result;
}

String String::operator+(String& other)
{
	return concat(other);
}

String String::operator+(const char* other)
{
	String result(other);
	return concat(result);
}

String& String::operator++()
{
	for (size_t i = 0; i < size-1; i++)
	{
		mstring[i] = ++mstring[i];
	}
	return *this;
}

String String::operator++(int)
{
	String temp(mstring);
	++(*this);
	return temp;
}

bool String::operator<(const String& obj) const
{
	return size<obj.size?true:false;
}
bool String::operator>(const String& obj) const
{
	return size > obj.size ? true : false;
}

bool String::operator<=(const String& obj) const
{
	if (*this<obj || *this==obj)
	{
		return true;
	}
	return false;
}

bool String::operator>=(const String& obj) const
{
	if (*this>obj||*this==obj)
	{
		return true;
	}
	return false;
}

bool String::operator==(const String& obj) const
{
	if (obj.size!=size)
	{
		return false;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (mstring[i]!=obj.mstring[i])
		{
			return false;
		}
	}
	return true;
}

String String::operator!()
{
	String result(size);
	size_t j = 0;
	for (int i = size-2; i >= 0; i--)
	{
		result.mstring[j] = mstring[i];
		j++;
	}
	return result;
}


bool String::operator!=(const String& obj) const
{
	return !(*this==obj);
}


String String::division(const String& other)
{
	String result(1);
	size_t currentword_lose = 0;
	//this -> size = 10
	//0 1 2 3 4 5 6 7 8 9
	//M i c r o s o f t \0
	//other -> size = 8
	//W i n d o w s \0
	//0 1 2 3 4 5 6 7
	//mstring
	if (size==0 || other.size==0)
	{
		return result;
	}
	for (int i = 0; i <= other.size-2; i++)
	{
		currentword_lose = 0;
		for (int j = 0; j <= this->size-2; j++)
		{
			
			if (mstring[i]!=other.mstring[j])
			{
				++currentword_lose;
			}
		
		}
		if (currentword_lose==size-1)
		{
			result.addArrElem(mstring[i]);
		}
	}
	return result;
}

void String::addArrElem(const char& symb)
{
	++size;
	char* tmp = new char[size] {};
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = mstring[i];
	}
	tmp[size-2] = symb;
	tmp[size - 1] = '\0';
	mstring = new char[size];
	mstring = tmp;
}



void String::getLine()
{
	
	char str[255];

	cin >> str;
	if (str == nullptr)
	{
		setStringSize(80);
		return;
	}
	setStringSize(strlen(str) + 1);
	strcpy_s(this->mstring, size, str);
}




void String::setStringSize(const size_t& size)
{
	this->size = size;
	mstring = new char[size] {};
}

String String::combinateStrings(const String& obj)
{
	String result;
	size_t loop_length=0;
	size_t countSymbols=0;
	if (this->size==0||obj.size==0)
	{
		return result;
	}
	if (this->size<obj.size)
	{
		loop_length = size;
	}
	else {
		loop_length = obj.size;
	}
	for (size_t i = 0; i < loop_length; i++)
	{
		if (mstring[i]==obj.mstring[i])
		{
			++countSymbols;
		}
	}
	if (countSymbols==0)
	{
		return result;
	}
	result.setStringSize(countSymbols+1);
	size_t j = 0;
	for (size_t i = 0; i < loop_length; i++)
	{
		if (mstring[i] == obj.mstring[i])
		{
			result.mstring[j] = mstring[i];
			++j;
		}
	}
	return result;
}

const char* String::getStr() const
{
	return mstring;
}

String::~String()
{
	delete[]mstring;
}
String::String(const String& other) {
		*this = other;
}

String String::concat(const String& obj)
{
	String result;
	result.setStringSize(strlen(this->mstring) + strlen(obj.mstring) + 1);
	for (size_t i = 0; i < this->size-1; i++)
	{
		result.mstring[i] = this->mstring[i];
	}
	size_t j = 0;
	for (size_t i = this->size-1; i < result.size; i++)
	{
		result.mstring[i] = obj.mstring[j];
		j++;
	}
	return result;
}

const size_t String::getSize() const
{
	return size;
}

ostream& operator<<(ostream& out, const String& str)
{
	out << str.getStr();
	return out;
}


void swapStrngs(String&& one, String&& other)noexcept
{
	String temp=(move(one));
	one = move(other);
	other = temp;
}
