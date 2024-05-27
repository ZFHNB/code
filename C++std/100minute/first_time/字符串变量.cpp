#include <iostream>
using namespace std;

void swap(string s1, string s2)
{
	string temp = s1;//1.字符串赋值操作
	s1 = s2;
	s2 = temp;
}

int main()
{
	string string1="Hello world", string2, string3, temp;
	cout<<"Please input two strings:";
	cin>>string2>>string3;
	
	//2.拼接字符串：
	
	cout<<"string1 + string2 = "<<string1 + string2<<endl;
	
	//3.获取字符串长度：

	int str1_len = string1.length();
	int str2_len = string2.size();
	
	cout<<"string1的长度为："<<str1_len<<endl;
	cout<<"string2的长度为："<<str2_len<<endl;
	
	//4.访问字符串中的某一位
	
	cout<<"通过遍历输出字符串：";
	for(int i=0;i<str1_len;i++){
		cout<<string1[i];
	}
	cout<<'\n';
	
	//5.查找和替换
	//查找子串
	int found = string1.find("world");
	if(found >= 0 && found < str1_len)
	{
		cout<<"字符串world从"<<found<<"位开始"<<"将world替换为universe"<<endl;
	}
	//替换子串
	string1.replace(found, 5, "universe");
		
	//6.大小写转换(亦可使用ASCII码)
	//使用增强for循环
	//转换大写(toupper())：
	for(char &c : string1)
	{
		c = toupper(c);
	}
	cout<<"将string1转换为大写："<<string1<<endl;
	
	//转换小写(tolower())
	for(char &c : string1)
	{
		c = tolower(c);
	}
	cout<<"将string1转换为小写："<<string1<<endl;
	
	//7.大小比较：
	if(string2>string1)
		swap(string1,string2);
	if(string3>string1)
		swap(string1,string3);
	if(string3>string2)
		swap(string2,string3);
		
	cout<<"大小比较："<<string1<<"   >   "<<string2<<"   >   "<<string3<<endl;
	
	return 0;
}
