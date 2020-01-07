#include <iostream>
#include <queue>
#include <utility>
#include <vector>


using namespace std;

class Adjacency{
public:
    Adjacency();
    int in(int);
    vector<int> out(int);
private:
    vector<vector<bool> > M;
};
Adjacency::Adjacency(){
    M.resize(12);
    for (auto &i:M)
        i.resize(12);
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            M[i][j]= false;
        }
    }
    M[2][3]=M[7][3]=M[7][8]=M[8][9]=M[3][0]=M[3][4]=M[3][5]=M[9][5]=M[0][1]=M[1][4]=M[5][4]=M[5][6]=M[6][4]=M[5][10]=M[10][11]=M[6][11]=true;

}

int Adjacency::in(int j){
    int ans=0;
    for (int i = 0; i < 12; ++i) {
        if(M[i][j])
            ans++;
    }
    return ans;
}

vector<int> Adjacency::out(int i){
    vector<int> ans;
    for (int j = 0; j < 12; ++j) {
        if(M[i][j])
            ans.push_back(j);
    }

    return ans;
}


class Topological{
public:
    explicit Topological(Adjacency);
    vector<int> sort();
private:
    Adjacency G;
};
Topological::Topological(Adjacency Graph){
    G=move(Graph);
}
vector<int> Topological::sort(){
    vector<int> ans;
    ans.reserve(12);
    queue<int> Q;
    vector<pair<int,int> > in_degree;
    in_degree.reserve(12);
    for (int i = 0; i < 12; ++i) {
        int tmp=G.in(i);
        if (tmp==0)
            Q.push(i);
        in_degree.emplace_back(pair<int,int>(i,tmp));


    }

    while (!Q.empty()){
        int v=Q.front();
        ans.push_back(v);
        Q.pop();
        for (auto j:G.out(v)){
            for (auto &t:in_degree){
                if(t.first==j){
                    t.second--;
                    if (t.second==0)
                        Q.push(t.first);
                    break;
                }
            }
        }
    }

    return ans;
}




int main(){
    Adjacency G;
    Topological T(G);

    auto a=T.sort();

    for (auto i:a)
        cout<<char(i+'A')<<" ";
    cout<<endl;

}