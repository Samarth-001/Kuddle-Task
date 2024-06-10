// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int test;
    cin>>test;
    int n,k;
    for(int t=0;t<test;t++){
        
        cin>>n;
        cin>>k;
        int a[n] = {0};
        int b[n] = {0};
        int maximum = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maximum = max(maximum,a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int c[maximum+1] = {0};
        
        for(int i=0 ; i<n; i++ ){
            if(a[a[i]]<b[i]){
            c[i] = b[i];
            }
        }
        
        for(int i=0; i<n; i++){
            int ind = i;
            for(int j=0;j<n;j++){
                if(c[j]<c[ind]){
                    ind = j;
                }
            }
            int temp = c[i];
            c[i] = c[ind];
            c[ind] = temp;
        }
        
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += c[i];
        }
        cout << sum;
    }    
        
    return 0;
}