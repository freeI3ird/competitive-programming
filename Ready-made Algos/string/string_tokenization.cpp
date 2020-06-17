// Link: http://www.cplusplus.com/reference/cstring/strtok/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // strtok:   char* strtok(char* str, const char* delimeters)
     
    // Perform string tokenization: C style (Recommended)
    char stg[] = "Hello Friends, My name is free.bird.";
    const char* delim = " ,.";  // Any char of delimeter string will be used to tokenize.
    char*token ;
    // token = strtok(stg, " ,.");
    token = strtok(stg, delim);
    while(token != NULL)
    {
        printf("%s\n", token);
        // token = strtok(NULL," ,.");
        token = strtok(NULL, delim); 
    }
    
    // String tokenization: C++ style
    string stg2 = "I love Machine Learning, AI and coding";
    char*token2;
    // token2 = strtok(stg, " ,."); 
    // This gives error: expects char* given string
    
    // Way around to above problem
    token2 = strtok(&stg2[0], " ,.");
    while(token2!= NULL)
    {
        cout<<token2<<endl;
        token2 = strtok(NULL, " ,.");
    }

    //Tokenize Using stringstream and getline, but only 1 char can be used as delimeter
    string stg = "Hello Friends, My name is free.bird.";
    stringstream mystream(stg); // converts the string into stream.
    char delim = ' ';
    string temp;
    while(getline(strm, temp, delim))
    {
        cout<<temp<<endl;
    }

	return 0;
}