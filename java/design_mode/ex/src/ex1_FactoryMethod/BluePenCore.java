package ex1_FactoryMethod;

public class BluePenCore extends PenCore{
    BluePenCore()
    {
        color = "蓝色";
    }
    public void writeWord(String s)
    {
        System.out.println(s);
    }
}
