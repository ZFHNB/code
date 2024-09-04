package shiyan1;


public class Invoker {
	
	Command command;
	public void setComand(Command command ){
		this.command = command;
	}
	public void executeCommand(){
		command.execute();
	}
}
