def sum_values(values):
    s = 0
    for v in values:
        s = s + v
    return s

array = [1, 3, 5, 7, 9]
print(sum_values(array))

def show_name(name = "zhangsan"):
    print(name)

show_name()
show_name("lisi")
