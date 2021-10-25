#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 50000
long int it = 0;//累加趟数
clock_t start, finish;//排序的前后时间
double s;//排序所需的时间
int isave = 1;//用来控制每次文件的写入
//保存数据
void SaveData(char *filename,int *testarr)
{
	FILE *fp;
	int i = 0;
	static int k = 0;

	if (k == 0 || isave == 0)
	{
		fp = fopen("data.txt","w");
		if (fp == NULL)
		{
			printf("打开数据文件失败,数据未保存！\n");
			return;
		}
		k = 1;
		isave = 1;//控制是否清除文件数据重新写入
		fprintf(fp,"%s%d\n\n","当前测试数据总数为：",MAX);
	}
	else
	{
		fp = fopen("data.txt","a");
		if (fp == NULL)
		{
			printf("打开数据文件失败,数据未保存！\n");
			return;
		}
	}

	fclose(fp);
}

//产生随机数
void random(int *testarr)
{
	int i;

	srand((unsigned int) time(NULL) ); //设置随机数种子
	for (i = 0 ; i < MAX; i++)
	{
		testarr[i] = rand()%20000;//在0-9999之间产生30000个数
	}

}

//打印数组
void PrintIntArray(int *myarray,int arraylen)
{
	int i;
	for (i = 0; i < arraylen; i++)
	{
		printf("%d ",myarray[i]);
	}
	printf("\n");
}

//数据的排序  1是从小到大  2是从大到小
void InsertSort1(int *myarray,int arraylen,int isign)
{
	int i;
	int iTemp,iPos;
	//循环数组中的元素
	for (i = 1; i < arraylen; i++)
	{
		//设置插入值
		iTemp = myarray[i];
		iPos = i - 1;
		if (isign == 1)
		{
			//寻找插入值的位置
			while (iPos >=0 &&(iTemp < myarray[iPos]))
			{
				//插入数值
				myarray[iPos + 1]=myarray[iPos];//使小的元素不断后移
				iPos--;//递减遍历已排序的数组
			}
		}
		else
		{
			//寻找插入值的位置
			while (iPos >=0 &&(iTemp > myarray[iPos]))
			{
				//插入数值
				myarray[iPos + 1]=myarray[iPos];//使小的元素不断后移
				iPos--;//递减遍历已排序的数组
			}
		}
		//将当前元素插入在已排序的数组中
		myarray[iPos + 1]=iTemp;
	}
}

//冒泡排序
double BubbleSort(int *myarray/*数组*/,int arraylen/*数组长度*/)
{
	int i,j,k;
	start = finish = 0;
	it = 0;//初始化趟数
	start = clock();//获得cpu初始时间
	for (i = 1; i < arraylen; i++)
	{
		//从最后一个数据开始比较
		//将小的数据不断移到最前面
		for (j = arraylen - 1; j >= i; j--)
		{
			//按从小到大排序
			if (myarray[j] < myarray[j-1])
			{
				//交换数据
				k = myarray[j-1];
				myarray[j-1] = myarray[j];
				myarray[j] = k;
			}
			it++;//累加内部循环趟数
		}
		it++;//累加外部循环趟数
	}
	finish = clock();//获得cpu结束时间
	s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
	printf("冒泡法排序所需的趟数为：%ld\n",it);
	printf("冒泡法排序所需的时间为：%lf秒\n",s);
	//保存排序后的数据
	SaveData("bubbledata.txt",myarray);
    return s;
}

//快速排序
void FastSort(int left1,int right1,int *myarray)
{
	static int k = 1;
	int i,j;
	int middle,iTemp;
	i = left1;
	j = right1;
	//求中间值
	middle = myarray[(left1+right1)/2];

	do
	{
		//从左找小于中值得数
		while ((myarray[i]<middle)&&(i<right1))
		{
			it++;
			i++;
		}
		//从右找大于中值得数
		while ((myarray[j]>middle)&&(j>left1))
		{
			it++;
			j--;
		}
		if (i<=j)
		{
			iTemp=myarray[i];
			myarray[i]=myarray[j];
			myarray[j]=iTemp;
			i++;
			j--;
		}
		it++;
	} while (i<=j);//如果两边的下标交错，就停止（完成一次）

	//递归左半边
	if (left1<j)
	{
		FastSort(left1,j,myarray);
	}
	//递归右半边
	if (right1>i)
	{
		FastSort(i,right1,myarray);
	}

}
double FastSortFunc(int *myarray,int mylen)
{
	it = 0;
	start = clock();//获得cpu初始时间
	FastSort(0,mylen - 1, myarray);
	finish = clock();//获得cpu结束时间
	s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
	printf("快速排序法排序所需的趟数为：%ld\n",it);
	printf("快速排序法排序所需的时间为：%lf秒\n",s);
	//保存排序后的数据
	SaveData("fastdata.txt",myarray);
	return s;
}



