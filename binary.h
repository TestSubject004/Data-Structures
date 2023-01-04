#include <iostream>
#include <fstream>
#include <ostream>


template <typename Key>
class binary{
  public:
    binary():root{NULL}{};
    binary(const binary &b);
    binary(const binary &&b);
    ~binary();

    const Key &findMin() const;
    const Key &findMax() const;

    bool contains(const Key& b) const;
    void insert(const Key& b);
    void insert(Key&& b);
    void remove(const Key& b);
    void makeEmpty();

    bool isEmpty() const;
    void printTree(std::ostream &out = std::cout) const;

    binary& operator=(const binary& b){ root = b.root;}
    binary& operator=(binary&& b) {root = b.root;}

  private:
    struct node{
      Key elem;
      node* left;
      node* right;

      node(const Key& elem, node* left = NULL, node* right = NULL):
        elem{elem},left{left}, right{right} {}

      node(const Key&& elem, node* left = NULL, node* right = NULL):
        elem{std::move(elem)},left{left}, right{right} {}

    };
    
    node* root;
    void insert(const Key& a, node*& b);
    bool contains(const Key& a, node* b) const;
    void remove(const Key& b, node*& c);
    node* findMin(node* a) const;
    node* findMax(node* a) const;
    void printTree(std::ostream &out, node* a,std::string c) const;
    void makeEmpty(node*& a);


};



  
template <typename T>
binary<T>::binary(const binary& b){
  root = b.root;  
}


template <typename T>
binary<T>::binary(const binary&& b){
  root = b.root;  
}


template <typename T>
void binary<T>::insert(const T &b){
  insert(b, root); 
}


template <typename T>
void binary<T>::insert(T &&b){
  insert(b, root); 
}

template <typename T>
void binary<T>::insert(const T& a, node*& b){
  if(b==NULL){
    b = new node{a};
  }

  else if (a > b->elem){
    insert(a, b->right);
  }

  else{
    insert(a,b->left);
  }
}


template <typename T>
bool binary<T>::isEmpty() const{
  if(root == NULL) return true;
  else
    return false;
}


template <typename T>
bool binary<T>::contains(const T& b) const{
  //std::cout<<"entry \n";
  return contains(b, root);
}

template <typename T>
bool binary<T>::contains(const T& a,  node* b) const{
 if(b->elem == a) return true;
 else if (b->elem > a && b->left!=NULL) contains(a, b->left);
 else if(b->elem < a && b->right!=NULL) contains(a, b->right);
 else return false;
}



template <typename T>
void binary<T>::remove(const T& b){
  std::cout<<"entry \n";
  remove(b, root);
}


template <typename T>
void binary<T>::remove(const T& b, node*& c){
 if(c == NULL){
  std::cout<<"not found the object to remove \n";
  return;
 }
 else if (b>c->elem) remove(b,c->right);
 else if(b<c->elem) remove(b,c->left);

 if(c->right!=NULL && c->left != NULL){
   c->elem = findMin(c->right)->elem;
   remove(findMin(c->right)->elem, c->right);
 }

 else{
  node* old = c;
  c = (c->left!= NULL)? c->left : c->right;
  delete old;
 }

}

template <typename T>
void binary<T>::printTree(std::ostream &out)const{
  printTree(out,root,"----");
}

template <typename T>
void binary<T>::printTree(std::ostream &out, node* a,std::string c) const{
  //std::cout<<"flagged \n";
  out<<c<<a->elem<<"\n";
  std::string b = c+"|----";
  if(a->left!=NULL){
  
  
  printTree(out,a->left,b);
  }
  if(a->right!=NULL){
  
  printTree(out,a->right,b);
  }
}

template<typename T>
typename binary<T>::node* binary<T>::findMin(node* a) const{
  if (a==NULL){
    std::cout<<"empty";
    return NULL;

  }
  else if (a->left!=NULL) 
    return findMin(a->left);
  else
    return a;
}

template<typename T>
const T& binary<T>::findMin()const{
  return findMin(root)->elem;
}

template<typename T>
typename binary<T>::node* binary<T>::findMax(node* a) const{
  if (a==NULL){
    std::cout<<"empty";
    return NULL;

  }
  else if (a->right!=NULL)
     return findMax(a->right);
  else
     return a;
}

template<typename T>
const T& binary<T>::findMax()const{
  return findMax(root)->elem;
}


template<typename T>
void binary<T>::makeEmpty(){
  makeEmpty(root);
}

template<typename T>
void binary<T>::makeEmpty(node*& a){
  if(a!=NULL){
    makeEmpty(a->left);
    makeEmpty(a->right);
  }
  delete a;
  a= NULL;
}

template<typename T>
binary<T>::~binary(){
  makeEmpty();

}
