#include<assert.h>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	stack<int> m_data, m_min;
	void push(int value) {
		m_data.push(value);
		if (m_min.size() == 0 || value < m_min.top())
			m_min.push(value);
		else
			m_min.push(m_min.top());
	}
	void pop() {
		assert(m_data.size() > 0 && m_min.size() > 0);
		m_data.pop();
		m_min.pop();
	}
	int top() {
		//assert(m_data.size() > 0 && m_min.size() > 0);
		return m_data.top();
	}
	int min() {
		//assert(m_data.size() > 0 && m_min.size() > 0);
		return m_min.top();
	}
};
void Test(char *str1, Solution s1, int expected){
	if (s1.min() == expected)
		cout << "pass" << endl;
	else
		cout << "fail" << endl;
}
int main(){
	Solution s1;
	s1.push(3);
	Test("Test1",s1, 3);
	s1.push(4);
	Test("Test2", s1, 3);
	s1.push(0);
	Test("Test3", s1, 0);
	//int result = s1.min();
	//cout << result << endl;
	s1.pop();
	Test("Test4", s1, 3);
	//result = s1.min();
	//cout << result << endl;
	return 0;
}