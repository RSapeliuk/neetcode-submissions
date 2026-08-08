class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(' || s[i] == '{' || s[i] =='[')
                {
                    stack.push(s[i]);
                }
                else
                { 
                    if(stack.empty()){
                        return false;
                    }
                    char top = stack.top();
                    if((s[i] == ')' && top == '(') ||
                     (s[i] == '}' && top == '{') ||
                      (s[i] == ']' && top == '['))
                      {
                        stack.pop();
                      }
                      else 
                      {
                        return false;
                      }
                }
            }
            return stack.empty();
        }
        
    };

