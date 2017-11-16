// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size()) {
        for(int i = 0; i < K; i++) {
            A.insert(A.begin(), A[A.size()-1]);
            A.erase(A.begin()+ A.size()-1);
        }
    }
    return A;
}
