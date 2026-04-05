#include "String.h"
#pragma warning (disable:4996)
void String::copyFrom(const String& other)
{
	this->string = new char[other.size + 1];
	strcpy(this->string, other.string);
	this->size = other.size;
}

void String::moveFrom(String&& other) noexcept
{
	this->string = other.string;
	this->size = other.size;
	other.string = nullptr;
	other.size = 0;
}

void String::free()
{
	delete[] this->string;
	this->string = nullptr;
	this->size = 0;
}

String::String() :  size(0)
{
	this->string = new char[1];
	this->string[0] = '\0';
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

String::String(String&& other) noexcept
{
	moveFrom(std::move(other));
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

String::String(const char* str) : size(strlen(str))
{
	allocate(str, this->size);
}

String::String(const char* str, int size) : size(size)
{
	allocate(str, size);
}

String::~String()
{
	free();
}

void String::allocate(const char* str, int size)
{
	this->size = size;
	this->string = new char[this->size + 1];
	strcpy(this->string, str);
}

int String::getLength() const
{
	return this->size;
}

bool String::isEmpty() const
{
	return this->string == nullptr || this->size == 0;
}

char& String::operator[](int index)
{
	//if (index < 0 || index > this->size)
	//{
	//	return;
	//}
	return this->string[index];
}

const char& String::operator[](int index) const
{
	return this->string[index];
}

String& String::operator+=(const String& other)
{
	int newSize = this->size + other.size + 1;
	char* result = new char[newSize + 1];
	strcpy(result, this->string);
	result[this->size] = ' ';
	result[this->size + 1] = '\0';
	strcat(result, other.string);
	delete[] this->string;
	this->string = result;
	this->size = newSize;
	return *this;
}

String& String::operator+=(char c)
{
	char* result = new char[this->size + 2];
	if (this->string != nullptr)
	{
		strcpy(result, this->string);
	}
	result[this->size] = c;
	result[this->size + 1] = '\0';
	delete[] this->string;
	this->string = result;
	this->size++;
	return *this;
}

String& String::operator-=(char c)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->string[i] == c)
		{
			for (int j = i; j < this->size - 1; j++)
			{
				swap(this->string[j], this->string[j + 1]);
			}
			this->size--;
			i--;
		}
	}
	if (this->string != nullptr)
	{
		this->string[this->size] = '\0';
	}
	return *this;
}

String& String::operator-=(int index)
{
	//if (index < 0 || index > this->size)
	//{
	//	std::cout << "Invalid index";
	//}
	for (int i = 0; i < this->size; i++)
	{
		if (i == index)
		{
			for (int j = index; j < this->size - 1; j++)
			{
				swap(this->string[j], this->string[j + 1]);
			}
		}
	}
	this->size--;
	this->string[size] = '\0';
	return *this;
}

void String::swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

void String::pushBack(char c)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->string[i] == c)
		{
			for (int j = i; j < this->size - 1; j++)
			{
				swap(this->string[j], this->string[j + 1]);
			}
		}
	}
}

void String::append(char c)
{
	*this += c;
}

bool String::operator==(const String& other) const
{
	return (strcmp(this->string, other.string) == 0);
}

bool String::operator<(const String& other) const
{
	return (strcmp(this->string, other.string) < 0);
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	if (str.string == nullptr || str.size == 0)
	{
		os << "Invalid string";
		return os;
	}
	os << "Your string is: \"" << str.string << "\"";
	return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char buffer[1024];
	is >> buffer;
	str = String(buffer);
	return is;
}

String operator+(const String& lhs, const String& rhs)
{
	String result(lhs);
	result += rhs;
	return result;
}
