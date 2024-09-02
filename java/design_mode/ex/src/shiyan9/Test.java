package shiyan9;

public class Test {

	public static void main(String[] args) {
		Fruit fruit1 = new Fruit("苹果");
		Fruit fruit2 = new Fruit("香蕉");
		Fruit fruit3 = new Fruit("梨");
		Fruit fruit4 = new Fruit("桑葚");
		Fruit fruit5 = new Fruit("樱桃");
		
		Plate plate1 = new Plate();
		Plate plate2 = new Plate();
		
		//plate里面放三个水果
		plate1.add(fruit1);
		plate1.add(fruit2);
		plate1.add(fruit3);
		
		//plate里面放两个水果
		plate2.add(fruit4);
		plate2.add(fruit5);
		
		//plate2是大盘子，把plate1放在plate2里面
		plate2.add(plate1);
		
		fruit1.eat();
		plate2.eat();
		
	}

}
