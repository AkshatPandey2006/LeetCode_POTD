class Solution {
public:
    
    using ll =long long;
    long long maxSumTrionic(vector<int>& nums) {
        long long n = nums.size();

        ll s1=nums[1];
        vector<vector<ll>> d;
        ll p = 1 , q =1;
        for(ll i =2 ; i< n-1; i++ ){
            if(nums[i]<nums[i-1]){
                s1+=nums[i];
                q++;
            }
            else{
                if(p!=q){
                    d.push_back({p,q,s1});
                }
                p = i,q=i;
                s1 = nums[i];
            }
        }
        if(p!=q){
            d.push_back({p,q,s1});
        }

        ll res = LLONG_MIN;
        for(auto it: d){

            ll f = it[0],l = it[1];
            if((nums[f-1] < nums[f-1] )|| (nums[l] > nums[l+1]))continue;

            ll tsum = it[2];

            ll s2 = LLONG_MIN ,s3=  LLONG_MIN;
            ll prev  = f-1 ,p2 = l+1;

            ll t1 =0 ,t2=0;
            while(prev>=0 && nums[prev]< nums[prev+1]){
                t1+=nums[prev];
                s2 = max(s2,t1);
                prev--;
            }

            tsum+=s2;

            while(p2 < n && nums[p2]>nums[p2-1]){
                t2+=nums[p2];
                s3=max(s3,t2);
                p2++;
            }
            tsum+=s3;

            res =max(res,tsum);
        }
        return res;
    }
};
