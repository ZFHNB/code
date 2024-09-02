package shiyan7;

public abstract class TV {
	protected String mark;
	public abstract int getId();//抽象产品，不知道编号
	public  void printInfo(){
		System.out.println("生产出一台" + mark + "牌，编号为" + getId() + "的电视机");
	}
}
