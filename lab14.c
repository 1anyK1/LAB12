#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("numbers.txt", "w");
    
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    
    fp = fopen("numbers.txt", "r");
    int sum = 0;
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
        sum += arr[i];
    }
    fclose(fp);
    
    float avg = (float)sum / n;
    
    int min_deviation = abs(arr[0] - avg);
    for(int i = 1; i < n; i++) {
        int deviation = abs(arr[i] - avg);
        if(deviation < min_deviation) {
            min_deviation = deviation;
        }
    }
    
    printf("Массив целых чисел: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nНаименьшее отклонение чисел от их среднего значения: %d\n", min_deviation);
    
    return 0;
}
