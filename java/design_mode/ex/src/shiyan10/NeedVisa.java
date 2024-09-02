package shiyan10;

public class NeedVisa extends TravelAbroad{

	public NeedVisa(String person, String name, int Days,String country) {
		super(person, name, Days,country);
	}
	public void Visa() {
		System.out.println("需要办签证...签证时间是" + Days + "天");
	}
}
