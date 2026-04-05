#pragma once
#include <iostream>
class String
{
private:
	char* string;
	int size;
	const int INITIAL_SIZE = 1;

	void copyFrom(const String& other);
	void moveFrom(String&& other) noexcept;
	void free();
public:
	String();
	String(const String& other);
	String& operator=(const String& other);

	String(String&& other) noexcept;
	String& operator=(String&& other) noexcept;

	String(const char* str);
	String(const char* str, int size);
	~String();

	void allocate(const char* str, int size);
	int getLength() const;
	bool isEmpty() const;

	char& operator[](int index);
	const char& operator[](int index) const;

	String& operator+=(const String& other);
	String& operator+=(char c);
	String& operator-=(char c);
	String& operator-=(int index);

	void swap(char& a, char& b);
	void pushBack(char c);
	void append(char c);

	bool operator==(const String& other) const;
	bool operator<(const String& other) const;

	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
};

String operator+(const String& lhs, const String& rhs);