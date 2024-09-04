package shiyan9;
import java.util.LinkedList;

public class Plate extends Component{
	LinkedList<Component> fruits;
	public Plate() {
		fruits = new LinkedList<Component>();
	}
	
	@Override
	public void add(Component cc) {
		fruits.add(cc);
	}

	@Override
	public void remove(Component cc) {
		fruits.remove(cc);
	}

	@Override
	public Component getChild(int index) {
		return fruits.get(index);
	}

	@Override
	public void eat() {
		for(int i = 0;i<fruits.size();i++){
			if(fruits.get(i).isLeaf()){
				fruits.get(i).eat();
			}
			else {
				//父类向子类转型，要强制类型转换
				Plate plate = (Plate)fruits.get(i);
				plate.eat();
			}
		}
	}

	@Override
	public boolean isLeaf() {
		return false;
	}

}
