class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }

        std::sort(ind.begin(), ind.end(), [&](int i, int j) { return position[i] > position[j]; });

        std::vector<int> temp = position;
        for (int i = 0; i < n; ++i) {
            position[i] = temp[ind[i]];
        }

        temp = speed;
        for (int i = 0; i < n; ++i) {
            speed[i] = temp[ind[i]];
        }

        int fleet_amount = 1;
        double fleet_time = (double)(target - position[0]) / speed[0];
        for (int i = 1; i < n; ++i) {
            if ((double)(target - position[i]) / speed[i] > fleet_time) {
                fleet_amount++;
                fleet_time = (double)(target - position[i]) / speed[i];
            }
        }

        return fleet_amount;
    }
};
