#include<iostream>
using namespace std;
int Index_KMP(string S, string T, int pos);

int main()
{
	string S1 = "scwqfqwabcddcbadqd";
	extern string pattern;
	int res;
	res=Index_KMP(S1, pattern, 0);
	if (res)
		cout << "在主串的位置：" << res << endl;
	else
		cout << "未找到" << endl;

	return 0;

}