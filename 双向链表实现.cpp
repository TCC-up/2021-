#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cstdlib>
//�������� 
using namespace std;
struct Node{     //�������typedef? 
	int key;
	Node *prev;
	Node *next; 
};              //�ṹ�崴��һ���ڵ����˫��ָ������� 
Node *head;
//��ǰ���typedef��������Node,*LinkList=>ֱ�� Node *LinkList;���� 
// typedef struct{} Node;
// typedef struct{} *LinkList;
// Node *p <=> LinkList p    
//�����ı��������������������
 

// typedef int *point_int;
// point_int p; <=> int *p;
Node *listSearch(int key){   //�ڵ���� 
	Node *cur=head->next;
	//LinkList cur ;
	while(cur!=head&&cur->key!=key){ //�жϲ��ǻص�ͷ�ˣ�Ȼ��ֵ�ֲ����ϱ�׼ 
		cur= cur->next;
	}
	return cur;
}

void init(){       //��ʼ���ڵ� 
	head=new Node;    //��ȶ�̬���飿���ǻ����е㲻̫��� 
	head->prev=head;   //��ָ��ͷ 
	head->next=head;    
}
void printlist(){               //��ӡ���� 
	Node *cur =head->next;
	int isf=0;
	while(1){
		if(cur==head)break;
		if(isf++ >0)printf(" ");  //���ƿո���� 
		printf("%d",cur->key);
		cur=cur->next;   //node��ָ��cur 
	}
	printf("\n");
}
void insert(int key){         //����һ��������� 
	Node *x=new Node;
	x->key=key;
	x->next=head->next;
	head->next->prev=x;    //��ԭ���ڵ��·�����Ƶ�x; 
	head->next=x; 
	x->prev=head;          //���ı��˵�·�� 
}
void deleteNode(Node *t){     //ɾ���ڵ� 
	if(t==head)return;
	t->prev->next=t->next;
	t->next->prev=t->prev;  
    free(t);       //�ͷŽڵ�ռ� 
}
void deleteFirst(){            //ɾ����һ���ڵ� 
	deleteNode(head->next);
}
void deleteLast(){            //ɾ�����һ���ڵ� 
	deleteNode(head->prev);
}
void deletekey(int key){
	deleteNode(listSearch(key));
}
int main(){
	int key,n,i;
	char com[20];   //ָ���Ӧ 
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
