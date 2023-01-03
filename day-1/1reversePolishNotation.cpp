/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Intuition
1) use stack to push all the numeric values
2) take two numbers and calculate it according to its arithmetic sign
3) push the calculated result into the stack so that later on  it can be evaluated
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<long long>st;
     for(auto x : tokens){
         if(x != "+" && x != "-" && x != "*" && x != "/"){
             st.push(stoi(x));
         }else{
             long long a = st.top();
             st.pop();
             long long b = st.top();
             st.pop();
             if(x == "+"){
                 st.push(a+b);
             }else if(x == "-"){
                 st.push(b-a);
             }
             else if(x == "*"){
                 st.push(a*b);
             }
             else{
                 st.push(b/a);
             }
         }
     } 
     return st.top(); 
    }
};
