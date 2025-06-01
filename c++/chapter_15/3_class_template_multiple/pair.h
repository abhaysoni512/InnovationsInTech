#ifndef PAIR_H
#define PAIR_H

template <typename T>
struct pair
{
    T first{};
    T second{};
};
template <typename T>
constexpr T get_max(pair<T> p)
{
    return (p.first > p.second) ? p.first : p.second;
}

#endif // PAIR_H