//归并排序
//构建堆
void adjust(int *arr,int i,int length)
{
	int child ;
	int temp;
	for(temp = arr[i];2*i+1 < length;i = child)
	{
		child = 2 * i +1;

		/*找到较大的儿子*/
		if(child != length-1 && arr[child+1] > arr[child])
		{
			child+=1;
		}
		/*如果空穴元素小于该儿子，则空穴下滑*/
		if(temp < arr[child])
		{
			arr[i] = arr[child];
		}
		else
			break;
		it++;
	}
	/*将i位置的元素放到正确的位置*/
	arr[i] = temp;
}
//交换数据
void swap1(int *a1,int *a2)
{
	int k = *a1;
	*a1 = *a2;
	*a2 = k;
}
//堆排序
double Heap_sort(int *myarray,int arraylen)
{
	int k =1;
	int i = 0;
	start = finish = 0;
	it = 0;//初始化趟数
	start = clock();//获得cpu初始时间
	/*构建堆*/
	for(i = arraylen /2;i >= 0;i--)
	{
		adjust(myarray,i,arraylen);

	}
	for(i = arraylen-1;i > 0;i--)
	{
		/*填充i位置的空穴*/
		swap1(&myarray[0],&myarray[i]);

		/*每次都处理堆顶元素*/
		adjust(myarray,0,i);
		it++;//累加趟数
	}
	finish = clock();//获得cpu结束时间
	s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
	printf("堆排序法排序所需的趟数为：%ld\n",it);
	printf("堆排序法排序所需的时间为：%lf秒\n",s);
	//保存排序后的数据
	SaveData("heapdata.txt",myarray);
	return s;
}

//归并操作
void merge(int *a, int low, int mid, int high) //归并操作
{
	int k, begin1, begin2, end1, end2;
	begin1 = low;
	end1 = mid;
	begin2 = mid + 1;
	end2 = high;
	int *temp = (int *) malloc((high - low + 1) * sizeof(int));
	for(k = 0; begin1 <= end1 && begin2 <= end2; k++) //自小到大排序
	{
		if(a[begin1] <= a[begin2])
			temp[k] = a[begin1++];
		else
			temp[k] = a[begin2++];
		it++;
	}
	if(begin1 <= end1) //左剩
		memcpy(temp + k, a + begin1, (end1 - begin1 + 1) * sizeof(int));
	else //右剩
		memcpy(temp + k, a + begin2, (end2 - begin2 + 1) * sizeof(int));
	memcpy(a + low, temp, (high - low + 1) * sizeof(int)); //排序后复制到原数组
	free(temp); //释放空间

}
//归并排序
void Merge_sort(int *myarray,int begin, int end)
{
	int mid;
	if(begin < end)
	{
		it++;
		mid=begin+((end-begin)>>1);
		Merge_sort(myarray, begin, mid); //分治
		Merge_sort(myarray, mid + 1, end); //分治
		merge(myarray, begin, mid, end);  //合并两个已排序的数列
	}

}
//希尔排序
double Hillsort(int *myarray, int arraylen)
{
	int i,j,d;
	start = finish = 0;
	it = 0;//初始化趟数
	start = clock();//获得cpu初始时间
	d=arraylen/2;    /*确定固定增虽值*/
	while(d>=1)
	{
		for(i = d+1;i <= arraylen;i++)    /*数组下标从d+1开始进行直接插入排序*/
		{
			myarray[0]=myarray[i];    /*设置监视哨*/
			j=i-d;    /*确定要进行比较的元素的最右边位置*/
			while((j>0)&&(myarray[0]<myarray[j]))
			{
				myarray[j+d]=myarray[j];    /*数据右移*/
				j=j-d;    /*向左移d个位置V*/
				it++;
			}
			it++;
			myarray[j + d]=myarray[0];    /*在确定的位罝插入s[i]*/
		}
		it++;
		d = d/2;    /*增里变为原来的一半*/
	}
	finish = clock();//获得cpu结束时间
	s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
	printf("希尔排序法排序所需的趟数为：%ld\n",it);
	printf("希尔排序法排序所需的时间为：%lf秒\n",s);
	//保存排序后的数据
	SaveData("hilldata.txt",myarray);
	return s;
}
//直接选择法排序 从小到大
double SelectSort(int *myarray,int arraylen)
{
	int i,j;
	int iTemp,iPos;
	start = finish = 0;
	it = 0;//初始化趟数
	start = clock();//获得cpu初始时间
	for (i = 0; i < arraylen - 1; i++)
	{
		iTemp=myarray[i];//记录当前比对第一个值
		iPos=i;//记录其数组下标
		for (j = i+1; j < arraylen; j++)
		{
			//按从大到小排序
			if (myarray[j] < iTemp)
			{
				iTemp = myarray[j];//当大于则记录其值
				iPos = j;//记录其数组下标
			}
			it++;//累加内部循环趟数
		}
		it++;//累加外部循环趟数
		//交换数据
		myarray[iPos] = myarray[i];
		myarray[i] = iTemp;
	}
	finish = clock();//获得cpu结束时间
	s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
	printf("直接选择法排序所需的趟数为：%ld\n",it);
	printf("直接选择法排序所需的时间为：%lf秒\n",s);
	//保存排序后的数据
	SaveData("selectdata.txt",myarray);
	return s;
}
//直接插入排序  从小到大
double InsertSort(int *myarray,int arraylen)
{
	int i;
	int iTemp,iPos;
	it = 0;//初始化趟数
	start = finish = 0;
	start = clock();//获得cpu初始时间
	//循环数组中的元素
	for (i = 1; i < arraylen; i++)
	{
		//设置插入值
		iTemp = myarray[i];
		iPos = i - 1;
		//寻找插入值的位置
		while (iPos >=0 &&(iTemp < myarray[iPos]))
		{
			//插入数值
			myarray[iPos + 1]=myarray[iPos];//使小的元素不断后移
			iPos--;//递减遍历已排序的数组
			it++;//累加内部循环趟数
		}
		it++;//累加外部循环趟数
		//将当前元素插入在已排序的数组中
		myarray[iPos + 1]=iTemp;
	}
	finish = clock();//获得cpu结束时间
	s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
	printf("直接插入法排序所需的趟数为：%d\n",it);
	printf("直接插入法排序所需的时间为：%lf秒\n",s);
	//保存排序后的数据
	SaveData("insertdata.txt",myarray);
	return s;
}

