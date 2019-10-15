// this function is faster than the normal binary search, it takes few less operations to get to the required result

// A[] --> Array in which we need to search the key
// l --> leftmost index of array A[]
// r --> rightmost index of array A[]

int fast_BinarySearch(int A[], int l, int r, int key) 
{ 
    int m; 
  
    while( r - l > 1 ) 
    { 
        m = l + (r-l)/2; 
  
        if( A[m] <= key ) 
            l = m; 
        else
            r = m; 
    } 
  
    if( A[l] == key ) 
        return l; 
   else if( A[r] == key ) 
        return r; 
    else
        return -1; 
} 



