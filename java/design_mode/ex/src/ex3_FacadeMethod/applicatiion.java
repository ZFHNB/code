package ex3_FacadeMethod;

public class applicatiion {
    public static void main(String []args)
    {
        String advertisement = "Hello world!";
        ClientServerFacade c = new ClientServerFacade(advertisement);
        c.doAdvertisement();
    }
}
