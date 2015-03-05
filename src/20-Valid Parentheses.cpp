// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : Javier Liu
// Date   : 2015-03-01

/********************************************************************************** 
* 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* 
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
* 
* Solution: use stack
*              
**********************************************************************************/

#include <stack>
class Solution {
public:
	bool isValid(string s) {
		stack<char> stack_c; 
		
		for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
		{
			if (*iter == '(' || *iter == '[' || *iter == '{')
			{
				stack_c.push(*iter);
			}
			else if (*iter == ')')
			{
				if (stack_c.empty())
					return false;
				else if (stack_c.top() != '(')
					return false;
				stack_c.pop();
			}
			else if (*iter == ']')
			{
				if (stack_c.empty())
					return false;
				else if (stack_c.top() != '[')
					return false;
				stack_c.pop();
			}
			else if (*iter == '}')
			{
				if (stack_c.empty())
					return false;
				else if (stack_c.top() != '{')
					return false;
				stack_c.pop();
			}
		}

		if (stack_c.empty()) 
			return true;
		return false;
	}
};