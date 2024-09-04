package shiyan1;
import java.util.Scanner;

public class Machine {

	public static void main(String[] args) {
		Invoker invoker = new Invoker();
		Light light = new Light();
		Camera camera = new Camera();
		Command command = null;
		
		System.out.print("输入规则：\n输入1打开灯\n输入2关闭灯\n输入3打开摄像头\n输入4关闭摄像头\n\n请输入：");
		Scanner scanner =new Scanner(System.in);
		int x = scanner.nextInt();
		switch (x) {
		case 1:command = new OnLightCommand(light);break;
		case 2:command = new OffLightCommand(light);break ;
		case 3:command = new OnCameraCommand(camera);break;
		case 4:command = new OffCameraCommand(camera);break;
		}
		
		invoker.setComand(command);
		System.out.println(command.getName());
		invoker.executeCommand();

	}

}
