#include <iostream>
#include <chrono>

int main() {
    // Get the current date
    auto now = std::chrono::system_clock::now();
    time_t now_c = std::chrono::system_clock::to_time_t(now);
    tm* current_time = std::localtime(&now_c);

    // Determine the current month and day
    int current_month = current_time->tm_mon + 1; // Month is zero-based
    int current_day = current_time->tm_mday;

    // Calculate the current timestamp and the timestamp for June 21st
    std::tm june21 = {0, 0, 0, 21, 5, current_time->tm_year}; // June 21st (Month is zero-based)
    std::time_t current_timestamp = std::mktime(current_time);
    std::time_t june21_timestamp = std::mktime(&june21);

    // Calculate the difference in seconds
    std::time_t difference = june21_timestamp - current_timestamp;

    // Convert seconds to days, hours, minutes, and seconds
    int days = difference / (60 * 60 * 24);
    difference -= days * (60 * 60 * 24);
    int hours = difference / (60 * 60);
    difference -= hours * (60 * 60);
    int minutes = difference / 60;
    int seconds = difference % 60;

    std::cout << "Time until summer: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << std::endl;

    return 0;
}
