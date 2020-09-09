#include "String.h"
#include "BF.h"


String::String(const char* temp)
{
	if (temp) {
		
		int count = 0;
		while(temp[count++]!='\0'){}
		this->size = count - 1;
		str = new char[count];
		count = 0;
		while (temp[count] != '\0') {
			str[count] = temp[count++];
		}
		str[count] = '\0';

	}
}

String::String() {
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

String::~String()
{
	if (this->str){
		delete[]  str;
	}
}

char String::operator[](int i) {
	if (i < this->length()) {
		return *(str + i);
	}
	else {
		return '-1';
	}
}

int String::length() { return this->size; }

int String::Strcmp(String& obj1, String& obj2) {
	if (obj1.length() > obj2.length()) {
		return 1;
	}
	else if (obj1.length() < obj2.length()) {
		return -1;
	}
	else {
		for (int i = 0; i < obj1.length(); i++) {
			if (obj1[i] > obj2[i]) {
				return 1;
			}
			else if(obj1[i] < obj2[i]){
				return -1;
			}
		}
		return 0;
	}
}

int String::rFind(String& obj, String& p) {
	int i = obj.length() - 1;
	int j = p.length() - 1;
	for (; i > -1; i--) {
		if (obj[i] != p[j]) {
			i = i + p.length() -  j - 1;
			j = p.length() - 1;
		}
		else {
			j--;
		}
		if (j == -1) {
			return i;
		}
	}
	return -1;
}