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
    for (int i = 0, j = len - 1; i <= j; i++, j = len - 1) {
        for (; j > i; j--) {
            if (value == arr[i] + arr[j])
                count++;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    int left = 0, right = len - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (value > *(arr + middle) + *(arr + i) || i == middle) {
            left = middle + 1;
        } else if (value < *(arr + middle) + *(arr + i) || i == middle) {
            right = middle - 1;
        } else {
            count++;
            while (value == (*(arr + middle--) + *(arr + i++)) && middle > i) {
                count++;
            }
            while (value == (*(arr + middle++) + *(arr + i++)) && middle > i) {
                count++;
            }
            return count;
        }
    }
    return count;
}
