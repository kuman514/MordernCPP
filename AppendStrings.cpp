#include <iostream>
#include <string>

// C++11

// We can append strings using template parameter pack
template <typename String>
std::string PlusStrings(const String& str)
{
    return std::string(str);
}

template <typename String, typename... Strings>
std::string PlusStrings(const String& str, Strings... strs)
{
    return std::string(str) + PlusStrings(strs...);
}

// However, std::string.operator+() requires too much memory.
// We can reserve less memory.

// Calculate memory size to be reserved.
size_t GetStringSize(const char* s)
{
    return sizeof(s);
}

size_t GetStringSize(const std::string& s)
{
    return s.size();
}

template <typename String, typename... Strings>
size_t GetStringSize(const String& str, Strings... strs)
{
    return GetStringSize(str) + GetStringSize(strs...);
}

// Appending strings to a created one.
void AppendString(std::string* created)
{
    // If there is no more strings to append, return.
    return;
}

template <typename String, typename... Strings>
void AppendString(std::string* created, const String& str, Strings... strs)
{
    created->append(str);
    AppendString(created, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& str, Strings... strs)
{
    // Reserve memory of string being created, just once
    std::string created;
    created.reserve(GetStringSize(str, strs...));
    
    // Append all strings to the created one.
    AppendString(&created, str, strs...);
    
    return created;
}

int main(void)
{
    std::cout << PlusStrings("yasuo", std::string(" "), "is", " ", std::string("science")) << std::endl;
    std::cout << StrCat("yasuo", std::string(" "), "is", " ", std::string("science")) << std::endl;
    return 0;
}
