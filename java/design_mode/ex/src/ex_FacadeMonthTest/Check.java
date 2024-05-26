package ex_FacadeMonthTest;

public class Check {
    private boolean isSafe = true;
    public Check(Package pkg)
    {
        isSafe = pkg.getIsSafe();
    }
    public void Checked()
    {
        if(isSafe)
        {
            System.out.println("包裹安全");
        }
        else
        {
            System.out.println("包裹不安全");
        }
    }
}
