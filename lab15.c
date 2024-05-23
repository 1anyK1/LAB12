#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Train {
    char destination[50];
    int train_number;
    int departure_time[2]; // массив из двух чисел: часы, минуты
};

int main() {
    FILE *fp;
    fp = fopen("Train.dat", "wb");
    
    struct Train trains[3]; // Создаем массив из трех структур Train
    
    strcpy(trains[0].destination, "Москва");
    trains[0].train_number = 101;
    trains[0].departure_time[0] = 8;
    trains[0].departure_time[1] = 30;
    
    strcpy(trains[1].destination, "Санкт-Петербург");
    trains[1].train_number = 202;
    trains[1].departure_time[0] = 10;
    trains[1].departure_time[1] = 45;
    
    strcpy(trains[2].destination, "Новосибирск");
    trains[2].train_number = 303;
    trains[2].departure_time[0] = 12;
    trains[2].departure_time[1] = 15;
    
    for(int i = 0; i < 3; i++) {
        fwrite(&trains[i], sizeof(struct Train), 1, fp);
    }
    
    fclose(fp);
    
    // Обработка файла Train.dat
    int search_number;
    printf("Введите номер поезда для поиска: ");
    scanf("%d", &search_number);
    
    fp = fopen("Train.dat", "rb");
    
    struct Train temp;
    int found = 0;
    while(fread(&temp, sizeof(struct Train), 1, fp) == 1) {
        if(temp.train_number == search_number) {
            printf("Информация о поезде:\n");
            printf("Название пункта назначения: %s\n", temp.destination);
            printf("Номер поезда: %d\n", temp.train_number);
            printf("Время отправления: %02d:%02d\n", temp.departure_time[0], temp.departure_time[1]);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Поезд с номером %d не найден.\n", search_number);
    }
    
    fclose(fp);
    
    return 0;
}
