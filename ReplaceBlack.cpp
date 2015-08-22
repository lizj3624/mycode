//题目：请实现一个函数，把字符串中的每个空格替换为"%20"，例如输入"We are happy",
//则输出 "We%20are%20happy"

//因为把空格替换为”%20“，每次替换多2个字符，因此可以统计出字符串中空格的总个数，
//然后新数组大小为  “原数组大小 + 2*空格数 ”。
//从后往前处理：遇到非空格，直接搬到后面，遇到空格替换为”%20“. 
//直到待插入位置指针和原数组为指针重合位置

#include <iostream>
using namespace std;

void ReplaceBlank(char string[],int length)
{
	if (string == NULL && length <= 0)
	{
		return;
	}

	int oldLength = 0;
	int numOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++oldLength;

		if (string[i] == ' ')
		{
			++numOfBlank;
		}

		++i;
	}

	int newLength = oldLength+ numOfBlank*2;
	if (newLength > length)
	{
		return;
	}

	while (oldLength >= 0 && newLength > oldLength)
	{
		if (string[oldLength] == ' ')
		{
			string[newLength--] = '0';
			string[newLength--] = '2';
			string[newLength--] = '%';
		}
		else
		{
			string[newLength--] = string[oldLength];
		}
		--oldLength;
	}
	

	/*
	int indexOfOldLength = oldLength;
	int indexOfNewLength = newLength;
	while (indexOfOldLength >= 0 && indexOfNewLength > indexOfOldLength)
	{
		if (string[indexOfOldLength] == ' ')
		{
			string[indexOfNewLength--] = '0';
			string[indexOfNewLength--] = '2';
			string[indexOfNewLength--] = '%';
		}
		else
		{
			 string[indexOfNewLength--] = string[indexOfOldLength];
		}
		--indexOfOldLength;
	}	
	*/
}

int main(int argc, char* argv[])
{
	char s[20] = "We are Happy.";
	for (int i = 0; i < 20; i++)
	{
		cout<<s[i];
	}
	ReplaceBlank(s,20);
	cout<<endl;
	for (int i = 0; i < 20; i++)
	{
		cout<<s[i];
	}
    cout << endl;

	return 0;
}

