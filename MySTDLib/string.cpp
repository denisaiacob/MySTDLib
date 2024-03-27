#include <iostream>
#include "string.h"

void strcopy(char* s1, const char* s2, int length) {
	for (int i = 0; i < length; ++i) {
		s1[i] = s2[i];
	}
	s1[length] = '\0';
}

string::string() {
	lengthStr = 0;
	capacityStr = 100;
	str = new char[capacityStr];
	if (str == NULL)
		return;
	str[0] = '\0';
}

string::string(const char* s, unsigned int n) {
	lengthStr = n;
	capacityStr = 100;
	while (lengthStr + 1 > capacityStr) {
		capacityStr = capacityStr * 2;
	}
	str = new char[capacityStr];
	if (str == NULL)
		return;
	strcopy(str, s, n);
	str[lengthStr + 1] = '\0';
}

string::string(const char* s) {
	lengthStr = strlen(s);
	capacityStr = 100;
	while (lengthStr + 1 > capacityStr) {
		capacityStr = capacityStr * 2;
	}
	str = new char[capacityStr];
	if (str == NULL)
		return;
	strcopy(str, s, lengthStr);
	str[lengthStr] = '\0';
}

string::string(const string& str) {
	this->lengthStr = str.lengthStr;
	this->capacityStr = str.capacityStr;
	this->str = new char[capacityStr];
	if (this->str == NULL)
		return;
	strcopy(this->str, str.str, str.lengthStr);

}

string::~string() {
	if (str)
		delete[] str;
}

void string::print() {
	std::cout << "length: " << lengthStr << std::endl;
	std::cout << "capacity: " << capacityStr << std::endl;
	std::cout << "string: " << str << std::endl;
	std::cout << "max size: " << maxSize << std::endl;

}

unsigned int string::size()
{
	return lengthStr;
}

unsigned int string::length()
{
	return lengthStr;
}

unsigned int string::max_size()
{
	return maxSize;
}

void string::resize(unsigned int newLength)
{
	if (newLength == lengthStr)
		return;
	if (newLength > lengthStr)
	{
		unsigned int oldCapacity = capacityStr;
		while (newLength + 1 > capacityStr) {
			capacityStr = capacityStr * 2;
		}

		if (oldCapacity != capacityStr) {
			delete[] str;
			str = new char[capacityStr];
		}

		if (str == NULL)
			return;

		memset(str + lengthStr, ' ', newLength - lengthStr);
	}
	lengthStr = newLength;
	str[lengthStr] = '\0';
}

void string::resize(unsigned int newLength, char fillCharacter)
{
	if (newLength == lengthStr)
		return;
	if (newLength > lengthStr)
	{
		unsigned int oldCapacity = capacityStr;
		while (newLength + 1 > capacityStr) {
			capacityStr = capacityStr * 2;
		}

		if (oldCapacity != capacityStr) {
			delete[] str;
			str = new char[capacityStr];
		}

		if (str == NULL)
			return;

		memset(str + lengthStr, fillCharacter, newLength - lengthStr);
	}
	lengthStr = newLength;
	str[lengthStr] = '\0';

}

unsigned int string::capacity()
{
	return capacityStr;
}

bool string::empty()
{
	if (lengthStr == 0)
		return true;
	return false;
}

char& string::at(unsigned int position)
{
	if (position >= lengthStr)
		throw std::out_of_range("Out of range");
	return str[position];
}

char& string::back()
{
	if (lengthStr > 0)
		return str[lengthStr - 1];
}

char& string::front()
{
	return str[0];
}

char& string::operator[](unsigned int position)
{
	if (position >= lengthStr)
		throw std::out_of_range("Out of range");
	return str[position];
}

string& string::append(const string& str)
{
	unsigned int lenS1 = this->lengthStr;
	unsigned int lenS2 = str.lengthStr;
	this->resize(lenS1 + lenS2);
	strcopy(this->str + lenS1, str.str, lenS2);
	return *this;
}

string& string::append(unsigned int n, char c)
{
	unsigned int len = lengthStr;
	this->resize(lengthStr + n);
	for (int i = 0; i < n; i++) {
		str[len + i] = c;
	}
	str[lengthStr + n] = '\0';
	return *this;
}

string& string::operator+=(const char* s)
{
	unsigned int lenS1 = this->lengthStr;
	unsigned int lenS2 = strlen(s);
	resize(lenS1 + lenS2);
	strcopy(this->str + lenS1, s, lenS2);
	return *this;
}

void string::push_back(char c)
{
	this->resize(lengthStr + 1);
	str[lengthStr - 1] = c;
	str[lengthStr] = '\0';
}

void string::pop_back()
{
	this->resize(lengthStr - 1);
	str[lengthStr] = '\0';
}

void string::swap(string& str)
{
	unsigned int auxLength = this->lengthStr;
	char* auxStr = new char[auxLength + 1];
	strcopy(auxStr, this->str, auxLength);

	this->resize(str.lengthStr);
	strcopy(this->str, str.str, str.lengthStr);

	str.resize(auxLength);
	strcopy(str.str, auxStr, str.lengthStr);

	delete[] auxStr;

}

string& string::replace(unsigned int pos, unsigned int len, const string& str)
{
	if (pos >= lengthStr)
		throw std::out_of_range("Out of range");
	if (pos + len + 1 > this->lengthStr)
		resize(pos + len + 1);
	if (len > str.lengthStr)
		len = str.lengthStr;

	for (int i = 0; i < len; i++) {
		this->str[pos + i] = str.str[i];
	}
	return*this;
}

string& string::insert(unsigned int pos, const string& str)
{
	char* tempStr = new char[this->lengthStr + 1];
	strcopy(tempStr, this->str, this->lengthStr);

	if (pos >= lengthStr)
		throw std::out_of_range("Out of range");

	this->resize(this->lengthStr + str.lengthStr);
	strcopy(this->str + pos, str.str, str.lengthStr);
	strcopy(this->str + pos + str.lengthStr, tempStr + pos, strlen(tempStr - pos));

	delete[] tempStr;
	return *this;
}

string& string::insert(unsigned int pos, const string& str, unsigned int subpos, unsigned int sublen)
{
	char* tempStr = new char[this->lengthStr + 1];
	strcopy(tempStr, this->str, this->lengthStr);

	if (pos >= lengthStr)
		throw std::out_of_range("Out of range");
	if (sublen == -1 || sublen > str.lengthStr)
		sublen = str.lengthStr;

	this->resize(this->lengthStr + sublen);
	strcopy(this->str + pos, str.str + subpos, sublen);
	strcopy(this->str + pos + sublen, tempStr + pos, strlen(tempStr - pos));

	delete[] tempStr;
	return *this;
}


