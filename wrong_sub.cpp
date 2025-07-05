#include<bits/stdc++.h>
using namespace std;
 
 int wrong_subtraction(int num,int k){
    for (int i =0;i<k;i++){
        if(num%10==0){
            num=num/10;
        }
        else{
            num=num-1;
        }
    }
    return num;
 }
 
int main()
{
 
 int number,k;
//  cout<<"enter two number to be subtracted: ";
 cin>>number>>k;

 int ans=wrong_subtraction(number,k);
 cout<<ans;
 
return 0;
}