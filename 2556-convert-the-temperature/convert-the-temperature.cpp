class Solution {
public:
    vector<double> convertTemperature(double celsius) {

        double kelvin = celsius + 273.15;
        double faha = (celsius* 1.80) + 32.00;

        vector<double> ans(2,0);

        ans[0] = kelvin;
        ans[1] = faha;

        return ans;
        
    }
};