
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
    cout<<"��ѡ��";
    cin>>ch;
    my_show(ch);
}






//�Ӻ���
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

        p=t;         //�嵽�������
    }

    else if (r){
        cout<<"��⵽����������Ѵ��ڣ������ǵ��ϼ�¼"<<end;
        r->name=t->name;
        r->tel_no=t->tel_no;
        r->arch=t->arch;

    }

    cout<<"�¼�¼������"<<endl;

}


Position find_list(Position t, _List head)//���ڼ���Ƿ��½ڵ����ظ�
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
