package shiyan11;

import java.util.*;
public class Caretaker{
      Stack <UnicodeLabel.Memento> stack;
      Caretaker(){
            stack=new Stack<UnicodeLabel.Memento>(); 
      }
      public  UnicodeLabel.Memento getMemento(){
            if(!(stack.isEmpty())){
               UnicodeLabel.Memento memento=stack.pop();
               return  memento; 
            }
            else{
               return null; 
            }
      }
      public void saveMemento(UnicodeLabel.Memento  memento){
            stack.push(memento);
      }
}