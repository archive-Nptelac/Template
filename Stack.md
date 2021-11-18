## Stack

- [Stack](#stack)
  - [Infix  to postfix](#Infix_To_Postfix)
  - [Infix  to prefix](#Infix_To_Prefix)
  - [Postfix  to prefix](#Postfix_To_Prefix)
  - [Postfix  to Infix](#Postfix_To_Infix)
  - [Prefix  to postfix](#Prefix_To_Postfix)
  - [Prefix  to Infix](#Prefix_To_Infix)

## Infix_To_Postfix
```C++
    string infixToPostfix(string s)
    {
        // Your code here
        stack<char>st;
        string res = "";
        st.push('(');
        s += ')';
        auto prec = [](char ch){
            if(ch=='+'||ch=='-')    return 1;
            else if(ch=='*'||ch=='/')   return 2;
            else if(ch=='^')    return 3;
            return 0;
        };
        for(char ch : s){
            if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    res.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')||(ch>='0'&&ch<='9')){
                res.push_back(ch);
            }
            else{
                while(!st.empty() && prec(st.top())>=prec(ch)){
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
        return res;
    }

```

## Infix_To_Prefix

```C++
string infixToPrefix(string s) {
	int l = s.size();
	reverse(s.begin(), s.end());
	for (int i=0;i<l;i++) {
		if (s[i] == '(') {
			s[i] = ')';
		}
		else if (s[i] == ')') {
			s[i] = '(';
		}
	}
	string res = infixToPostfix(s);
	reverse(res.begin(), res.end());
	return res;
}
```

## Postfix_to_Prefix
```C++
string postToPre(string s){
    stack<string> st;
    int length = s.size();
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')) {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = s[i] + op2 + op1;
            st.push(temp);
        }
        else {
            st.push(string(1, s[i]));
        }
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
```

## Postfix_To_Infix
```C++
string Postfix_to_Infix(string s)
{
    stack<string> st;
    for (int i=0; s[i]!='\0'; i++){
        if (isOperand(s[i])){
           string op(1, s[i]);
           st.push(op);
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op2 + s[i] + op1 + ")");
        }
    }
    return st.top();
}
```

## Prefix_To_Postfix
```C++
string preToPost(string pre_exp){
	stack<string> s;
	int length = pre_exp.size();
	for (int i = length - 1; i >= 0; i--)
	{
	    char ch = pre_exp[i];
	    if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')){
	        string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			string temp = op1 + op2 + pre_exp[i];
			s.push(temp);
	    }
		else {
			s.push(string(1,ch));
		}
	}
	return s.top();
}
```

## Prefix_To_Infix
```C++
string preToInfix(string s) {
    stack<string>st;
    int length = s.size();
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(s[i])) {
            string op1 = st.top();   st.pop();
            string op2 = st.top();   st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
        else {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}
```

