
struct person_node{
    string name;
    string tel_no;
    char arch;
    person_node* next;
};

void Input(){

    Insert();

    Position tmpcell;
    tmpcell=malloc( sizeof( struct person_node));
    if (tmpcell==NULL)
        cout<<"Input error: out of space ";

    cout<<"name: "<<endl;
    cin>>tmpcell->name;
    cout<<"telephone number:"<<endl;
    cin>>tmpcell->tel_no;
    cout<<"which arch: 'A' for family; 'B' for friend:"<<endl;
    cin>>tmpcell->arch;
    tmpcell->next=NULL;

    Insert(tmpcell,_List);

}


void Show(){

    my_show();
    char ch;
    cout<<"which arch you want to show:"<<endl;
    cout<<"     A: family; B: friend "<<endl;
    cout<<"请选择：";
    cin>>ch;
    my_show(ch);
}






//子函数
void Insert(Position t,_List head){

    find_list(Position t, _List head);
    Position p=head->next;
    Position r;

    if(p==NULL)
        p=t;
    else if ((r=find_list(t,head))!=NULL)
    {
        while (p!=NULL)
            p=p->next;

        p=t;         //插到链表最后
    }

    else if (r){
        cout<<"检测到姓名或号码已存在，将覆盖掉老记录"<<end;
        r->name=t->name;
        r->tel_no=t->tel_no;
        r->arch=t->arch;

    }

    cout<<"新记录添加完成"<<endl;

}


Position find_list(Position t, _List head)//用于检测是否新节点有重复
{

    Position p=head->next;
    while(p!=NULL && strcmp(t->name,p->name)!=0 &&strcmp(t->tel_no,p->tel_no)!=0 )
    p=p->next;

    return p;
}


void my_show(char c){

    Position p=_List->next;
    while(p!=NULL){
        if(p->arch==c)
        {
            cout<<p->name<<endl;
            cout<<p->tel_no<<endl;
        }

        p=p->next;
    }
}
