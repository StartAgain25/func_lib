#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
//sort函数
#include <algorithm>

	using namespace std;

class Solution
{
public:
	Solution();
	vector<int> interSection(vector<int> &num1,vector<int> &num2);
	vector<int> inter2Section(vector<int> &num1,vector<int> &num2);
	vector<int> inter3Section(vector<int> &num1,vector<int> &num2);
	test_interSection();

};

Solution::Solution()
{
};
vector<int> Solution::interSection(vector<int> &num1,vector<int> &num2)
{
	if(num1.empty() || num2.empty())
		return vector<int>();
	
	unordered_set<int> st;
	for(auto a:num1)
		st.insert(a);
	vector<int> res;
	for(auto a:num2)
	{
		if(st.count(a)>0)
		{
			res.push_back(a);
			st.erase(a);
		}
	}
	return res;
};

vector<int> Solution::inter2Section(vector<int> &num1,vector<int> &num2)
{
	sort(num1.begin(),num1.end());
	sort(num2.begin(),num2.end());
	
	set<int> st;
	vector<int> res;
	int p1=0,p2=0;
	cout<<num2.size();
//未写出
	while(p1<num1.size() && p2<num2.size())
	{
		if(num1[p1] == num2[p2])
		{
			st.insert(num1[p1]);
			++p1;++p2;
		}
		else
		{
			num1[p1]<num2[p2] ? ++p1:++p2;
		}
	}
	//老是遗忘 分号
	for(auto a:st)
		res.push_back(a);
	return res;
}

Solution::test_interSection()
{
	vector<int> v1,v2,res;
	for(int i=0;i<5;i++)
	{
		v1.push_back(i);
		v2.push_back(i*2-1);
	}
	// res = interSection(v1,v2);
	// res = inter2Section(v1,v2);
	res = inter3Section(v1,v2);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
};
bool binary_search(vector<int> &num,int iTarget)
{
	int l=0,r=num.size()-1;
	while(l<=r)
	{
		int m = (l+r)/2;
		if(num[m] < iTarget) l = m+1;
		else if(num[m]>iTarget) r = m-1;
		else return true;
	}
	return false;
}
vector<int> Solution::inter3Section(vector<int> &num1,vector<int> &num2)
{
	sort(num1.begin(),num1.end());
	
	vector<int> res;
	set<int> st;
	int p1=0,p2=0;
	
	for(auto a:num2)
	{
		if(binary_search(num1,a))
			st.insert(a);
	}
	for(auto a:st)
		res.push_back(a);
	return res;
}
int main()
{
	Solution s = Solution();
	s.test_interSection();
	return 0;
}