package shiyan7;

public abstract class TV {
	protected String mark;
	public abstract int getId();//�����Ʒ����֪�����
	public  void printInfo(){
		System.out.println("������һ̨" + mark + "�ƣ����Ϊ" + getId() + "�ĵ��ӻ�");
	}
}
