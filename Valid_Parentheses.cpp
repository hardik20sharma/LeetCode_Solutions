class Solution {
public:
    bool isValid(string str)
    {
        stack<char> s;
        for(char i : str)
            if(i == '(' || i == '{' || i == '[')
                s.push(i);
            else if(i == ')' && s.size()!=0 && s.top() == '(')
                s.pop();
            else if(i == '}' && s.size()!=0 && s.top() == '{')
                s.pop();
            else if(i == ']' && s.size()!=0 && s.top() == '[')
                s.pop();
            else
                return false;
        return s.size() == 0;
    }
};
