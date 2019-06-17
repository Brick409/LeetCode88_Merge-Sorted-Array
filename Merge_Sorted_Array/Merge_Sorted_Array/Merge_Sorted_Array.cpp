// Merge_Sorted_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>  //包括min和max函数

using namespace std;

/*
88题：给定两个有序整型数组nums1,nums2,
	将nums2的元素归并到nums1中，并保证nums1是有序的
	Input:
	nums1 = [1,2,3,0,0,0], m = 3
	nums2 = [2,5,6],       n = 3

	Output: [1,2,2,3,5,6]
*/
class Solution88 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		int i = 0, j = 0;
		int k = 0;
		vector<int> ans = nums1;

		while ((i < m) && (j < n))
		{

			if (nums1[i] < nums2[j])
			{
				ans[k++] = nums1[i++];
			}
			else
				ans[k++] = nums2[j++];
		}

		while (i < m)
		{
			ans[k++] = nums1[i++];
		}

		while (j < n)
		{
			ans[k++] = nums2[j++];
		}

		for (int i = 0;i < k;i++)
		{
			nums1[i] = ans[i];
		}

	}
};

int main()
{
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int m = 3;

	int nums2[] = { 2, 5, 6 };
	int n = 3;

	vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));
	vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));
	
	cout << "原始数据：";

	for (int i = 0;i < m + n;i++)
	{
		cout << vec1[i] << " ";
	}

	cout << endl;

	Solution88().merge(vec1, m, vec2, n);

	cout << "插入后排序新数据：";

	for (int i=0;i<m+n;i++)
	{
		cout << vec1[i] << " ";
	}

	cout << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
