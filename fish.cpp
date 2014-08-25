// prob: Fish 
// url : https://codility.com/c/intro/demoSBVAHF-2KD
// lang: C++-11

#include <stack>


size_t solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    
    //sanity check 
    if ( A.size() <= 1 || B.size() <= 1)
        return 1;
    if ( A.size() != B.size() )
        return -1; //error
    
    
    //stack<int> upfishes; - we used 'int alive' instead of a stack. A single int is enough.
    stack<int> downfishes;
    
    //first find the first fish that is going down.
    size_t i = 0;
    while (B[i] != 1 && i < B.size()) 
        ++i;
    
    //all fishes will be alive if they are ALL going up
    if (i == B.size()) 
        return i;
    
    //count all the alive fishes but ignore them in the eating game.
    int alive = i;
    
    
    for ( ; i < B.size(); ++i )
    {
        if ( B[i] == 1 )
            downfishes.push(A[i]);
        else
        {
            ++alive;
            
            //a fish going up can eat all smaller fishes in the stack
            while ( downfishes.size() > 0 && downfishes.top() < A[i] )
                downfishes.pop();
            //if a fish is going up but gets stoped by a bigger fish then that big fish eats it.
            if ( downfishes.size() > 0 )
                --alive;
        }
    }
    
    return downfishes.size() + alive;
}