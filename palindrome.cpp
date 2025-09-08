#include <iostream>
using namespace std;
int main()
{
    string s;//madam
    cin>>s;
    int left=0,right=s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            cout<<"false"<<end;
            break;
        }
    }
    cout<<"true"<<endl;
    

    return 0;
}