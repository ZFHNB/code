package ex1_FactoryMethod;

public class RedPenCore extends PenCore{
    RedPenCore()
    {
        color="红色";
    }
    public void writeBoard(String s)
    {
        System.out.println("写出"+color+"的字:"+s);
    }
}
