public class ThreadCreation implements  Runnable{

    private String name;
    private int age;

    public ThreadCreation(int age,String name) {
        this.age = age;
        this.name = name;
    }

    @java.lang.Override
    public void run() {
        System.out.println("Name"+name + "'s Age "+age);
    }
}
