package shiyan7;

public abstract class Phone {
	protected String mark;
	
	public abstract int getId();
	public  void printInfo(){
		System.out.println("������һ��" + mark + "�ƣ����Ϊ" + getId() + "���ֻ�");
	}
}
