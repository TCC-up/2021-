#include<iostream> 
#include<limits.h> 
#include<time.h>

using namespace std;
const int N=2e5; //2*10��5�η� 
int p[N];     //�������� 

int main(){
	
   int n;
   cin>>n;
   	for(int i=0;i<n;i++){
   	  	 cin>>p[i];
		 }              //����           
   int minval=p[0];     //��һ������С 
   int maxval=INT_MIN;   //������С����time.hͷ�ļ����� 
   
   	for(int i=1;i<n;i++){
   	   maxval=max(maxval,p[i]-minval);  //max��minֱ����iostream���� 
   	   minval=min(minval,p[i]);       //����ÿһȡ��С 
	}
	cout<<maxval<<endl;
  return 0;
} 
