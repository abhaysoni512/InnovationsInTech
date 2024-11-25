# Compiling and Executing Our Program:--
    # Running the Compiler from the CommandLine:
        
        for Windows :

            s1 Compiling 
                $ CC prog1.cc
            
            s2 Run Executuable Program:
                $ prog1
                or
                $ .\prog1
        
        for Unix :
            s1. compiling
                $ prog1
            
            s2 Run Executuable Program
                $ a.out
                or
                $ ./a.out
        
    # How to check status of the program
        In windows:
            $ echo %ERRORLEVEL%

        In unix:
            $ echo $?
    
    special case:
        Running on GNU Compiler:
            $ g++ -o prog1 prog1.cc

        for specific standard:`
            $ g++ -std=c++17 -o prog1 prog1.cc
        
****************************************************************

# Space taking characters:

    getline(cin,variable_name)

****************************************************************

# Difference between c++ core language vs Standard library vs STL:

    Core features: It is basic fundamental blocks that constitute c++ programming language

    Standard library: third party predefined libraries that we are using programm, ex iostream

    STL: It is part of the standard library but it is collection of containers (algortithms, iterators helps to navigate through containers)




