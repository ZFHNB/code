package shiyan3_1;

public class CoffeeBean2 extends Beverage{

	public CoffeeBean2() {
		price = 20;//父类继承过来的属性
		name = "第二种咖啡";
	}
	@Override
	public int getPrice() {
		return price;
	}

	@Override
	public String getName() {
		return name;
	}

}
