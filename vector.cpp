# include <iostream>
using namespace std;

class vector{
public:
vector();
void insert (int i, const int& s);
void remove (int k);
bool empty();
int size();
int& operator[](int i);
void reserve(int k);
int n;
int c;
int* a;

};

vector::vector(){
a=NULL;
n=0;
c=0;
}

bool vector::empty(){
return (n==0);
}

int vector::size(){
return n;
}

int& vector::operator[](int i){
return a[i];
}

void vector::reserve(int k){
int* q= new int[k];
if(!empty()){
for (int i=0;i<k;i++){
q[i]=a[i];
}}
int* l = a;
a=q;
q=l;
c=k;
delete [] q;
}

void vector::insert (int i, const int& s){
if (n>c){
reserve(2*size());}
if (c==0){
		reserve(10);}	
	
for (int g=size();g>i;g--){
a[g+1]=a[g];

}
a[i]=s;
n++;
}

void vector::remove(int k){
for (int i=k;i<size();i++)
a[i]= a[i+1];
n--;
}

int main(){
vector v;
while (1){
int i;
cin>>i;
if (i==1){
int k,l;
cin >>k>>l;
v.insert (k,l);
}
else if (i==2){
int i;
cin>>i;
v.remove(i);
}
else if(i==3){
cout<<v.size()<<endl;
}
else if (i==4){
int i;
cin>>i;
cout<< v[i];
}
else return 0;
}
}


