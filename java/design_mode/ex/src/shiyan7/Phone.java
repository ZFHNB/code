package shiyan7;

public abstract class Phone {
	protected String mark;
	
	public abstract int getId();
	public  void printInfo(){
		System.out.println("生产出一部" + mark + "牌，编号为" + getId() + "的手机");
	}
}
