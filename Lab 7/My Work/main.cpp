#include <iostream>
#include <ctime>
#define Max_Size 21
using namespace std;

class Array{
public:
    explicit Array(const int *);
    void swap(int ,int);

protected:
    int* a;
    int size;
    int len;
};

class heap_sort:Array{
public:
    explicit heap_sort(int *);
    int Max(int,int,int);
    void Max_family(int);
    void construct();
    void sort();
    void print();
    void show();
};

Array::Array(const int *array) {
    a=new int[Max_Size];
    for (int i = 0; i < Max_Size-1; ++i)
        a[i+1]=array[i];
    size=len=Max_Size-1;
}
void Array::swap(int x,int y){
    int tmp=a[y];
    a[y]=a[x];
    a[x]=tmp;
}


heap_sort::heap_sort(int *in):Array(in){}
int heap_sort::Max(int x,int y,int z){
    if (a[x]>=a[y])
        return a[x]>=a[z]?x:z;
    else
        return a[y]>=a[z]?y:z;
}
void heap_sort::Max_family(int i){
    if(2*i>len)
        return;
    int tmp= 2*i==len ? Max(i,i,2*i):Max(i,2*i,2*i+1);
    if(i!=tmp){
        swap(i,tmp);
        Max_family(tmp);
    }
}
void heap_sort::construct(){
    for (int i = len; i >=1 ; --i)
        Max_family(i);
}
void heap_sort::sort(){
    while (len>=1){
        swap(1,len--);
        Max_family(1);
    }
}

void heap_sort::print(){
    for (int i = 1; i <= size; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
void heap_sort::show(){
    cout<<"input:";
    print();
    construct();
    cout<<"constructed:";
    print();
    sort();
    cout<<"sorted:";
    print();
}


int main() {
    int array[Max_Size-1];
    srand(time(nullptr));
    for (int & i : array)
        i=rand()%100;
    heap_sort a(array);
    a.show();

    return 0;
}