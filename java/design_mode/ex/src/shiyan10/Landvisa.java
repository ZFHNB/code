package shiyan10;

public class Landvisa extends TravelAbroad{

	public Landvisa(String person, String name, int Days,String country) {
		super(person, name, Days,country);
	}
	public void Visa() {
		System.out.println("��Ҫ�����ǩ֤,ǩ֤ʱ����" + Days + "��");
	}
}
