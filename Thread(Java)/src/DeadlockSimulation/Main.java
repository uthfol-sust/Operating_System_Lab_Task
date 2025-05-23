package DeadlockSimulation;

public class Main {
    public static void main(String[] args) {
       final Object lockA = new Object();
       final Object lockB = new Object();

       Thread th1 =new Thread(new ResourcesA(lockA,lockB));
       Thread th2 = new Thread(new ResourcesB(lockA,lockB));

       th1.start();
       th2.start();

        System.out.println("finshed threads");
    }
}
