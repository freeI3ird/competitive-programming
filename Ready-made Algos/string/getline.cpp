#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	string stg;
	getline(cin, stg); // Read from stream until EOF is reached or \n or delimeter char (if provided)
	cout<<stg<<endl;;
	getline(cin, stg,',');  // Delimeter char is used
	cout<<stg;
    while(getline(cin,stg))
    {
        cout<<stg<<endl;
    }
    while(getline(cin,stg, ','))
    {
        cout<<stg<<endl;
    }
    
	return 0;
}