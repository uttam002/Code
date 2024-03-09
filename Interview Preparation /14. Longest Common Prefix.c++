class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            string temp="";
            while(j<ans.size() && j<strs[i].size()){
                if(ans[j]==strs[i][j]) temp.push_back(ans[j]);
                else break;
                j++;
            }
            ans=temp;
        }
        return ans;
    }
};
