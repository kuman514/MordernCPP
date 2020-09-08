#include <iostream>
#include <string>

// C++17

template <typename... Numerics>
double Sum(Numerics... nums)
{
    // () required for a fold expression
    return (... + nums);
}

int main(void)
{
    std::cout << Sum(10, 20, 30) << std::endl;
    
    // How it works?
    // Sum(10, 20, 30) -> return (Sum(10, 20) + 30) -> return ((10 + 20) + 30)
    
    return 0;
}
