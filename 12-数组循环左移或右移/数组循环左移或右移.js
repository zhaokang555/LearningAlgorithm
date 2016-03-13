function reverse(arr, left, right) {
    var i, j, temp;
    for (i = left, j = right; i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 数组循环左移m位
function f1 (arr, m) {
    reverse(arr, 0, arr.length - 1);
    reverse(arr, 0, m - 1);
    reverse(arr, m, arr.length -1);
}

// 数组循环右移m位
function f2 (arr, m) {
    reverse(arr, 0, arr.length - 1);
    reverse(arr, 0, m - 1);
    reverse(arr, m, arr.length -1);
}