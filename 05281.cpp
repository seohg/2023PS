/* 2023.05.28 백준 1874 -  스택수열 */
#include <iostream> 
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n;
int cnt = 0;
int arr[100001];
vector<int> v;
vector<char> ans;

int main()
{	
	cin >> n;
	for (int i = 0; i < n; i++){
    cin >> arr[i];
  } 

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		ans.push_back('+');

		while (!v.empty() && v.back() == arr[cnt])
		{
			v.pop_back();
			ans.push_back('-');
			cnt++;
		}
	}

	if (!v.empty()) cout << "NO"; 
	else for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
	

}