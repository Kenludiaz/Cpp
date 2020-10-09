#include <iostream>
#include <string>

using namespace std;

string Capitalize_first_letter(string text) {

	for (size_t x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}

	return text;
}

int main() 
{
	cout << Capitalize_first_letter("Write a C++ program");
	cout << "\n" << Capitalize_first_letter("cpp string exercises");
	return 0;
}