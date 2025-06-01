struct Employee
{
    int id{};
    int age{};
    double wage{76000.0};
    double whatever;
};

int main()
{
    Employee joe{2, 28}; // joe.whatever will be value-initialized to 0.0

    return 0;
}

/*
In the above example, joe.id will be initialized with value 2 
and joe.age will be initialized with value 28. Because joe.wage wasn’t given an explicit initializer but has a default member initializer, 
joe.wage will be initialized to 76000.0. 
And finally, because joe.whatever wasn’t given an explicit initializer, joe.whatever is value-initialized to 0.0.
*/