package shiyan10;

public class NoVisa extends TravelAbroad{

	public NoVisa(String person, String name, int Days,String country) {
		super(person, name, Days,country);
	}
	
	public boolean hook() {
		return false;
	}
	public void Visa() {
		System.out.println("����Ҫ��ǩ֤��ǩ֤ʱ����" + Days + "��");
	}
}
