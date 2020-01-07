#include <iostream>
#include <iomanip>
#include <ctime>

#define Max_size 9
#define LEFT 1
#define RIGHT 2

using namespace std;
struct Node{
    int value;
    int id;
    Node* next;
    explicit Node(int v=-1,int i=-1,Node* n= nullptr):value(v),id(i),next(n){}
};
typedef Node ValueType;

class min_heap{
public:
    min_heap();
    ~min_heap();

    int Swap(int,int);
    int Min(int,int,int);
    int Max(int,int,int);

    ValueType top();
    void pop();
    void push(ValueType);
    void clear();
    bool empty();
    void show_by_array();
    void show_by_tree();
    void show_by_tree(int,int,int);

private:
    ValueType* root;
    int size;
};
min_heap::min_heap():size(0){
    root=new ValueType[Max_size];
    root[0]=Node();
}
min_heap::~min_heap(){
    clear();
}
int min_heap::Swap(int i,int j){
    ValueType tmp=root[i];
    root[i]=root[j];
    root[j]=tmp;

    return j;
}
int min_heap::Min(int i,int j,int k){
    if(root[i].value<=root[j].value)
        return root[i].value<=root[k].value?i:k;
    else
        return root[j].value<root[k].value?j:k;

}
int min_heap::Max(int i,int j,int k){
    if(root[i].value>=root[j].value)
        return root[i].value>=root[k].value?i:k;
    else
        return root[j].value>root[k].value?j:k;

}
ValueType min_heap::top(){
    return root[1];
}
void min_heap::pop(){
    if(size==0||size==1){
        size=0;
        return;
    }
    root[1]=root[size--];
    int i=1;
    int i_pre=0;

    while (i!=i_pre){
        i_pre=i;
        if(size>=2*i+1)
            i=Swap(i,Min(i,2*i,2*i+1));
        else if(size==2*i)
            i=Swap(i,Min(i,2*i,2*i));
    }
}
void min_heap::push(ValueType v){
    root[++size]=v;
    if(size==1)
        return;
    int i=size;
    int i_pre=0;
    while(i!=i_pre&&i!=1){
        i_pre=i;
        i=Swap(i,Max(i,i/2,i/2));
    }
}
void min_heap::clear(){
    delete root;
}
bool min_heap::empty() {
    return size==0;
}

void min_heap::show_by_array(){
    for (int i = 1; i <= size; ++i){
        cout<< root[i].value;
        if (i!=size)
            cout<<"-";
    }
    cout<<endl;

}
void min_heap::show_by_tree(){
    show_by_tree(1,0,0);
}
void min_heap::show_by_tree(int p,int l_r,int depth){
    if (2*p+1<=size)
        show_by_tree(2*p+1,RIGHT, depth+1);
    for (int i = 0; i < depth; ++i) {
        cout<<"        ";
    }
    if (l_r==LEFT)
        cout<<"\\----";
    if (l_r==RIGHT)
        cout<<"/----";

    cout<<root[p].id<<"th:"<<"["<<root[p].value<<"]"<<endl;

    if (2*p<=size)
        show_by_tree(2*p,LEFT, depth+1);
}


class Queue{
public:
    Queue();
    void cons(int *,int);
    ~Queue();
    void push(Node);
    Node top();
    void clear();

    void show();
    static int id_number;

private:
    Node* head;
    Node* tail;
    int id;
};
int Queue::id_number=0;

Queue::Queue():head(nullptr),tail(nullptr),id(id_number++){
}
void Queue::cons(int * a,int size) {
    clear();
    Node* p=new Node(a[0],id);
    head=p;
    for (int i = 1; i < size; ++i) {
        p->next=new Node(a[i],id);
        p=p->next;
    }
    tail=p;
}
Queue::~Queue(){
    clear();
}
void Queue::clear(){
    if (head== nullptr)
        return;
    while (head!=tail){
        Node* p=head;
        head=head->next;
        delete p;
    }
    delete head;
    head=tail=nullptr;
}
void Queue::push(Node n){
    if(head== nullptr){
        head=tail=new Node(n.value,id);
        return;
    }

    tail->next=new Node(n.value,id);
    tail=tail->next;
}
Node Queue::top(){
    return *head;
}
void Queue::show() {
    Node* p=head;
    while (p!= nullptr){
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;
}


int main() {
    int ary[8][15];
    int n=0;
    for (auto & i : ary) {
        for (int &j : i) {
            j = n++;
        }
    }

    Queue* qq=new Queue[8];
    for (int i = 0; i < 8; ++i)
        qq[i].cons(ary[i],15);

    Queue res;
    min_heap heap;

    for (int i = 0; i < 8 ; ++i)
        heap.push(qq[i].top());

    while (!heap.empty()){
        res.push(heap.top());
        Node* tmp=heap.top().next;
        heap.pop();
        if (tmp!= nullptr)
            heap.push(*tmp);
    }
    res.show();
}