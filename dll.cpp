# include <iostream>
using namespace std;

class node{
public:
string data;
node* prev;
node* next;
};


class listop{
public:
listop();
~listop();
void add();
void remove();
void display();
node* search();
bool isempty();
void reverse();
node* head;
node* tail;
};

listop::listop(){
head= new node;
tail= new node;
head->next= tail;
tail->prev= head;
head->prev=NULL;
tail->next=NULL;
}

listop::~listop(){
if (isempty()){
		cout<<"list is empty\n";
		return;}
	while(head->next!=NULL){
	node* d = head;
	head=head->next;
	//head->next=head->next->next;
	delete d;}
delete tail;
	return;
}

void listop::reverse(){
	if (isempty()){
		cout<<"list is empty \n";
		return;
		}
listop p;
node* k;
k=head->next;
	//n=new node;
	while(k->next!=NULL){
		node* n;
		n=new node;
		n->prev=p.head;
		n->next=p.head->next;
		p.head->next->prev=n;
		p.head->next=n;
		n->data= k->data;
		k=k->next;}
p.display();
k=tail->prev;
node* m= p.tail->prev;
while(m->prev!=NULL){
k->data=m->data;
k=k->prev;
m=m->prev;
}
display();
p.~listop();
//p.display();
}

void listop::add(){

	string s;
	cin>>s;
	node* n;
	n=new node;

		n->prev=head;
		n->next=head->next;
		head->next->prev=n;
		head->next=n;
		n->data= s;
		return;

}

node* listop::search(){
	if (isempty()){
		cout<<"list is empty \n";
		return NULL;}
	string s;
	cin>>s;
	node* n;
	n=head->next;
	int i=0;
	while (n->data!=s){
		n=n->next;
		i++;
		if (n==tail){
			cout<< "element not found \n";
			return NULL;}
		
}

cout<<"element is at index\t"<<i<<"\t"<<n->data<<"\t"<<n<<"\n";
return n;
}

void listop::display(){
	if (isempty()){
		cout<<"list is empty\n";
		return;}
node* n=head->next;
while (n->next!=NULL){
cout<<"\n"<<n->data<<"\n";
n=n->next;
}
cout<<"---------------------- \n";
return;
}

bool listop::isempty(){
	if ((head->next==tail) && (tail->prev==head))
		return true;
	else 
		return false;
}

void listop::remove(){
	if (isempty()){
		cout<<"list is empty \n";
		return;}
int k;
cin>>k;
if (k==1){
	node* d = head->next;
	head->next->next->prev=head;
	head->next=head->next->next;
	delete d;
	return;
}
else{
	node* d= search();
	d->prev->next=d->next;
	d->next->prev=d->prev;
	//cout<<d->prev->next->data<<"\n";
	delete d;
return;
}
	}

int main(){
listop l;
while (1){
int i;
cin >>i;

switch (i){
case 1:
	l.add();
	break;
case 2:
	l.remove();
	break;
case 3:
	l.search();
	break;
case 4:
	l.display();
	break;
case 5:
	l.reverse();
	break;
default:
	break;
}

}
return 0;
}
