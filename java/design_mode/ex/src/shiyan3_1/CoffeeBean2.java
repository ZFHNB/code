package shiyan3_1;

public class CoffeeBean2 extends Beverage{

	public CoffeeBean2() {
		price = 20;//����̳й���������
		name = "�ڶ��ֿ���";
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
