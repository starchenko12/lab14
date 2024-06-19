#include <iostream>
using namespace std;

// Функція сортування бульбашкою
void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функція сортування вставками
void insertionSort(double arr[], int size) {
    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    double arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Масиви для зберігання парних і непарних елементів
    double evenElements[n / 2 + 1];
    double oddElements[n / 2 + 1];
    int evenCount = 0;
    int oddCount = 0;

    // Заповнення масивів парних і непарних елементів
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenElements[evenCount++] = arr[i];
        }
        else {
            oddElements[oddCount++] = arr[i];
        }
    }

    // Сортування парних елементів методом бульбашки
    bubbleSort(evenElements, evenCount);
    // Сортування непарних елементів методом вставок
    insertionSort(oddElements, oddCount);

    // Об'єднання відсортованих елементів назад у масив
    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] = evenElements[evenCount++];
        }
        else {
            arr[i] = oddElements[oddCount++];
        }
    }

    // Виведення відсортованого масиву
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
