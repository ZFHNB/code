package shiyan6_2;

public abstract class Food {
	private String name;
	public abstract String getName();
	public void show (){
		System.out.println("工厂正在生产..." + getName());
	}
}
