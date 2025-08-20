#include <iostream>
#include <string>

using namespace std;
class Printer{
private:
    string m_name;
    int m_availablepaper{};
public:
    Printer(const string name,int available_paper) : m_name(name),m_availablepaper(available_paper){}

    void print (const string &textDoc) {

        int required_pages = textDoc.length()/10; 
        if(required_pages>m_availablepaper){
            throw "Out of paper\n";
        }
        cout<<textDoc<<"\n";
        m_availablepaper-=required_pages;
    }

};
int main(){

    Printer p{"Hp inkject",40};
    try{
        p.print("printing ...... I am Abhay Soni I am Software Enginer\n");
        p.print("printing ...... I am Abhay Soni I am Software Enginer\n");
    }
    catch(const char * txtexp){
        cout<<"Exception No paperleft \n";
    }
    return 0;
}