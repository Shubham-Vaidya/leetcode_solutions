
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;
            }
            else if (part == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(part);
            }
        }

        string res = "";

        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        if (res == "") {
            return "/";
        }

        return res;
    }
};
