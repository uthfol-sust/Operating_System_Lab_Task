package DeadlockSimulation;

public class ResourcesA implements Runnable{
    private final Object lockA;
    private  final Object lockB;

    public ResourcesA(Object lockA, Object lockB) {
        this.lockA = lockA;
        this.lockB = lockB;
    }

    @Override
    public void run() {
        synchronized (lockA){
            System.out.println("Thread A acquired LockA");
            //try { Thread.sleep(100); } catch (InterruptedException ignored) {}
            synchronized (lockB){
                System.out.println("Thread B acquired LockB");
            }
        }
    }
}
