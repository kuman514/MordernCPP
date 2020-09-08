#include <iostream>
#include <string>

// C++11

double SumAll(void)
{
    return 0.0;
}

template <typename Numeric, typename... Numerics>
double SumAll(Numeric num, Numerics... nums)
{
    return static_cast<double>(num) + SumAll(nums...);
}

template <typename... Numerics>
double Avg(Numerics... nums)
{
    return SumAll(nums...) / sizeof...(nums);
}

int main(void)
{
    std::cout << Avg(10, 20, 30) << std::endl;
    return 0;
}
