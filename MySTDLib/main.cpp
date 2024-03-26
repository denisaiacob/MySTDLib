#include <iostream>
#include "string.h"

int main() {
	string s1;
	string s2("Ana are mere");
	string s3("Ana are mere", 3);
	string s4(s2);
	std::cout << s1.size() << std::endl;
	std::cout << s2.length() << std::endl;
	s2.resize(18, 'A');
	s2.print();
	s2.resize(7);
	s2.print();
	std::cout << "S1 is empty " << s1.empty() << std::endl;
	std::cout << "S2 is empty " << s2.empty() << std::endl;
	std::cout << "S1 capacity " << s1.capacity() << std::endl;
	std::cout << s3.at(2) << std::endl;
	std::cout << s3.back() << std::endl;
	s3.front() = 'T';
	std::cout << s3.front() << std::endl;
	std::cout << s2[5];


}