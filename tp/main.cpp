#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int evaluate(std::vector<int> &solution, std::vector<std::vector<int>> &distance)
{
    int size = solution.size() - 1;
    int value = 0;

    for (int i = 0; i < size; i++)
        value += distance[solution[i]][solution[i + 1]];
    value += distance[solution[size]][solution[0]];

    return value;
}

std::pair<bool, std::vector<int>> find_best_improvement(std::vector<int> &solution, std::vector<std::vector<int>> &distance)
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
        std::reverse(solution.begin() + best_i, solution.begin() + best_j + 1);
        return std::make_pair(true, solution);
    }

    return std::make_pair(false, solution);
}

int local_search(std::vector<int> &solution, std::vector<std::vector<int>> &distance)
{
    int solution_size = solution.size();

    while (true)
    {
        auto [improved, new_solution] = find_best_improvement(solution, distance);
        if (!improved)
            break;
        solution = new_solution;
    }

    return evaluate(solution, distance);
}

int main()
{
    std::vector<std::string> paths = {
        "instances/burma14.tsp",
        "instances/berlin52.tsp",
        "instances/st70.tsp",
        "instances/gil262.tsp",
        "instances/gr666.tsp",
        "instances/dsj1000.tsp",
        "instances/tburma14.tsp",
        "instances/tberlin52.tsp",
        "instances/tst70.tsp",
        "instances/tgil262.tsp"};

    for (const auto &path : paths)
    {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Instância: " << path << "\n"
                  << std::endl;

        std::ifstream file(path);
        if (!file)
        {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return 1;
        }

        std::string line;
        int dimension;
        std::string edgeWeightType;
        double t, p, l;

        while (std::getline(file, line))
        {
            if (line.find("DIMENSION") != std::string::npos)
            {
                std::stringstream ss(line);
                std::string keyword;

                ss >> keyword >> dimension;
            }
            else if (line.find("EDGE_WEIGHT_TYPE") != std::string::npos)
            {
                std::stringstream ss(line);
                std::string keyword;

                ss >> keyword >> edgeWeightType;
            }
            else if (line.find("FREE_TOLLS") != std::string::npos)
            {
                std::stringstream ss(line);
                std::string keyword;

                ss >> keyword >> t;
            }
            else if (line.find("TOLLS_PRICE") != std::string::npos)
            {
                std::stringstream ss(line);
                std::string keyword;

                ss >> keyword >> p;
            }
            else if (line.find("THRESHOLD") != std::string::npos)
            {
                std::stringstream ss(line);
                std::string keyword;

                ss >> keyword >> l;
            }
            else if (line.find("NODE_COORD_SECTION") != std::string::npos)
                break;
        }

        std::vector<std::pair<double, double>> nodes;
        while (std::getline(file, line))
        {
            if (line.find("EOF") != std::string::npos)
                break;

            std::stringstream ss(line);
            int id;
            double x, y;

            ss >> id >> x >> y;
            // std::cout << id << " " << x << " " << y << std::endl;

            nodes.push_back({x, y});
        }

        std::vector<std::vector<int>> distance(dimension, std::vector<int>(dimension, 0));

        for (int i = 0; i < dimension; i++)
            for (int j = 0; j < dimension; j++)
            {
                double i_x = nodes[i].first;
                double j_x = nodes[j].first;
                double i_y = nodes[i].second;
                double j_y = nodes[j].second;

                int distance_ij = std::round(std::sqrt((j_x - i_x) * (j_x - i_x) + (j_y - i_y) * (j_y - i_y)));

                distance[i][j] = distance_ij;
            }

        std::vector<std::vector<bool>> tolls(dimension, std::vector<bool>(dimension, 0));

        for (int i = 0; i < dimension; i++)
        {
            for (int j = i + 1; j < dimension; j++)
                if (distance[i][j] <= l)
                    tolls[i][j] = 1;
        }

        int start = -1;
        std::vector<int> solution_1(dimension);
        std::generate(solution_1.begin(), solution_1.end(), [&start]()
                      { start += 1; return start; });

        start = -2;
        std::vector<int> solution_2(dimension);
        std::generate(solution_2.begin(), solution_2.begin() + (solution_2.size() / 2), [&start]()
                      { start += 2; return start; });
        start = -1;
        std::generate(solution_2.begin() + (solution_2.size() / 2), solution_2.end(), [&start]()
                      { start += 2; return start; });

        file.close();

        std::cout << "Parte 0 - Preliminar" << std::endl;
        std::cout << "Custo para solução 1: " << evaluate(solution_1, distance) << std::endl;
        std::cout << "Custo para solução 2: " << evaluate(solution_2, distance) << std::endl;

        std::cout << "\nParte 1 - Local Search" << std::endl;
        std::cout << "Custo para solução 1: " << local_search(solution_1, distance) << std::endl;
        std::cout << "Custo para solução 2: " << local_search(solution_2, distance) << std::endl;

        std::cout << "-------------------------------------" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
