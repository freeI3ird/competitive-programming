### Common Mistakes and Concepts

1. **POSITIVE**:
	- if mentioned some attribute is **positive**(> 0)
	- always keep a check for value of attribute <=0.

2. **Triangle Property**:
	- Sum of every two sides > third side.
	- Common but useful

3. **Edge Cases**:
	- Must check your program on following type of inputs.
		- Value of all inpus are **Equal**
		- Value of input = **End values of Range**
		- Value of input = **0**

4. **Errors in Binary Search**
	- Calculation of mid
  	- mid = lo + (hi-lo)/2 : rounds down (in case of even numbers, )
  	- mid = lo + (hi-lo +1)/2: rounds up
  	- mid = (lo+hi)/2
    	- Cause Integer Overflow if (lo+hi) > INT_MAX
    	- In case of negative numbers, (lo+hi)/2 rounds up
      	- lo = -3, hi = -2
      	- mid = (lo+hi)/2 = (-3-2)/2 = -2 : rounds up
      	- mid = lo + (hi-lo)/2 = -3 + (-2+3)/2 = -3 : rounds down
        	- Difference (hi-lo) is always > 0 and +ve number rounds down whereas -ve number rounds up on division.

	- Verify that the lower and upper bounds are not overly constrained: it’s usually better to relax them.
  	- As time increases logarithmically, try to keep lower and upper bounds relaxed, so that no test case is left by mistake.
  	- Predicate Evaluation must not fail on any value of Search Space.
	- Real Numbers
  	- Run BS for over hundred iterations(best option).
  	- Or Terminate the search when Search space is very small, try to use `Relative comparison of bounds instead of Absolute comparison`.
  	- The reason for this is that doubles can never give you more than 15 decimal digits of precision so if the search space contains large numbers (say on the order of billions), you can never get an absolute difference of less than 10e-7.
	- If the search space consists only of integers, `test your algorithm on a two-element set` to be sure it doesn’t lock up, (two elements must be: (no,yes))
    - Remember to always test your code on a two-element set where the predicate is false for the first element and true for the second.
5. Using distance array instead of parent and visited array in BFS.
6. Use functions: loga(b) = log(b)/log(a), log2(x), log10(x), pow(a,b), exp(x), sqrt(x)
7. getline in c++: http://www.cplusplus.com/reference/string/string/getline/

8. LCM and GCD/HCF
9. In GAME questions, Try to identify the states when the game will end.
   1. Sometimes try to think backwards, what will the end state and would have been the state before the end state.
10. Think out loud and think from base cases and small cases.

11. // Leap year concept u might don't know :
 condition :
 if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))


#### Mistakes
1. use scanf instead of cin when TLE .
2. a*(temp*temp)%mod X wrong precendece of % * is same
	correct : a*((temp*temp)%mod)  

3. int dp[MAX][MAX] ;
	for(i,0,MAX)
	    for(j,0,MAX)
	        dp[i][j]=-1; // it gives SIGSEV(runtime error)
   because area allocated till  dp[MAX-1][MAX-1] not dp[MAX][MAX];
4. Whenever there is a chance of overflow of int value , take everthing
    long long ,because if you take some of variables as 'int' ,in some places
    overflow can take place

4. ALWAYS INITIALIZE YOUR ARRAY OR DP[][]
    Sometime it takes garbage value other time it takes 0, never take risk;

5. in dp or recursion ,FIND THE BASE CASES CORRECTLY,half of the mistakes are done there.

6. u have a lot of confusion in statements like if( ex1 && ex2) , if(ex1 || ex2) , take care of it .

7. Whenever need to initialize an array ,donot initialize ,try to take it global as default value of global =0.

8. ALWAYS USE YOUR "power(ll a,ll b)" FUNCTION, don't trust built-in function.

9. To count no. of bits, don't use "log2(N)" : for 64bit N it shows wrong result, e.g N=288230376151711743 it gives 57 	
   instead of 58. Use
   while(n>0){
   		n=n/2;
   		bits++;
   }

### Concepts
1. In 1s around 10^7- 10^8 operations are performed.
2. Complexity of recursive dp : arguements in memorization,complexity of rec fun. taking recursive calls as constant
   - e.g  dp[idx][tk] , and idx - (0-n), tk- (0-k) and rec fun has complexity=O(n) then Time = O( n*k*n)

1. Longest path in a tree :using bfs
	-> apply bfs for each node , max level is longest path
	or
	-> apply bfs from any node to find the farthest node from that one
	-> apply bfs from farthest gives you the longest path  (ref : labyrinth.cpp)

2. Use of STL 'set' in place priority_queue in prim's algo. (reference: streets.cpp)

3. long long : %lld (format specifier) .

4. Many a times scanf and printf saves TLE.

5. SLIDING WINDOW conecpt ,used for O(n) approaches .(reference :spoj aliens)

6. a mod b = (a%b + b)%b  or r = a mod b ; if(r<0) r=r+b ; (to handle the negative values)

7. BFS(MAZE) :	each state is the ans to question 'where am i'  ; state =(i,j)
    BFS/ BITMASK :  state becomes complicated  ,question ' where am i and what are the conditions' ; these conditions can be represented by
		using bit masking
    		hint : in bfs(bitmasking) , whenever we are about to move to some position , ask yourself
            		' Did i have visited this dest. position from the current position?'
		reference "KEYTASK"  spoj.

8. <cctype> header : int isupper( int ch) , int islower(int ch)
		 int tolower( int ch) , int toupper(int ch)

