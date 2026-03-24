class Solution {
public:
    bool x(vector<vector<char>>& a,string &b,int i,int j,int k){
        if(k==b.size()) return true;
        if(i<0||j<0||i>=a.size()||j>=a[0].size()||a[i][j]!=b[k]) return false;
        char t=a[i][j];
        a[i][j]='#';
        bool p=x(a,b,i+1,j,k+1)||x(a,b,i-1,j,k+1)||x(a,b,i,j+1,k+1)||x(a,b,i,j-1,k+1);
        a[i][j]=t;
        return p;
    }
    bool exist(vector<vector<char>>& q,string w){
        int n=q.size(),m=q[0].size();
        for(int u=0;u<n;u++){
            for(int v=0;v<m;v++){
                if(x(q,w,u,v,0)) return true;
            }
        }
        return false;
    }
};