function quickSort(arr, left, right) {
    // 判断参数个数
    switch (arguments.length) {
        case 1:
            left = 0;
            right = arr.length - 1;
            break;
        case 3:
            break;
        default:
            throw Error('number of arguments must be 1 or 3');
    }

    // 跳出递归的条件
    if (left >= right)
        return;

    var i = left,
        j = right,
        temp = arr[i];
    while (i < j) {
        // 以arr[left]为基准
        // 顺序很重要, 要先从右往左找
        while (arr[j] >= arr[left] && i < j)
            j--;
        while (arr[i] <= arr[left] && i < j)
            i++;

        // 交换两个数在数组中的位置
        if (i < j) { // 当哨兵i和哨兵j没有相遇时
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 最终将基准数归位
    temp = arr[left];
    arr[left] = arr[i];
    arr[i] = temp;

    quickSort(arr, left, i - 1); // 继续处理左边的，这里是一个递归的过程
    quickSort(arr, i + 1, right); // 继续处理右边的，这里是一个递归的过程
}

