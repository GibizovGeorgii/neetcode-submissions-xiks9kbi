class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int tok_size = tokens.size();
        if (tok_size == 1) {
            return std::stoi(tokens[0]);
        }
        std::stack<int> operands;

        int operand1, operand2;
        for (int i = 0; i < tok_size; ++i) {
            if (tokens[i] == "+") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 + operand2);
            } else if (tokens[i] == "-") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 - operand2);
            } else if (tokens[i] == "*") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 * operand2);
            } else if (tokens[i] == "/") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 / operand2);
            } else {
                operands.push(std::stoi(tokens[i]));
            }
        }

        return operands.top();
    }
};
