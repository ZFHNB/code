package ex2_AbstractFactory;

public class WesternTrousers extends Trousers{
    private int waistSize;
   private int height;
   private String name;

   WesternTrousers(String name,int waistSize,int height){
       this.name=name;
       this.waistSize=waistSize;
       this.height=height;
   }

    public int getWaistSize(){       return waistSize;   }
    public int getHeight(){       return height;   }
    public String getName(){      return name;   } 

}
