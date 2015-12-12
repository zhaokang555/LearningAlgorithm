#include <iostream>
#include <string>

const int MaxSize = 100;

bool match(std::string expression)
{
	char stack[MaxSize]; int top = -1;

	for (int i = 0; i < expression.size(); i++) {
		switch (expression[i]) {
			case '(':
				stack[++top] = '('; 
				break;
			case '[':
				stack[++top] = '['; 
				break;
			case '{':
				stack[++top] = '{'; 
				break;
			case ')':
				if (top == -1 || stack[top] != '(') // "())"或者"[)"的情况
					return false;
				else 
					--top; 
				break;
			case ']':
				if (top == -1 || stack[top] != '[') 
					return false;
				else
					--top; 
				break;
			case '}':
				if (top == -1 || stack[top] != '{') 
					return false;
				else
					--top; 
				break;
		}
	}

	if (top == -1) 
		return true;	
	else 
		return false;
}

int main(int argc, char const *argv[])
{
	using namespace std;

	string s = "[()]";
	cout << match(s) << endl << "Press any key to continue" << endl;

	getchar();
	return 0;
}

