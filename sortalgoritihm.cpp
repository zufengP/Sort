#include "sortalgoritihm.h"

SortAlgoritihm::SortAlgoritihm()
{
    count=0;//初始化
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }

}
//初始化数组
void SortAlgoritihm::init()
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%int (pow(2,15)); //数组赋值
    }
}
//头插入法扎入数据
Node* SortAlgoritihm::creatNodeListHeade()
{
    srand(time(0));

    int data;
    Node *p;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    for(int i=0;i<n;i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->next = NULL;
        data=rand()%int (pow(2,15));
        //链表赋值
        p->data = data;
        p->next = head->next;
        head->next= p;
    }
    return head;
}
//控制台打印数据
//归并算法
void SortAlgoritihm::displayNodeList1(Node *head)
{
    if(head == NULL)
    {
        return ;
    }
    Node *p;
    p=head;
    while(p != NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<endl;
}
//其他算法
void SortAlgoritihm::displayNodeList(Node *head)
{
    if(head == NULL)
    {
        return ;
    }
    Node *p;
    p=head->next;
    while(p != NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<endl;
}
//排序前数据存在text文档内
void SortAlgoritihm::BeforeRecordFile()
{
    FILE *fp;
    if((fp=fopen("text","w+")) == NULL)
    {
        cout<<"can't open the file";
        exit(0);
    }
    Node *p;
    p=head->next;
    while(p != NULL)
    {
        fprintf(fp," %d ",p->data);
        p=p->next;
    }
    fclose(fp);
}
//排序后数据存在text1文档内
void SortAlgoritihm::AfterRecordFile()
{
    FILE *fp;
    if((fp=fopen("text1","w+")) == NULL)
    {
        cout<<"can't open the file";
        exit(0);
    }
    Node *p;
    p=head->next;
    while(p != NULL)
    {
        fprintf(fp," %d ",p->data);
        p=p->next;
    }
    fclose(fp);
}
//冒泡排序
void SortAlgoritihm::BubbleSort(Node *head)
{
    clock_t start;
    clock_t end;
    double timeUsed;

    start =clock();

    if(head == NULL)
    {
        return ;
    }
    Node *p,*q,*r;
    r=head->next;

    while(r !=NULL)
    {
        //前后两个指针比较大小
        p=head->next;
        q=p->next;
        while( q != NULL)
        {
            //前面数比后面大，交换它们
            if( p->data > q->data)
            {
                int temp;
                temp=q->data;
                q->data=p->data;
                p->data=temp;
                //count++;
            }
            p=q;
            q=q->next;
        }
        r=r->next;
    }
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"BubbleSort  timeUsed="<<timeUsed<<"s"<<endl;

}

//直接插入排序
void SortAlgoritihm::Straight_Insert_Sort(Node *head)
{

    //计时器处理
    clock_t start;
    clock_t end;
    double timeUsed;

    start = clock();

    if(head == NULL)
    {
        return ;
    }
    Node *p,*q,*r;
    //使p为head的第二个指针,成为插入的无序表
    p=head->next->next;
    //此时head为一个值的有序表
    head->next->next=NULL;

    while(p !=NULL)
    {
        q=p->next;//暂时保存p的后继节点
        //由于单链表无法指向前置指针
        //故只能从头结点前后依次插值
        r=head;// 先用r来保存head
        while(r->next!=NULL && r->next->data < p->data)
        {
            r = r->next;
        }
        //插值并钩链
        p->next = r->next ;
        r->next = p ;
        p = q ;// 用p指向q，使循环指向无序表的下一个结点

    }
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"Straight_Insert_Sort  timeUsed="<<timeUsed<<"s"<<endl;
}

//简单选择排序
void SortAlgoritihm::simple_selection_sort(Node *head)
{
    //计时器处理
    clock_t start;
    clock_t end;
    double timeUsed;

    start = clock();

    Node *p,*q,*r;
    p=head->next; //初始化p结点为头结点的后继结点
    int min; //选出每次循环最小一个

    while(p != NULL)
    {
        q=p;//是q一直为p的后继节点的前结点,比较大小
        //用r结点代替p比较大小，防止循环一次p直接为NULL
        for(r=p->next; r != NULL ;r=r->next)
        {
            if( q->data > r->data)
            {
                q=r;//找出最小值的结点
            }
        }
        //若上述循环运行且最小值结点不为q
        if( q != p)
        {
            min=q->data;
            q->data=p->data;
            p->data=min;
        }
        p=p->next;
    }
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"simple_selection_sort  timeUsed="<<timeUsed<<"s"<<endl;
}
//快速排序
void SortAlgoritihm::QuickSort(Node *head,Node *high)
{
    //如果head和high结点为空，返回
    if(head == NULL)
    {
        return ;
    }

    if (head->next == high)
	{
		return ;
	}
	Node *mid=head->next;
	Node *p=head;//p 连接的是比mid的值小的链表
    Node *q=mid;//q连接是比(包括mid)mid值大的链表
	Node *t=mid->next;//指向mid后继结点
	int k;
	k=mid->data; //这里取第一个值为基数
	while (t != high)
	{
		if (t->data < k)
		{
			p=p->next=t;// 比基数小钩链
		}
		else
		{
			q=q->next=t;//比基数大钩链
		}
		t=t->next;
	}
	// p链表连接上q链表
	p->next=mid;
	q->next=high;
	//q链表尾部指向NULL

	QuickSort(head,mid);//递归调用QuickSort
	QuickSort(mid,high);
}

//归并排序
//自下而上
Node* SortAlgoritihm::MergemidNode(Node *head)
{
    Node *Ha,*Hb;
    Ha=head->next;
    Hb=head;
    while( Ha != NULL && Ha->next != NULL)
    {
        Ha=Ha->next->next;//分为两路，一次跳两个
        Hb=Hb->next;

    }
    return Hb;//中间结点一分为二
}
//合并链表
Node *SortAlgoritihm::MergeNode(Node *h1,Node *h2)
{
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    Node *p ,*q;
    p = h1;
    q = h2;
    Node *Temp=NULL;
    if(p->data <= q->data)
    {
        Temp = p;
        p = p->next;
    }
    else
    {
        Temp = q;
        q = q->next;
    }
    Node *r = Temp; //初始化头结点不为空，且为最小值的头节点
    while (p != NULL && q != NULL )
    {
        if (p->data <= q->data)
        {
            Temp->next = p;
            Temp = p;
            p = p->next;
        }
        else
        {
            Temp->next = q;
            Temp = q;
            q = q->next;
        }

    }
    //合并剩余部分
    if( p !=NULL)
    {
        Temp->next = p;
    }
    else
    {
        Temp->next = q;
    }
    return r ;
}
Node *SortAlgoritihm::MergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = MergemidNode(head); //获取中间结点
    Node *h1 = head; //链表前半部分
    Node *h2 = mid->next;//链表后半部分
    mid->next = NULL;
    //displayNodeList(h1);
    //displayNdeList(h2);
    h1=MergeSort(h1); //排序前半部分数据
    //displayNodeList(h1)
    h2=MergeSort(h2); //排序后半部分数据
    head =MergeNode(h1, h2);//两个链表合并成一个有序链表
    return head;
}


void SortAlgoritihm::draw(int a[])
{
    outtextxy(20,20,const_cast<char *>("可视化排序"));
    for(int j=0;j<n;j++)
    {
         line(j*0.04+40,700,j*0.04+40,700-a[j]*0.02);
    }
    printf("\n");
}
void SortAlgoritihm::EXlime(int a[],int j)
{
    line(j*0.04+40,700,j*0.04+40,700-a[j]*0.02);
}
void SortAlgoritihm::ShowBubbleSort(int a[])
{
    /*clock_t start;
    clock_t end;
    double timeUsed;

    start =clock();*/
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<n-1;k++)
        {
            //如果前面比后面大，交换它们
            if(a[k] > a[k+1])
            {

                //画图显示两条线交换
                setcolor(0);
                EXlime(a,k);
                setcolor(0);
                EXlime(a,k+1);
                int temp;
                temp=a[k+1];
                a[k+1]=a[k];
                a[k]=temp;
                setcolor(15);
                EXlime(a,k);
                setcolor(15);
                EXlime(a,k+1);
            }
            /*cleardevice();
            draw(a);*/
        }
    }
    /*end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"BubbleSort  timeUsed="<<timeUsed<<"s"<<endl;*/
}
void SortAlgoritihm::ShowSelectSort(int a[])
{
    /*clock_t start;
    clock_t end;
    double timeUsed;

    start =clock();*/
    int min,temp;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;//得到一轮最小值的位置
            }
        }
        //如果不相等，最小值与第i位交换
        if(i != min)
        {
            //画图显示两条线交换
            setcolor(0);
            EXlime(a,i);
            setcolor(0);
            EXlime(a,min);
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            setcolor(15);
            EXlime(a,i);
            setcolor(15);
            EXlime(a,min);
        }
    }
    /*end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"SelectSort  timeUsed="<<timeUsed<<"s"<<endl;*/
}
void SortAlgoritihm::ShowQuickSort(int a[],int low,int high)
{
    if(low >= high)
    {
        return ;
    }
    int i=low;
    int j=high;
    int r=a[low];//设为基准数
    while( i != j)
    {
        //从基数右边选者一个比基数小的位置
        while( i < j && a[j] >= r)
        {
            j--;
        }
        //从基数左边选者一个比基数大的位置
        while(i < j && a[i] <= r)
        {
            i++;
        }
        //两者交换
        if( i < j)
        {
            //画图显示两条线交换
            setcolor(0);
            EXlime(a,i);
            setcolor(0);
            EXlime(a,j);
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            setcolor(15);
            EXlime(a,i);
            setcolor(15);
            EXlime(a,j);
        }
        //交替进行，直到结束
    }
    //将数组基数按顺序相连
    a[low]=a[i];
    a[i]=r;
    //排序先左后右
    ShowQuickSort(a,low,i-1);
    ShowQuickSort(a,i+1,high);
}
void SortAlgoritihm::ShowInsertSort(int a[])
{
    clock_t start;
    clock_t end;
    double timeUsed;

    start =clock();

    int temp;
    for(int i=1;i<n;i++)
    {
        temp =a[i]; //每次插入的值
        int j;
        //如果这个值比前面大，交换，依次向前比较
        //直到为顺序升序位置
        for(j=i-1;i>0 && temp < a[j]; j--)
        {
            //画图显示两条线交换
            setcolor(0);
            EXlime(a,j+1);
            a[j+1]=a[j];
            setcolor(15);
            EXlime(a,j+1);
        }
        a[j+1]=temp;
    }
    /*end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"InsertSort  timeUsed="<<timeUsed<<"s"<<endl;*/
}
void SortAlgoritihm::Merge(int a[], int a1[], int Left, int mid, int Right)
{
    int i = Left;
    int j = mid + 1;
    int k = Left;
    //将数组a赋值a1
    while (i <= mid && j <= Right)
    {
        //如果a[i]小于等于a[j]
        //则将a[i]的值赋给a1[k],之后i,k各加一,
        if (a[i] <= a[j])
        {
            a1[k++] = a[i++];
        }
        //否则，将a[j]的值赋给a1[k],j,k各加一
        else
        {
            a1[k++] = a[j++];
        }
    }
    //若[left,mid]区间还有剩余未被赋值
    //将剩下的值逐步赋值a1
    if (i <= mid)
    {
        while (i <= mid)
        {
            a1[k++] =a[i++];
        }
    }
    //若[mid,rigth]区间还有剩余未被赋值
    //将剩下的值逐步赋值a1
    else
    {
        while (j <= Right)
        {
            a1[k++] = a[j++];
        }
    }
    //归并后在重新赋值给数组a
    for (int i = Left; i <= Right; i++)
    {

        setcolor(0);
        EXlime(a,i);
        a[i] = a1[i];
        setcolor(15);
        EXlime(a,i);

    }

}

