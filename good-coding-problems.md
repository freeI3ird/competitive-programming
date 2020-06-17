Topic Wise :

Binary Search:
	// Sometimes we are given a key and we Search it to find the answer
	// Sometimes, we do Binary search on the Answer or range of answer and try to fit the approximation to desired conditions
	-SnakeEAT :https://www.codechef.com/problems/SNAKEEAT
	-Smallest missing no. (geeks)
	-Search an element in a sorted and rotated array(Good).
Greedy :
	-Job Sequencing Problem(deadline and profit),using 'Disjoint set' also.
	-Huffman Coding for Sorted Input :O(n)
	-Min. Time Required to Finish all the Jobs
	-Paper cut into Minimum no. of squares( here greedy choice is not safe proof??)
	-Rearrange a string so that all same characters become d distance away
	-***Minimum edges to reverse to make path from a source to a destination***
DP :
// Interval dp : R(i,j) = R(i+1,j)+R(i,j-1) or R(i+1,j-1)
// E.g MCM, Longest palindrome subsequence, LCS and other Interval problems,
// BUILD DP SOL. FROM SMALLER LENGTH TO GREATER LENGTH
/* 	for(len=2;len<=n;len++)
 	{
 		for(i=1,j=len;j<=n;i++,j++)
 	}
*/
	- Ugly Numbers (geeks)
	- #ways to partition n elements in a set to 'k' subsets (geeks)
	   Stirlings number of 'second kind' :S(n,k) = #ways to partition n elements into 'k' subsets
	   Bell no. : #ways to partition 'n' elements of a set, Bell no = {S(n,k) | 0<=k<=n }; S(n,0)=0

	- Given a squarefree number x, find the number of different multiplicative partitions of x?
	- Egg Droping
	- Box Stacking Problem(MUST)
	- Longest Length Arithmetic Progression(Must)
	- Buy And Sell Stock Problem
			=> Kadane algo on the profit (difference array)
			=>*** start from last and maintain the highest price till now and find the maximum difference***
	- Palindrome Partitioning :O(n^2);
	- Boolean parantherzian problem.(geeks).
	- If String is interleaving of two strings(Must)
	- Optimal Game Stratergy(Geek)***.
	- Count # of AP subsequence in an array.

Segment Tree and BIT :
	- Persistan Segment tree and BIT ("TO DO")
	- KQUERY (Spoj)
	- Chef and Prime Queries (june long17)
	- Merge Sort Tree:https://discuss.codechef.com/questions/94448/merge-sort-tree-tutorial

MO's' :
	-

Array implementation:
	- Find the two repeating elements in a given array(say X,Y are two elements that are repeating),range(1-n)
	-Sort an array of 0s, 1s and 2s
	- Cycle Sort
	-Smallest missing number (Binary Search)
	-Interpolation Search
	-Check if array elements are consecutive
	-Sliding Window Maximum (Maximum of all subarrays of size k) (Using Deque O(N):Useless elements)
	- One no. missing and One no. repeated.(Xor,USe hashing and Indx)
		- Use Sum and Product Equation ***Use Sum and Square Sum equation.***
	- Rotate the Matrix by 90 degree(MUST).
	- Set Matrix Zeroes /Boolean Matrix.
Graph:
	- Biconnected Graph (Graph which is connected and Do not have any Articulation point)
	- All Stepping No. from 'n' to 'm' range.(Stepping no. = difference of adjacent digits =1)***

Tree: Preorder,Inorder,Postorder= DFS of Graph, and Level Order= Bfs of Graph
	  //***Think Tree as a Special case of Graph, you are good in graph so you are good in Tree also.***
	-Inorder Traversal without stack without recursion (Morris)
	-Connect nodes at same level using constant extra space(MUST)***
	-Postorder,Inorder,Preorder Iterative traversals.***
	-Convert binary tree to DLL (all methods)***
	-Construct Binary tree from different traversals given.***
	-Reverse alternate levels of a perfect binary tree.(two inorder traversals)
	-Check if a tree 's' is subtree of another tree 'T'(Hint inorder and preorder uniquely identify a tree )
	-print left ,top ,right,bottom view of tree.
		left view: 1.first node of every level. 2. recursive traversal ,maintain a max_level if(level of node >max_level) then it is first node in that level.
	- CLONE LINKED LIST AND CLONE A BINARY TREE.
	- Construct Binary tree from Parent Array Representation.(Find height given Parent array representation)
	- Diagonal Traversal (MUST).
	-Construct complete Binary tree from the Linked List representation.(MUST)(use level order traversal).
	-find vertical sum (Space optimized using DLL).
	-Boundary Traversal.

