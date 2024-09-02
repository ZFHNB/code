package shiyan6_1;

public abstract class Laptop {
	public String name;
	public abstract int getId();
	public  void show(){
		System.out.println("生产出一台" + name + "牌，编号为" + getId() + "的笔记本电脑");
	}
}
