#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cstdlib>
//环形链表？ 
using namespace std;
struct Node{     //如果想用typedef? 
	int key;
	Node *prev;
	Node *next; 
};              //结构体创建一个节点包含双向指针和数据 
Node *head;
//（前面加typedef）后面是Node,*LinkList=>直接 Node *LinkList;区别 
// typedef struct{} Node;
// typedef struct{} *LinkList;
// Node *p <=> LinkList p    
//定义别的变量的属性与变量的区别
 

// typedef int *point_int;
// point_int p; <=> int *p;
Node *listSearch(int key){   //节点遍历 
	Node *cur=head->next;
	//LinkList cur ;
	while(cur!=head&&cur->key!=key){ //判断不是回到头了？然后值又不符合标准 
		cur= cur->next;
	}
	return cur;
}

void init(){       //初始化节点 
	head=new Node;    //类比动态数组？但是还是有点不太清楚 
	head->prev=head;   //都指向头 
	head->next=head;    
}
void printlist(){               //打印链表 
	Node *cur =head->next;
	int isf=0;
	while(1){
		if(cur==head)break;
		if(isf++ >0)printf(" ");  //控制空格输出 
		printf("%d",cur->key);
		cur=cur->next;   //node的指针cur 
	}
	printf("\n");
}
void insert(int key){         //插入一个具体的数 
	Node *x=new Node;
	x->key=key;
	x->next=head->next;
	head->next->prev=x;    //把原来节点的路径复制到x; 
	head->next=x; 
	x->prev=head;          //更改别人的路径 
}
void deleteNode(Node *t){     //删除节点 
	if(t==head)return;
	t->prev->next=t->next;
	t->next->prev=t->prev;  
    free(t);       //释放节点空间 
}
void deleteFirst(){            //删除第一个节点 
	deleteNode(head->next);
}
void deleteLast(){            //删除最后一个节点 
	deleteNode(head->prev);
}
void deletekey(int key){
	deleteNode(listSearch(key));
}
int main(){
	int key,n,i;
	char com[20];   //指令对应 
	scanf("%d",&n);
	init();
	for(i=0;i<n;i++){
		scanf("%s%d",com,&key);
		if(com[0]=='i'){insert(key);}
		else if(com[0]=='d'){
			if(strlen(com)>6){
				if(com[6]=='F')deleteFirst();
				else if(com[6]=='L')deleteLast();
			}
		else{
			deletekey(key);
		}
		}
	}
	printlist();
	return 0;
}
