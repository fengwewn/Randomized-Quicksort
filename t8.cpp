// t8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <fstream>
#include <string>

#include <iomanip>　
#include <regex>
using namespace std;

void quicksort(vector<double>& data, int p, int r) {//快排函数 //Fast permutation function
	int pivot, low = 0, high= 0 , q;
	if (p >= r)return;//当越界或者等界的时候跳出 //Jump out when crossing or waiting
	//随机数 //Random number
	int a = (rand() % (r - p + 1) + p);
	int b = (rand() % (r - p + 1) + p);
	int c = (rand() % (r - p + 1) + p);
	int zhong = 0;
	//求中值 //Find median
	if (a <= b <= c) {
		zhong = b;
	}
	else if (b <= c <= a) {
		zhong = c;
	}
	else if (c <= a <= b) {
		zhong = a;
	}
	//获得中值 //Get median
	pivot = zhong;

	low = p;
	high = r;
	//快排逻辑函数 //Fast scheduling logic function
	while (low < high){
		while ((data[low] <= data[pivot]) && (low <r))low++;
		while ((data[high] >= data[pivot]) && (high> p))high--;
		if (low < high)swap(data[low], data[high]);
	}
	if ((pivot<high) || (data[pivot] <data[high]))
	{
		swap(data[pivot], data[high]);
	}
	
	
	q = high;
	quicksort(data, p, q - 1);
	quicksort(data, q + 1, r);


}

int main()
{
	srand(time(NULL));//时间作为key //Time as key
	string numline;
	ifstream myfile("test4.txt");

	if (myfile.is_open())
	{
		getline(myfile, numline);//第一行数 //Number of first rows
		int num = stoi(numline);
		regex reg("[-]?([0-9]*\.[0-9]+|[0-9]+)");//正则 -9* ~9* //Regular - 9* ~ 9*
		vector<double>array;
		string line;
		for (int i = 0; myfile >> line; i++) {

			if (!(regex_match(line, reg))) {//过滤 例如"A" //Filter, e.g. "a"
				cout << "字符错误 Input character error" << endl;
				return 0;
			}

			array.push_back(atof(line.c_str()));
		}
		if (num != array.size()) {//过滤 长度不一
			cout << "数据长度错误 Data length error" << endl;
			return 0;
		}
		if (array.size()<3) {//过滤 长度小于3
			cout << "长度小于3 Length less than 3" << endl;
			return 0;
		}

		quicksort(array, 0, num-1);

		//输出 前五 后5 //Output first five and last five
		cout << setiosflags(ios::fixed) << setprecision(2);
		for (int i = 0; ((i != num)&& (i<5)); i++) {
			cout << array[i] << "  ";
		}
		cout << "\n";
		for (int i = 5; i!=0 && (0 < num - i); i--) {
			cout << array[num - i] << "  ";
		}
		cout << "\n";
		
		
	}
	else {
		cout << "文件无法打开 The file cannot be opened" << endl;
	}
}

