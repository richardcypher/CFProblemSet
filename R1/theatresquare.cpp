#include <iostream>
#include <cmath>

int main() {
    long long  n,m,a;
    std::cin>>n>>m>>a;
    if (n<=0 || m <=0 ||a <=0) {
        std::cout<<0<<std::endl;
        return 0;
    }
    long long n_num = ceil(n  * 1.0  / a);
    long long m_num = ceil(m  * 1.0 / a );
    long long final = n_num * m_num;
    std::cout<<final<<std::endl;
}
