#include <iostream>
#include <thread>
#include <string>
#include <map>
#include <chrono>
#include <functional>  // For std::ref
using namespace std::chrono_literals;

void refreshFor(std::map<std::string, int>& m) {  // Pass by reference
    while (true) {
        for (auto& p : m) {
            p.second++;
            std::cout << p.first << "-" << p.second << std::endl;
        }
        std::this_thread::sleep_for(2000ms);  // Sleep for 2 seconds
    }
}

int main() {
    std::map<std::string, int> m = {
        {"new york", 20},
        {"mumbai", 25},
        {"delhi", 30}
    };

    std::thread bgworker(refreshFor, std::ref(m));  // Pass by reference using std::ref

    bgworker.detach();  // Detach the thread to run independently

    // Alternatively, you can use `bgworker.join();` if you want the main thread to wait for it to complete.

    std::this_thread::sleep_for(10000ms);  // Prevent the main thread from terminating immediately
    return 0;
}
