//以链表记录

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct person_node{
    //string name;
    char name[20];
    char tel_no[15];
    char arch;
    person_node* next;
};



typedef struct person_node * ptrtonode;

typedef ptrtonode Position;
typedef ptrtonode _List;
_List Head;




void Show();
void Delete ();
void Input();
void Alter();
void Done();
void Showall();

int main()
{

    Head=(person_node*)malloc(sizeof(struct person_node));  //链表头结点
    Head->next=NULL;

    char ch;
    while(1){

    printf("          **********************************************************");
    printf("\n\n\n\n\t                         欢迎来到通讯录！");
    printf("\n\n\t\t                  请选择操作:");
    printf("\n\t\t1.                显示通讯录");
    printf("\n\t\t2.                添加通讯录");
    printf("\n\t\t3.                show all");
    printf("\n\t\t4.                删除记录\n");
    printf("\n\t\t5.                修改记录\n");
    printf("\n\t\t0.                退出\n");
    printf("          **********************************************************");
    printf("\n\n\n");
    printf("\t        选择您想要的操作:");

    cin>>ch;
    if (ch=='0')
    {
        Done();
        return 0;
    }
    switch(ch){
        case '1': Show();break;
        case '4': Delete();break;
        case '2': Input();break;
        case '3': Showall();break;
        case '5': Alter();break;
        //case 5: Done();break;
        default:
                printf("\n\t*********************************\n");
        printf("\n\t The num should 1-5!!! \n");
        printf("\n\t**********************************");
        break;
    }

    }
    return 0;

}


void Delete(){

    Position find_list(char *s, const _List head);

    char d_name[20];
    cout<<"要删除的姓名："<<endl;
    cin>>d_name;

    Position p=find_list(d_name,Head);

    //findprevious p1
    Position p1=Head;
    while(p1->next!=NULL&& p1->next!=p )
        p1=p1->next;

    if (p1->next!=NULL)
    {
        p1->next=p->next;
        p->next=NULL;
        free(p);
    }






}

void Alter(){

    Position find_list(char *s, const _List head);
    char A_name[20];
    cout<<"要修改的姓名："<<endl;
    cin>>A_name;

    Position p=find_list(A_name,Head);
    cout<<p->name<<endl;
    cout<<p->tel_no<<endl;
    cout<<"请重新输入:"<<endl;

      cout<<"name: "<<endl;
    cin>>p->name;
    cout<<"which arch: 'A' for family; 'B' for friend:"<<endl;
    cin>>p->arch;
    cout<<"telephone number:"<<endl;
    cin>>p->tel_no;

    cout<<"修改完成"<<endl;


}

void Done(){
    cout<<"thanks for using"<<endl;
}

void Input(){

    void Insert(Position t, _List head);

    Position tmpcell;
    tmpcell=(Position)malloc( sizeof( struct person_node));
    if (tmpcell==NULL)
        cout<<"Input error: out of space ";


    cout<<"name: "<<endl;
    cin>>tmpcell->name;
    cout<<"which arch: 'A' for family; 'B' for friend:"<<endl;
    cin>>tmpcell->arch;
    cout<<"telephone number:"<<endl;
    cin>>tmpcell->tel_no;

    tmpcell->next=NULL;

    Insert(tmpcell,Head);

}


void Show(){

    void my_show(char);
    char ch;
    cout<<"which arch you want to show:"<<endl;
    cout<<"     A: family; B: friend "<<endl;
    cout<<"请选择：";
    cin>>ch;
    my_show(ch);
}






//子函数
void Insert(Position t, const _List head){

    Position find_list(Position t, _List head);
    Position p=head;//p=p->head
    Position r;
/*
    if(head->next==NULL)
        head->next=t;
    else if ((r=find_list(t,head))==NULL)
    {
        while (p!=NULL)
            p=p->next;


        p=t;         //插到链表最后
    }
*/
    if ((r=find_list(t,head))) {
        cout<<"检测到姓名或号码已存在，将覆盖掉老记录"<<endl;
        strcpy(r->name,t->name);
        strcpy(r->tel_no,t->tel_no);
        r->arch=t->arch;

    }

    else
    {
        while((p->next)!=NULL)    //sss指向最后一个节点
            p=p->next;

        p->next=t;
    }

    cout<<"新记录添加完成"<<endl;

}


Position find_list(Position t,const _List head)//用于检测是否新节点有重复
{

    Position p=head->next;
    while(p!=NULL && strcmp(t->name,p->name) && strcmp(t->tel_no,p->tel_no) )//&&strcmp(t->tel_no,p->tel_no)!=0 )
    p=p->next;

    return p;
}

Position find_list(char *s, const _List head)
{
    Position p=head->next;
    while(p!=NULL && strcmp(s,p->name) && strcmp(s,p->tel_no) )//&&strcmp(t->tel_no,p->tel_no)!=0 )
    p=p->next;

    return p;

}


void my_show(char c){

    Position p=Head->next;
    while(p!=NULL){
        if(p->arch==c)
        {
            cout<<p->name<<endl;
            cout<<p->tel_no<<endl;
        }

        p=p->next;
    }
}


void Showall(){
    Position p=Head->next;
    cout<<"all record:"<<endl;
    while (p!=NULL){
        cout<<p->name<<endl;
            cout<<p->tel_no<<endl;
            p=p->next;

    }
}
