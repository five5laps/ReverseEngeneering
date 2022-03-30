import java.awt.*;
import java.awt.event.InputEvent;
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
            int delay = rand.nextInt(1000);
            System.out.println("Next move in " + delay);
            int MoveDelay = rand.nextInt(1000);
            Thread.sleep(delay);
            /*
            KeyPress(KeyEvent.VK_W,MoveDelay);
            //KeyPress(KeyEvent.VK_A,MoveDelay);
            //KeyPress(KeyEvent.VK_S,MoveDelay);
            //KeyPress(KeyEvent.VK_D,MoveDelay);
            System.out.println("green eye coordinates ");
            //green eye coordinates
            bot.mouseMove(1790,1060);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            System.out.println("pvp coordinates ");
            //pvp coordinates
            bot.mouseMove(220,590);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            System.out.println("fast match coordinates ");
            //fast match coordinates
            bot.mouseMove(68,250);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            System.out.println("queue coordinates ");
            //queue coordinates
            bot.mouseMove(444,495);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            System.out.println("join coordinates ");
            //join coordinates
            bot.mouseMove(458,557);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            System.out.println("game found coordinates ");
            //game found coordinates
            bot.mouseMove(902,341);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            System.out.println("game exit coordinates ");
            //game exit coordinates
            bot.mouseMove(956,805);
            Thread.sleep(300);
            bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
            bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            Thread.sleep(delay);
            */
            //random jump
            Jump_State = rand.nextInt(5);

            if(Jump_State == 2){
                //Jump
                bot.keyPress(KeyEvent.VK_SPACE);
                bot.keyRelease(KeyEvent.VK_SPACE);
            }
        }
    }
}
