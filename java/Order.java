public class Order
{
    static int[] a =  {108, 10, 23, 56, 92, 37};
    static int i;

    public static void main(String[] args)
    {
        order(a, 0);
        printout(a);
    }

    public static void printout(int[] a)
    {
        System.out.println("排序后的数组：");
        for(int num : a)
        {
            System.out.println(num + " ");
        }
    }

    public static void swap(int[] a, int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void order(int a[], int i)
    {
        if(i == a.length - 1)//查找到最后一位，跳出递归
        {
            return ;
        }

        int k = i;//记录当前位
        for(int j = i + 1; j < a.length; j++)//从a[i]到a.length - 1找到当前的最小值
        {
            if(a[k] > a[j])
            {
                k = j;//记录较小数在哪一位
            }
        }
        if(k != i)//将找到的最小值放到无序区第一位，使其变成有序区第一位
        {
            swap(a, i, k);
        }
        order(a, i + 1);//进入下一层递归（下一层递归的i在上一层的基础上+1）
    } 
}