bool isSorted(vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; i++)
        if (!(arr[i] <= arr[i + 1]))
            return false;
    return true;
}

void reverse(vector<int>& arr, int left, int right) {
    for (int i = left, j = 0; i <= (left + right) / 2; i++, j++) {
        swap(arr[i], arr[right - j]);
    }
}

void almostSorted(vector<int> arr) {
    freopen("test.out", "w", stdout);
    if (arr.size() <= 2) {
        cout << "yes\nswap" << " " << 1 << " " << 2;
        return;
    }
    int left, right;
    right = left = -1;
    for (int i = 0, j = arr.size() - 1; i < arr.size() - 1, j >= 1; i++, j--) {
        if (left != -1 && right != -1)
            break;
        if (arr[i] > arr[i + 1] && left == -1)
            left = i;
        if (arr[j] < arr[j - 1] && right == -1) {
            right = j;
        }
    }

    swap(arr[left], arr[right]);
    if (isSorted(arr)) {
        cout << "yes\nswap" << " " << left + 1 << " " << right + 1;
        return;
    }

    swap(arr[left], arr[right]);
    reverse(arr, left, right);

    if (isSorted(arr)) {
        cout << "yes\nreverse" << " " << ++left << " " << ++right;
        return;
    }

    cout << "no";
}
