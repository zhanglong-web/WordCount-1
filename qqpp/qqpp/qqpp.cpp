#include<iostream>
#include<fstream>
#include<string>
#include <cstring>
#include<algorithm>

using namespace std;
bool isnum_str(char str)  //判断是否是字符或数字
{
	if ((str >= 'A' && str <= 'z'))
		return true;
	else
		return false;
}
bool isnum_str2(char str)
{
	if (str >= ' ' && str <= 'z' || str == 't')
		return true;
	else
		return false;
}


int main() {
	char str[1000];    //用于接收用户输入的字符串
	char s[1000][40] = { 0 };     //用于储存每一个不同的单词

	int i = 0;                //字符串下标
	int m = 0;                //行
	int n = 0;                //列
	char temp[40] = { 0 };      //用于临时储存字符串中方每个单词
	int len = 0;              //记录单词的长度
	int count[1000] = { 0 };      //记录每个单词出现次数
	int k;                    //单词每个字符下表
	int flag = -1;                 //判断能否找到
	int cnt[3] = { 0 };               //统计字符数、单词数、行数
	int x = 0;

	cout << "输入文本：";
	cin.getline(str, 1000);


	for (int i = 0; i < 1000; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	
	while (str[i] == ' ')      //作用是把开头的空格给过滤掉
	{
		i++;
		cnt[2]++;
	}
	while (str[i] != 0)        //外层循环判断str是否结束
	{

		k = 0;                //temp长度清零
		flag = -1;            //是否找到相同单词打标志位重置

		while (str[i] >= 0 && str[i] <= 9 && str[i] != 0 || str[i] >= 'a' && str[i] <= 'z')   //每一个非''位存入temp
		{
			temp[k] = str[i];
			k++;                             //每次加一，用于计算单词长度
			i++;
			cnt[2]++;
		}
		//if(temp[0]>=0&&temp[0]<=9||k<4)	int x=0;x++;  不符合的单词数 
		cnt[0]++;
		if (temp[0] >= 0 && temp[0] <= 9 || k < 4)
			x++;                          //不符合的单词数 
		if (str[i - 1] != ' ')             //一个单词录完后str[i]的值是空，find函数可以在s[][]中找到，会出现错乱
		{
			//flag =  find (s, temp, m);    //找到单词为单词在s[][]中的行号，否则为-1

			for (int x = 0; x < m; x++)     //传入了行号，每个都要比较
			{
				if (strcmp(s[x], temp) == 0)
					flag = x;
			}
			if (flag == -1)
			{
				//strcpy(s[m], temp);         //若是-1就在s[][]中加入新单词
				for (int j = 0; j < k; j++)
				{
					s[m][j] = temp[j];
				}
				for (int j = 0; j < k; j++)  //要清空，不然前面长的单词会影响后面的短的单词
				{
					temp[j] = '\0';
				}
				count[m] = 1;               //count[]要记录单词出现一次
				m++;                        //s[][]行号加一
			}
			else
			{
				//strcpy(s[flag], temp);        //和上面没有找到类似
				for (int j = 0; j < k; j++)
				{
					s[flag][j] = temp[j];
				}
				for (int j = 0; j < k; j++)
				{
					temp[j] = '\0';
				}
				count[flag] += 1;
			}
		}
		else
		{
			break;
		}
		while (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')      //作用是把中间和最后的空格给过滤掉
		{
			i++;
			cnt[2]++;
		}
	}
	cnt[1]++;
	



	cout << "文件读入有(两竖线中间内容)：";
	for (int ii = 0; ii < i; ii++)
	{
		cout << str[ii];
	}
	cout << endl;
	cout << "characters: " << cnt[2] << endl;
	cout << "有效单词数:" << cnt[0]-x << endl;
	cout << "lines:" << cnt[1]<< endl;
	cout << "此文本统计有：" << endl << "单词";
	cout.width(21);                                       //格式输出

	cout << "个数\n";
	for (i = 0; i < 10; i++)
	{
		for (int j = 0; j < strlen(s[i]); j++)
		{
			cout << s[i][j];
		}
		cout.width(21 - strlen(s[i]));
		cout << count[i] << endl;
	}
	cout << "统计完毕！";
	return 0;
}