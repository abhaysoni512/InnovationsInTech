#ifndef MY_HEADER_H
#define MY_HEADER_H
int g_x {5}; // non-constant globals have external linkage by default
extern const int g_y {42}; //for constant v External linkage
extern constexpr int g_z{42}; // constexpr globals can be defined as extern, making them external (but this is pretty useless, see the warning in the next section)

#endif