class Solution {
public:
/*
    int ns = 0, hs = -prices[0], prev_ns = 0;
        for(int i=1;i<prices.size();i++){
            int chs = max(hs, prev_ns-prices[i]);
            int cns = max(ns, hs + prices[i]);
            prev_ns = ns;
            ns = cns;
            hs = chs;
        }
        return ns;
*/
    int maxProfit(vector<int>& prices) {
        int ns = 0, hs = -prices[0], prev_ns = 0;
        int n = prices.size();
        int back_ns[n], back_hs[n];
        for(int i=0;i<n;i++){
            back_ns[i] = back_hs[i] = -5;
        }
        for(int i=1;i<prices.size();i++){
            int cns=ns, chs=hs;
            if(hs < prev_ns-prices[i]){
                chs = prev_ns - prices[i];
                back_hs[i] = i-2;
            }
            if(ns < hs + prices[i]){
                cns = hs + prices[i];
                back_ns[i] = i-1;
            }
            prev_ns = ns;
            ns = cns;
            hs = chs;
        }
        vector<string> path;
        bool nos = true;
        int i = 0;
        for(i=n-1;i>=0;i--){
            if(nos){
                if(back_ns[i] != -5){
                    path.push_back("Sell at " + to_string(i));
                    nos = false;
                }
            } else {
                if(back_hs[i] != -5){
                    path.push_back("Buy at " + to_string(i));
                    i--;
                    nos = true;
                }
            }
        }
        if(!nos){
            path.push_back("Buy at 0");
        }
        for(auto it=path.rbegin();it != path.rend();it++){
            cout << *it << "\n";
        }
        return ns;
    }
};
