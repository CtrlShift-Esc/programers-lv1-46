#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void permutation(int depth, int r, vector<int> nums, vector<int>& vt)
{
	if (depth == r)
	{
		int r = 0;
		for (int i = 0; i < r; i++)
			r += nums[i];
		vt.push_back(r);
		return;
	}

	for (int i = depth; i < nums.size(); i++)
	{
		swap(nums[depth], nums[i]);
		permutation(depth + 1, r, nums, vt);
		swap(nums[depth], nums[i]);
	}
}

bool isPrime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = -1;

	int size = nums.size();
	vector<int> vt;
	answer = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				int n = nums[i] + nums[j] + nums[k];
				if (isPrime(n))
					answer++;
			}
		}
	}

	return answer;
}

void main()
{
	//test
	//auto ret = solution({1,2,7,6,4});
}