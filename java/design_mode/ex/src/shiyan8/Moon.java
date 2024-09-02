package shiyan8;

public class Moon {
	private static Moon uniqueMoon;
	double radius;
	double distanceToEarth;
	
	//��Ĺ��췽����˽�е�
	private Moon() {
		uniqueMoon = this;
		radius = 1738;
		distanceToEarth = 363300;
	}
	public static Moon getMoon() {
		if(uniqueMoon == null){
			uniqueMoon = new Moon();
			return uniqueMoon;
		}
		else{
			return uniqueMoon;
		}
	}
	public void show() {
		System.out.println("����İ뾶Ϊ"+radius+"km\n����������ľ���Ϊ"+distanceToEarth+"km");
	}
	
}
