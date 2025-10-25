class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
         map<char,int>m;
         int x=1;
         vector<int>patternNum;
         for(int i=0;i<pattern.size();i++){
              if(m[pattern[i]]){
              patternNum.push_back(m[pattern[i]]);
              }else{
                m[pattern[i]]=x;
              patternNum.push_back(x);
                x++;

              }
         }
        
         vector<int>resultNum;
         m.clear();
         vector<string>ans;
         for(int i=0;i<words.size();i++){
          x=1;
             for(int j=0;j<words[i].size();j++){
              if(m[words[i][j]]){
                resultNum.push_back(m[words[i][j]]);
              }else{
                m[words[i][j]]=x;
                resultNum.push_back(x);
                x++;

              }
         }
         if(patternNum==resultNum){
          ans.push_back(words[i]);
         }
         resultNum.clear();
         m.clear();
         }
     return ans;   
    }

};