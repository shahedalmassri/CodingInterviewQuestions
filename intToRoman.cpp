#include <string>
#include <unordered_map>


std::string intToRoman(int num)
{
	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	std::string roman;

	int arrLength = sizeof(values) / sizeof(values[0]);
	
	for (int i = 0; i < arrLength; i++)
	{
		int temp = num / values[i];
		if (temp != 0)
		{
			for (int j = 0; j < temp; j++)
			{
				roman += symbols[i];
			}
			num %= values[i];
		}
	}
	return roman;
	

}