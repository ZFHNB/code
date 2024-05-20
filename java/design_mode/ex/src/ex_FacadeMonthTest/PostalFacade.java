package ex_FacadeMonthTest;

public class PostalFacade {
    private Check c;
    private Weight w;
    private Transport t;

    public PostalFacade(Package pkg, int i)
    {
        c = new Check(pkg);
        w = new Weight(pkg);

        c.Checked();
        System.out.println("费用为："+w.Charge());
        t = new Transport(i);
    } 
}
