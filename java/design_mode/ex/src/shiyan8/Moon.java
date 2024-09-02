package shiyan8;

public class Moon {
	private static Moon uniqueMoon;
	double radius;
	double distanceToEarth;
	
	//类的构造方法是私有的
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
		System.out.println("月球的半径为"+radius+"km\n月球距离地球的距离为"+distanceToEarth+"km");
	}
	
}
