# MySTDLib

 Task 1 Lib:
# 	-> Clasa String
	membrii privati : char* str ( pointerul in care lucram si tinem stringul ) , 
					  unsigned int length ( length-ul lui ), 
					  unsigned int capacity = 100 default ( capacitatea lui )
					
	Constructori :
	string();
	string (const char* s, size_t n);
	string (const char* s);
	string (const string& str);
	
	Metode:
	Capacity:
		-> size()
		-> length()
		-> max_size() return capacity
		-> resize()
		-> capacity()
		-> empty()
	
	Element access : 
		-> at()
		-> back()
		-> front()
		-> operator[]
	Modifiers:
		-> append()
		-> operator+=()
		-> push_back()
		-> insert()
		-> replace()
		-> swap()
		-> pop_back()
