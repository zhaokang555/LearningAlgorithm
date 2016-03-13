function swap(arr, p1, p2) {
    var temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

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
        pivot = left; // 以arr[left]为基准，将arr分成两部分
        
    while (i < j) {
        // 顺序很重要, 要先从右往左找。这样才能保证当i、j相遇时arr[i]<=arr[left]
        while (arr[j] >= arr[pivot] && i < j) // 这里的i<j不能漏写
            j--;
        while (arr[i] <= arr[pivot] && i < j)
            i++;

        // 当哨兵i和哨兵j没有相遇时
        // 交换两个数在数组中的位置
        if (i < j)
            swap(arr, i, j);
    }

    // 最终将基准数归位，此时i==j
    swap(arr, pivot, i);

    quickSort(arr, left, i - 1); // 继续处理左边的，这里是一个递归的过程
    quickSort(arr, i + 1, right); // 继续处理右边的，这里是一个递归的过程
}

