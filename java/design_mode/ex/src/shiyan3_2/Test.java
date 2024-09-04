package shiyan3_2;

public class Test {

	public static void main(String[] args) {
		Hamburger burger = new ChickenBurger();
		Lettuce burger1 = new Lettuce(burger);
		System.out.println(burger1.getName() + burger1.getPrice() + "Ԫ");
		Sauce burger2 = new Sauce(burger1);
		System.out.println(burger2.getName() + burger2.getPrice() + "Ԫ");
	}
}
