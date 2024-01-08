class Solution {
public:
    
    /*

    Standard Djkistra question ,where we have to apply djkistra on each node 

    */
    typedef pair<int,int> pi;

    void djkistra(int s,vector<int>& dis, vector<vector<pair<int,int>>>& adj){

        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,s});
        dis[s]=0;

    while(!pq.empty()){

            int size=pq.size();

        while(size--){

            int sEdge=pq.top().second;
            int sDist=pq.top().first;
            pq.pop();

            for(auto it:adj[sEdge]){

                int dEdge=it.first;
                int dDist=it.second;
                if(sDist+dDist<dis[dEdge]){

                    dis[dEdge]=sDist+dDist;
                    pq.push({dis[dEdge],dEdge});
                }
            }
        }
    }

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

       vector<vector<pair<int,int>>> adj(n);
       for(auto it:edges){

           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
       int ans=0;
       int oldCnt=n+1;
       for(int city=0;city<n;city++){

           vector<int> dis(n,1e9);
           djkistra(city,dis,adj);
           int cnt=0;
           for(int i=0;i<n;i++){

               if(dis[i]<=distanceThreshold ){

                   cnt++;
               }
           }

           if(cnt<=oldCnt){
               ans=city;
               oldCnt=cnt;
           }


       }

       return ans;

    }
};
