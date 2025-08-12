class Solution {
public:
    int splitNum(int num) {
        string s;
        while(num)
        {
            int digit = num%10;
            s+= to_string(digit);
            num /= 10;
        }
        
        sort(s.begin(), s.end());
        cout<<s<<endl;

        int num1= s[0]-'0', num2= s[1]-'0';
        for(int i =2; i<s.size(); i++) {
            if(i%2 ==0){ 
                num1 = num1*10 + (s[i]-'0');
            }
            else
            {
                num2 = num2*10 + (s[i]-'0');
            }
        }
        cout<<num1<<endl<<num2;
        return num1+num2;
    }
};