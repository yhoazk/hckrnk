/*
 * Decompiled with CFR 0_122.
 */
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class CrackMe {
    public static void main(String[] object) {
        byte[] arrby;
        object = new Scanner(System.in);
        byte[] arrby2 = new byte[16];
        boolean bl = false;
        a a2 = new a();
        do {
            System.out.println("Passwort 1:");
            arrby = object.nextLine();
        } while (!(String.valueOf(a2.a()) + "!").equals(arrby));
        int n = arrby.length();
        System.arraycopy(arrby.getBytes(), 0, arrby2, 0, n);
        while (!bl) {
            System.out.println("Passwort 2:");
            arrby = object.nextLine();
            if (arrby.isEmpty()) continue;
            arrby = arrby.getBytes();
            String string = a2.a(arrby);
            System.arraycopy(string.getBytes(), 0, arrby2, 8, Math.min(8, arrby.length));
            if (!a2.a().equals(string)) continue;
            arrby2[1] = arrby[3];
            bl = true;
        }
        object.close();
        arrby = a2.a(arrby2);
        if (arrby.substring(1, 2).equals("h")) {
            System.out.println("Dein Gewinncode lautet: " + (String)arrby);
        }
    }
}
