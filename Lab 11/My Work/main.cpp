#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define Edge 22

class Kruskal{
public:
    Kruskal();
    static bool sort_func(const vector<int>& ei,const vector<int>& ej);
    vector<pair<int,int> > min_span();
private:
    vector<vector<int> > M;

};


Kruskal::Kruskal(){
    vector<vector<int> > tmp(Edge,{0,0,0,0,0,0,0,0,0,0,0,0});
    int i=0;
    tmp[i]['C'-'A']=tmp[i]['E'-'A']=i+1;
    ++i;
    tmp[i]['H'-'A']=tmp[i]['I'-'A']=i+1;
    ++i;
    tmp[i]['G'-'A']=tmp[i]['I'-'A']=i+1;
    ++i;
    tmp[i]['F'-'A']=tmp[i]['G'-'A']=i+1;
    ++i;
    tmp[i]['B'-'A']=tmp[i]['E'-'A']=i+1;
    ++i;
    tmp[i]['E'-'A']=tmp[i]['H'-'A']=i+1;
    ++i;
    tmp[i]['B'-'A']=tmp[i]['C'-'A']=i+1;
    ++i;
    tmp[i]['H'-'A']=tmp[i]['K'-'A']=i+1;
    ++i;
    tmp[i]['H'-'A']=tmp[i]['L'-'A']=i+1;
    ++i;
    tmp[i]['D'-'A']=tmp[i]['E'-'A']=i+1;
    ++i;
    tmp[i]['G'-'A']=tmp[i]['H'-'A']=i+1;
    ++i;
    tmp[i]['I'-'A']=tmp[i]['K'-'A']=i+1;
    ++i;
    tmp[i]['B'-'A']=tmp[i]['D'-'A']=i+1;
    ++i;
    tmp[i]['D'-'A']=tmp[i]['F'-'A']=i+1;
    ++i;
    tmp[i]['E'-'A']=tmp[i]['G'-'A']=i+1;
    ++i;
    tmp[i]['K'-'A']=tmp[i]['L'-'A']=i+1;
    ++i;
    tmp[i]['J'-'A']=tmp[i]['K'-'A']=i+1;
    ++i;
    tmp[i]['I'-'A']=tmp[i]['J'-'A']=i+1;
    ++i;
    tmp[i]['G'-'A']=tmp[i]['J'-'A']=i+1;
    ++i;
    tmp[i]['A'-'A']=tmp[i]['B'-'A']=i+1;
    ++i;
    tmp[i]['A'-'A']=tmp[i]['D'-'A']=i+1;
    ++i;
    tmp[i]['E'-'A']=tmp[i]['F'-'A']=i+1;

    M=tmp;


}
bool Kruskal::sort_func(const vector<int>& ei,const vector<int>& ej){
    int i,j;
    for (auto k:ei){
        if (k!=0){
            i=k;
            break;
        }
    }
    for (auto k:ej){
        if (k!=0){
            j=k;
            break;
        }
    }

    return i<j;
}
vector<pair<int,int> > Kruskal::min_span(){
    vector<pair<int,int> > res;

    map<int,int> set;
    for (int i = 0; i < 12; ++i)
        set.insert(pair<int,int>(i,i));


    sort(M.begin(),M.end(),sort_func);

    for (auto edge:M){
        int i=-1,j=-1;
        for (int k = 0; k < edge.size(); ++k) {
            if(edge[k]!=0){
                if (i==-1){
                    i=k;
                    continue;
                }
                j = k;
                break;
            }
        }
        if (set[i]==set[j])
            continue;
        else{
            res.push_back(pair<int,int>(i,j));
            auto si=set[i];
            for (auto iter=set.begin();iter!=set.end();++iter){
                if (iter->second==si)
                    iter->second=set[j];
            }
        }

    }
    return res;

}

int main() {
    Kruskal k;
    auto v=k.min_span();
    for (auto e:v)
        cout<<(char)(e.first+'A')<<"-"<<(char)(e.second+'A')<<endl;

    return 0;
}
