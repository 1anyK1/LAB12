#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения информации об автобусе
typedef struct {
    int bus_number;
    char driver[50];
    int route_number;
} Bus;

// Узел для связного списка
typedef struct Node {
    Bus bus;
    struct Node* next;
} Node;

// Функция для создания нового узла
Node* create_node(int bus_number, char* driver, int route_number) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->bus.bus_number = bus_number;
    strcpy(new_node->bus.driver, driver);
    new_node->bus.route_number = route_number;
    new_node->next = NULL;
    return new_node;
}

// Функция для добавления автобуса в список
void add_bus(Node** head, int bus_number, char* driver, int route_number) {
    Node* new_node = create_node(bus_number, driver, route_number);
    new_node->next = *head;
    *head = new_node;
}

// Функция для удаления автобуса из списка и возврата его данных
Bus remove_bus(Node** head, int bus_number) {
    Node* temp = *head;
    Node* prev = NULL;
    Bus bus;
    while (temp != NULL && temp->bus.bus_number != bus_number) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        bus = temp->bus;
        free(temp);
    } else {
        bus.bus_number = -1; // Индикатор, что автобус не найден
    }
    return bus;
}

// Функция для отображения списка автобусов
void display_buses(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Номер автобуса: %d, Водитель: %s, Номер маршрута: %d\n",
               temp->bus.bus_number, temp->bus.driver, temp->bus.route_number);
        temp = temp->next;
    }
}

int main() {
    Node* park = NULL;         // Список автобусов в парке
    Node* on_route = NULL;     // Список автобусов на маршруте

    // Добавляем начальные данные
    add_bus(&park, 1, "Иванов И.И.", 101);
    add_bus(&park, 2, "Петров П.П.", 102);
    add_bus(&park, 3, "Сидоров С.С.", 103);

    int choice;
    int bus_number;
    char driver[50];
    int route_number;
    Bus bus;

    while (1) {
        printf("\n1. Показать автобусы в парке\n2. Показать автобусы на маршруте\n3. Автобус выезжает из парка\n4. Автобус въезжает в парк\n5. Выход\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Автобусы в парке:\n");
                display_buses(park);
                break;
            case 2:
                printf("Автобусы на маршруте:\n");
                display_buses(on_route);
                break;
            case 3:
                printf("Введите номер автобуса для выезда из парка: ");
                scanf("%d", &bus_number);
                bus = remove_bus(&park, bus_number);
                if (bus.bus_number != -1) {
                    add_bus(&on_route, bus.bus_number, bus.driver, bus.route_number);
                    printf("Автобус номер %d выехал из парка.\n", bus_number);
                } else {
                    printf("Автобус не найден в парке.\n");
                }
                break;
            case 4:
                printf("Введите номер автобуса для въезда в парк: ");
                scanf("%d", &bus_number);
                bus = remove_bus(&on_route, bus_number);
                if (bus.bus_number != -1) {
                    add_bus(&park, bus.bus_number, bus.driver, bus.route_number);
                    printf("Автобус номер %d въехал в парк.\n", bus_number);
                } else {
                    printf("Автобус не найден на маршруте.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Неверный выбор.\n");
        }
    }

    return 0;
}
