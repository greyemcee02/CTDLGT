#include<bits/stdc++.h>
using namespace std;
int N, OK = 0, A[11];
void in(){
    for(int i=1;i<=N;i++) cout << A[i] << " ";
    cout << endl;
}
void sinh(){
    int i = N-1, j, t;
    while(A[i] > A[i+1]) i--;
    if(i==0) OK = 1;
    else{
        j = N;
        while(A[j] < A[i]) j--;
        t = A[i]; A[i] = A[j]; A[j] = t;
        int d = i+1, c= N;
        while(d<c){
            t = A[d]; A[d] = A[c]; A[c] = t;
            d++; c--;
        }
    }
}
main(){
    cin >> N;
    for(int i=1;i<=N;i++) A[i] = i;
    while(!OK){
        in();
        sinh();
    }
}
