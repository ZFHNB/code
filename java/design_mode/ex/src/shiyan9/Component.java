package shiyan9;

public abstract class Component {
	public abstract void add(Component cc);
	public abstract void remove(Component cc);
	public abstract Component getChild(int index);
	public abstract void eat();
	public abstract boolean isLeaf();
}
