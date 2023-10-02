#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, id;
	std::cin >> n;
    std::vector<int> h(n + 1);
    
    for(int i = 1; i < n + 1; i++)
    {
    	std::cin >> id;
    	h[i] = h[id] + 1;
    }
    
    std::cout << std::distance(h.begin(), std::max_element(h.begin(), h.end()));
    return 0;
}