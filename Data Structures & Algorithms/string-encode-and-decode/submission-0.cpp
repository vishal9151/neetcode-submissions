class Solution {
public:

    string encode(vector<string>& strs) {

        string res = "";

        for(string str : strs)
        {
            res += to_string(str.length()) + "#" + str;
        }

        return res;
    }

    vector<string> decode(string s) {

        vector<string> res;

        int i = 0;

        while(i < s.length())
        {
            int j = i;

            // find '#'
            while(s[j] != '#')
            {
                j++;
            }

            // length of string
            int len = stoi(s.substr(i, j - i));

            // move after '#'
            j++;

            // extract actual word
            string word = s.substr(j, len);

            res.push_back(word);

            // move pointer to next encoded string
            i = j + len;
        }

        return res;
    }
};