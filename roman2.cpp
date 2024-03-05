#include <string>
#include <unordered_map>
#include "Tools.h"

int romanToInt2(std::string s)
{
	std::unordered_map<char, int> symbols;
	symbols['M'] = 1000;
	symbols['D'] = 500;
	symbols['C'] = 100;
	symbols['L'] = 50;
	symbols['X'] = 10;
	symbols['V'] = 5;
	symbols['I'] = 1;

	int num = 0;
	int length = s.length();

	for (int i = 0; i < length; i++)
	{
		if ((symbols[s[i]] < symbols[s[i + 1]]) && i < length - 1)
		{
			num += symbols[s[i + 1]] - symbols[s[i]];
			i++;
		}
		else
		{
			num += symbols[s[i]];
		}
	}
	return num;

}