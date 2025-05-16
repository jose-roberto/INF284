#include "../include/Heuristic.h"

Heuristic::Heuristic() {}

int Heuristic::verify_tolls(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance,
    std::vector<std::vector<bool>> &tolls,
    int t, double p)
{
    int solution_size = solution.size();
    int value = 0;
    int free_tolls = t;

    for (int i = 0; i < solution_size; i++)
    {
        int a = solution[i];
        int b = solution[(i + 1) % solution_size];
        value += distance[a][b];

        if (tolls[a][b])
        {
            if (free_tolls > 0)
                free_tolls--;
            else
                value += p;
        }
    }

    return value;
}

std::pair<bool, std::vector<int>> Heuristic::find_best_improvement(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance)
{
    int solution_size = solution.size();

    int best_i = -1, best_j = -1;
    int best_improvement = 0;

    for (int i = 1; i < solution_size - 1; i++)
        for (int j = i + 1; j < solution_size; j++)
        {
            int prev = solution[i - 1];
            int first_node = solution[i];
            int last_node = solution[j];
            int next_j = (j + 1) % solution_size;
            int after = solution[next_j];

            int original_value = distance[prev][first_node] + distance[last_node][after];

            int new_value = distance[prev][last_node] + distance[first_node][after];

            int improvement = new_value - original_value;

            if (improvement < best_improvement)
            {
                best_improvement = improvement;
                best_i = i;
                best_j = j;
            }
        }

    if (best_improvement < 0)
    {
        std::reverse(solution.begin() + best_i,
                     solution.begin() + best_j + 1);

        return {true, solution};
    }

    return std::make_pair(false, solution);
}

std::pair<bool, std::vector<int>> Heuristic::find_best_improvement_tolls(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance,
    std::vector<std::vector<bool>> &tolls,
    int t, double p)
{
    int solution_size = solution.size();

    int best_improvement = 0;

    std::vector<int> best_solution;

    int original_value = verify_tolls(solution, distance, tolls, t, p);

    for (int i = 1; i < solution_size - 1; i++)
    {
        for (int j = i + 1; j < solution_size; j++)
        {
            std::vector<int> candidate = solution;
            std::reverse(candidate.begin() + i, candidate.begin() + j + 1);

            int new_value = verify_tolls(candidate, distance, tolls, t, p);
            int improvement = new_value - original_value;

            if (improvement < best_improvement)
            {
                best_improvement = improvement;
                best_solution = candidate;
            }
        }
    }

    if (best_improvement < 0)
        return {true, best_solution};

    return {false, solution};
}

int Heuristic::evaluate(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance,
    std::vector<std::vector<bool>> &tolls,
    int t, double p)
{
    int size = solution.size() - 1;
    int value = 0;

    for (int i = 0; i < size; i++)
    {
        value += distance[solution[i]][solution[i + 1]];
        if (tolls[solution[i]][solution[i + 1]] && t == 0)
            value += p;
        else if (tolls[solution[i]][solution[i + 1]])
            t--;
    }

    value += distance[solution[size]][solution[0]];

    if (tolls[solution[size]][solution[0]] && t == 0)
        value += p;

    return value;
}

int Heuristic::local_search(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance,
    std::vector<std::vector<bool>> &tolls,
    int t, double p)
{
    while (true)
    {
        bool improved = false;
        std::vector<int> new_solution;

        auto result = (solution.size() == t)
                          ? find_best_improvement(solution, distance)
                          : find_best_improvement_tolls(solution, distance, tolls, t, p);

        improved = result.first;
        new_solution = result.second;

        if (!improved)
            break;

        solution = new_solution;
    }

    return evaluate(solution, distance, tolls, t, p);
}

int Heuristic::nearest_neighbor_v1(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance,
    std::vector<std::vector<bool>> &tolls,
    int t, double p)
{
    return 0;
}

int Heuristic::nearest_neighbor_v2(
    std::vector<int> &solution,
    std::vector<std::vector<int>> &distance,
    std::vector<std::vector<bool>> &tolls,
    int t, double p)
{
    return 0;
}