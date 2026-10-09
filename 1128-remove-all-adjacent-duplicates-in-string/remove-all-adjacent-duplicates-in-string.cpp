class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        for(char c : s){
            // if the result string is not empty
            if(!result.empty() && result.back() == c){
             result.pop_back(); 
            //  remove the duplicate (pop) 

            }
            else{
                result.push_back(c);
                // Otherwise, add the character (push)
            }
        }
        return result;
    }
};