//��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻Ϊ"%20"����������"We are happy",
//����� "We%20are%20happy"

//��Ϊ�ѿո��滻Ϊ��%20����ÿ���滻��2���ַ�����˿���ͳ�Ƴ��ַ����пո���ܸ�����
//Ȼ���������СΪ  ��ԭ�����С + 2*�ո��� ����
//�Ӻ���ǰ���������ǿո�ֱ�Ӱᵽ���棬�����ո��滻Ϊ��%20��. 
//ֱ��������λ��ָ���ԭ����Ϊָ���غ�λ��

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

