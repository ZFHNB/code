package ex1_FactoryMethod;

public class RedPenCore extends PenCore 
{
    RedPenCore() 
    {
        color = "红色";
    }
    public void writeWord(String s)
    {
        System.out.println(s);
    }
}