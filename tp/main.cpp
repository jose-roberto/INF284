#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int evaluate(std::vector<int> &solution, std::vector<std::vector<int>> &distance, std::vector<std::vector<bool>> &tolls, int t, double p)
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

int verify_toll(std::vector<std::vector<bool>> &tolls, int a, int b, int t, double p)
{
    if (tolls[a][b] && t == 0)
        return p;

    return 0;
}

std::pair<bool, std::vector<int>> find_best_improvement(std::vector<int> &solution, std::vector<std::vector<int>> &distance, std::vector<std::vector<bool>> &tolls, int t, int &aux_t, double p, std::vector<std::vector<bool>> &free_tolls_in_solution)
{
    int solution_size = solution.size();

    int best_i = -1, best_j = -1;
    int best_improvement = 0;

    std::vector<int> tuple(4);

    int flag = 0;
    for (int i = 0; i < solution_size - 1; i++)
        if (tolls[solution[i]][solution[i + 1]] && free_tolls_in_solution[solution[i]][solution[i + 1]])
            flag++;

    if (flag == 0)
    {
        free_tolls_in_solution = std::vector<std::vector<bool>>(tolls.size(), std::vector<bool>(tolls.size(), 0));
        aux_t = t;
    }
    else
        aux_t = t - flag;

    for (int i = 1; i < solution_size - 1; i++)
        for (int j = i + 1; j < solution_size; j++)
        {
            int prev = solution[i - 1];
            int first_node = solution[i];
            int last_node = solution[j];
            int next_j = (j + 1) % solution_size;
            int after = solution[next_j];

            tuple = {prev, first_node, last_node, after};

            int original_value = distance[prev][first_node] + distance[last_node][after];
            original_value += verify_toll(tolls, prev, first_node, aux_t, p);
            original_value += verify_toll(tolls, last_node, after, aux_t, p);

            int new_value = distance[prev][last_node] + distance[first_node][after];
            new_value += verify_toll(tolls, prev, last_node, aux_t, p);
            new_value += verify_toll(tolls, first_node, after, aux_t, p);

            int improvement = new_value - original_value;

            if (improvement < best_improvement)
            {
                best_improvement = improvement;
                best_i = i;
                best_j = j;

                tuple = {prev, last_node, first_node, after};
            }
        }

    if (best_improvement < 0)
    {
        std::reverse(solution.begin() + best_i, solution.begin() + best_j + 1);

        int a = tuple[0];
        int b = tuple[1];
        int c = tuple[2];
        int d = tuple[3];

        if (tolls[a][b] && aux_t > 0)
        {
            aux_t--;
            free_tolls_in_solution[a][b] = 1;
            free_tolls_in_solution[b][a] = 1;
        }
        if (tolls[c][d] && aux_t > 0)
        {
            aux_t--;
            free_tolls_in_solution[c][d] = 1;
            free_tolls_in_solution[d][c] = 1;
        }

        return std::make_pair(true, solution);
    }

    return std::make_pair(false, solution);
}

int local_search(std::vector<int> &solution, std::vector<std::vector<int>> &distance, std::vector<std::vector<bool>> &tolls, int t, int &aux_t, double p, std::vector<std::vector<bool>> &free_tolls_in_solution)
{
    int solution_size = solution.size();

    while (true)
    {
        auto [improved, new_solution] = find_best_improvement(solution, distance, tolls, t, aux_t, p, free_tolls_in_solution);
        if (!improved)
            break;
        solution = new_solution;
    }

    return evaluate(solution, distance, tolls, t, p);
}

int main()
{
    std::vector<std::string> paths = {
        // "instances/burma14.tsp",
        // "instances/berlin52.tsp",
        // "instances/st70.tsp",
        // "instances/gil262.tsp",
        // "instances/gr666.tsp",
        // "instances/dsj1000.tsp",
        "instances/t1_burma14.tsp",
        "instances/t2_burma14.tsp",
        "instances/t3_burma14.tsp",
        "instances/t1_berlin52.tsp",
        "instances/t2_berlin52.tsp",
        "instances/t3_berlin52.tsp",
        "instances/t1_st70.tsp",
        "instances/t2_st70.tsp",
        "instances/t3_st70.tsp",
        "instances/t4_st70.tsp",
        "instances/t1_gil262.tsp",
        "instances/t2_gil262.tsp"};

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
        int t, p, l;

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

            nodes.push_back({x, y});
        }

        std::vector<std::vector<int>> distance(dimension, std::vector<int>(dimension, 0));

        for (int i = 0; i < dimension; i++)
            for (int j = i + 1; j < dimension; j++)
            {
                double i_x = nodes[i].first;
                double j_x = nodes[j].first;
                double i_y = nodes[i].second;
                double j_y = nodes[j].second;

                int distance_ij = std::round(std::sqrt((j_x - i_x) * (j_x - i_x) + (j_y - i_y) * (j_y - i_y)));

                distance[i][j] = distance_ij;
                distance[j][i] = distance_ij;
            }

        std::vector<std::vector<bool>> tolls(dimension, std::vector<bool>(dimension, 0));
        std::vector<std::vector<bool>> free_tolls_in_solution(dimension, std::vector<bool>(dimension, 0));
        int aux_t = t;

        for (int i = 0; i < dimension; i++)
            for (int j = i + 1; j < dimension; j++)
                if (distance[i][j] <= l)
                {
                    tolls[i][j] = 1;
                    tolls[j][i] = 1;
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
        std::cout << "Custo para solução 1: " << evaluate(solution_1, distance, tolls, t, p) << std::endl;
        if (p == 0)
            std::cout << "Custo para solução 2: " << evaluate(solution_2, distance, tolls, t, p) << std::endl;

        std::cout << "\nParte 1 - Busca local" << std::endl;
        std::cout << "Custo para solução 1: " << local_search(solution_1, distance, tolls, t, aux_t, p, free_tolls_in_solution) << std::endl;
        if (p == 0)
            std::cout << "Custo para solução 2: " << local_search(solution_2, distance, tolls, t, aux_t, p, free_tolls_in_solution) << std::endl;

        std::cout << "\nParte 2 - Solução inicial" << std::endl;
        std::cout << "Custo para solução 1: " << "-" << std::endl;
        if (p == 0)
            std::cout << "Custo para solução 2: " << "-" << std::endl;

        std::cout << "-------------------------------------" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
