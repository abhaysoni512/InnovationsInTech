
//avoid this as we are exposing vairable directly to other files
#if 0
namespace constants
{
    extern const double gravity{9.8}; // has external linkage, can be accessed by other files
}
#endif

namespace constants
{
    constexpr double gravity{9.8}; // has internal linkage, is accessible only within this file
}

double getGravity() // has external linkage, can be accessed by other files
{
    // We could add logic here if needed later
    // or change the implementation transparently to the callers
    return constants::gravity;
}