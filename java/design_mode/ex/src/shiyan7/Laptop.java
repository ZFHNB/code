package shiyan7;

public abstract class Laptop {
	protected String mark;
	public abstract int getId();//�����Ʒ����֪�����
	public  void printInfo(){
		System.out.println("������һ̨" + mark + "�ƣ����Ϊ" + getId() + "�ıʼǱ�����");
	}
}
