package ex_FacadeMonthTest;

public class PostalFacade {
    private Check c;
    private Weight w;
    private Transport t;

    public PostalFacade(Package pkg, int i)
    {
        this.c = new Check(pkg);
        this.w = new Weight(pkg);

        c.Checked();
        System.out.println("费用为："+w.Charge());
        this.t = new Transport(i);
    } 
}
