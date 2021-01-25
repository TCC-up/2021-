#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
bool isDegital(string str) {
    for (int i = 0;i < str.size();i++) {
        if (str.at(i) == '-' && str.size() > 1)  // 有可能出现负数
            continue;
        if (str.at(i) > '9' || str.at(i) < '0')
            return false;
    }                   //判断一个string是否为数字的模块函数 
    return true;
}
int main(){
	stack<int> s;
	string c;
	int a,b;
	int p;
	while(cin>>c){	
	//c =getchar();
	if(isDegital(c)){  //为数字 
		stringstream ss;
		ss<<c;
		int temp;
		ss>>temp;      //输入输出流转化 
		s.push(temp);   //法二 int result = atoi（c.c_c()); 
	}
	if(c=="+"){
	  a=s.top();
	  s.pop();
	  b=s.top();
	  s.pop();
	  p=a+b;
	  s.push(p);	  
	}
	if(c=="-"){
	  a=s.top();
	  s.pop();   //删除栈顶 
	  b=s.top();  
	  s.pop();
	  p=b-a;
	  s.push(p);
	}
	if(c=="*"){
	  a=s.top();
	  s.pop();   //删除栈顶 
	  b=s.top();
	  s.pop();
	  p=b*a;
	  s.push(p);
	}
	if(cin.get()=='\n') break; 
	}
	cout<<s.top()<<endl;
	return 0;
}
 
