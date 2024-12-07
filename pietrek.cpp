#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool palindrom(int number) {
    string str = to_string(number); 
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false; 
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        int kwadrat = i * i;  
        if (palindrom(kwadrat)) {
            std::cout << "Kwadrat liczby " << i << " (" << kwadrat << ") jest palindromem.\n";
        }
    }

    return 0;
}
