#include <iostream>
#include <ctime>
#include <thread> 
#include <chrono> 

using namespace std;


void remainingTimeUntilSummer() {
    while (true) {
        time_t currentTime;
        struct tm *localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        int currentYear = localTime->tm_year + 1900;
        tm summerStartDate = {0, 0, 0, 1, 5, currentYear};
        time_t summerStartSeconds = mktime(&summerStartDate);
        time_t currentSeconds = mktime(localTime);

        if (currentSeconds > summerStartSeconds) {
            summerStartDate.tm_year++;
            summerStartSeconds = mktime(&summerStartDate);
        }
        time_t remainingSeconds = summerStartSeconds - currentSeconds;

        int remainingDays = remainingSeconds / (60 * 60 * 24);
        int remainingHours = (remainingSeconds % (60 * 60 * 24)) / (60 * 60);
        int remainingMinutes = (remainingSeconds % (60 * 60)) / 60;
        int remainingSecondsOutput = remainingSeconds % 60;

        // Выводим результат
        cout << "До начала лета осталось " << remainingDays << " дней, " << remainingHours << " часов, "
             << remainingMinutes << " минут и " << remainingSecondsOutput << " секунд." << endl;

        // Задержка перед следующим обновлением (например, каждую секунду)
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    // Вызываем функцию для расчета оставшегося времени до лета
    remainingTimeUntilSummer();
    return 0;
}
