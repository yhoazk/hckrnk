/*
 * Decompiled with CFR 0_122.
 * http://knack-den-code.itestra.de/
 */
public final class a {
    private int a = 0;

    public final String a(byte[] arrby) {
        int n;
        this.a = arrby.length;
        byte[] arrby2 = new byte[8];
        byte[] arrby3 = new byte[8];
        int n2 = 0;
        int n3 = 13;
        int n4 = 21;
        int n5 = 0;
        while (n5 < 8)
        {
            byte[] arrby4 = arrby;
            int n6 = arrby4.length;
            int n7 = 0;
            while (n7 < n6)
            {
                n = arrby4[n7];
                byte[] arrby5 = arrby2;
                int n8 = n2;
                arrby5[n8] = (byte)(arrby5[n8] + (n ^ n3));
                arrby3[7 - n2] = (byte)(n4 + n2);
                n = n4;
                n4 = (byte)(n4 << 1);
                n3 = (n3 ^ n2) + arrby2[n2];
                byte[] arrby6 = arrby2;
                int n9 = n2;
                arrby6[n9] = (byte)(arrby6[n9] + (n & n4));
                n4 = (byte)(n4 + (n4 + 1));
                n2 = (n2 + 1) % 8;
                ++n7;
            }
            ++n5;
        }
        char[] arrc = new char[8];
        n = 0;
        while (n < 8) {
            arrc[n] = (char)((arrby2[n] & 63) + 48);
            ++n;
        }
        return String.valueOf(arrc);
    }

    public final String a() {
        switch (this.a) {
            case 1: {
                return "lL8D0uWh";
            }
            case 2: {
                return "Vx\\D5<N@";
            }
            case 3: {
                return "Whk1=qAO";
            }
            case 4: {
                return "Fu6hS_dB";
            }
            case 5: {
                return "GBi\\vji6";
            }
            case 6: {
                return "e8QO^ro9";
            }
            case 7: {
                return "WkTrF:7i";
            }
            case 8: {
                return "j9v`CAYT";
            }
            case 9: {
                return "FEWPPGDq";
            }
            case 10: {
                return "^1y]]Se7";
            }
            case 11: {
                return "8vM=lZoU";
            }
            case 12: {
                return "@y0^Z2lb";
            }
            case 13: {
                return "<m9hJnp7";
            }
            case 14: {
                return "e2PNSgej";
            }
            case 15: {
                return "j1_SXH^x";
            }
            case 16: {
                return "_gtFZoRO";
            }
            case 17: {
                return "<mx<U_09";
            }
            case 18: {
                return "@k8_;r7H";
            }
            case 19: {
                return "mM0bBw=R";
            }
            case 20: {
                return "s2>=i40F";
            }
        }
        return "BQc7qLNU";
    }
}
