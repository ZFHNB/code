package shiyan5;

public class Pharmacy {
	public String name;
	double price;

	public Pharmacy(String describe) {
		
		switch (describe) 
		{
			case "ͷʹ":
				name = "�����";
				System.out.println("ҩƷ�۸�10Ԫ");
				break;
			case "��ð":
				name = "999��ð��";
				System.out.println("ҩƷ�۸�12.5Ԫ");
				break;
			case "�����巢��": 
				name = "˫�����ڷ�Һ";
				System.out.println("ҩƷ�۸�15Ԫ");
				break;
		}
		
	}
	
	public String getName() {
		return name;
	}
	
}
