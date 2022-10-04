def maxChunksToSorted(self, arr: List[int]) -> int: 
	
		## approach is to store the min and max range of the valid chunk -in code it will be stored in pairs in stack 
		
		## FOR THAT WE HAVE TO CHECK- if previous chunk's max range is greater than current arr[i] that means the arr[i] is the part 
		##of the previous chunk , so then update the max and min range of that chunk
		
		## KEEP IN MIND -every valid chunk is - if previous chunk's max range is less than the next chunk's min range
		## eg : [(1,2),(3,4),(5,6)] , so 2<3 and 4<5 , this is how the chunk will be formed
		
		
        st=[] ##stack
        for i in range(len(arr)):
			 ## taking arr[i] minimum (mi) and maximum(ma) , as some chunks can be just single element also 
			 ##eg : [2] or [3]  (here min and max range is same)
			 
            mi=arr[i]
            ma=arr[i] 
			
			## now need to check if the stack is not empty and previous chunk's max 
			##range is greater than current mi, that means the mi is the part of the previous chunk
			
            while st and st[-1][1]>mi:
				## if thats true then update the chunk min and max range and pop the 
				##previous pair because the stack is updated now
                mi=min(mi,st[-1][0])
                ma=max(ma,st[-1][1])
                st.pop()
				
			## automaticallly doing -previous chunk's max range is less than the current 
			##chunk's min range (i.e, mi) so forming the new chunk
            st.append([mi,ma])
		## return the total chunk present in stack
        return len(st)
