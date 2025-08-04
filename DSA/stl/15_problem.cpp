    /*
        Problem
        Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

        The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

        Help Monk prepare the same!

        Input format:
        On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

        Output format:
        You must print the required list.

        Constraints:
        1 <= N <= 105
        1 <= | Length of the name | <= 100
        1 <= Marks <= 100
    */

    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        // humko sorting marks ki karni h so: same marks multiple student ke ho skte h h
    //  map<int,vector<string>> m;
    // but question ki requirement ye hai same marks then humhe names ke basis m sort krna h so

        map<int,multiset<string>> mp;

        int N;
        cin>>N;
        for(int i{};i<N;i++){
            int marks;
            string name;
            cin>> name >>marks;
            // bhulna nahi kaise map m operation kaise lagate the key value pair array type then 2nd map h to set m operation insert hota h means mp[marks] become set ab usme jo operation lagna h laga lo
            mp[marks].insert(name);
        }

        auto cur_it = --mp.end();
        while (true)
        {
            auto &students = cur_it->second;
            int marks = cur_it->first;
            for(const auto student : students){
                cout<<student<<" "<<marks<<"\n";
            }
            if(cur_it==mp.begin()) break;
            cur_it--;
        }
        

        return 0;
    }