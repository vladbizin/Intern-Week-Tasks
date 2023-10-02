#include <iostream>

int main()
{
	long long n, m, c2, c5;
    std::cin >> n >> m >> c2 >> c5;
    
    if (m < n) std::cout << 0;
    else if (4*c2 <= c5) std::cout << c2*(m - n);
    else std::cout << c5*((m - n)/4) + std::min(c2*((m - n)%4), c5);
    
    return 0;
}