#include <iostream>
#include <vector>
#include <algorithm>

// Класс Computer
class Computer {
public:
    std::string processorType;
    int ramSize;

    // Конструктор
    Computer(std::string pType, int rSize) : processorType(pType), ramSize(rSize) {}

    // Метод для отображения информации о компьютере
    void display() const {
        std::cout << "Processor Type: " << processorType << ", RAM Size: " << ramSize << " GB" << std::endl;
    }

    // Метод для получения объема оперативной памяти
    int getRamSize() const {
        return ramSize;
    }
};

// Функция для сортировки вектора по объему оперативной памяти
bool compareByRamSize(const Computer &a, const Computer &b) {
    return a.getRamSize() < b.getRamSize();
}

int main() {
    int n, ramThreshold;

    // Ввод размерности вектора и критерия фильтрации
    std::cout << "Enter the number of computers: ";
    std::cin >> n;
    std::cout << "Enter the RAM size threshold: ";
    std::cin >> ramThreshold;

    std::vector<Computer> computers;

    // Ввод данных компьютеров
    for (int i = 0; i < n; ++i) {
        std::string processorType;
        int ramSize;

        std::cout << "Enter processor type for computer " << i+1 << ": ";
        std::cin >> processorType;
        std::cout << "Enter RAM size (GB) for computer " << i+1 << ": ";
        std::cin >> ramSize;

        computers.push_back(Computer(processorType, ramSize));
    }

    // Создание нового вектора с компьютерами, удовлетворяющими критерию
    std::vector<Computer> filteredComputers;
    for (const auto &comp : computers) {
        if (comp.getRamSize() >= ramThreshold) {
            filteredComputers.push_back(comp);
        }
    }

    // Проверка на пустоту нового вектора
    if (filteredComputers.empty()) {
        std::cout << "No computers with RAM size greater than " << ramThreshold << " GB." << std::endl;
    } else {
        // Сортировка нового вектора по объему оперативной памяти
        std::sort(filteredComputers.begin(), filteredComputers.end(), compareByRamSize);

        // Вывод отсортированного списка
        std::cout << "Filtered and sorted computers:" << std::endl;
        for (const auto &comp : filteredComputers) {
            comp.display();
        }
    }

    return 0;
}
