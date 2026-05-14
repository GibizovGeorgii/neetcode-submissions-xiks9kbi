class Solution {
public:
    string decodeString(string s) {
        std::stack<int> amount;
        std::vector<std::string> word_stack;
        int num = 0;

        word_stack.push_back(""); // первый элемент и будет расшифрованной строкой
        for (char& ch : s) {
            if (ch >= '0' and ch <= '9') {
                num = num * 10 + (int)(ch - '0');
            } else if (ch == '[') {
                amount.push(num);
                num = 0;
                word_stack.push_back("");
            } else if (ch == ']') {
                for (int i = 0; i < amount.top(); i++) {
                    word_stack[word_stack.size() - 2] += word_stack.back();
                }
                amount.pop();
                word_stack.pop_back();
            } else {
                word_stack.back() += ch;
            }
        }

        return word_stack[0];
    }
};