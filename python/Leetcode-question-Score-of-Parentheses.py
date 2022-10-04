def scoreOfParentheses(self, s: str) -> int: 
        st=[] #stack declared
        
        for i in s:
            #if ( is found put in stack
            if i=='(': 
                st.append(i)
                
            #if ) is found 
            elif i==')': 
                
                #and stack top is opening bracket then need to enter the score 1
                #as said in question => "()" has score 1
                if st[-1]=='(': 
                    st.pop()
                    st.append(1)
                
                #but if closing bracket is not found then there must me score numbers
                #are present in above opening bracket => 2nd rule (check in ques)
                #eg: st=[(,(,1,1,1,)] , closing bracket in st only for understanding, we are not really append it
                else:
                    #calculate the score till the opening bracket found
                    score=0
                    while st[-1]!='(':
                        score+=st.pop()
                        
                    #so pop the opening bracket as we have calculated the score above it and 
                    #now we have reached the 3rd rule => (A) has score 2 * A
                    #eg: st=[(,(,3,)] , closing bracket in st only for understanding, we are not really append it
                    st.pop()
                    st.append(2*score)
                    
        #return total sum of numbers present in st
        return sum(st)
