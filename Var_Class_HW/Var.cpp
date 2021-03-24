#include "Var.h"

void Var::show() const
{
	if (pos==1)
	{
		cout << *int_;
	}
	else if (pos==2) {
		cout << *double_;
	}
	else if (pos == 3) {
		cout << *str;
	}
	else {
		cout << "Unitializated variable" << endl;
	}
}

const size_t& Var::getPos() const
{
	return pos;
}

void Var::toString()
{
	pos = 3;
	if (pos>3)
	{
		return;
	}
		if (pos==1)
		{
			str = new String(reinterpret_cast<char*>(int_));
			
		}
		else if (pos==2)
		{
			str = new String(reinterpret_cast<char*>(double_));
		}
		
}

void Var::toInt()
{
	if (pos==4)
	{	
		int_ = 0;
	}
	if (pos == 3 && str != nullptr)
	{
		const char* tmp = str->toCharArray();
		int count = 0;
		if (pos == 1 && int_ == nullptr)
		{
			*int_ = 0;
			return;
		}
		if (pos==1)
		{
			return;
		}
		for (int i = 0; i < strlen(tmp); i++)
		{	
			if (isdigit(tmp[i]))
			{
				++count;
			}
		}
		if (count == strlen(tmp))
		{
			*int_ = stoi(str->toString());
		}
		else {
			*int_ = 0;
		}
	}
	else if (pos == 2 && double_!= nullptr)
	{
		*int_ = (int)double_;
	}
	pos = 1;
}

void Var::toDouble()
{
	if (pos == 2 && double_ == nullptr)
	{
		double_ = 0;
		return;
	}
	if (pos == 2 )
	{
		return;
	}
	if (pos == 1)
	{
		double_ = reinterpret_cast<double*>(int_);
	}
	if (pos == 3)
	{
		int count_points=0;
		string tmp = str->toString();
		for (size_t i = 0; i < tmp.length(); i++)
		{
			if (!isdigit(tmp[i]) && tmp[i]!= '.' || count_points >=2)
			{
				pos = 2;
				double_ = 0;
				return;
			}
			if (tmp[i]=='.')
			{
				++count_points;
			}
		}
		this->double_ = reinterpret_cast<double*>(str);
	}
	if (pos > 3)
	{
		double_ = 0;
	}
}
const Var Var::operator+(const Var& obj)const
{
	if (obj.pos == 4 || pos==4)
	{
		return Var(0);
	}
	Var result;
	Var tmp = obj;
	if (pos==3)
	{
		tmp.toString();
		string res =tmp.str->toString()+str->toString();
		result = res.c_str();
		result = tmp;
	}
	else if (pos==2)
	{
		tmp.toDouble();
		double res = *tmp.double_ + *double_;
		result = res;
	}
	else if (pos==1)
	{
		tmp.toInt();
		int res = *tmp.int_ + *int_;
		result = res;
	}
	
	return result;
}

const Var Var::operator-(const Var& obj)const
{
	if (obj.pos == 4 || pos == 4)
	{
		return Var(0);
	}
	Var result;
	Var tmp = obj;
	if (pos == 3)
	{
		tmp.toString();
		result = str - obj.str;
		
	}
	else if (pos == 2)
	{
		tmp.toDouble();
		double res = *tmp.double_ - *double_;
		result = res;
	}
	else if (pos == 1)
	{
		tmp.toInt();
		int res = *tmp.int_ - *int_;
		result = res;
	}

	return result;
}

const Var Var::operator*(const Var& obj)const
{
	if (obj.pos == 4 || pos == 4)
	{
		return Var(0);
	}
	Var result;
	Var tmp = obj;
	if (pos == 3)
	{
		tmp.toString();
		result = (str->concat(*tmp.str));
		result.pos = 3;
	}
	else if (pos == 2)
	{
		tmp.toDouble();
		double res = *tmp.double_ * *double_;
		result = res;
		result.pos = 2;
	}
	else if (pos == 1)
	{
		tmp.toInt();
		int res = *tmp.int_ * *int_;
		result = res;
		result.pos = 1;
	}

	return result;
}

