class Solution {
public:
    
    int totalRow,totalCol,i=0,j=0;

    Solution(int m, int n) {
        
        totalRow=m;
        totalCol=n;
    }
    
    //Flipping must be done in random manner , means each cell must have equal chance of being selected , so instead of using rand() function , we can select element one by one using pointer , initially pointer is at i=0,j=0 so select that element and increment j , similarly go on incrementing j till our first row is complete then increment i , and once our i and j becomes equal to n and m , start again at i=0,j=0 this way each element will have same chance of being selected and also we dont have to store each element to flip its value , as we are going one by one , element which is selected once means it has been flipped

    vector<int> flip() {
        
        int row=i,col=j;

        if(j+1<totalCol){

            j++;
        }
        else if(i+1<totalRow){

            i++;
            j=0;

        }

        else{

            i=0;
            j=0;
        }
       
        


        return {row,col};
        
    }
    
    void reset() {

 
       
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
