package shiyan10;
import java.util.HashSet;
import java.util.Iterator;

public class TravelAbroad {
	String person;//身份证号
	String name;//姓名
	int Days;//签证有效时间
	String country;//去的目的地
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
	//钩子方法，
	public boolean hook() {
		return true;
	}
	public void passport() {
		System.out.println("编号为" + person +"的" + name +"\n正在办护照...");
	}
	public void Visa() {
		System.out.println("正在办签证...");
	}
	public void tickets() {
		System.out.println("正在买票...");
	}
	public void arrive() {
		System.out.println("到达目的地---" + country + "\n");
	}
}
