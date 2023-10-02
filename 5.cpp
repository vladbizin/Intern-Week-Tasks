#include <iostream>
#include <vector>
#include <map>
#include <list>

int main()
{
    int n_abit, n_prog;
    std::cin >> n_abit >> n_prog;
    std::vector<int> vacant_places(n_prog);
    for(int i = 0; i < n_prog; i++) std::cin >> vacant_places[i];

    std::map<int,std::list<int>> abit_of_rank;
    std::vector<std::list<int>> desired_progs_of_abit(n_abit);
    std::vector<int> enrolled(n_abit, -2);

    for(int abit_id = 0; abit_id < n_abit; abit_id++)
    {
        int abit_rk, prog_count;
        std::cin >> abit_rk >> prog_count;
        abit_of_rank[abit_rk].push_back(abit_id);
        for (int prog_rk = 0; prog_rk < prog_count; prog_rk++)
        {
            int prog_id;
            std::cin >> prog_id;
            desired_progs_of_abit[abit_id].push_back(prog_id - 1);
        }
    }


    for(auto& [rk, abits] : abit_of_rank)
    {
        for(int abit_id : abits)
        {
            for (int prog_id : desired_progs_of_abit[abit_id])
            {
                if (vacant_places[prog_id] == 0) continue;
                vacant_places[prog_id]--;
                enrolled[abit_id] = prog_id;
                break;
            }
        }
    }
    for (int  prog_id : enrolled) std::cout << prog_id + 1 << ' ';
    return 0;
}