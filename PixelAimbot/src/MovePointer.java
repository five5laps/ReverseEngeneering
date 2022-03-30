
import java.awt.*;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.Rectangle;
import java.awt.AWTException;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.util.Scanner;

public class MovePointer {

    public static void main(String[] args) throws AWTException, InterruptedException {
        int r,g,b;
        int area, sleep, smooth, click;
        Scanner sc = new Scanner(System.in);
        //input data

        System.out.printf("Choose red [0-255]\n");
        r = sc.nextInt();
        System.out.printf("Choose green [0-255]\n");
        g = sc.nextInt();
        System.out.printf("Choose blue [0-255]\n");
        b = sc.nextInt();
        System.out.printf("Choose area around cursor [0-500]\n");
        area = sc.nextInt();
        System.out.printf("Choose delay after assist [0-1000]\n");
        sleep = sc.nextInt();
        System.out.printf("Choose smooth speed [0-300]\n");
        smooth = sc.nextInt();
        System.out.printf("Choose to click or not [0-1]\n");
        click = sc.nextInt();
        if(r > 255 || g > 255 || b > 255 || area > 500 || smooth > 300 || sleep > 1000 || sleep < 0 || r < 0 || g < 0 || b < 0 || area < 0 || smooth < 0) System.exit(0);

        Color usercolor = new Color(r,g,b);
        while (true) {
            Thread.sleep(10);
            scanScreen(usercolor,area,smooth,click,sleep);
        }
    }
    //check if square out of screen and check for SC for pixel
    private static BufferedImage grabScreen(Rectangle screenRect,Point PCord, int area) {
        try {
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
            int XL = (PCord.x - area) < 0 ? 0 : (PCord.x - area);
            int XR = (PCord.x + area) > screenSize.width ? screenSize.width : (PCord.x + area);
            int YT = (PCord.y + area) > screenSize.height ? screenSize.height : (PCord.y + area);;
            int YB = (PCord.y - area) < 0 ? 0 : (PCord.y - area);
            screenRect.setRect(XL,YB,XR,YT);
            return new Robot().createScreenCapture(screenRect);
        } catch (SecurityException e) {
        } catch (AWTException e) {
        }
        return null;
    }
    //scanning around pointer
    public static void scanScreen(Color matchColor, int area, int smooth, int click, int sleep) throws AWTException {
        try{
            int speed = 100;
            Scanner sc = new Scanner(System.in);
            Rectangle newrect = new Rectangle();
            PointerInfo pointer;
            Robot bot = new Robot();
            pointer = MouseInfo.getPointerInfo();
            Point PCord = pointer.getLocation();

            BufferedImage SC = grabScreen(newrect,PCord,area);

            for (int XArea = newrect.x; XArea < newrect.width; XArea++) {
                    for (int YArea = newrect.y; YArea < newrect.height; YArea++) {
                        if (matchColor.getRGB() == SC.getRGB((int) XArea - newrect.x,(int) YArea - newrect.y)) {
                            for (int i=0; i<=smooth; i++) {
                                int mov_x = PCord.x + (XArea - PCord.x) * i / smooth;
                                int mov_y = PCord.y + (YArea - PCord.y) * i / smooth;

                                if(click == 1){
                                    bot.delay(2);
                                    bot.mouseMove(mov_x, mov_y);

                                    bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                                    bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);

                                }else{
                                    bot.mouseMove(mov_x, mov_y);
                                }
                            }
                            return;
                        }
                    }
                }
        }catch (AWTException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
