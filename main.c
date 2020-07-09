#include <stdio.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1025

typedef struct Test {
    int address;
    int next;
    int data;
} Test;

int main() {
    int address;
    int number, k;
    scanf("%d %d %d", &address, &number, &k);
    struct Test testArray[number];
    int index = 0;
    for (int i = 0; i < number; ++i) {
        scanf("%d %d %d", &testArray[i].address, &testArray[i].data, &testArray[i].next);
    }
    //按照链表的地址顺序排序
    for (int i = 0; i < number; i++) {
        for (int j = i; j < number; j++) {
            //找到指定的地址
            if (testArray[j].address == address) {
                Test temp = testArray[i];
                testArray[i] = testArray[j];
                testArray[j] = temp;
                //交换位置以后
                //把这个地址的next 作为下一个指定的地址
                address = testArray[i].next;
                //如果地址为-1了 就跳过
                if (testArray[i].next == -1) {
                    number = i + 1;
                }
                break;
            }
        }
    }
    //判断是否有足够的数据操作
    //对每间隔k个倒着排序
    while (number - index * k >= k) {
        for (int i = index * k; i < index * k + k / 2; i++) {
            struct Test temp = testArray[i];
            testArray[i] = testArray[index * k + (index + 1) * k - i - 1];
            testArray[index * k + (index + 1) * k - i - 1] = temp;
        }
        index++;
    }
    //把地址换一下 后面的地址，变成前面的next
    testArray[number - 1].next = -1;
    for (int i = number - 1; i > 0; i--) {
        testArray[i - 1].next = testArray[i].address;
    }
    //输出结果即可
    for (int l = 0; l < number; ++l) {
        if (l != number - 1) {
            printf("%05d %d %05d\n", testArray[l].address, testArray[l].data, testArray[l].next);
        } else {
            printf("%05d %d %d\n", testArray[l].address, testArray[l].data, testArray[l].next);
        }
    }
    return 0;
}
