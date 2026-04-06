class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result = 0;
        std::vector<int> records;
        for (auto& op : operations) {
            if (op == "+") {
                int s = records.size() - 1;
                records.push_back(records[s] + records[s - 1]);
            } else if (op == "D") {
                int s = records.size() - 1;
                records.push_back(records[s] * 2);
            } else if (op == "C") {
                records.pop_back();
            } else {
                records.push_back(std::stoi(op));
            }
        }
        for (auto rec : records) {
            result += rec;
        }
        return result;
    }

   
};