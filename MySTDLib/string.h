#pragma once
class string {
private:
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

	char& at(unsigned int position);
	char& back();
	char& front();
	char& operator[](unsigned int position);
	string& append(const string& str);
	string& append(unsigned int n, char c);
	string& operator+= (const char* s);
	void push_back(char c);
	void pop_back();
	void swap(string& str);
	string& replace(unsigned int pos, unsigned int len, const string& str);
	string& insert(unsigned int pos, const string& str);
	string& insert(unsigned int pos, const string& str, unsigned int subpos, unsigned int sublen);

};