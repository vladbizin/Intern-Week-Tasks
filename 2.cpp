#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
    std::cin >> n >> k;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++) std::cin >> h[i];
    
    std::sort(h.begin(), h.end());
    
    int dif = h[n-1] - h[0];
    for(int i = 0, j = n - k - 1; j < n; i++, j++) dif = std::min(dif, h[j] - h[i]);
    
    std::cout << dif;
    return 0;
}