#include <iostream>
#include <iomanip>
#include <ctime>

#define Max_size 100
#define LEFT 1
#define RIGHT 2

using namespace std;
class min_heap{
public:
    min_heap();
    ~min_heap();

    int Swap(int,int);
    int Min(int,int,int);
    int Max(int,int,int);

    void pop();
    void push(int);
    void clear();
    void show_by_array();
    void show_by_tree();
    void show_by_tree(int,int,int);

private:
    int* root;
    unsigned int size;
};
min_heap::min_heap():size(0){
    root=new int[Max_size];
    root[0]=0;
}

min_heap::~min_heap(){
    clear();
}
int min_heap::Swap(int i,int j){
    int tmp=root[i];
    root[i]=root[j];
    root[j]=tmp;

    return j;
}
int min_heap::Min(int i,int j,int k){
    if(root[i]<=root[j])
        return root[i]<=root[k]?i:k;
    else
        return root[j]<root[k]?j:k;

}

int min_heap::Max(int i,int j,int k){
    if(root[i]>=root[j])
        return root[i]>=root[k]?i:k;
    else
        return root[j]>root[k]?j:k;

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

void min_heap::push(int v){
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

void min_heap::show_by_array(){
    for (int i = 1; i <= size; ++i){
        cout<< root[i];
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

    cout<<"  ["<<root[p]<<"]"<<endl;
    //cout<<"  ["<<setw(5)<<root[p]<<"]"<<endl;

    if (2*p<=size)
        show_by_tree(2*p,LEFT, depth+1);
}


int main() {
    if(true){
        min_heap m_heap;
        for (int i = 20 ; i>=2 ; i=i-2) //按从大到小的顺序push进20以下的偶数
            m_heap.push(i);
        m_heap.push(11);//push奇数11
        m_heap.show_by_array();
        m_heap.show_by_tree();
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;


    if(true){
        min_heap m_heap;
        for (int i = 2 ; i<=20 ; i=i+2) //按从小到大的顺序push进20以下的偶数
            m_heap.push(i);
        m_heap.push(11); //push进奇数11
        m_heap.show_by_array();
        m_heap.show_by_tree();

        for (int j = 0; j < 5; ++j) //只pop5次就可以了，全pop出去无法查看树形情况
            m_heap.pop();
        m_heap.show_by_array();
        m_heap.show_by_tree();
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;


    int nn=3;
    while(nn--){
        srand(time(nullptr));
        min_heap m_heap;
        int n=rand()%10+25; //操作次数由随机数决定
        while (n--){
            int flag=rand()%4; //每次操作由随机数决定操作类型
            if(flag!=0)
                m_heap.push(rand()%10000); //若为push则由随机数
            else
                m_heap.pop();
        }

        m_heap.show_by_array();
        m_heap.show_by_tree();
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }




}