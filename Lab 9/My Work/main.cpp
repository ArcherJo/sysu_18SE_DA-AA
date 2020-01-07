#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class HashTable{
public:
    HashTable();

    static unsigned int initial(unsigned int entry);
    static unsigned int jump(unsigned int entry);


    int hash_locate(unsigned int entry,size_t * probe_number=nullptr);

    int hash_insert(unsigned int entry);
    bool hash_erase(unsigned int entry);
    int hash_find(unsigned int entry);

    void show();


private:
    unsigned int hash_table[64];
    bool sign[64];
    size_t size;
    size_t probe;
};

HashTable::HashTable(){
    for (int i = 0; i < 64; ++i) {
        hash_table[i]=0;
        sign[i]=true;
    }
    size=probe=0;
}
unsigned int HashTable::initial(unsigned int entry){
    return entry & 63;
}
unsigned int HashTable::jump(unsigned int entry){
    return entry >> 18 | 1;
}

int HashTable::hash_locate(unsigned int entry,size_t * probe_number){
    unsigned int ini=HashTable::initial(entry);
    unsigned int j=HashTable::jump(entry);

    int pro=0;

    while (!sign[ini] && hash_table[ini]!=entry && pro<=64){
        ini=(ini+j) & 63;
        pro+=1;
    }

    if (probe_number)
        *probe_number=pro+1;

    return ini;//隐式转换
}
int HashTable::hash_insert(unsigned int entry){
    size_t pro;
    int index=hash_locate(entry,&pro);
    if (sign[index]){
        sign[index]= false;
        hash_table[index]=entry;
        probe+=pro;
        ++size;
        return index;
    }
    else return -1;

}
bool HashTable::hash_erase(unsigned int entry){
    int index=hash_locate(entry);

    if (!sign[index]){
        sign[index]=true;
        --size;
        return true;
    }
    else return false;
}
int HashTable::hash_find(unsigned int entry){
    int index=hash_locate(entry);

    return sign[index] ? -1 : index;
}
void HashTable::show() {
    for (int i = 0; i < 64; ++i) {
        cout<<i<<" -> [";
        if (sign[i])
            cout<<" ";
        else
            cout<<hash_table[i];
        cout<<"]"<<endl;
    }
    cout<<endl;

    cout<<"The size of hash is: "<<size<<endl;
    cout<<"The number of probes is: "<<probe<<endl;
    cout<<"So, the average number of probes is: probe/size = "<<(float)probe/size;
}

int main() {
    srand(time(0));
    HashTable h;

    for (int i = 0; i < 32; ++i) {
        unsigned int entry = rand()%(int)(pow(2,24));
        int index=h.hash_insert(entry);
        if (index!=-1)
            cout<<"Insert "<<entry<<" successfully in the index: "<<index<<endl;
        else
            cout<<"Can't insert the "<<entry<<endl;

    }
    cout<<endl;
    h.show();

}

