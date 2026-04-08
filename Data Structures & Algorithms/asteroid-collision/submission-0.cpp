class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> rest;

        for (auto asteroid : asteroids) {
            if (rest.empty()) {
                rest.push(asteroid);
            } else {
                if (asteroid > 0) {
                    rest.push(asteroid);
                } else {
                    while (!rest.empty() and rest.top() > 0 and rest.top() + asteroid < 0) {
                        rest.pop();
                    }
                    if (rest.empty() or rest.top() < 0) {
                        rest.push(asteroid);
                    } else if (rest.top() + asteroid == 0) {
                        rest.pop();
                    }
                }
            }
        }

        std::vector<int> answer (rest.size());
        for (int i = rest.size() - 1; i >= 0; --i) {
            answer[i] = rest.top();
            rest.pop();
        }
        return answer;
    }
};