#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int evaluate(std::vector<int> solution, std::vector<std::vector<double>> distance)
{
    int size = solution.size() - 1;
    int value = 0;

    for (int i = 0; i < size; i++)
        value += distance[solution[i]][solution[i + 1]];
    value += distance[solution[size]][solution[0]];

    return value;
}

int twopt(std::vector<int> solution, std::vector<std::vector<double>> distance)
{
    int size = solution.size() - 2;
    int best_improvement = 0, improvement;

    for (int i = 1; i < size; i++)
    {
        for (int j = i + 3; j < size; j++)
        {
            int a1 = i;
            int a2 = j;

            std::vector<int> solution_copy = solution;
            std::swap(solution_copy[a1], solution_copy[a2]);
            std::swap(solution_copy[a1 + 1], solution_copy[a2 - 1]);
            improvement = evaluate(solution_copy, distance);
        }

        if (improvement < best_improvement)
            break;

        best_improvement = std::max(best_improvement, improvement);
    }

    return best_improvement;
}

int main()
{
    std::string instance;
    std::cout << "Digite o nome da instância: ";
    std::cin >> instance;

    std::string path = "../instances/" + instance + ".tsp";
    std::cout << "Lendo arquivo: " << path << std::endl;

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
            // std::cout << keyword + " " << dimension << std::endl;
        }
        else if (line.find("EDGE_WEIGHT_TYPE") != std::string::npos)
        {
            std::stringstream ss(line);
            std::string keyword;

            ss >> keyword >> edgeWeightType;
            // std::cout << keyword + " " << edgeWeightType << std::endl;
        }
        else if (line.find("FREE_TOLLS") != std::string::npos)
        {
            std::stringstream ss(line);
            std::string keyword;

            ss >> keyword >> t;
            // std::cout << keyword + " " << t << std::endl;
        }
        else if (line.find("TOLLS_PRICE") != std::string::npos)
        {
            std::stringstream ss(line);
            std::string keyword;

            ss >> keyword >> p;
            // std::cout << keyword + " " << p << std::endl;
        }
        else if (line.find("THRESHOLD") != std::string::npos)
        {
            std::stringstream ss(line);
            std::string keyword;

            ss >> keyword >> l;
            // std::cout << keyword + " " << l << std::endl;
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

    std::vector<std::vector<double>> distance(dimension, std::vector<double>(dimension, 0));

    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
        {
            double i_x = nodes[i].first;
            double j_x = nodes[j].first;
            double i_y = nodes[i].second;
            double j_y = nodes[j].second;

            double distance_ij = std::round(std::sqrt((j_x - i_x) * (j_x - i_x) + (j_y - i_y) * (j_y - i_y)));

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

    start = -1;
    std::vector<int> solution_2(dimension);
    std::generate(solution_2.begin(), solution_2.begin() + (solution_2.size() / 2), [&start]()
                  { start += 2; return start; });
    start = -2;
    std::generate(solution_2.begin() + (solution_2.size() / 2), solution_2.end(), [&start]()
                  { start += 2; return start; });

    file.close();

    std::cout << "Custo 1: " << twopt(solution_1, distance) << std::endl;

    std::cout << "Custo 2: " << twopt(solution_2, distance) << std::endl;

    return 0;
}
