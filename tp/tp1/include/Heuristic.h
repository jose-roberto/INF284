#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <algorithm>
#include <list>
#include <vector>

class Heuristic
{
private:
    int solution_size;
    std::vector<std::vector<int>> distance;
    std::vector<std::vector<bool>> tolls;
    int free_tolls;
    double tolls_price;

    std::pair<bool, std::vector<int>> find_best_improvement(std::vector<int> &solution);

    std::pair<bool, std::vector<int>> find_best_improvement_tolls(const std::vector<int> &solution);

public:
    Heuristic(
        int solution_size,
        const std::vector<std::vector<int>> &distance,
        const std::vector<std::vector<bool>> &tolls,
        int free_tolls, double tolls_price);

    int evaluate(const std::vector<int> &solution, int free_tolls);

    int local_search(std::vector<int> &solution);

    std::vector<int> nearest_neighbor_v1();

    std::vector<int> nearest_neighbor_v2();
};

#endif
