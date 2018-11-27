#include <iostream>
#include <vector>

void swap(int &a, int &b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int swap_count(int i, int j)
{
    return 2 * (j - i) - 1;
}

int count_bubble(std::vector<int> &values)
{

    int swaps = 0;
    bool changed = true;

    while (changed == true)
    {
        changed = false;
        for (int i = 0; i < values.size() - 1; i++)
        {
            if (values[i] != i)
            {
                swaps += swap_count(i, values[i]);
                swap(values[i], values[values[i]]);
                changed = true;
            }
        }
    }
    return swaps;
}

int main()
{
    int inputs, value, n_changes;

    std::cin >> inputs;
    std::vector<int> values;

    while (inputs != 0)
    {

        values.clear();
        values.push_back(0);
        while (inputs > 0)
        {
            std::cin >> value;
            values.push_back(value);
            inputs -= 1;
        }
        n_changes = count_bubble(values);
        std::cin >> inputs;

        if (n_changes % 2 == 0)
        {
            std::cout << "Carlos" << std::endl;
        }
        else
        {
            std::cout << "Marcelo" << std::endl;
        }
    }

    return 0;
}