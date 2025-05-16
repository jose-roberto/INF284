#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <algorithm>
#include <vector>

class Heuristic
{
private:
    int verify_tolls(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance,
        std::vector<std::vector<bool>> &tolls,
        int t, double p);

    std::pair<bool, std::vector<int>> find_best_improvement(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance);

    std::pair<bool, std::vector<int>> find_best_improvement_tolls(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance,
        std::vector<std::vector<bool>> &tolls,
        int t, double p);

public:
    Heuristic();

    int evaluate(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance,
        std::vector<std::vector<bool>> &tolls,
        int t, double p);

    int local_search(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance,
        std::vector<std::vector<bool>> &tolls,
        int t, double p);

    int nearest_neighbor_v1(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance,
        std::vector<std::vector<bool>> &tolls,
        int t, double p);

    int nearest_neighbor_v2(
        std::vector<int> &solution,
        std::vector<std::vector<int>> &distance,
        std::vector<std::vector<bool>> &tolls,
        int t, double p);
};

#endif