HEAP :- ALWAYS CHECK THE BOUNDARY CONDITIONS, i>=0 and i<=h->count-1
	- k largest/smallest elements in unsorted array. (USE HEAP : O((n-k)*logk))
	- kth smallest/largest in HEAP. (USe HAUX heap, O(klogk))
	- Print all elements in sorted order from row and column wise sorted matrix
	 ( use the approach used for merging k sorted arrays.
	  The idea is to use a Min Heap of size N which stores elements of first column)
	- Rearrange Characters in a string such that no. two same char are adjacent.(MUST).
			(Use greedy,insert the most frequent first)

BST : ALWAYS TRY TO APPLY BST PROPERTY - (ELEMENTS IN LEFT SUBTREE <ROOT<ELEMENTS IN RIGHT SUBTREE).
	-Check Bst or Not (USE BST PROPERTY)
	-LCA of n1 and n2 .(USE BSt property)
	- Inorder Successor and Predecessor.(FIND THE FIRST RIGHT ANCESTOR , FIRST LEFT ANCESTOR)
	- kth smallest element in bSt.( maintain Lcount: no. of elments in leftSubtree).
	- Check for Identical BSTs without building the trees.
	-Conversion of DLL and Linked list to BST.

Linked List:TAKE CARE OF FOLLOWING CASES: 1. 'WHEN Linked list is empty' 2.'Only One Node'
 										  3.'When TARGET NODE IS head'   4. 'WHEN TARGET NODE IS last'.
  - ***SWAP two nodes without swapping the data (IMPORTANT)(1.handle the prev pointers 2.handle cur ptrs.)***
  - Find the middle element
  		* Rabbit and turtle method
  		* Initialize mid=*head,traverse the list and increment mid only on odd nodes.***
  - Find Nth node from last
  		1. Recursive method 2. Two pointer 'Main' and 'Ref' and seperate them by 'N' distance and then move.
  - Delete a node, only pointer to that node is available(head is not available)
  		( copy the data from the next node to the node to be deleted and delete the next node)
  		This is method donot work if the node to be deleted is last node.
  - DETECT LOOP AND REMOVE IT. (MUST).
  			* Using Hashing and Visited flag
  			* Floyd : slow and fast pointer (detection)
  			* Find the Lenght of Cycle say 'k', Now keep to pointers 'k' distance apart and move them at same pace
  			  one at Head ,other at 'k' distance from Head.Now when Prev. one will be at starting node of loop, other will
  			  be at 'k' distance apart and loop's' length is 'k' so another pointer is also at starting node.
  			* Let dist(fast pointer) = 2*dist(slow pointer), let n= length of loop
  				  m+ n*x + k = 2*(m+n*y+k)
  				  n*(x-2y) = m+k   i.e (m+k) is multiple of length of loop.
  			 so if we start one pointer at Head and other from point of intersection then they will meet at point of intersection
    -Find the first non-repeating character from a stream of characters.(MUST)

#### Back-Tracking
1. Rat in a maze.
	- Maze is (N,N) matrix, rat have to reach from 	         source(0,0) to destination(N-1,N-1), some cells are     blocked. **Rat can move in all 4 directions.**
	- Our Thought: keep marking the cells that we visit 	in the path and if encounter some visited cells than 	 backtrack.
	- **TRICK**: This can be done with `int 		   previous_dirction` variable only but we have to follow the specific order of directions when we move. ```order : down, left, up, right```
	- Link: [https://algorithms.tutorialhorizon.com/backtracking-rat-in-a-maze-puzzle/](http://)

2. Next question

#### Binary search
1. Median of arrays
   - https://www.interviewbit.com/problems/median-of-array/
2.

#### Segment tree
1. https://cp-algorithms.com/data_structures/segment_tree.html
2.

#### General
1. Lexographically next permutation of sequence
	- https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/

#### Game Theory
1.
