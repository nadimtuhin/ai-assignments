// C++ program to find
// minimum number of prefix reversals
// to sort permutation of first N numbers
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the minimum prefix reversals
int minimumPrefixReversals(int a[], int n)
{
    string start = "";
    string destination = "", t, r;
    for (int i = 0; i < n; i++) {
        // converts the number to a character
        // and add  to string
        start += to_string(a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        destination += to_string(a[i]);
    }
 
    // Queue to store the pairs
    // of string and number of reversals
    queue<pair<string, int> > qu;
    pair<string, int> p;
 
    // Initially push the original string
    qu.push(make_pair(start, 0));
 
    // if original string is the destination string
    if (start == destination) {
        return 0;
    }
 
    // iterate till queue is empty
    while (!qu.empty()) {
 
        // pair at the top
        p = qu.front();
 
        // string
        t = p.first;
 
        // pop the top-most element
        qu.pop();
 
        // perform prefix reversals for all index and push
        // in the queue and check for the minimal
        for (int j = 2; j <= n; j++) {
            r = t;
 
            // reverse the string till prefix j
            reverse(r.begin(), r.begin() + j);
 
            // if after reversing the string from first i index
            // it is the destination
            if (r == destination) {
                return p.second + 1;
            }
 
            // push the number of reversals for string r
            qu.push(make_pair(r, p.second + 1));
        }
    }
}
 
// Driver Code
int main()
{
 
    int a[] = { 1, 2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
 
    // Calling function
    cout << minimumPrefixReversals(a, n);
 
    return 0;
}
