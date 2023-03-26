// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value, int n) {
    int left = n, right = size - 1, middle, count = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        if (*(arr + middle) > value) {
            right = middle - 1;
        } else if (*(arr + middle) < value) {
            left = middle + 1;
        } else {
            count++;
            int bord_mid = middle - 1;
            while ((*(arr + bord_mid)) == value
                   && (bord_mid >= left)) {
                count++;
                bord_mid--;
            }
            bord_mid = middle + 1;
            while ((*(arr + bord_mid) == value)
                   && (bord_mid <= right)) {
                count++;
                bord_mid++;
            }
            return count;
        }
    }
    return count;
}

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
    int m = len - 1;
    while (arr[m] > value)
        m--;
    for (int i = 0; i < m; i++) {
        for (int j = m; j > i; j--) {
            if (value == arr[i] + arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        count += cbinsearch(arr, len, value, i);
    }
    return count;
}
