package shiyan10;
import java.util.HashSet;
import java.util.Iterator;

public class TravelAbroad {
	String person;//���֤��
	String name;//����
	int Days;//ǩ֤��Чʱ��
	String country;//ȥ��Ŀ�ĵ�
	public TravelAbroad(String person,String name,int Days,String country) {
		this.person = person;
		this.name = name;
		this.Days = Days;
		this.country = country;
	}
	public void Process(){
		passport();
		if(hook())
			Visa() ;
		tickets();
		arrive();
	}
	//���ӷ�����
	public boolean hook() {
		return true;
	}
	public void passport() {
		System.out.println("���Ϊ" + person +"��" + name +"\n���ڰ커��...");
	}
	public void Visa() {
		System.out.println("���ڰ�ǩ֤...");
	}
	public void tickets() {
		System.out.println("������Ʊ...");
	}
	public void arrive() {
		System.out.println("����Ŀ�ĵ�---" + country + "\n");
	}
}
