//The best practice is to declare the default argument in the forward declaration 
//and not in the function definition, as the forward declaration is more likely to be seen by other files 
//and included before use(particularly if it’s in a header file).

#ifndef FOO_H
#define FOO_H
void print(int x, int y = 4);
#endif
