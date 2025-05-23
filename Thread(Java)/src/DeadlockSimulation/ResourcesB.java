package DeadlockSimulation;

public class ResourcesB implements  Runnable{
    private final  Object lockA;
    private final  Object lockB;

    public ResourcesB(Object lockA, Object lockB) {
        this.lockA = lockA;
        this.lockB = lockB;
    }


    @Override
    public void run() {
        synchronized (lockB){
            System.out.println("Thread B acquired LockB");
            //try { Thread.sleep(100); } catch (InterruptedException ignored) {}
            synchronized (lockA){
                System.out.println("Thread A acquired LockA");
            }
        }
    }
}
