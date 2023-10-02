#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    int k, n, m, d, w;
    std::cin >> k >> n >> m;
    std::vector<int> last_job_day(k);
    std::vector<int> sad_intervals;
    sad_intervals.reserve(n);
    
    for (int i=0; i < n && m >= 0; i++)
    {
        std::cin >> d >> w;
        if (last_job_day[w - 1]) sad_intervals.push_back(d-last_job_day[w - 1]);
        else m--;
        last_job_day[w - 1] = d;
    }

    if (m < 0) std::cout << -1;
    else
    {
        std::sort(sad_intervals.begin(), sad_intervals.end());
        std::cout << std::accumulate(sad_intervals.begin(), sad_intervals.begin() + sad_intervals.size() - m, 0LL);
    }
    return 0;
}