#include <iostream>
using namespace std;

// ������� ���������� ����������
void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� ���������� ���������
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

    // ������ ��� ��������� ������ � �������� ��������
    double evenElements[n / 2 + 1];
    double oddElements[n / 2 + 1];
    int evenCount = 0;
    int oddCount = 0;

    // ���������� ������ ������ � �������� ��������
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenElements[evenCount++] = arr[i];
        }
        else {
            oddElements[oddCount++] = arr[i];
        }
    }

    // ���������� ������ �������� ������� ���������
    bubbleSort(evenElements, evenCount);
    // ���������� �������� �������� ������� �������
    insertionSort(oddElements, oddCount);

    // ��'������� ������������ �������� ����� � �����
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

    // ��������� ������������� ������
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
