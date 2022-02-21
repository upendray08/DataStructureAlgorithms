class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int size = S.length();
        for(int i=0;i<size;++i){
            if(S[i]>='0'&&S[i]<='9'){
                st.push(S[i]-'0');
            }else{
                int o2= st.top();
                st.pop();
                int o1 = st.top();
                st.pop();
                switch(S[i]){
                    case '+':
                        st.push(o1+o2);
                        break;
                    case '*':
                        st.push(o1*o2);
                        break;
                    case '-':
                        st.push(o1-o2);
                        break;
                    case '/':
                        st.push(o1/o2);
                        break;
                }
                
            }
        }
        return st.top();
    }
};