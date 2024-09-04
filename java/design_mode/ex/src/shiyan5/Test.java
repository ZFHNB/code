package shiyan5;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		System.out.print("ÇëÃèÊöÄúµÄ²¡Çé£º");

		Scanner scanner = new Scanner(System.in);
		String describe = scanner.next();
		Facade person = new Facade(describe);
		person.seeDoctor();

	}

}
