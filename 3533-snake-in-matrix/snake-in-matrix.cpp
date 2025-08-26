class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
         
         int i=0,j=0;
        for(auto s: commands) {
            if(s == "UP" ) { --i;}
            else if(s == "DOWN") { ++i;}
            else if(s == "LEFT") { --j;}
            else ++j;
            cout<<i<<endl;
        }
        cout<<i<<" ,"<<j;

        int pos = (i*n) + j;
        return pos;
        
    }
};