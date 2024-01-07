class Solution {
public:
    int findTheWinner(int n, int k) {
        
        //Used a vector to store presence of players in game , once a player exit we make a[player]=0 

        vector<int> a(n,1);
        int i=0;
        int size=n;

        //As at end we need 1 player
        while(size>1){

            int cnt=1;

            //Skipping k-1 players which are present in game
            while(cnt<k){

                if(a[i]) cnt++;

                i=(i+1)%n;

                
            }
            
            
            //Once k players are skipped , find the next player position , as it may be possible that some players may have exit in betweeb
            while(a[i]==0){

                i=(i+1)%n;

            }

            //found the current player , make him exit
            a[i]=0;
            size--;
            i=(i+1)%n;
            

        }

        for(int i=0;i<n;i++){

            if(a[i]==1) return i+1;
        }

        return 1;


        //Logical queue base solution 

        queue<int> q;
        for(int i=1;i<=n;i++){

            q.push(i);
        }
        
        //start the game
        while(q.size()!=1){

            int cnt=1;

            //skiiping k-1 players
            while(cnt<k){

                int front=q.front();
                q.pop();
                q.push(front);
                cnt++;
            }
            //removing kth player from game
            q.pop();
        }

        return q.front();
    }
};
