package shiyan10;

public class Test {

	public static void main(String[] args) {
		TravelAbroad person1 = new NeedVisa("001", "����", 10,"ӡ��������");
		person1.Process();
		
		TravelAbroad person2 = new Landvisa("002", "����", 20,"���ô�");
		person2.Process();
	}

}
