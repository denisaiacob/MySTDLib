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
		if (oldCapacity != capacityStr)
			realloc(str, capacityStr);
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
		if (oldCapacity != capacityStr)
			realloc(str, capacityStr);
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

