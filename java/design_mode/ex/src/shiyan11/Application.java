package shiyan11;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class Application extends JFrame implements MouseListener{
       UnicodeLabel label;
       Caretaker  caretaker;      //������
       Application(){
           label=new UnicodeLabel();
           label.addMouseListener(this);
           add(new JLabel("���������ʾһ�����֣������Ҽ�������������Ĳ���Ч��"),
                 BorderLayout.NORTH);
           add(label,BorderLayout.CENTER);
           caretaker=new Caretaker();             //���������� 
     }
     public void mousePressed(MouseEvent e) { 
           if(e.getModifiers()==InputEvent.BUTTON1_MASK){
                 caretaker.saveMemento(label.createMemento());    //���汸��¼   
           } 
           if(e.getModifiers()==InputEvent.BUTTON3_MASK){
                  UnicodeLabel.Memento memento=caretaker.getMemento();     //�õ�����¼
                  if(memento!=null){ 
                         label.restoreFromMemento(memento);  //ʹ�ñ���¼�ָ�״̬ 
                 }
           }
     }
     public void mouseReleased(MouseEvent e){}
     public void mouseEntered(MouseEvent e) {}
     public void mouseExited(MouseEvent e) {}
     public void mouseClicked(MouseEvent e){}
     public static void main(String args[]) {
         Application win=new Application();
         win.setBounds(10,10,300,300);
         win.setVisible(true); 
         win.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
     }
}
