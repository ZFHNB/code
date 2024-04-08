#include <stdio.h>

struct Date{
	int year;
	int month;
	int day;
};

struct Book{
	char title[128];
	char author[40];
	float price;
	struct Date date;
	char publisher[40];
}book = {
	"《带你学习带你飞》",
	"小甲鱼",
	48.8,
	{2017,11,11},
	"清华大学出版社"
};

int main(){
	
	struct Book *pt = &book;

	printf("通过点号运算符访问结构体成员：\n");
	printf("书名:%s\n", book.title);
	printf("作者：%s\n",book.author);
	printf("售价: %.2f\n", book.price);
	printf("出版日期：%d-%d-%d\n", book.date.year, book.date.month, book.date.day);
	printf("出版社: %s\n", book.publisher);
	
	printf("\n通过结构体指针访问，法一：(*结构体指针).成员名\n");
	printf("书名:%s\n", (*pt).title);
	printf("作者：%s\n",(*pt).author);
	printf("售价: %.2f\n", (*pt).price);
	printf("出版日期：%d-%d-%d\n", (*pt).date.year, (*pt).date.month, (*pt).date.day);
	printf("出版社: %s\n", (*pt).publisher);
	
	printf("\n通过结构体指针访问，法二：结构体指针->成员名\n");
	printf("书名:%s\n", pt->title);
	printf("作者：%s\n",pt->author);
	printf("售价: %.2f\n", pt->price);
	printf("出版日期：%d-%d-%d\n", pt->date.year, pt->date.month, pt->date.day);
	printf("出版社: %s\n", pt->publisher);
	
	return 0; 
}
