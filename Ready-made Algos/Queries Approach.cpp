/*
	During Journey ,many Queries Related Concepts and Questions are encountered those are mentioned here
*/
- Queries can be done using 'Segment tree', 'BIT','MO's ,other RMQ Concepts

1. KQuery : Queries (i,j,k): #Elements greater than 'k' in range a[i]....a[j]
	Solution: Offline 
	- Take an array b[], b[i]=(0/1) ,1=> means ith element is greater than 'k'
	- Make BIT or segment tree of b[],with b[i]=1 for all i.
	- Save the queries Offline and Sort a/c to 'k'
	- Now sort the original array.
	- Traverse the Queries,for each k of query
		- make all the b[i]=0 corresponding to elements <=k in sorted array
		- Then the remaining no. are greater than k
		- get sum of elements :Query(i,j)
2. Chef and Prime Queries: (same approach as above)

3. Merge sort Tree: Segement + sorted vector on each node, Can KQuery ONLNE:in O(q*logn*logn)
	Reference:https://discuss.codechef.com/questions/94448/merge-sort-tree-tutorial

4. Finding Sum of maximum element in all the 'Subsegments', total segments:n(n-1)/2 :O(n^2)
   - Construct a Segment tree 
   - Refer Imbalanced Array of Codeforces