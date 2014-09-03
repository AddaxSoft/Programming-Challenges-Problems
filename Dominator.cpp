// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    
    //sanity check
    if (A.size() == 0)
        return -1;
    else if (A.size() <= 2)
        return 0;
    
    
    int size =0;
    int val = A[0];
    
    
    //get dominant element
    for (size_t i = 0; i < A.size(); i++)
    {
        if (size == 0)
        {
            size = 1;
            val = A[i];
        }
        else
        {
            if (val != A[i])
                size--;
            else
                size++;            
        }
    }
    
    if (size == 0)
        return -1;
        
    //counting dominant  element and return index of it whenever its occurrence is more than half of the vector/array
    int count =0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == val)
            count++;
        if( count > A.size()/2 )
            return i;
    }
    return -1;
}