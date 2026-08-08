class MinStack {
public:

    long min;
    std::vector<long> stack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(stack.empty())
        {
            stack.push_back(0);
            min = val;
        } else {
            stack.push_back(val - min);
            if(val < min)
            {
                min = val;
            }
        }
    }
    
    void pop() {
        if(stack.empty()) return;
        long top = stack.back();
        stack.pop_back();
        if(top < 0){
            min = min - top;
        }
    }
    
    int top() {
        return stack.back() > 0 ? stack.back() + min : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
