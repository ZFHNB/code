package ex3_FacadeMethod;

public class TypeSeting 
{
    String advertisement;

    public TypeSeting(String advertisement)
    {
        this.advertisement = advertisement;
    }
    public void typeSeting()
    {
        System.out.println("广告排版格式:");
        System.out.println("********");
        System.out.println(advertisement);
        System.out.println("********");  
    }
}
