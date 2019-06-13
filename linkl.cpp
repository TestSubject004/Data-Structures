# include <iostream>
# include <string>
using namespace std;

class node{
public:
	string data;
	node* next;
};
class list{
public:
	list();
	~list();
	bool empty() const;
	const string& front () const;
	void add ();
	void remove();
	void display();
	node* head;
};
list::list()
{head=NULL;}

list::~list(){
node* old=head;
if (old==NULL){
cout<< "this list is empty \n";
return ;
}
while(head->next!=NULL){
remove();
}
remove();
delete head;
head==NULL;
}

void list::add(){
string p;
cin>>p;
node* v = new node;
v->data=p;
v->next= head;
head = v;
}

void list::remove(){
node* old = head;
if (old==NULL){
cout<< "this list is empty \n";
return ;
}
head = old->next;
delete old;
//if(head->next==NULL){
//head=NULL;
//return ;}
}

void list::display(){
node* d=head;
if (d==NULL){
cout<< "this list is empty \n";
return ;
}
while(d->next!=NULL){
cout<<d->data<<"\t counter \n";
d=d->next;}

cout<<d->data<<"\t counter \n";
}

int main(){
list l;
while (1){
int k;
cin>>k;
switch(k){
case 1:
	
	l.add();
	break;
case 2:
	l.remove();
	break;
case 3:
	l.display();
	break;
case 4:
	l.~list();
	break;
default:
//	l.~list();
	break;}

}
return 0;
}
