package shiyan6_2;

public abstract class KFC_Factory {
	
	public String name;
	public abstract Food produce();
	public  void show(){
		System.out.println("生产出的食品是" + name);
	}
}
