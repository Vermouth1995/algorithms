#include <bits/stdc++.h>
using namespace std;

stack<int> sorting(stack<int>);

int main() {
	int n;
	cin >> n;
	stack<int> myStack;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		myStack.push(tmp);
	}

	stack<int> result = sorting(myStack);
	vector<int> answer;

	while (!result.empty()) {
		answer.push_back(result.top());
		result.pop();
	}

	for (auto i = answer.rbegin(); i != answer.rend(); ++i) {
		cout << *i << endl;
	}

	return 0;
}

stack<int> sorting(stack<int> myStack) {
	stack<int> result;

	if (myStack.empty()) {
		return result;
	}

	int tmp = myStack.top();
	myStack.pop();

	while (!myStack.empty() || (!result.empty() && result.top() > tmp)) {
		if (result.empty() || result.top() <= tmp) {
			result.push(tmp);
			tmp = myStack.top();
			myStack.pop();
		} else {
			myStack.push(result.top());
			result.pop();
		}
	}

	result.push(tmp);
	return result;
}