const Var Var::operator/(const Var& obj)const
{
	if (obj.pos == 4 || pos == 4)
	{
		return Var(0);
	}
	Var result;
	Var tmp = obj;
	if (pos == 3)
	{
		tmp.toString();
		result = (str->division(*tmp.str));
		result.pos = 3;
	}
	else if (pos == 2)
	{
		tmp.toDouble();
		double res = *tmp.double_ / *double_;
		result = res;
		result.pos = 2;
	}
	else if (pos == 1)
	{
		tmp.toInt();
		int res = *tmp.int_ / *int_;
		result = res;
		result.pos = 1;
	}

	return result;
}

Var* Var::operator+=(const Var& obj)
{
	if (obj.pos == 4 || pos == 4)
	{
		return this;
	}
	if (pos == 3)
	{
		this->toString();
		*this = *str + *obj.str;
		pos = 3;
	}
	else if (pos == 2)
	{
		this->toDouble();
		*this->double_ = *this->double_ + *obj.double_;
		pos = 2;
	}
	else if (pos == 1)
	{
		this->toInt();
		*this->int_ = *this->int_ + *obj.int_;
		pos = 1;
	}

	return this;
}

Var* Var::operator-=(const Var& obj)
{
	if (obj.pos == 4 || pos == 4)
	{
		return this;
	}
	if (pos == 3)
	{
		this->toString();
		*this = str - obj.str;
	}
	else if (pos == 2)
	{
		this->toDouble();
		*this->double_ = *this->double_ - *obj.double_;
	}
	else if (pos == 1)
	{
		this->toInt();
		*this->int_ = *this->int_ - *obj.int_;

	}

	return this;
}

Var* Var::operator*=(const Var& obj)
{
	if (obj.pos == 4 || pos == 4)
	{
		return this;
	}
	if (pos == 3)
	{
		this->toString();
		*this->str = (*str * *obj.str);
	}
	else if (pos == 2)
	{
		this->toDouble();
		*this->double_ = *this->double_ - *obj.double_;
	}
	else if (pos == 1)
	{
		this->toInt();
		*this->int_ = *this->int_ - *obj.int_;

	}

	return this;
}

Var* Var::operator/=(const Var& obj)
{
	if (obj.pos == 4 || pos == 4)
	{
		return this;
	}
	if (pos == 3)
	{
		this->toString();
		*this->str = (*str / *obj.str);
	}
	else if (pos == 2)
	{
		this->toDouble();
		*this->double_ = *this->double_ / *obj.double_;
	}
	else if (pos == 1)
	{
		this->toInt();
		*this->int_ = *this->int_ / *obj.int_;

	}

	return this;
}

const bool& Var::operator<(const Var& obj) const
{
	if (obj.getPos() > getPos())
	{
		return true;
	}
	if (pos == 1)
	{
		if (*int_ < *obj.int_)
		{
			return true;
		}
	}
	else if (pos == 2)
	{
		if (*double_ < *obj.double_)
		{
			return true;
		}
	}
	else if (pos == 3)
	{
		if (*str < *obj.str)
		{
			return true;
		}
	}
	return false;
}

const bool& Var::operator>(const Var& obj) const
{
	return !(*this < obj);
}

const bool& Var::operator<=(const Var& obj) const
{
	return *this == obj || *this < obj ? true : false;
}

const bool& Var::operator>=(const Var& obj) const
{
	return *this == obj || *this > obj ? true : false;
}

const bool& Var::operator==(const Var& obj) const
{
	if (!(pos == obj.getPos()))
	{
		return false;
	}
	if (pos == 1)
	{
		if (*int_ == *obj.int_)
		{
			return true;
		}
	}
	else if (pos == 2)
	{
		if (*double_ == *obj.double_)
		{
			return true;
		}
	}
	else if (pos == 3)
	{
		if (*str == *obj.str)
		{
			return true;
		}
	}
	return false;
}

const bool& Var::operator!=(const Var& obj) const
{
	return !(*this == obj);
}

