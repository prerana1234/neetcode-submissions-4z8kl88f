class Solution {
public:

    string encode(vector<string>& strs) {
         string encoded = "";
    for (string s : strs) {
        encoded += to_string(s.length()) + "#" + s;
    }
    return encoded;
    }

   vector<string> decode(string s) {
    vector<string> result;
    int i = 0;

    while (i < s.length()) {
        int j = i;

        // find '#'
        while (s[j] != '#') {
            j++;
        }

        // length before '#'
        int length = stoi(s.substr(i, j - i));

        // extract the string of that length
        string str = s.substr(j + 1, length);
        result.push_back(str);

        // move i to start of next section
        i = j + 1 + length;
    }
    return result;
}
};
