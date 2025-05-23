package lab2;

public class MyThread implements  Runnable{
    private  String name;
    private  int age;

    public MyThread(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public void run() {

        try {
            for(int i=0; i<=3; i++){
                System.out.println(i +" Helle "+name+ "! Age: "+age);
                Thread.sleep(1000);
            }
        }catch (Exception e){
            System.out.println("Exceptions");
        }
    }
}
