#python数据类型：

name = "hello"
online = True
age = 20
price = 6.3
print(name, online, age, price)
print(name[0:2])
print(type(name), type(online), type(age), type(price))

new_price = float("3")#带参构造
print(new_price, type(new_price))

#数组
arr = [1, 2, 3, 4, 5, 6]
print(len(arr))
print(arr[0], arr[1], arr[0:5])

#字典类型(类似于结构体？),用来存储键值对：
my_dict = {"a": 1, "b": 2, "c": "hello"}
my_dict["a"] = 100
print("a被修改为："+str(my_dict["a"]))
print(my_dict)

