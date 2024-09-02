package shiyan10;

public class Test {

	public static void main(String[] args) {
		TravelAbroad person1 = new NeedVisa("001", "李四", 10,"印度尼西亚");
		person1.Process();
		
		TravelAbroad person2 = new Landvisa("002", "王五", 20,"加拿大");
		person2.Process();
	}

}
