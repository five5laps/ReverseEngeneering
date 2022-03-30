import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.Random;
import java.util.Scanner;
import java.util.stream.IntStream;

public class AFK {

    public static void KeyPress(int key,int delay) throws AWTException, InterruptedException {

        Robot bot = new Robot();
        bot.keyPress(key);
        Thread.sleep(delay);
        bot.keyRelease(key);
        Thread.sleep(3000);
    }


    public static void main(String[] args) throws AWTException, InterruptedException {
        //Print
        System.out.println("" +
                "█████████████████████████████████████\n" +
                "█────█─██─█───█───█████────█───█─██─█\n" +
                "█─██─█──█─██─███─██████─██─█─███─█─██\n" +
                "█────█─█──██─███─██───█────█───█──███\n" +
                "█─██─█─██─██─███─██████─██─█─███─█─██\n" +
                "█─██─█─██─██─██───█████─██─█─███─██─█\n" +
                "█████████████████████████████████████");
        System.out.println("Press enter to start botting");
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println("Working...");
        //base
        int Jump_State;
        Random rand = new Random();
        Robot bot = new Robot();

        while(true){
            int delay = rand.nextInt(120000);
            System.out.println("Next move in " + delay);
            int MoveDelay = rand.nextInt(5000);
            //System.out.println("MoveDelay is " + MoveDelay);
            Thread.sleep(delay);
            KeyPress(KeyEvent.VK_W,MoveDelay);
            KeyPress(KeyEvent.VK_A,MoveDelay);
            KeyPress(KeyEvent.VK_S,MoveDelay);
            KeyPress(KeyEvent.VK_D,MoveDelay);
            Jump_State = rand.nextInt(5);

            if(Jump_State == 2){
                //Jump
                bot.keyPress(KeyEvent.VK_SPACE);
                bot.keyRelease(KeyEvent.VK_SPACE);

            }
        }
    }
}
