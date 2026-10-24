#include <iostream>
using namespace std;
struct node
{
    int PRN;
    char name[10];
    node*next;
};
class club
{
    public:
        node*pres;
        node*secr;
    club()
    {
        pres = secr = NULL;
    }    
    void create();
    void add();
    void delet();
    void display();
    void compute();
    void concate(club c1 , club c2);
};
void club ::create()
{
    int n ; 
    cout<<"enter the total no of student";
    cin>>n;
    for(int i = 0 ; i <n ; i++)
    {
        node*nn = new node;
        nn->next= NULL;
        cout<<"enter the PRN of student";
        cin>>nn->PRN;
        cout<<"enter the name of student";
        cin>>nn->name;
        if(pres == NULL)
        {
            pres = secr = nn;
        }
        else
        {
            secr->next = nn;
            secr = nn;
        }
    }
}
void club:: add()
{
    int choice;
    cout<<"\n1.presedent";
    cout<<"\n2.memeber";
    cout<<"\n3.secreatry";
    cout<<"\nenter ur choice";
    cin>>choice;
    node*nn = new node;
    nn->next = NULL;
    cout<<"enter the PRN of student";
    cin>>nn->PRN;
    cout<<"enter the name of student";
    cin>>nn->name;
    if(choice == 1)
    {
        nn->next = pres;
        pres = nn;
    }
    else if(choice == 2)
    {
        if(pres == NULL)
        {
            pres = secr = nn;
        }
        else
        {
           int key;
            node*temp = pres;
           cout<<"enter the PRN of student after which u want to add";
           cin>>key;
           while(temp->next->PRN != NULL)
           {
                temp = temp->next;
           }
           nn = temp->next;
           temp->next = nn;
           cout<<"student added successfully"; 
        }
        
    }
    else if(choice == 3)
    {
        if(pres == NULL)
        {
            pres = secr = nn;
        }
        else
        {
            secr->next = nn;
            secr = nn;
        }
        cout<<"student added successfully";
    }
    else
    {
        cout<<"invalid choice";
    }
}
void club::delet()
{
    cout<<"delete the student";
    int choice;
    cout<<"\n1.presedent";
    cout<<"\n2.memeber";
    cout<<"\n3.secreatry";
    cout<<"\nenter ur choice";
    cin>>choice;
    node*temp,*temp1;
    if(choice == 1)
    {
        if(pres == NULL)
        {
            cout<<"empty list";
        }
        temp = pres;
        pres = pres->next;
        delete temp;
    }

    else if(choice == 2)
    {
        
        temp = pres;
        int key;
        if(pres == NULL)
        {
            cout<<"empty list";
        }
        cout<<"enter the PRN of student which u want to delete";
        cin>>key;
        while(temp->next->PRN != key)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        cout<<"student deleted successfully";
    }
    else if(choice == 3)
    {
        if(pres == NULL)
        {
            cout<<"empty list";
        }
        temp = pres;
        while(temp->next != secr)
        {
            temp = temp->next;
        }
        temp1 = secr;
        temp->next = NULL;
        secr = temp;
        delete temp1;
    }
    else
    {
        cout<<"invalid choice";
    }
}
void club :: compute()
{
    int count = 0;
    node*temp=pres;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    cout<<"total number of students: "<<count<<endl;
}
void club::concate(club c1 , club c2)
{
    node*temp = c1.pres;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = c2.pres;
    c1.display();

}
void club::display()
{
    node*temp = pres;
    if(pres == NULL)
    {
        cout<<"empty list";
    }
    else
    {
        cout<<"\nPRN\tName\n";
        while(temp != NULL)
        {
            cout<<"\n"<<temp->PRN<<" \t"<<temp->name<<endl;
            temp = temp->next;
        }
    }
}

int main()
{
    club c1,c2;
    int choice;
    char ch;
    do
    {
        cout<<"\n\n******Menu******";
        cout<<"\n\n1.create";
        cout<<"\n2.add";
        cout<<"\n3.delete";
        cout<<"\n4.display";
        cout<<"\n5.compute";
        cout<<"\n6.concatenate";
        cout<<"\nenter your choice";
        cin>>choice;
        switch(choice)
        {
            case 1:
                c1.create();
                c1.display();
                break;
            case 2:
                c1.add();
                c1.display();
                break;
            case 3:
                c1.delet();
                c1.display();
                break;
            case 4:
                c1.display();
                break;
            case 5:
                c1.compute();
                c1.display();
                break;
            case 6:
                c2.create();    
                c1.concate(c1,c2);
                c1.display();
                break;
            default:
                cout<<"invalid choice";
        }
        cout<<"\ndo you want to continue(y/n)";
        cin>>ch;
    }while(ch =='y');
        return 0;
}
