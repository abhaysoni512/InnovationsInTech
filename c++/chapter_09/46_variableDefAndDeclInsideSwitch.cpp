#if 0
    switch (1)
    {
        int a; // okay: definition is allowed before the case labels
        int b{ 5 }; // illegal: initialization is not allowed before the case labels

    case 1:
        int y; // okay but bad practice: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;

    case 2:
        int z{ 4 }; // illegal: initialization is not allowed if subsequent cases exist
        y = 5; // okay: y was declared above, so we can use it here too
        break;

    case 3:      //subsequent case
        break;
    }

    //if u want to define a variable inside a case, then u have to use a block

    switch (1)
    {

    case 1:
    {
        int y; // okay: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;
    }
    default :
        break;
    }
        
#endif