package shiyan5;

public class Pharmacy {
	public String name;
	double price;

	public Pharmacy(String describe) {
		
		switch (describe) 
		{
			case "头痛":
				name = "布洛芬";
				System.out.println("药品价格：10元");
				break;
			case "感冒":
				name = "999感冒灵";
				System.out.println("药品价格：12.5元");
				break;
			case "扁桃体发炎": 
				name = "双黄连口服液";
				System.out.println("药品价格：15元");
				break;
		}
		
	}
	
	public String getName() {
		return name;
	}
	
}
