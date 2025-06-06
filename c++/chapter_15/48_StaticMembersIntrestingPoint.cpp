/*
    Static member functions have two interesting quirks worth noting. 
    First, because static member functions are not attached to an object,
    they have no this pointer! This makes sense when you think about it -- the this pointer always points to the object 
    that the member function is working on.
    Static member functions do not work on an object, so the this pointer is not needed.

Second, static member functions can directly access other static members (variables or functions), but not non-static members.
 This is because non-static members must belong to a class object, and static member functions have no class object to work with!
*/

#include <iostream>
Class Roll
   