function quicksort(arr, left, right) {
    // 跳出递归的条件
    if (left < right)
        return;

    // 判断参数个数
    switch (arguments.length) {
        case 1:
            left = arr[0];
            right = arr[arr.length - 1];
            break;
        case 3:
            break;
        default:
            throw Error('number of arguments must be 1 or 3');
    }

    var i = left,
        j = right;
    while (i < j) {
        // 以arr[left]为基准
        // 顺序很重要, 要先从右往左找
        while (arr[j] >= arr[left])
            j--;
        while (arr[i] <= arr[left])
            i++;

        // 交换两个数在数组中的位置
        if (i < j) { // 当哨兵i和哨兵j没有相遇时
            var temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 最终将基准数归位
    temp = a[left];
    a[left] = a[i];
    a[i] = temp;

    quicksort(arr, left, i - 1); // 继续处理左边的，这里是一个递归的过程
    quicksort(arr, i + 1, right); // 继续处理右边的，这里是一个递归的过程
}

