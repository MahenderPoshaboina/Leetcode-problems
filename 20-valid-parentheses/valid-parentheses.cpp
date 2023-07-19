class Solution {
public:
    bool isValid(string s) {
        std::string str = s;

        while (str.find("[]") != std::string::npos || str.find("()") != std::string::npos || str.find("{}") != std::string::npos) {
            str = std::regex_replace(str, std::regex("\\[\\]|\\(\\)|\\{\\}"), "");
        }

        return str.empty();
    }
};