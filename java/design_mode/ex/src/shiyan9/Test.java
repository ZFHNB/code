package shiyan9;

public class Test {

	public static void main(String[] args) {
		Fruit fruit1 = new Fruit("ƻ��");
		Fruit fruit2 = new Fruit("�㽶");
		Fruit fruit3 = new Fruit("��");
		Fruit fruit4 = new Fruit("ɣ��");
		Fruit fruit5 = new Fruit("ӣ��");
		
		Plate plate1 = new Plate();
		Plate plate2 = new Plate();
		
		//plate���������ˮ��
		plate1.add(fruit1);
		plate1.add(fruit2);
		plate1.add(fruit3);
		
		//plate���������ˮ��
		plate2.add(fruit4);
		plate2.add(fruit5);
		
		//plate2�Ǵ����ӣ���plate1����plate2����
		plate2.add(plate1);
		
		fruit1.eat();
		plate2.eat();
		
	}

}
