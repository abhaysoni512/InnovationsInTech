#include <iostream>
using namespace std;
// Forward declaration of the class
class humidity;

class temperature{
private:
    int m_temp{};
public:
    temperature(int temp) : m_temp(temp) {}

    friend void printWeather(const temperature &temp, const humidity &hum);
};

class humidity{
private:
    int m_hum{};
public:
    humidity(int hum) : m_hum(hum) {}

    friend void printWeather(const temperature &temp, const humidity &hum);
};
// Friend function that can access private members of both temperature and humidity classes
void printWeather(const temperature &temp, const humidity &hum) {
    cout << "Temperature: " << temp.m_temp << "°C, Humidity: " << hum.m_hum << "%" << endl;
}
int main() {
    temperature temp(25);
    humidity hum(60);

    // Call the friend function to print weather information
    printWeather(temp, hum);

    return 0;
}