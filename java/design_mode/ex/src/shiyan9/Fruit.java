package shiyan9;

public class Fruit extends Component{

	String name;
	public Fruit(String name) {
		this.name = name;
	}
	
	@Override
	public void add(Component cc) {}

	@Override
	public void remove(Component cc) {}

	@Override
	public Component getChild(int index) {return null;}

	@Override
	public void eat() {
		System.out.println("�õ���һ��" + name);
	}

	@Override
	public boolean isLeaf() {
		return true;
	}

}
