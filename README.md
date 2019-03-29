# gizmo-interview
answer to the coding question
input format :  
eg.  
7,1  
5,2  
3,3  
1,4  
2,7  
4,8  
6,5  
8,6  

O/P :  
true  

and for failed test case   
(x,y)--->co-ordinates of the queen.  

execute-  

g++ queen.cpp -oqueen  
./queen


# COMPLEXITY ANALYSIS:  
the algorithm scales with n as O( n <sup>2</sup>  )  
# logic:  

EightQueen :  
  for each queen in list:                 ..O(n)  
      >find if it attacks                 ..O(n)  
       any other queen   
       
       
overall it's O(n <sup>2</sup>)
