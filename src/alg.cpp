// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (value == arr[i] + arr[j])
                count++;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int j = len - 1;
    while (arr[j] >= value)
        j--;
    for (int i = 0; i < j; i++) {
        if (value == arr[i] + arr[j]) {
            count++;
            j--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int left = 0, right = len - 1, middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (value > *(arr + middle) + *(arr + i) || i == middle)
                left = middle + 1;
            else if (value < *(arr + middle) + *(arr + i) || i == middle)
                right = middle - 1;
            else {
                while (value == (*(arr + middle) + *(arr + i)) && middle > i) {
                    count++;
                    middle--;
                    i++;
                }
                while (value == (*(arr + middle) + *(arr + i)) && middle > i) {
                    count++;
                    middle++;
                    i++;
                }
                return count;
            }
        }
    }
    return count;
}
