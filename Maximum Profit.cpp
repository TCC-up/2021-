#include<iostream> 
#include<limits.h> 
#include<time.h>

using namespace std;
const int N=2e5; //2*10的5次方 
int p[N];     //定义数组 

int main(){
	
   int n;
   cin>>n;
   	for(int i=0;i<n;i++){
   	  	 cin>>p[i];
		 }              //输入           
   int minval=p[0];     //第一个作最小 
   int maxval=INT_MIN;   //整型最小，在time.h头文件里面 
   
   	for(int i=1;i<n;i++){
   	   maxval=max(maxval,p[i]-minval);  //max和min直接在iostream里面 
   	   minval=min(minval,p[i]);       //遍历每一取最小 
	}
	cout<<maxval<<endl;
  return 0;
} 
