// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         char char1 = ' ';
//         char char2 = ' ';
//         int c1 = 0;
//         int c2 = 0;
//         int i = s.size() - 1 , j = t.size() - 1;
//         while(i >= 0 && j >= 0){
//         while(i >= 0 )
//         {
//             if(s[i] == '#')
//             {
//                 c1++;
//                 i--;
//             }
//             else
//             {
//                 if(c1 > 0){
//                     c1--;
//                     i--;
//                 }
//                 else{
                    
//                         char1 = s[i];
//                         i--;
                    
                    
//                 }
//             }
//         }
//         while(j >= 0)
//         {
//             if(t[j] == '#'){
//                 c2++;
//                 j--;
//             }
//             else{
//                 if(c2 > 0){
//                     c2--;
//                     j--;
                    
//                 }
//                 else{
                   
//                         char2 = t[j];
//                         j--;
                    
//                 }
//             }
//         }
        
//             if(char1 != ' ' && char2 != ' ' && char1 != char2){
//                 return false;
//             }
//             else{
//                 if(char1 == char2){
//                     char1 = ' ';
//                     char2 = ' ';
//                 }
                
//             }
//         }
        
//             return true;
//     }
// };


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        int c1 = 0;
        int c2 = 0;

        while (i >= 0 || j >= 0) {

            // Find next valid character in s
            while (i >= 0) {
                if (s[i] == '#') {
                    c1++;
                    i--;
                }
                else if (c1 > 0) {
                    c1--;
                    i--;
                }
                else {
                    break;
                }
            }

            // Find next valid character in t
            while (j >= 0) {
                if (t[j] == '#') {
                    c2++;
                    j--;
                }
                else if (c2 > 0) {
                    c2--;
                    j--;
                }
                else {
                    break;
                }
            }

            // One string has a character while the other doesn't
            if (i < 0 && j < 0)
                return true;

            if (i < 0 || j < 0)
                return false;

            // Compare valid characters
            if (s[i] != t[j])
                return false;

            // Move past the characters we just compared
            i--;
            j--;
        }

        return true;
    }
};