9. Binary form :
	- a no. is even is LSB is 0  i.e  if(n%2==0) then LSB=0 else LSB=1, use  (n&1) its faster
	-  x>>1  its equivalent to  x/2
	- x<<1   its equivalent to 2*x   references (cook_match.cpp)or COOKMATCH
 *** CONCEPT OF BITMASKING****
	- set_mask(mask,i)   :  mask|(1<<(i-1))   or mask|(pow(2,i-1)  but  "bitewise OPERATION ARE FASTER "
	- check_mask(mask,i) : mask& (1<<(i-1))
10. fibonnaci of 46 is very big can't be stored in any variable only upto 45.
11. Count no. of bits in 'n' :  int bits = floor(log2(n))+1;
	To find the next pow of 2 : int x = Ceil(log2(n)) => pow2 = 2^x;     
	or Count no. of bits
		while(n>0)
		{
			n=n/2;
			bits++;
		}

12. Sum of digits of number 1-n : sum(9) = 1+2+3+4+...+9 = 45
			     sum(99)= sum(9)*10 + 45*10
		         	     sum(999)= sum(99)*10 + 45*100
    *** sum(10^d-1)= 45*d*pow(10,d)/10 ***
	(reference sum of digits , spoj)

13. Palindrome question : reference COUNTPAL, palindromic subsequences

14. Binary Search : floating point  if(predicate) l= mid; else r = mid ; not l=mid+1 or r = mid-1; reference 'CISTFILL'

15. upper_bound(v.begin(),v.end(),value) , lower_bound(v.begin(),v.end(),value);     these might be slow
      for faster operation use :  "pair< vi::iterator,vi::iterator > equal_range(v.begin(),v.end(),value)" reference 'sumfour.cpp'
      more to study       
16. Ceil function :  a/b,   (a+b-1)/b

17. a*b*c we want to reduce one of(a,b,c) such that remaining product is max
	Rem = (a-1)*b*c || a*(b-1)*c || a*b*(c-1)  which one to reduce ???
	Ans: Reduce max(a,b,c)
	3*5 = 3+3+3+3+3 || 5+5+5  => if (3-1) then one 5 reduced else if(5-1) one 3 reduced
	Reference : ChefDiv (april17)
18. cin.ignore(n,del) :This extracts characters from the input sequence and discards them, until either n characters have been 	
	extracted, or one compares equal to 'delim'.
	e.g cin>>n ; cin.getline(s) : Here s.length()=0 because '\n' was present at starting in buffer when control of flow reaches cin.getlin(s) and this function stops reading after it encounters '\n'
	Correction : cin>>n; cin.ignore(1,'\n') ; cin.getline(s);
19. no. of bits =  ceil( log2(N))
      no. of digits = ceil( log10(N))

20. Min. no. of moves(Some other thing) required to reach some destination, TRY TO CONVERT THEM TO GRAPH PROBLEMS.

21. No. is Power of 2 or not :  if( x!=0 && (x&x-1)==0) return true : x&x-1 => removes the rightmost set bit and in power of 2 there is only one
   			set bit.

22. When something in given in terms of "ODD/EVEN"
	USE THIS : EVEN+EVEN= EVEN 				EVEN+ODD=ODD			   
			   ODD +ODD = EVEN 				ODD+EVEN=ODD

23. FACT:
	f(A)= S ; S= sum of digits,
    f(A)= S if S<=9
        = f(S) otherwise

    f(A^N) = ?
    Property:
        f(A^N)= f((f(A))^N)
        f(p.q)= `f(f(p)*f(q))`
    `Reference: strange function @ codechef`

1. In many cases you don't need to use flag to check some condition , if look carefully you can some condition with
the help of your i used in the loop (hint : compare with the limit of loop)

2. When you have to find min. or max then you don't need to first enter the no.s in array and then check for max.
  Do it in one loop only ,simultaneously input and check in one loop only.

3. To find power of '2' Use `(1<<i)` instead of pow(2,i), former one is faster.

### Code Tactics

1. Compare if 3 numbers are in order i.e `3 2 1 or 1 2 3`
   - `if((a < b) != (b < c)) 'inorder' else 'not inorder'`
2. memset
   - `memset(void*ptr, int val, size_t n)`
   - It performs following steps
     - Converts `int val` to `unsigned char` by data conversion.
       - So if `val` is out of this range `(0, 255)` then there will data loss.
     - `unsigned char` takes 1 Byte, so it copies this `unsigned char val` at first `n` Bytes of the memory pointed by `ptr`.
   - USE CASES
     - `memset(str, '-', 6)`
       - Replace First 6 Bytes/chars with char '-'.
       - No data loss
     - `memset(arr, 0, sizeof(arr))`
       - All the elements of array will be set to 0.
       - Here 0 is integer, upon its conversion to char its 3 bytes out of 4 Bytes will be discarded. But 0 has all its bits as 0, so there is not effect of truncation.
       - Replace all the bytes of arr with Byte/Char = `00000000`
     - `memset(arr, -1, sizeof(arr))`
       - All the elements of array will be set to -1.
       - Here -1 is integer, it is represented by all 1s in binary, upon its truncation there will be no affect.
     - `memset(arr, x, sizeof(arr))`
       - NOT set all elements to x if x != 0 and x != -1.
       - When interger x is converted to unsigned char, data will be lost.
       - memset works for 0 or -1 only.
3. sizeof operator
   - `sizeof(int), sizeof(5), sizeof(arr), sizeof(str)`
   - Returns memory size in Bytes of data type, structure, class, literal.
   - It returns a value of type `size_t` i.e unsigned int.
   - USE CASES
     - No of elements in arr
       - `sizeof(arr)/sizeof(arr[0])`
