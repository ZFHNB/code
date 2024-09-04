package shiyan3_1;

public class Test {

	public static void main(String[] args) {
		Beverage bean1 = new CoffeeBean1();
		System.out.println(bean1.getName()+bean1.getPrice()+"Ԫ");
		
		Milk milk = new Milk(bean1);
		System.out.println(milk.getName()+milk.getPrice()+"Ԫ");
		Soy soy = new Soy(milk);
		System.out.println(soy.getName()+soy.getPrice()+"Ԫ");
	}

}
