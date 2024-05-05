#include <stdio.h>
#include <stdlib.h>

struct Book
{
	char title[128];
	char author[40];
	struct Book *next;
};

void getInput(struct Book *book);
void addBook(struct Book **library);
void printLibrary(struct Book *library);
void releaseLibrary(struct Book **library);

void getInput(struct Book *book)
{
	printf("������������");
	scanf("%s", book->title);
	printf("���������ߣ�");
	scanf("%s", book->author);
}

void addBook(struct Book **library)//libraryΪָ��book�ṹ���ָ���ָ�루*libraryָ��book�ṹ�壩
{
	struct Book *book, *temp;
	
	book = (struct Book *)malloc(sizeof(struct Book));
	if(book == NULL){
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	
	getInput(book);
	
	if(*library != NULL)
	{
		temp = *library;
		*library = book;
		book->next = temp;
	}
	else
	{
		*library = book;
		book->next = NULL;
	}
}

void printLibrary(struct Book *library)
{
	struct Book *book;
	int count = 1;
	
	book = library;
	
	printf("������Ľ��Ϊ��\n");
	while(book != NULL)
	{
		printf("Book%d",count);
		printf("������%s\n",book->title);
		printf("���ߣ�%s\n",book->author);
		book = book->next;	
		count++;
	}
}

void releaseLibrary(struct Book **library)
{
	struct Book *temp;
	while(*library != NULL)
	{
		temp = *library;
		*library = (*library)->next;
		free(temp);
	}
}

int main()
{
	struct Book *library = NULL;
	char ch;
	
	while(1)
	{
		printf("�����Ƿ���Ҫ�����鼮��Ϣ��Y/N��");
		do{
			ch = getchar();
		}while(ch != 'Y' && ch != 'N');
		
		if(ch == 'Y')
		{
			addBook(&library);
		}
		else
		{
			break;
		}
	}
	
	printf("�����Ƿ���Ҫ��ӡͼ����Ϣ��Y/N��");
	do{
			ch = getchar();
	}while(ch != 'Y' && ch != 'N');
			
	if(ch == 'Y')
	{
		printLibrary(library);
	}
	
	releaseLibrary(&library);
	
	return 0;
}
