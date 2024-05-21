
#ifndef SORTALGORITIHM_H
#define SORTALGORITIHM_H

#include<ctime>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<math.h>
#include "winbgim.h"

#define Length 1000
#define Width 1000

#define n 20000

using namespace std;
//创建链表结构体
struct Node
{
    int data;
    Node *next;
};

class SortAlgoritihm
{
    public:
        //链式结构表排序
        SortAlgoritihm();
        Node *creatNodeListHeade();//头插入法插入数据
        void BubbleSort(Node *head); //冒泡排序
        void Straight_Insert_Sort(Node *head); //直接插入排序
        void simple_selection_sort(Node *head); //简单选择排序 升序
        void QuickSort(Node *head,Node *high); //快速排序,递归算法
        Node *MergemidNode(Node *head);
        Node *MergeNode(Node *h1,Node *h2);
        Node *MergeSort(Node *head); //归并排序 一分为二

        void displayNodeList(Node *head);//显示数据
        void displayNodeList1(Node *head);//用于归并排序显示数据
        void BeforeRecordFile();//排序前的数据
        void AfterRecordFile();//排序后的数据
        void CheckAlg(); //测试结果

        //数组显示各种排序效果
        void init();//初始化并重新赋值数据a[n]
        void ShowBubbleSort(int a[]); //冒泡排序显示
        void ShowSelectSort(int a[]); //简单选择排序 升序显示
        void ShowQuickSort(int a[],int low,int high);//快速排序,递归算法
        void ShowInsertSort(int a[]);//插入排序
        void ShowMergeSort(int a[], int a1[], int Left, int Right);//归并排序
        void Merge(int a[], int a1[], int Left, int mid, int Right);
        void draw(int a[]); //画图
        void EXlime(int a[],int j); //交换两条线
    private:
        //int n; //随机数的个数
        int count;//移动的次数
        int a[n]; //用于效果排序的数组
        Node *head;
};

#endif // SORTALGORITIHM_H
