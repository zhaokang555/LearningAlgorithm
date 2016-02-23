function swap(arr, p1, p2) {
    var temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

function bubbleSort(arr) {
    var len = arr.length;
    // 冒泡排序的核心部分
    // n个数排序，只用进行n-1趟
    for (var i = 1; i <= len-1; i++) {
        // 从第1位开始比较直到最后一个尚未归位的数，
        // 想一想为什么到n-i就可以了。
        for (var j = 1; j <= len-i; j++) {
            // 比较大小并交换
            if (arr[j-1] > arr[j])
                swap(arr, j-1, j);
        }
    }
    return arr;
}

