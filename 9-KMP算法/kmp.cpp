#include <string>

using std:: string;

int KMP(string str, string subStr, int next[])
{
	int i = 0, j = 0;
	while (i < str.size() && j < subStr.size()) {
		if (j == -1 || str[i] == subStr[j]) {
			// 1. 如果 j 等于 -1, 说明上一次 str[0] 和 subStr[0] 不相等，
			//    需要把 i 加 1（即++i）, 把 j 置为 0（即++j）
			// 2. 如果当前字符匹配成功，令i++，j++
			i++;
			j++;
		} else {
			// 如果j不等于-1，说明：上一次不是str[0]和subStr[0]不相等，不需要移动i
			// 并且现在：当前字符匹配失败（即str[i] != subStr[j]），则需要令 i 不变，j = next[j]

			
            j = next[j];
		}

		if (j == subStr.size())
			return i - subStr.size(); // 返回匹配区间的首位地址
		else
			return -1;
	}
}

// next 数组考虑的是：除当前字符(即j)外的最长的相同的前后缀长度(即k)
// KMP 的next 数组相当于告诉我们：
// 当模式串中的某个字符跟文本串中的某个字符匹配失配时，模式串下一步应该跳到哪个位置。
// 如模式串中在j 处的字符跟文本串在i 处的字符匹配失配时，
// 下一步用next [j] 处的字符继续跟文本串i 处的字符匹配，相当于模式串向右移动 j - next[j] 位
// 即：失配时，模式串向右移动的位数为：已匹配字符数 - 失配字符的上一位字符所对应的最大长度值
void getNext(string subStr, int next[])
{
	next[0] = -1; // 循环前，写入next[0]=-1

	int k = -1, j = 0;
	// 注意：这里j 最多指向subStr 的倒数第二个位置。
	// 		 因为后边还要++j（这时j 指向倒数第一的位置），然后写入next[j]
	while (j < subStr.size() - 1) { 
		// subStr[k]表示前缀，subStr[j]表示后缀
		if (k == -1 || subStr[k] == subStr[j]) {
			++k;
			++j;
			// 情形1：第一次循环时，写入next[1]=0。
			// 		  或者：不断递归前缀索引k = next[k]的过程中，并没有找到长度更短的相同前缀后缀。
			// 				最后k变成了-1。只好写入next[j+1]=0
			// 情形2：之后的循环时，写入next[j+1] = next[j] + 1 = k + 1
			next[j] = k; 
		} else {
			k = next[k];
		}
	}
}

