#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
bool isDegital(string str) {
    for (int i = 0;i < str.size();i++) {
        if (str.at(i) == '-' && str.size() > 1)  // �п��ܳ��ָ���
            continue;
        if (str.at(i) > '9' || str.at(i) < '0')
            return false;
    }                   //�ж�һ��string�Ƿ�Ϊ���ֵ�ģ�麯�� 
    return true;
}
int main(){
	stack<int> s;
	string c;
	int a,b;
	int p;
	while(cin>>c){	
	//c =getchar();
	if(isDegital(c)){  //Ϊ���� 
		stringstream ss;
		ss<<c;
		int temp;
		ss>>temp;      //���������ת�� 
		s.push(temp);   //���� int result = atoi��c.c_c()); 
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
	  s.pop();   //ɾ��ջ�� 
	  b=s.top();  
	  s.pop();
	  p=b-a;
	  s.push(p);
	}
	if(c=="*"){
	  a=s.top();
	  s.pop();   //ɾ��ջ�� 
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
 
