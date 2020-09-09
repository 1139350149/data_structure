#pragma once
class String
{
public:
	String(const char* temp);
	String();
	~String();
	int length();
	static int Strcmp(String& obj1, String& obj2);
	static int rFind(String& obj, String& p);
	char operator[](int i);
private:
	char* str;
	int size;
};

