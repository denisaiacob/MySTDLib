#include <iostream>
#include "string.h"

int main() {
	string s1;
	string s2("Ana are mere");
	string s3("Ana are mere", 3);
	string s4(s2);
	//std::cout << s1.size() << std::endl;
	//std::cout << s2.length() << std::endl;
	/*s1.resize(8, 'A');
	s1.print();*/
	//s2.resize(7);
	//s2.print();
	/*std::cout << "S1 is empty " << s1.empty() << std::endl;
	std::cout << "S2 is empty " << s2.empty() << std::endl;
	std::cout << "S1 capacity " << s1.capacity() << std::endl;
	std::cout << s3.at(2) << std::endl;
	*///std::cout << s3.back() << std::endl;
	//s3.front() = 'T';
	/*std::cout << s3.front() << std::endl;
	std::cout << s2[5] << std::endl;
	*/
	/*s1.append(s2).print();
	s1.append(3, 'T').print();*/
	/*s2 += "ANA";
	s2.push_back('M');
	s2.pop_back();*/
	string s5("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!@#$%^&*()_-+=[]{}|;:,.<>?/`~QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!@#$");
	s2.swap(s5);
	s2.print();
	s5.print();
	//s2.replace(3, 2, s3).print();
	//s2.insert(4, s3).print();
	//s2.insert(3, s4, 3, 4).print();
	//s2.at(5) = 'a';
	//std::cout << s2.at(5);


}