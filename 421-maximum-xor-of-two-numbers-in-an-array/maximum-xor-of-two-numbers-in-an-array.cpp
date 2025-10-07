class tn{
    public:
    vector<tn*> v;
    tn(): v(2,NULL){}
};
class Solution {
public:
    tn* root = new tn();
    int findMaximumXOR(vector<int>& nums) {
        int ans= 0;
        for(int i : nums){
            string str = bitset<32>(i).to_string();
            tn* node = root;
            for(char ch: str){
                if(!node->v[ch - '0']) node->v[ch - '0'] = new tn();
                node = node->v[ch - '0'];
            }
        }

        for(int i : nums){
            string str = bitset<32>(i).to_string();
            tn* node = root;
            string temp = "";
            for(char ch: str){
                int ele = ch - '0' ^ 1;
                if(node->v[ele]){
                    node = node->v[ele];
                    temp += to_string(ele);
                }
                else{
                    node = node->v[ch - '0'];
                    temp += ch;
                }
            }
            ans = max(ans, stoi(temp,0,2)^i);
        }
        return ans;
    }
};