#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct DSU{
        vector<int> parent;

        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return false;

            parent[b]=a;
            return true;
        }
    };

    bool can(int X,int n,vector<vector<int>>& edges,int k){

        DSU dsu(n);
        int used=0;
        int upgrades=0;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s < X) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
        }

        vector<pair<int,int>> cand;

        for(int i=0;i<edges.size();i++){
            auto &e=edges[i];
            int s=e[2],must=e[3];

            if(must) continue;
            /*Add those edges whose strnegth are grater that current 
                strenth 
            */
            if(s>=X) cand.push_back({0,i});
            else if(2*s>=X) cand.push_back({1,i});
        }

        sort(cand.begin(),cand.end());

        for(auto &[cost,i]:cand){

            auto &e=edges[i];
            int u=e[0],v=e[1];

            if(dsu.unite(u,v)){
                upgrades+=cost;
                used++;
                if(upgrades>k) return false;
                if(used==n-1) return true;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
         /*
            first thing to notice is we must connetc all the edges that our must be 
            connected according to the problem statement 


            so from it all edges will have their own strength and they will not be
            upgraded so it will have a minimum strength let's say X 


            so now our main goal is to find some edges from the remaiing ones
            whose strength is strength>=X to maximise the answer

            or whose 2*strength >=X to maximse the answer and use K-1 operations for rest

            this is optimal thing to do 

        */

        /*
            Now to Connect edges one by one we can use dsu .....

            To maximise our minumum strength we can use binary search on answer
            becase we have a X now we want to find strength>=X ...strength >=X+1...

            for this binary search can be used 
        */
        int l=0,r=2e9,ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(can(mid,n,edges,k)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};