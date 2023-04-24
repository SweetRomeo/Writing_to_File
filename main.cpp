#include <iostream>
#include <vector>
#include <fstream>


constexpr bool isPrime(const int val)
{
    if(val <= 1)
        return false;
    if(val % 2 == 0)
        return val == 2;
    if(val % 3 == 0)
        return val == 3;
    if(val % 5 == 0)
        return val == 5;
    if(val % 7 == 0)
        return val == 7;
    if(val % 11 == 0)
        return val == 11;
    for(int i = 13;i * i < val;i += 2){
        if(val % i == 0)
            return false;
    }
    return true;
}


template<typename Iter>
void print(Iter beg,Iter end)
{
    while(beg != end){
        std::cout << *beg++ << ' ';
    }
    std::cout << '\n';
}
template<typename Con>
void print(Con con)
{
    for(auto iter = con.begin();iter != con.end();++iter){
        std::cout << *iter << ' ';
    }
    std::cout << '\n';
}

template<typename Iter,typename File>
void printToFile(Iter beg,Iter end,File& ofs)
{
    while(beg != end){
        ofs << *beg++ << ' ';
    }
    ofs << '\n';
}
template<typename Con,typename File>
void printToFile(Con& con,File& ofs)
{
    for(auto iter = con.begin();iter != con.end();++iter){
        ofs << *iter << ' ';
    }
    ofs << '\n';
}

int main()
{
    std::vector<int> primes;
    std::fstream ofs{"Primes.txt",std::ios::out};
    for(int i = -10;i < 100;++i){
        if(isPrime(i))
            primes.push_back(i);
    }
    print(primes.begin(),primes.end());
    print(primes);
    printToFile(primes,ofs);
    printToFile(primes.begin(),primes.end(),ofs);
}