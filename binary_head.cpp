# include <iostream>
# include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap{
    public:
        explicit BinaryHeap(int capacity = 100);
        explicit BinaryHeap(const vector<Comparable> & items);

        bool isEmpty() const;
        const Comparable& findMin() const;

        void insert(const Comparable& x);
        void insert (Comparable &&x);

        void deleteMin();
        void deleteMin(Comparable & minItem);
        void makeEmpty();

    private:
        int currentSize;
        vector<Comparable> array;
        void buildHeap();
        void percolateDown(int hole);
};

template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x){
    if (currentSize == array.size()-1)
        array.resize(array.size()*2);
    
    //percolate up
    int hole = ++currentSize;
    Comparable copy = x;

    array[0] = move(copy);
    for(;x<array[hole/2]; hole/=2)
        array[hole] = move(array[hole/2]);
    array[hole] = move(array[0]);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(){
    if (isEmpty())
        throw "UnderflowException{}";
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}


template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem){
    if( isEmpty( ) )
        throw "UnderflowException";

    minItem = std::move( array[ 1 ] );
    array[ 1 ] = std::move( array[ currentSize-- ] );
    percolateDown( 1 );
}

template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole){
    int child;
    Comparable tmp = move(array[hole]);

    for (; hole *2 <= currentSize; hole = child){
        child = hole*2;
        if (child != currentSize && array[child + 1] < array[child])
            ++child;
        if (array[child] < tmp)
            array[hole] = move(array[child]);
        else
            break;
    }
    array[hole] = move(tmp);
}

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> & items):array(items.size()+10),currentSize{items.size()} {
    for (int i =0; i < items.size();++i){
        array[i+1] = items[i];
    }
    buildHeap();
}

template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap(){
    for (int i = currentSize/2; i>0;--i)
        percolateDown(i);
}

template <typename Comparable>
const Comparable& BinaryHeap<Comparable>::findMin() const{
    if (!isEmpty())
        return array[1];
    else
        throw "empty heap";
}

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const{
    if (array.size() == 0)
        return true;
    else
        return false;
}


int main(){
    vector<int> heap;

    int k;
    for (int i =0;i<10;i++){
        cin>>k;
        heap.push_back(k);
    }

    BinaryHeap<int> b_heap(heap);

    b_heap.deleteMin();
    int j = b_heap.findMin();

    cout<<j<<endl;
}
