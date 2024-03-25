#pragma once
class string {
	char* str;
	unsigned int lengthStr;
	unsigned int capacityStr;
	const unsigned int maxSize = 10000;

public:
	string();
	string(const char* s, unsigned int n);
	string(const char* s);
	string(const string& str);
	~string();

	void print();

	unsigned int size();
	unsigned int length();
	unsigned int max_size();
	void resize(unsigned int newLength);
	void resize(unsigned int newLength, char fillCharacter);
	unsigned int capacity();
	bool empty();

};