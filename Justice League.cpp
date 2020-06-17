// COMPARATOR FUNCTION.
bool comp(const pair<int,int> &p1,const pair<int,int> &p2) // returning 'false' will swap the elements
{
	if(p1.first==p2.first)
	{
		return p1.second<p2.second;
	}
	return p1.first<p2.first;
}

//C++ STRUCTURE :
typedef struct node
{
	int freq;
	struct node*left,*right;
	// Constructor
	node(int f,node*left,node*right):
	freq(f),left(left),right(right){}

	// Constructor
	node(int f,node*l, node*r)
	{
		freq = f;
		left = l;
		right = r;
	}
	// Method
	void function_name(arguements)
	{

	}
}Node;

// sprintf() : Can use it to convert something to string
	int sprintf(char*buffer,char*format,...)
	- char stg[MAX];
	  int a=10,b=20;
	  sprintf(stg,"a=%d,b=%d",a,b);
	- returns the no. chars written to string 'stg'.
	- Use : convert int to stg
	  sprintf(stg,"%d",cnt);

//Algorithms:
	accumulate(start,end,init);// accumulate(v.begin(),v.end(),sum) accumulate(arr,arr+n,sum);
	int val=atoi(char* s); // change string containing numbers only to 'int' or 'long long int' type
	string s= itoa(int num);// changes no. to string.
										size();
										empty();
passing of vector : int build_tree(vii tree)  -> not efficient
					int build_tree(vii &tree)   -> correct

Macros:
	- #define tr(cont, it) for(typeof(cont.begin()) it = cont.begin(); it != cont.end(); it++)
	- #define all(v) v.begin,v.end() // range of the container


iterators:
	// Defining iterator of any type:  container_type::iterator it;
	vector< int >::iterator it = v.begin();
	vector< int >::const_iterator it = v.begin();
	vector< int >::reverse_iterator it = v.rbegin();
	// other way of defining iterator
	typeof(v.begin()) it = v.begin();
	// Traversing any iterator
	for( typeof(container.begin()) it = container.begin(); it != container.end(); it++)
	// important macro
	#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it!= container.end(); it++)

pair:
	pair< int, int > p;
	pair< int, int > p('first', 'second');
	pair< int, int > p1 = p2;
	pair< int, int > p1(p2);
	p.first; p.second;
	p = make_pair('first', 'second');
	if(p1 == p2) // compare both elements, first compare 'first' element of both then 'second'.
	if(p1 != p2) // compare both elements 

vector:
	vector< int > v;  // creates empty vector
	vector< int > v(10, myvalue); // creates vector of size 10, initialized with myvalue
	vector< int > v[10]; // creates array of vector< int > , size is 10 and all are empty vectors.
	vector< vector< int > > v(N, vector< int >(M, myvalue)) // vector of vector 
	vector< int > v2 = v;   // initialization copy elments of v to v2
	vector< int > v2(v);    // same as above
	vector< int > v2( v.begin(), v.end()); // intialize vector v2 with elements in range (v.begin(),v.end())
	vector< int > v2( arr, arr + N); // 'c' type array
	vector< int > v2( arr, arr + sizeof(arr)/sizeof(arr[0]));


	v.size();  
	v.empty(); 
	v.push_back(5);
	v.pop_back();
	v.clear(): // remove all elements from the vector
	int myfunction( vector< int > v);  // not efficient, a copy of vector will be generated
	int myfunction( vector< int >& v); // always pass vector as reference.
	v.begin(); v.end();  // iterator pointing to first and last elements
	v.rbegin(); v.rend(); // reverse iterator pointing to last and first element
	v.insert(idx, myelement); // insert myelement at position idx
	v.insert(idx, v2.begin(), v2.begin() + 5); // insert 5 elements of v2 at position idx of 'v'
	v.erase(iterator);  // erase the elements pointed by the iterator 
	v.erase(v.begin()+2, v.begin() + 5); // erase the range specified by the iterator

string :
	string s;
	string s = "manish";
	s = s + "rathi";
	s.length()    :O(1)
	s.append(str) : appends the str at end of string s
	s.append(int n,char c) : appends char 'c' n times 
	s+=c  		  : appends the char 'c' at end of string.
	s.push_back(char c) : appends 'c' at end. *** best
	// Erase 
	s.pop_back()  : delete last char /remove char from end
	s.erase(postion, len): deletes the char starting at the position and upto the length 'len'.
	
	s.substr(pos, len); // returns the copy of substring starting at 'pos' and of length 'pos'



List :
	list<int> my_list;
	my_list.push_front(1);
	my_list.push_back(2);
	my_list.pop_front(3);
	my_list.pop_back(4);
	my_list.front();
	my_list.back();
	my_list.insert(iterator pos, int item);
	my_list.erase(iterator pos);
	my_list.reverse();
	my_list.sort();
	***my_list.empty();***

Deque: DOUBLE ENDED QUEUE
	deque<int> d;
	d.push_front(1);
	d.push_back(2);
	d.pop_front(2);
	d.pop_back(2);
	d.front();
	d.back();

Stack : STACK IS ALSO 'CONTAINER ADAPTOR' , IT IS A LAYER ABOVE THE UNDERLYING DEQUEUE CONTAINER
	stack<int> s;
	s.push(1);
	s.pop(2);
	s.top();
	s.size();
	s.empty();

Queue : Queue is CONTAINER ADAPTOR , IT IS A LAYER ABOVE THE UNDERLYING DEQUEUE CONTAINER
	queue<int> q;
	q.push(1);
	q.pop();    **its return type is Void 
	q.front();
	q.empty();
	q.size();

Priority_queue : By default Max Heap
	priority_queue<int> p;
	p.push(2);
	p.pop(); -> it donot oreturn the top element just delete it 
	p.top();
	p.empty(); p.size();
	priority_queue<int, vector<int> ,less<int> > p ; =>MAX Heap
	priority_queue<int, vector<int> ,greater<int> > p ; =>MIN Heap
	prioriy_queue< my_struct, vector<my_struct> , my_comp> pq;
	struct my_comp
	{
		bool operator()(const my_struct &p,const my_struct &q)
		{
			return p.a < q.a ; // MAX heap
			return p.a> q.a  ; // MIN heap
		}
	}

set/multiset/unordered_set/unordered_multiset : 
	set<int> s;
	s.insert(42)   : logn
	s.erase(42)    : logn
	s.erase(s.find(42))
	s.insert(42)   : nothing happens no duplicacy allowed
	s.find(42)     : logn , returns ITERATOR 
	multiset<int>
	s.size(); // returns the count of elements, unsigned_int so careful.

	set<int > s(arr, arr + n);
	set< int > s(v.begin(),v.end());
	vector< int > v(s.begin(), s.end()); // all duplicates removed and array is sorted.

map/multimap/unordered_map/unordered_multimap:
	map<string,int> m  : 	(key,value) pair and KEY CANNOT BE DUPLICATE
	m.insert(make_pair("TOP",2))  : logn 
	m.erase(key)				  : logn
	m.erase(iterator)
	m .find(key); -> returns ITERATOR (pointer) to the corresponding node(pair) :logn 
    	//Accessing value corresponding to the key
    	it = m.find("TOP");
    	int x = it->second;  or int x = m["TOP"];
  	
  	//multimap<string,int>: allows duplicate keys to be inserted in the map.
  	//- operator []: using operator [] creates a key in the map
  	m["mykey"]; // default value = 0
  	// operator [] cannot be used with 'const map<int,int> m' because [] operator can alter0 value of map