void SortAlgoritihm::ShowMergeSort(int a[], int a1[], int Left, int Right)
{
    if (Left < Right)
    {
        int mid = (Left + Right) / 2;
        //先左后右分
        ShowMergeSort(a, a1, Left, mid);
        ShowMergeSort(a, a1, mid + 1, Right);
        //依次在合并
        Merge(a, a1, Left, mid, Right);
    }
}
void SortAlgoritihm::CheckAlg()
{
    clock_t start;
    clock_t end;
    double timeUsed;

    Node *head1,*head2,*head3,*head4,*head5;
    head1=head2=head3=head4=head5=creatNodeListHeade();//比较时间，则每个链表初始值都应相同

    BeforeRecordFile();//将排序前链表存储在文件中

    //displayNodeList(head);
    cout<<"链式结构消耗时间"<<endl;
    BubbleSort(head1);
    Straight_Insert_Sort(head2);
    simple_selection_sort(head3);
    //displayNodeList(head);

    start =clock();
    QuickSort(head4,NULL);
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"QuickSort timeUsed="<<timeUsed<<"s"<<endl;

    head5=head5->next;
    start =clock();
    head5=MergeSort(head5);
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"MergeSort timeUsed="<<timeUsed<<"s"<<endl;
    //displayNodeList1(head5);

    //将排序后链表存储在文件中
    AfterRecordFile();

    /*cout<<"顺序结构消耗时间"<<endl;
    init();
    ShowBubbleSort(a);
    init();
    ShowInsertSort(a);
    init();
    ShowSelectSort(a);
    init();
    start =clock();
    ShowQuickSort(a,0,n-1);
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"QuickSort timeUsed="<<timeUsed<<"s"<<endl;
    init();
    start =clock();
    int a1[n];
    ShowMergeSort(a,a1,0,n-1);
    end =clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"MergeSort timeUsed="<<timeUsed<<"s"<<endl;*/

    //显示排序过程
    int m,k;
    cout<<"Do you wanna watch the Sorting change(1 or -1)?"<<endl;
    cin>>m;
    while( m != -1)
    {
        init();
        draw(a);
        cout<<"1.冒泡排序"<<endl;
        cout<<"2.选择排序"<<endl;
        cout<<"3.快速排序"<<endl;
        cout<<"4.插入排序"<<endl;
        cout<<"5.归并排序"<<endl;
        cout<<"Which one is you favorite Sorting change?"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
                ShowBubbleSort(a);
                break;
            case 2:
                ShowSelectSort(a);
                break;
            case 3:
                ShowQuickSort(a,0,n-1);
                break;
            case 4:
                ShowInsertSort(a);
                break;
            case 5:
                int a1[n];
                ShowMergeSort(a,a1,0,n-1);
                break;
            default :
                cout<<" please Enter again";
                cin>>k;
        }
        cout<<"Do you wanna watch again?(1 or -1)"<<endl;
        cin>>m;
        cleardevice();
    }
}

