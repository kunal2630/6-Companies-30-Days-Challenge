class DataStream {
public:

   /*

   //Approacj -1 (Extra Space Taken)

   We have a maintain a window of size k , and if if that window all k elements are equal to value we return return true , else return false

   So to maintain window we can use deque, pushing element into it from back , and when window size becomes greater than k just pop the front element 

  
    
    deque<int> dq;
    int value,k,cnt=0,trackValue=0;
    DataStream(int value, int k) {

        this->value=value;
        this->k=k;
        
    }
    
    bool consec(int num) {

        dq.push_back(num);
        cnt++;
        if(num==value) trackValue++;
        if(cnt<k) return false;

        if(dq.size()>k){

            int front=dq.front();
            if(front==value) trackValue--;
            dq.pop_front();

        }

        return trackValue==k;
        
    }

     */

    //Approach 2 - Space Optimised 

    //Since at any moment we need last k integers VALUE equals value , so if any one is not equal value then that window is not our answer
    
 
    int value,k,trackValue=0;
    DataStream(int value, int k) {

        this->value=value;
        this->k=k;
        
    }
    
    bool consec(int num) {

        if(num==value){

            trackValue++;
        }
        else{

            trackValue=0;
        }

 

        return trackValue>=k;
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