int testarr[MAX];
enum data_type {m_random =1,m_increase,m_decrease};
void create_data(enum data_type m){
    if(m==m_random){
        random(testarr);//产生随机数，为避免影响其他排序，所以每次重新申请随机数
    }else if(m==m_increase){
        int i=0;
        for(;i<MAX;i++)
            testarr[i] = i;
    }else if(m==m_decrease){
        int i=0;
        for(;i<MAX;i++)
            testarr[i] = MAX-i;
    }
}
int main()
{
	enum data_type d_type = m_random;

	while (1)
	{
	    printf("______________________\n");
		scanf("%d",&d_type);
		printf("当前测试数据总数为：%d\n",MAX);
		double avg_time[7]={0};
		while(d_type<=3){
            double tmp_time=0;
            if(d_type==1){
                printf("------------------------数据为随机生成--------------\n");
            }else if(d_type==2){
                printf("------------------------数据为顺序从小到大生成--------------\n");
            }else{
                printf("------------------------数据为顺序从大到小生成--------------\n");
            }
            create_data(d_type);

            printf("正在排序...\n");
            /*
            if (d_type == 1)
            {
                // 不操作
                tmp_time=InsertSort(testarr,MAX);
            }
            else if (d_type == 2)
            {
                //采用插入排序从小到大先进行排序
                tmp_time = InsertSort1(testarr,MAX,1);
            }
            else if (d_type == 3)
            {
                //采用插入排序从大到小先进行排序
                tmp_time = InsertSort1(testarr,MAX,2);
            }
            else
            {
                printf("输入错误！！！");
                system("pause");//暂停程序
                system("cls");//清屏
                continue;
            }
            */
           avg_time[0]=(avg_time[0]+=tmp_time)/3.0;
            
			tmp_time=InsertSort(testarr,MAX);
			printf("\n");
            //InsertSort(testarr,MAX);
            //printf("\n");
			avg_time[1] +=tmp_time;
			//test
			create_data(d_type);
            tmp_time=BubbleSort(testarr,MAX);
            avg_time[2]=(avg_time[2]+=tmp_time)/3.0;
            printf("\n");
            tmp_time=FastSortFunc(testarr,MAX);
            avg_time[3]=(avg_time[3]+=tmp_time)/3.0;
            printf("\n");
            tmp_time=Heap_sort(testarr,MAX);
            avg_time[4]=(avg_time[4]+=tmp_time)/3.0;
            printf("\n");
            it = 0;//初始化趟数
            start = finish = 0;
            start = clock();//获得cpu初始时间
            Merge_sort(testarr,0,MAX - 1);
            finish = clock();//获得cpu结束时间
            s = (double)(finish - start)/CLOCKS_PER_SEC;//计算秒数
            tmp_time=s;
            avg_time[5]=(avg_time[5]+=tmp_time)/3.0;
		//保存排序后的数据
            SaveData("mergedata.txt",testarr);
            printf("\n");
            tmp_time=Hillsort(testarr,MAX);
            avg_time[6]=(avg_time[6]+=tmp_time)/3.0;
            printf("\n");
            SelectSort(testarr,MAX);
            d_type++;
        }
        int i; 
        for(i=0;i<=6;i++){
                printf("%lf\t",avg_time[i] / 3.0);
        }
	}

	isave = 0;
    system("pause");//暂停程序
    system("cls");//清屏
	return 0;
}

