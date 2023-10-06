// calnextval_KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
//void cal_nextval(string T, int* nextval, int num);  //函数声明
string pattern = "abcdfdcba";

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

void cal_nextval(string T, int* nextval, int num)    //下标从0开始的
{
	int i, k;
	i = 0;
	k = -1;
	nextval[0] = -1;
	while (i < num - 1)
	{
		if (k == -1 || T[i] == T[k])
		{
			i++;
			k++;
			if (T[i] != T[k])
				nextval[i] = k;
			else
				nextval[i] = nextval[k];
		}
		else
			k = nextval[k];
	}

}


int Index_KMP(string S, string T, int pos)
{
    int i = pos;
    int j = 0;
    int S_len = S.length();
    int p_len = T.length();
    int next[250];
    cal_nextval(T, next, p_len);
    while (i < S_len && j < p_len)
    {
        if (j == -1 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }


    }
    if (j == p_len)
        return i - p_len;
    else
        return 0;
}