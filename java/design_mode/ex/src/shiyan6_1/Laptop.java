package shiyan6_1;

public abstract class Laptop {
	public String name;
	public abstract int getId();
	public  void show(){
		System.out.println("������һ̨" + name + "�ƣ����Ϊ" + getId() + "�ıʼǱ�����");
	}
}
